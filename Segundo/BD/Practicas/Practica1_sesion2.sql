
---PRÁCTICA 1 SESI�N 2---

INSERT INTO compañia
    VALUES ('A00000001','Kietostar','http://www.kietostar.com'); 

INSERT INTO compañia
    VALUES ('B00000002','Aotra','http://www.aotra.com'); 
    
SELECT *FROM compañia; --Para ver la tabla compañia

INSERT INTO tarifa
    VALUES ('joven','A00000001','menores de 25 años',0.25);
    
INSERT INTO tarifa
    VALUES ('dúo','A00000001','la pareja también está en la compañía',0.20);

INSERT INTO tarifa
    VALUES ('familiar','A00000001','4 miembros de la familia en la compañía',0.15);

INSERT INTO tarifa
    VALUES ('familiar','A00000001','4 miembros de la familia en la compañia',0.15);
    
INSERT INTO tarifa 
    VALUES ('autónomos','B00000002','trabajador autónomo',0.12);

INSERT INTO tarifa 
    VALUES ('dúo','B00000002','la pareja también está en la compañia',0.15);
    
DESCRIBE tarifa --Sirve para ver la estructura de la tablar para asi saber que atributos tiene y su sintaxis
DESCRIBE compañia

DELETE FROM compañia WHERE cif='B00000002';




        