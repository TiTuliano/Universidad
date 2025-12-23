
---PR�CTICA 1 SESI�N 1---

CREATE TABLE compa�ia
(
    cif varchar2(9),
    nombre varchar2(20),
    web varchar2(30),       
    CONSTRAINT ciaClave PRIMARY KEY (cif)

);

CREATE TABLE tarifa
(
   tarifa varchar2(10),
   compañia varchar2(9),
   descripcion varchar2(50),
   coste number (3,2),
   CONSTRAINT tarifaClave PRIMARY KEY (tarifa,compa�ia),
   CONSTRAINT tarifaAjena FOREIGN KEY (compa�ia)
                REFERENCES compa�ia(cif) ON DELETE CASCADE
);

CREATE TABLE cliente
(
    dni char(9),
    nombre varchar2(50),
    f_nac date,
    direccion varchar2(100),
    cp char(6),
    ciudad varchar2(50),
    provincia varchar2(50),
    CONSTRAINT clienteClave PRIMARY KEY (dni)
);

CREATE TABLE telefono
(
    numero char(9),
    f_contrato date,
    tipo char(1),
    puntos number(6,0),
    compa�ia varchar(9),
    tarifa varchar2(10),
    cliente char(9),
    CONSTRAINT claveTelefono PRIMARY KEY(numero),
    CONSTRAINT tarifa_compa�iaAjena FOREIGN KEY(tarifa,compa�ia) 
                REFERENCES tarifa(tarifa,compa�ia) ON DELETE CASCADE,
    CONSTRAINT compa�iaAjena FOREIGN KEY(compa�ia) 
                REFERENCES compa�ia(cif) ON DELETE CASCADE,
    CONSTRAINT clienteAjena FOREIGN KEY(cliente) 
                REFERENCES cliente(dni) ON DELETE CASCADE,
   CONSTRAINT tipo_valido CHECK(tipo='T' OR tipo='C')
                
);

CREATE TABLE llamada
(
    tf_origen char(9),
    tf_destino char(9),
    fecha_hora timestamp,
    duracion number(5,0),
    CONSTRAINT claveLlamada PRIMARY KEY(tf_origen,fecha_hora),
    CONSTRAINT tf_origenAjena FOREIGN KEY(tf_origen)
                REFERENCES telefono(numero) ON DELETE CASCADE,
    CONSTRAINT tf_destinoAjena FOREIGN KEY(tf_destino)
                REFERENCES telefono(numero) ON DELETE CASCADE,
    UNIQUE (tf_destino, fecha_hora)
);

/*ALTER TABLE compañia
ADD CONSTRAINT nom_comp_unico UNIQUE(nombre);*/

ALTER TABLE llamada
ADD CONSTRAINT check_no_autollamada CHECK (tf_origen <> tf_destino);

ALTER TABLE tarifa
ADD CONSTRAINT precio_tarifa2 CHECK(coste<=1.5 AND coste>=0.05);

ALTER TABLE compa�ia
MODIFY (nombre NOT NULL);

ALTER TABLE cliente
MODIFY (nombre NOT NULL);

ALTER TABLE tarifa
MODIFY (coste NOT NULL);

ALTER TABLE telefono
MODIFY (compania NOT NULL, tarifa NOT NULL);

ALTER TABLE llamada
MODIFY (duracion NOT NULL);




    
    
    
                        
    