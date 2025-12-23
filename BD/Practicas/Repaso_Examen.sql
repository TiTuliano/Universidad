
--S3.1 Obtener la fecha (día mes año) en la que se realizó la 
--llamada de mayor duración

SELECT TO_CHAR(fecha_hora, 'dd/mm/yyy') AS Fecha
FROM mf.llamada 
WHERE duracion>=ALL
    (SELECT duracion FROM mf.llamada);

--S3.2 Obtener el nombre de los abonados de la compañía ‘Aotra’
--con el mismo tipo de tarifa que la del telefono "654123321"

SELECT cli.nombre
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Aotra'
    AND tel.tarifa=(SELECT tarifa FROM mf.telefono WHERE numero='654123321');
    
--EXAMEN DE PABLO

--2.1

SELECT DISTINCT cli.nombre
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
    INNER JOIN mf.llamada llam ON tel.numero=llam.tf_origen
WHERE llam.duracion>240 AND EXTRACT(MONTH FROM llam.fecha_hora)=09;


--2.3

SELECT cli.nombre,cia.nombre AS compañia,tel.numero
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
WHERE llam.duracion > ALL(SELECT llam2.duracion
                            FROM mf.llamada llam2 INNER JOIN mf.telefono tel2 ON tel2.numero=llam2.tf_origen
                                INNER JOIN mf.compañia cia2 ON cia2.cif=tel2.compañia
                            WHERE cia2.nombre='Kietostar');

--S3.3 Mostrar, utilizando para ello una subcobsulta,
--el número de teléfono, fecha de contrato y tipo de los
--abonados que han llamado a teléfonos de clientes de fuera de 
--la provincia de La Coruña durante el mes de octubre de 2006.

SELECT DISTINCT tel.numero,tel.f_contrato,tel.tipo
FROM mf.telefono tel INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
WHERE TO_CHAR(llam.fecha_hora,'mm/yy')='10/06'
AND llam.tf_destino NOT IN(SELECT tel2.numero
                            FROM mf.telefono tel2 INNER JOIN mf.cliente cli ON tel2.cliente=cli.dni
                            WHERE cli.provincia='La Coruña');


--S3.4 Se necesita conocer el nombre de los clientes que tienen teléfonos con tarifa “dúo” pero no “autónomos”.

SELECT cli.nombre
FROM mf.cliente cli 
WHERE cli.dni IN (SELECT tel.cliente
                    FROM mf.telefono tel
                    WHERE tel.tarifa='dúo')
AND cli.dni NOT IN (SELECT tel2.cliente
                 FROM mf.telefono tel2
                WHERE tel2.tarifa='autónomos');

--S3.5 Obtener mediante subconsultas los nombres de clientes y números de teléfono que aquellos que hicieron
--llamadas a teléfonos de la compañía Petafón pero no Aotra

SELECT cli.nombre, tel.numero
FROM mf.cliente cli
     INNER JOIN mf.telefono tel ON cli.dni = tel.cliente
WHERE tel.numero IN (
        SELECT llam.tf_origen
        FROM mf.llamada llam
             INNER JOIN mf.telefono telP ON llam.tf_origen = telP.numero
             INNER JOIN mf.compañia cia ON cia.cif = telP.compañia
        WHERE cia.nombre = 'Petafón'
)
AND tel.numero NOT IN (
        SELECT llam2.tf_origen
        FROM mf.llamada llam2
             INNER JOIN mf.telefono telA ON llam2.tf_origen = telA.numero
             INNER JOIN mf.compañia cia2 ON cia2.cif = telA.compañia
        WHERE cia2.nombre = 'Aotra'
);


--S4.5 S4.5 Utilizando consultas correlacionadas, obtener el
--nombre y número de teléfono de los clientes de la
--compañía Kietostar que no han hecho llamadas a otros teléfonos 
--de la misma compañía

SELECT cli.nombre,tel.numero
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
        INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Kietostar'
AND NOT EXISTS (SELECT * 
                FROM mf.llamada llam INNER JOIN mf.telefono tel2 ON llam.tf_destino=tel2.numero
                    INNER JOIN mf.compañia cia2 ON tel2.compañia=cia2.cif
                WHERE llam.tf_origen=tel.numero AND cia2.nombre='Kietostar');
                
--S4.3 Utilizando consultas correlacionadas, obtener el nombre
--de los abonados de la compañía ‘KietoStar’ que no
--hicieron ninguna llamada el mes de septiembre

SELECT cli.nombre
FROM mf.cliente cli INNER JOIN mf.telefono tel ON tel.cliente=cli.dni
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Kietostar'
AND NOT EXISTS(SELECT * FROM mf.llamada llam 
                WHERE llam.tf_origen=tel.numero AND TO_CHAR(llam.fecha_hora, 'mm')=09);
                
--S5.1 Mostrar la compañía con la que se realizaron más llamadas 
--durante el día 16/10/06

SELECT cia.nombre
FROM (mf.compañia cia INNER JOIN mf.telefono tel ON tel.compañia=cia.cif)
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
WHERE TO_CHAR(llam.fecha_hora, 'dd/mm/yy')='16/10/06'
GROUP BY cia.nombre
HAVING COUNT(*)=(SELECT MAX(COUNT(*)) 
FROM mf.llamada llam INNER JOIN mf.telefono tel ON llam.tf_origen=tel.numero
WHERE TO_CHAR(llam.fecha_hora, 'dd/mm/yy')='16/10/06'
GROUP BY tel.compañia);

--S5.3 Mostrar el nombre de cada cliente junto con coste total de las llamadas que realiza con cada compañia. El
--resultado debe mostrarse ordenado descendentemente por cliente y ascendentemente por compañia

SELECT cli.nombre, SUM(llam.duracion/60*tar.coste)
FROM mf.cliente cli INNER JOIN mf.telefono tel ON tel.cliente=cli.dni
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
    INNER JOIN mf.tarifa tar USING (tarifa,compañia)
GROUP BY cia.nombre, cli.nombre
ORDER BY cli.nombre DESC, cia.nombre ASC;


