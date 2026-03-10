
/*Crear un procedimiento que tenga como parámetros de entrada el nombre de una
compañía y una fecha. Dicho procedimiento debe realizar las siguientes
operaciones:

1. Comprobar que existen en la BD llamadas realizadas en la fecha que se pasa
como parámetro. En caso contrario lanzar una excepción y mostrar el
mensaje “No hay llamadas en la fecha <fecha> en la BD”.

2. Para cada teléfono de la compañía que se pasa por parámetro, el
procedimiento debe mostrar la siguiente información: número de teléfono,
número total de llamadas realizadas en la fecha indicada, número de
llamadas de duración mayor de 100 segundos realizadas en la fecha,
porcentaje que suponen estas últimas respecto al total de las realizadas.

3. Un resumen del número de llamadas realizadas por todos los teléfonos de la
compañía indicada en la fecha pasada por parámetro.*/

/*create or replace procedure llamadas_en_una_fecha(nom_cia mf.compañia.nombre%type,fecha date) is
    
    no_existen_llamadas integer;
    excepcion_no_llamadas exception;

    porcentaje number(5,2);
    mayor100 integer;
    num_llamadas integer;
    num_llamadas_totales integer;

    cursor telefonos is
        select tel.numero
        from mf.telefono tel
             inner join mf.compañia cia on cia.cif = tel.compañia
        where cia.nombre = nom_cia;

    cursor llamadas_por_telefono(telefono mf.llamada.tf_origen%type) is
        select llam.duracion
        from mf.llamada llam
        where llam.tf_origen = telefono
          and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha,'dd/mm/yy');

begin

    num_llamadas_totales := 0;

    select count(*)
    into no_existen_llamadas
    from mf.llamada llam
         inner join mf.telefono tel on tel.numero = llam.tf_origen
         inner join mf.compañia cia on cia.cif = tel.compañia
    where cia.nombre = nom_cia
      and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha,'dd/mm/yy');

    if no_existen_llamadas = 0 then
        raise excepcion_no_llamadas;
    end if;

    for t in telefonos loop

        num_llamadas := 0;
        mayor100 := 0;
        porcentaje := 0;

        for l in llamadas_por_telefono(t.numero) loop

            num_llamadas := num_llamadas + 1;
            num_llamadas_totales := num_llamadas_totales + 1;

            if l.duracion > 100 then
                mayor100 := mayor100 + 1;
            end if;

        end loop;

        if num_llamadas > 0 then
            porcentaje := (mayor100 * 100) / num_llamadas;
        end if;

        dbms_output.put_line(t.numero || ' ' || num_llamadas || ' ' || mayor100 || ' ' || porcentaje || '%');

    end loop;
    
    dbms_output.put_line('-----------------------------------------');
    dbms_output.put_line('Numero Llamadas Realizadas: ' || num_llamadas_totales);

exception
    when excepcion_no_llamadas then
        dbms_output.put_line('no hay llamadas para esa fecha');

    when others then
        dbms_output.put_line('ha ocurrido un error');

end llamadas_en_una_fecha;
/ 

execute llamadas_en_una_fecha('Aotra', TO_DATE('01/10/06','dd/mm/yy'));*/

/*Crear un procedimiento que tenga como parámetros de entrada el nombre de una
compañía y una fecha. Dicho procedimiento debe realizar las siguientes
operaciones:

1. Comprobar que existen en la BD llamadas realizadas en la fecha que se pasa
como parámetro. En caso contrario lanzar una excepción y mostrar el
mensaje “No hay llamadas en la fecha <fecha> en la BD”.

2. Para cada teléfono de la compañía que se pasa por parámetro, el
procedimiento debe mostrar la siguiente información: número de teléfono,
número total de llamadas realizadas en la fecha indicada, número de
llamadas de duración mayor de 100 segundos realizadas en la fecha,
porcentaje que suponen estas últimas respecto al total de las realizadas.

3. Un resumen del número de llamadas realizadas por todos los teléfonos de la
compañía indicada en la fecha pasada por parámetro.*/    

