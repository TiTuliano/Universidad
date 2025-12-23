
--Practica 2 sesion 4
--EXISTS, NOT EXISTS

--Consulta 1
SELECT cli.nombre
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
WHERE EXISTS (SELECT * FROM mf.llamada llam WHERE tel.numero=llam.tf_origen AND TO_CHAR(fecha_hora,'dd/mm/yy')='16/10/06');

--Consulta 2
SELECT cli.nombre
FROM mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente
WHERE EXISTS (SELECT * FROM mf.llamada llam WHERE tel.numero=llam.tf_origen AND duracion<90);

--Consulta 3
SELECT cli.nombre, tel.numero
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente)
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Kietostar' AND NOT EXISTS (SELECT * FROM mf.llamada llam WHERE EXTRACT (MONTH FROM llam.fecha_hora)=9 AND tel.numero=llam.tf_origen);

--Consulta 4
SELECT *
FROM mf.telefono tel 
WHERE EXISTS (SELECT * FROM mf.llamada llam WHERE llam.tf_destino='654234234' AND llam.tf_origen=tel.numero)
    AND NOT EXISTS (SELECT * FROM mf.llamada llam2 WHERE llam2.tf_destino='666789789' AND llam2.tf_origen=tel.numero);

--Consulta 5
SELECT cli.nombre, tel.numero
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente)
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
WHERE cia.nombre='Kietostar' AND NOT EXISTS (SELECT * FROM mf.llamada llam INNER JOIN mf.telefono tel2 ON tel2.numero=llam.tf_destino
                                                INNER JOIN mf.compañia cia2 ON cia2.cif=tel2.compañia
                                                WHERE cia2.nombre='Kietostar'  AND tel.numero=llam.tf_origen);