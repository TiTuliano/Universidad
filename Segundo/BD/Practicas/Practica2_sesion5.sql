
--Práctica 2 Sesión 5
--COUNT, HAVING COUNT, SUM, AVG, GROUP BY

--S5.1
SELECT cia.nombre
FROM (mf.compañia cia INNER JOIN mf.telefono tel ON tel.compañia=cia.cif)
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
WHERE TO_CHAR(llam.fecha_hora, 'dd/mm/yy')='16/10/06'
GROUP BY cia.nombre
HAVING COUNT(*)=(SELECT MAX(COUNT(*)) 
FROM mf.llamada llam INNER JOIN mf.telefono tel ON llam.tf_origen=tel.numero
WHERE TO_CHAR(llam.fecha_hora, 'dd/mm/yy')='16/10/06'
GROUP BY tel.compañia);

--S5.3
SELECT cli.nombre AS Cliente, cia.nombre AS Compañia, SUM(llam.duracion/60*tar.coste) AS Coste_total
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente)
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
    INNER JOIN mf.compañia cia ON cia.cif=tel.compañia
    INNER JOIN mf.tarifa tar ON tar.tarifa=tel.tarifa
GROUP BY cli.nombre, cia.nombre
ORDER BY cli.nombre DESC, cia.nombre ASC;

--S5.4
SELECT c_origen.nombre,SUM(llam.duracion)
FROM mf.llamada llam
INNER JOIN mf.telefono t_origen ON llam.tf_origen = t_origen.numero
INNER JOIN mf.cliente c_origen ON t_origen.cliente = c_origen.dni
INNER JOIN mf.telefono t_destino ON llam.tf_destino = t_destino.numero
INNER JOIN mf.cliente c_destino ON t_destino.cliente = c_destino.dni
WHERE c_origen.provincia = 'La Coruña'
  AND c_destino.provincia = 'Jaén'
GROUP BY c_origen.nombre;
  
--S5.5
SELECT cli.nombre
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente)
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
GROUP BY cli.nombre
HAVING COUNT(llam.tf_origen)>5;

--S5.6
SELECT cli.nombre
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON cli.dni=tel.cliente)
    INNER JOIN mf.tarifa USING (tarifa,compañia)
GROUP BY cli.nombre
HAVING AVG(coste) > 
    (SELECT AVG(tar.coste) --AVG para calcular la media
    FROM mf.tarifa tar);
    
--S5.7
SELECT cli.nombre
FROM (mf.cliente cli INNER JOIN mf.telefono tel ON tel.cliente=cli.dni)
    INNER JOIN mf.llamada llam ON llam.tf_origen=tel.numero
    INNER JOIN mf.tarifa USING (tarifa,compañia)
WHERE llam.tf_destino IN(SELECT tel.numero 
        FROM mf.telefono tel INNER JOIN mf.compañia cia ON cia.cif=tel.compañia 
        WHERE cia.nombre='Kietostar')
GROUP BY cli.nombre
HAVING SUM((llam.duracion*coste)/60)<100;












