create or replace procedure llamadas_cia(nom_cia compañia.nombre%type,fecha_llam date) is

    num_llamadas_por_telefono integer;
    total_llamadas integer := 0;
    no_llamadas exception;

    mayor100 integer;
    porcentaje number(10,2);
    num_llamadas integer;

    cursor selecionar_numeros is
        select tel.numero
        from mf.telefono tel
        inner join mf.compañia cia on cia.cif = tel.compañia
        where cia.nombre = nom_cia;

    cursor ver_llamadas(telefono mf.llamada.tf_origen%type) is
        select duracion
        from mf.llamada
        where tf_origen = telefono
        and to_char(fecha_hora,'dd/mm/yy') = to_char(fecha_llam,'dd/mm/yy');

    

begin
    -- 1. Comprobar si existen llamadas
    select count(*)
    into num_llamadas
    from mf.llamada llam
    inner join mf.telefono tel on llam.tf_origen=tel.numero
    inner join mf.compañia cia on cia.cif=tel.compañia
    where to_char(llam.fecha_hora,'dd/mm/yy') = to_char(fecha_llam,'dd/mm/yy')
    and cia.nombre = nom_cia;

    if num_llamadas = 0 then
        raise no_llamadas;
    end if;

    -- 2. Procesar teléfonos
    for telefonos in selecionar_numeros loop
        
        num_llamadas_por_telefono := 0;
        mayor100 := 0;

        for llamadas in ver_llamadas(telefonos.numero) loop
            
            num_llamadas_por_telefono := num_llamadas_por_telefono + 1;
            total_llamadas := total_llamadas + 1;

            if llamadas.duracion > 100 then
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

    -- 3. Resumen final
    dbms_output.put_line('-----------------------------------------');
    dbms_output.put_line('Numero Llamadas Realizadas: ' || total_llamadas);

exception
    when no_llamadas then
        dbms_output.put_line('No hay llamadas con esa fecha');
    when others then
        dbms_output.put_line('Ha ocurrido un error: ' || SQLERRM);
end llamadas_cia;
/

--Ejecucion
EXEC llamadas_cia('Aotra', TO_DATE('01/10/06','dd/mm/yy'));
/      
            
            

    
    
    
    