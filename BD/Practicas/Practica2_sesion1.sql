
--Select from where

--S1.1
SELECT nombre --selecionamos lo que se pide
FROM mf.compañia --de donde se pide
WHERE web LIKE '%et%.com'; --con la condicion que se pide

--S1.2
SELECT nombre, direccion --podemos seleccionar varios atributos separandolos con comas
FROM mf.cliente
WHERE EXTRACT (YEAR FROM f_nac) IN (1973,1985) --Extraemos el año de la fecha completa y ponemos la condicion 
    AND cp LIKE '15%'                         
ORDER BY nombre ASC, direccion DESC;  --Ordenamos la salida de los datos

--S1.3
SELECT tf_destino
FROM mf.llamada
WHERE tf_origen=666010101 --Los numeros no van entre comas
    AND EXTRACT(YEAR FROM fecha_hora)=2006; --Cuando en el extract solo ponnemos un valor no se usa IN, se usa =

--S1.4
SELECT tf_origen
FROM mf.llamada
WHERE tf_destino=666010101
    AND EXTRACT(HOUR FROM fecha_hora)>=10 --tambien se podria hacer con between
    AND EXTRACT(HOUR FROM fecha_hora)<=12;
    
--S1.5
SELECT DISTINCT t.tarifa
FROM mf.telefono t
JOIN mf.cliente c ON t.cliente=c.dni
WHERE c.dni NOT LIKE '%2%'
    AND t.tipo='contrato'
    AND t.puntos BETWEEN 10000 AND 20000;
    
--S1.6
SELECT DISTINCT tarifa, numero
FROM mf.telefono
WHERE EXTRACT(MONTH FROM f_contrato)=5 --5 pq mayo es el mes 5
    AND tarifa <> 'joven' -- <> es el simbolo distinto de
    AND numero LIKE '%9'
    ORDER BY puntos DESC;
    
--S1.7
SELECT DISTINCT tf_destino
FROM mf.llamada
WHERE tf_origen=654345345
    AND duracion>250
    AND EXTRACT(MONTH FROM fecha_hora) IN (10,11); --IN pq no solo queremos un mes sino varios
    
--S1.8
SELECT nombre
FROM mf.cliente
WHERE EXTRACT(YEAR FROM f_nac) BETWEEN 1970 AND 1985 --para seleccionar entre esos años usamos el between
    AND provincia='Huelva'
ORDER BY ciudad ASC, provincia DESC;

