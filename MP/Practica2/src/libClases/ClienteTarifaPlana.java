package libClases;

public class ClienteTarifaPlana extends Cliente {

    private static float precioTP = 20.0f;
    private static float precioExcesoMinutos = 0.15f;
    private static float limiteMinutos = 300.0f;
    private float minutosHablados;
    private String nacionalidad;

    public ClienteTarifaPlana(String NIF, String nom, Fecha fNac, Fecha fAlta, float mh, String nac) { //constructor
        super(NIF, nom, fNac, fAlta);

        nacionalidad = nac;
        minutosHablados = mh;
    }

    public ClienteTarifaPlana(String NIF, String nom, Fecha fNac, float mh, String nac) { //constructor corto
        super(NIF, nom, fNac, Cliente.getFechaPorDefecto());
        minutosHablados = mh;
        nacionalidad = nac;
    }

    public ClienteTarifaPlana(ClienteTarifaPlana tp) { //constructor de copia
        super(tp.getNif(), tp.getNombre(), tp.getFechaNac(), tp.getFechaAlta());
        minutosHablados = tp.minutosHablados;
        nacionalidad = tp.nacionalidad;
    }

    public void setNacionalidad(String nac) {
        nacionalidad = nac;
    }

    public void setMinutos(float min) {
        minutosHablados = min;
    }

    public static void setTarifa(float min, float precio) {
        limiteMinutos = min;
        precioTP = precio;
    }

    public static float getTarifa() {

        return precioTP;

    }

    public static float getLimite() {
        return limiteMinutos;
    }
    
    public float factura(){
        if (minutosHablados <= limiteMinutos)
            return precioTP;
        else
            return precioTP + (minutosHablados - limiteMinutos) * precioExcesoMinutos;
    }

    public String toString() {
        float factura = this.factura();
        return super.toString() + " " + nacionalidad + " [" + limiteMinutos + " por " + precioTP + "] " + minutosHablados + " --> " + factura;
    }

    public void ver() {
        System.out.println(this.toString());
    }

    public Object clone() {
        //return new Fecha(this);
        Object obj = null;
        obj = new ClienteTarifaPlana(this);
        return obj;
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
        Cliente tp = (Cliente) obj;
        return (this.getNif().equals(tp.getNif()));
    }

}
