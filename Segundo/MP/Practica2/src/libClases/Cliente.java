package libClases;

public class Cliente implements Cloneable, Proceso {

    private final String nif; //dni del cliente (letra incluida) (NO puede cambiar)
    private final int codCliente; //codigo único (y fijo) generado por la aplicación
    private String nombre; //nombre completo del cliente (SI se puede modificar)
    private final Fecha fechaNac; //fecha nacimiento del cliente (NO se puede cambiar)
    private Fecha fechaAlta; //fecha de alta del cliente (SI se puede modificar)
    private static Fecha FechaDefecto = new Fecha(1, 1, 2018);
    private static int contador = 1;
    

    public Cliente(String NIF, String nom, Fecha fNac, Fecha fAlta) { //constructor

        nif = NIF;
        nombre = nom;
        fechaNac = (Fecha) fNac.clone();
        fechaAlta = (Fecha) fAlta.clone();
        codCliente = contador++;
    }

    public Cliente(String NIF, String nom, Fecha fNac) { //constructor corto

        nif = NIF;
        nombre = nom;
        fechaNac = (Fecha) fNac.clone();
        fechaAlta = (Fecha) FechaDefecto.clone();
        codCliente = contador++;
    }

    public Cliente(Cliente c) { //constructor de copia
        nif = c.nif;
        nombre = c.nombre;
        fechaNac = (Fecha) c.fechaNac.clone();
        fechaAlta = (Fecha) c.fechaAlta.clone();
        codCliente = contador++;
    }
    
    public float factura(){
        return 0f;
    }

    public String toString() {//devuelve una cadena con la información del cliente
        return nif + " " + fechaNac + ": " + nombre + "(" + codCliente + " - " + fechaAlta + ")";
    }

    public void ver() {
        System.out.println(this.toString());
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nom) {
        nombre = nom;
    }

    public Fecha getFechaAlta() {
        return (Fecha) fechaAlta.clone();
    }

    public void setFechaAlta(Fecha f) {
        fechaAlta = (Fecha) f.clone();
    }

    public static Fecha getFechaPorDefecto() {
        return (Fecha) FechaDefecto.clone();

    }

    public static void setFechaPorDefecto(Fecha defecto) {
        FechaDefecto = (Fecha) defecto.clone();
    }

    public final Fecha getFechaNac() {
        return (Fecha) fechaNac.clone();
    }

    public final String getNif() {
        return nif;
    }

    public Object clone() {
        //return new Fecha(this);
        Object obj = null;
        try {
            obj = super.clone(); //se llama al clone() de la clase base (Object)
//que hace copia binaria de los atributos
        } catch (CloneNotSupportedException ex) {
            System.out.println(" no se puede duplicar");
        }
        obj = new Cliente(this);
        return obj;
    }
    
    public int getCodCliente(){
        return codCliente;
    }
    
    public boolean equals(Object obj) { //true sin son iguales
        if (this == obj) {
            return true; //si apuntan al mismo sitio son iguales
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass())//if (!(obj instanceof Cliente))
        {
            return false; // si los 2 no son de la misma clase no son iguales
        }
        Cliente c = (Cliente) obj;
        return (nif.equals(c.nif));
    }            
}
