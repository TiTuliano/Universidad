
--INNER JOIN

--S2.1
SELECT t.tarifa, t.coste, c.nombre
--INNER JOIN tablas a unir --ON clave primaria de la primera tabla = clave ajena de la segunda tabla
FROM mf.compañia c INNER JOIN mf.tarifa t ON c.cif=t.compañia 
WHERE t.descripcion LIKE '%compañía';

--S2.2
SELECT c.nombre, t.numero
FROM (mf.cliente c INNER JOIN mf.telefono t ON c.dni=t.cliente)
    INNER JOIN mf.tarifa tar USING (tarifa,compañia) --usamos USING pq la clave primaria de tarifa se llama igual que la ajena de telefono
WHERE tar.coste <0.20;

--S2.3
SELECT tarifa, cia.nombre, tel.numero, tel.puntos --como uso el using con tarifa no se puede poner tar.
FROM (mf.compañia cia INNER JOIN mf.tarifa tar ON cia.cif=tar.compañia)
    INNER JOIN mf.telefono tel USING(tarifa,compañia)
WHERE tel.puntos>200
    AND EXTRACT(YEAR FROM tel.f_contrato)=2006;

--S2.4
SELECT llam.tf_origen, llam.tf_destino, tel.tipo, llam.fecha_hora, lamm.duracion
FROM (mf.llamada llam INNER JOIN mf.telefono tel ON llam.tf_origen=tel.numero)
    INNER JOIN mf.telefono telf ON llam.tf_destino=telf.numero
WHERE EXTRACT(HOUR FROM llam.fecha_hora) BETWEEN 8 AND 10; 

--S2.5 --Preguntar esto en tutoria
SELECT clte.nombre, llam.tf_origen, llam.tf_destino, llam.fecha_hora, llam.duracion
FROM mf.telefono tel_origen
INNER JOIN mf.llamada llam ON llam.tf_origen = tel_origen.numero
INNER JOIN mf.cliente clte ON tel_origen.cliente = clte.dni
INNER JOIN mf.telefono tel_destino ON llam.tf_destino = tel_destino.numero
WHERE tel_origen.compañia <> tel_destino.compañia
  AND llam.duracion > 15;