/*create or replace procedure llamadas_cia (cia_nombre compañia.nombre % type, fecha date) is

    no_llamadas integer;
    excepcion_no_llamadas exception;
    
    mayor100 integer;
    llamadas_totales integer;
    num_llamadas integer;
    porcentaje number(4,2);
    
    cursor telefonos is
        select tel.numero
        from mf.telefono tel inner join mf.compañia cia on cia.cif = tel.compañia
        where cia.nombre = cia_nombre;
    
    cursor llamadas_por_telefono (telefono mf.llamada.tf_origen % type) is
        select llam.duracion 
        from mf.llamada llam 
        where llam.tf_origen= telefono and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha,'dd/mm/yy');
    
begin
    
    no_llamadas:=0;
    
    select count(*)
    into no_llamadas
    from mf.llamada llam inner join  mf.telefono tel on tel.numero=llam.tf_origen
    inner join mf.compañia cia on cia.cif = tel.compañia
    where cia.nombre = cia_nombre
        and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha,'dd/mm/yy');
    
    if no_llamadas = 0 then
        raise excepcion_no_llamadas;
    end if;
    
    llamadas_totales := 0;
    
    for t in telefonos loop
        num_llamadas := 0;
        mayor100 := 0;
        porcentaje :=0;
        
        for l in llamadas_por_telefono(t.numero) loop
            num_llamadas := num_llamadas + 1;
            llamadas_totales := llamadas_totales + 1;
            
            if l.duracion > 100 then
                mayor100 := mayor100 + 1;
            end if;
        
        end loop;
        
        if num_llamadas > 0 then
             porcentaje := (mayor100 * 100) / num_llamadas;
        end if;
        
         dbms_output.put_line(t.numero || ' ' || num_llamadas || ' ' || mayor100 || ' ' || porcentaje || '%');

    end loop;
    
    dbms_output.put_line('-----------------------------------------');
    dbms_output.put_line('Numero Llamadas Realizadas: ' || llamadas_totales);
            
exception 
    when excepcion_no_llamadas then
        dbms_output.put_line('No hay llamadas en esa fecha');
    when others then
        dbms_output.put_line('Ha ocurrido un error');
    

end llamadas_cia;
/

execute llamadas_cia('Kietostar', '16/10/06');*/

/*Crear un procedimiento que tenga como parámetros de entrada el nombre de una
compañía y una fecha. Dicho procedimiento debe realizar las siguientes
operaciones:

1. Comprobar que existen en la BD llamadas realizadas en la fecha que se pasa
como parámetro. En caso contrario lanzar una excepción y mostrar el
mensaje “No hay llamadas en la fecha <fecha> en la BD”.

2. Para cada teléfono de la compañía que se pasa por parámetro, el
procedimiento debe mostrar la siguiente información: número de teléfono,
número total de llamadas realizadas en la fecha indicada, número de
llamadas de duración mayor de 100 segundos realizadas en la fecha,
porcentaje que suponen estas últimas respecto al total de las realizadas.

3. Un resumen del número de llamadas realizadas por todos los teléfonos de la
compañía indicada en la fecha pasada por parámetro.*/

create or replace procedure llamadas_cia(cia_nombre compañia.nombre % type, fecha date) is
    
    no_llamadas  integer;
    excepcion_no_llamadas exception;
    
    mayor100 integer;
    porcentaje number (4,2);
    llamadas_totales integer;
    llamadas_por_numero integer;
    
    
    cursor telefonos is
        select tel.numero
        from mf.telefono tel inner join mf.compañia cia on cia.cif = tel.compañia
        where cia.nombre = cia_nombre;
    
    cursor llamadas (numero llamada.tf_origen % type) is
        select llam.duracion
        from mf.llamada llam
        where llam.tf_origen = numero and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha, 'dd/mm/yy');
    
begin
    
    select count (*)
    into no_llamadas
    from mf.llamada llam inner join mf.telefono tel on tel.numero = llam.tf_origen
        inner join mf.compañia cia on cia.cif = tel.compañia
    where cia.nombre = cia_nombre and to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha, 'dd/mm/yy');
    
    if no_llamadas = 0 then
        raise excepcion_no_llamadas;
    end if;
    
    llamadas_totales := 0;
    
    for t in telefonos loop
        llamadas_por_numero := 0;
        mayor100 := 0;
        porcentaje := 0;
        
        for l in llamadas(t.numero) loop
         llamadas_por_numero :=llamadas_por_numero + 1;
         llamadas_totales := llamadas_totales + 1;
         
         if l.duracion > 100 then
            mayor100 := mayor100 + 1;
        end if;
        end loop;
        
        if num_llamadas_por_telefono > 0 then
            porcentaje := (mayor100 / num_llamadas_por_telefono) * 100;
        else
            porcentaje := 0;
        end if;

        dbms_output.put_line(
            telefonos.numero || '   ' ||
            num_llamadas_por_telefono || '   ' ||
            mayor100 || '   ' ||
            porcentaje || '%'
        );

    end loop;
    
    dbms_output.put_line('-----------------------------------------');
    dbms_output.put_line('Numero Llamadas Realizadas: ' || total_llamadas);

exception 

   when excepcion_no_llamadas then
        dbms_output.put_line('No hay llamadas en esa fecha');
   when others then
        dbms_output.put_line('Ha ocurrido un error');
        
end;
/

execute llamadas_cia('Aotra', to_date('01/10/06','dd/mm/yy'));
/
