-- Practica 3 - Ejercicio 1
-- Funcion facturacion()

CREATE OR REPLACE FUNCTION facturacion(p_tf_origen mf.llamada.tf_origen%TYPE,p_año INTEGER)
RETURN FLOAT IS

    importe_total    NUMBER(10,2);
    facturacionBaja  EXCEPTION;

BEGIN

    SELECT TRUNC(SUM((llam.duracion * tar.coste) / 60), 2)
    INTO importe_total
    
    FROM mf.telefono tel
        INNER JOIN mf.tarifa tar USING (tarifa, compañia)
        INNER JOIN mf.llamada llam ON llam.tf_origen = tel.numero
    
    WHERE EXTRACT(YEAR FROM llam.fecha_hora) = p_año
      AND llam.tf_origen = p_tf_origen;

    -- No hay llamadas → SUM devuelve NULL
    IF importe_total IS NULL THEN
    
        RETURN -1;
    
    END IF;

    -- Facturación menor de 1€
    IF importe_total < 1 THEN
    
        RAISE facturacionBaja;
    
    END IF;

    RETURN importe_total;

EXCEPTION
    
    WHEN facturacionBaja THEN
    
        dbms_output.put_line('Error. El precio es menor a 1€');
    
        RETURN -1;

    WHEN OTHERS THEN
    
        dbms_output.put_line('Ha ocurrido un error');
    
        RETURN -1;
END;
/
---------------------------------------------------------------

-- Practica 3 - Ejercicio 2
-- Procedimiento llamadaFacturacion()

CREATE OR REPLACE PROCEDURE llamadaFacturacion(p_año INTEGER) IS

    CURSOR c_telefonos IS
    
        SELECT DISTINCT tf_origen
    
        FROM mf.llamada llam
    
        WHERE EXTRACT(YEAR FROM llam.fecha_hora) = p_año;

BEGIN
    
    dbms_output.put_line('N telefono     Importe(€)');
    dbms_output.put_line('---------------------------');

    FOR r_telefono IN c_telefonos LOOP
        
        dbms_output.put_line(r_telefono.tf_origen || '        ' ||facturacion(r_telefono.tf_origen, p_año));
    
    END LOOP;

EXCEPTION
    
    WHEN OTHERS THEN
        dbms_output.put_line('Ha ocurrido un error');
END;
/
---------------------------------------------------------------

-- Pruebas de ejecución (activar DBMS_OUTPUT primero)
 SET SERVEROUTPUT ON;

-- Ejecutar función
CALL dbms_output.put_line( facturacion('654123321', 2006) );

-- Ejecutar procedimiento
BEGIN
    llamadaFacturacion(2006);
END;
/






