package libClases;

public class ClienteMovil extends Cliente {

    private float precioMinuto;
    private float minutosHablados;
    private Fecha FPermanencia = new Fecha(1, 1, 2019);

    public ClienteMovil(String NIF, String nom, Fecha fNac, Fecha fAlta, Fecha per, float pm, float mh) { //constructor
        super(NIF, nom, fNac, fAlta);
        precioMinuto = pm;
        minutosHablados = mh;
        FPermanencia = (Fecha) per.clone();
    }

    public ClienteMovil(String NIF, String nom, Fecha fNac, float pm, float mh) { //constructor corto
        super(NIF, nom, fNac, Cliente.getFechaPorDefecto());
        precioMinuto = pm;
        minutosHablados = mh;
    }

    public ClienteMovil(ClienteMovil cm) { //constructor de copia
        super(cm.getNif(), cm.getNombre(), cm.getFechaNac(), cm.getFechaAlta());
        precioMinuto = cm.precioMinuto;
        minutosHablados = cm.minutosHablados;
        FPermanencia = (Fecha) cm.FPermanencia.clone();
    }

    public void setFPermanencia(Fecha Fper) {
        FPermanencia = (Fecha) Fper.clone();
    }

    public Fecha getFPermanencia() {
        return (Fecha) FPermanencia.clone();
    }

    public void setPrecio(float precio) {
        precioMinuto = precio;
    }

    public float getPrecio() {
        return precioMinuto;
    }

    public void setMinutos(float minutos) {
        minutosHablados = minutos;
    }

    public float getMinutos() {
        return minutosHablados;
    }

    public float factura() {
        return minutosHablados * precioMinuto;
    }

    public String toString() {
        return super.toString() + " " + this.getFechaAlta() + " " + precioMinuto + " x " + minutosHablados + " --> " + minutosHablados * precioMinuto;
    }

    public void ver() {
        System.out.println(this.toString());
    }

    
    public Object clone() {
        Object obj = null;
        obj = new ClienteMovil(this);
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
        Cliente cm = (Cliente) obj;
        return (this.getNif().equals(cm.getNif()));
    }

}
