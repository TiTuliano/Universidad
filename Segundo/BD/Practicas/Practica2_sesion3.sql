
--Subconsultas IN, NOT IN, ANY

--S3.1
SELECT TO_CHAR(fecha_hora,'dd/mm/yyyy') AS Fecha --usamos un alias a la hora de mostrar la salida
FROM mf.llamada
WHERE duracion>=ALL --asi conseguimos la mayor duraccion
    (SELECT DISTINCT duracion FROM mf.llamada); --subconsulta para obtener las duracciones

--S3.2
SELECT cli.nombre, cia.nombre, tel.numero, tel.tarifa
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni = tel.cliente) -- Unimos las tablas por dni
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Aotra'
  AND tel.tarifa = (SELECT tarifa -- Obtenemos el tipo de tarifa del número de teléfono
                  FROM mf.telefono
                  WHERE numero ='654123321');

--S3.3
SELECT DISTINCT tel.numero, tel.f_contrato, tel.tipo
FROM mf.telefono tel INNER JOIN mf.llamada llam ON tel.numero=llam.tf_origen
WHERE to_char(llam.fecha_hora,'mm/yy')='10/06'
    AND llam.tf_destino NOT IN(SELECT tel.numero
                               FROM mf.telefono telf INNER JOIN mf.cliente cli ON cli.dni=telf.cliente
                               WHERE provincia = 'La Coruña');

--S3.4
SELECT cli.nombre
FROM mf.cliente cli
WHERE cli.dni IN (  --cliente tiene tarifa duo
        SELECT tel.cliente
        FROM mf.telefono tel
        WHERE tel.tarifa = 'dúo'
    )
AND cli.dni NOT IN ( --pero no autonomos
        SELECT telf.cliente
        FROM mf.telefono telf
        WHERE telf.tarifa = 'autónomos'
    );

--S3.5
SELECT cli.nombre, tel.numero
FROM mf.cliente cli
INNER JOIN mf.telefono tel ON cli.dni = tel.cliente --unimos las tablas
WHERE tel.numero IN (
        SELECT llam1.tf_origen
        FROM mf.llamada llam1     --selecionamos todas las llamadas
        WHERE llam1.tf_destino IN (
                SELECT t1.numero
                FROM mf.telefono t1  --que llamaron a petafon
                INNER JOIN mf.compañia c1 ON t1.compañia = c1.cif
                WHERE c1.nombre = 'Petafón'
        )
    )
AND tel.numero NOT IN (
        SELECT llam2.tf_origen
        FROM mf.llamada llam2     --y ahora volvemos a seleecionar todas
        WHERE llam2.tf_destino IN (
                SELECT t2.numero
                FROM mf.telefono t2      --y nos quedamos con las que no llamaron a aotra
                INNER JOIN mf.compañia c2 ON t2.compañia = c2.cif
                WHERE c2.nombre = 'Aotra'
        )
    );
   
--S3.6    
SELECT cli.nombre
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente) --unimos todas las tablas necesarias
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Kietostar' 
    AND EXTRACT(YEAR FROM llam.fecha_hora)=2006
    AND EXTRACT(MONTH FROM llam.fecha_hora)=09
    AND llam.duracion=(SELECT MAX (llam2.duracion) --usamos la subconsulta para obtener la mayor duraccion de las llamadas de los clientes de la compañia kietostar
                        FROM mf.llamada llam2
                        WHERE  EXTRACT(YEAR FROM llam2.fecha_hora)=2006
                            AND EXTRACT(MONTH FROM llam2.fecha_hora)=09 );
                        
--S3.7
SELECT cli.nombre
FROM mf.cliente cli
INNER JOIN mf.telefono tel ON cli.dni = tel.cliente
WHERE cli.nombre <> 'Ramón Martínez Sabina' --excluimos a Ramón
  AND tel.f_contrato < ANY (  --Usamos any para ver que fechas son menores a las de Ramón
        SELECT tel2.f_contrato
        FROM mf.telefono tel2
        INNER JOIN mf.cliente cli2 ON tel2.cliente = cli2.dni
        WHERE cli2.nombre = 'Ramón Martínez Sabina'
  );

    

