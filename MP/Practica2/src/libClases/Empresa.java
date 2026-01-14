package libClases;

import java.util.Scanner;

public class Empresa implements Cloneable {

    private Cliente[] clientes;   // array dinámico de referencias a Cliente
    private int n;                // número de clientes almacenados
    Scanner sc = new Scanner(System.in);

    public Empresa() {
        clientes = new Cliente[0];
        n = 0;
    }

    public Empresa(Empresa e) {
        this.n = e.n;

        // crear array nuevo
        this.clientes = new Cliente[n];

        // clonar cliente a cliente
        for (int i = 0; i < n; i++) {
            this.clientes[i] = (Cliente) e.clientes[i].clone();
        }
    }

    public int getN() {
        return n;
    }

    public void alta(Cliente c) { //este metodo  ya da un cliente (no tengo que pedir datos)
        for (int i = 0; i < this.getN(); i++) //comprobamos que el cliente no esta en el array
        {
            if (c.getNif().equals(clientes[i].getNif())) {
                return;
            }

        }

        //aumentamos el tamaños del array
        Cliente aux[] = new Cliente[n + 1];

        //metemos los clientes en este nuevo array de n+1
        for (int i = 0; i < this.getN(); i++) {
            aux[i] = clientes[i];
        }

        //ahora insertamos el cliente que se pasa por parametro
        aux[n] = c;

        //sustituimos el array viejo por el nuevo
        clientes = aux;
        n++;

    }

    public void alta() {

        System.out.println("Introduce un NIF: ");
        String dni = sc.nextLine();
        for (int i = 0; i < n; i++) //comprobamos que el cliente no esta en el array
        {
            if (dni.equals(clientes[i].getNif())) {
                System.out.println("Ya existe un cliente con el mismo NIF");
                System.out.println(clientes[i].toString());
                return;
            }

        }

        System.out.println("Introduce un Nombre: ");
        String nom = sc.nextLine();

        System.out.println("Introduce tu Fecha de Nacimiento (dd/mm/aaaa): ");
        String fNac = sc.nextLine();

        //usamos split para partir la fecha cada vez que vea "/"
        String[] partesNac = fNac.split("/");

        //usamos el constructor de fecha
        Fecha FechaNac = new Fecha(
                Integer.parseInt(partesNac[0]),
                Integer.parseInt(partesNac[1]),
                Integer.parseInt(partesNac[2])
        );

        System.out.println("Introduce tu Fecha de Alta (dd/mm/aaaa): ");
        String fAlta = sc.nextLine();

        //usamos split para partir la fecha cada vez que vea "/"
        String[] partesAlta = fAlta.split("/");

        //usamos el constructor de fecha
        Fecha FechaAlta = new Fecha(
                Integer.parseInt(partesAlta[0]),
                Integer.parseInt(partesAlta[1]),
                Integer.parseInt(partesAlta[2])
        );

        System.out.println("Introduce los Minutos: ");
        float mins = sc.nextFloat();
        //importante limpiar el proximo salto de linea
        sc.nextLine();

        System.out.println("Indique tipo de Cliente (1.Movil, 2.Tarifa Plana): ");
        int tipo = sc.nextInt();
        sc.nextLine();

        //creamos un cliente
        Cliente nuevo = null;

        if (tipo == 1) { //ClienteMovil
            System.out.println("Indique Precio por Minuto: ");
            float precio = sc.nextFloat();
            sc.nextLine();

            System.out.println("Introduce la fecha fin de la permanencia (dd/mm/aaaa): ");
            String fPermanencia = sc.nextLine();

            //usamos split para partir la fecha cada vez que vea "/"
            String[] partesPer = fPermanencia.split("/");

            //usamos el constructor de fecha
            Fecha FechaPer = new Fecha(
                    Integer.parseInt(partesPer[0]),
                    Integer.parseInt(partesPer[1]),
                    Integer.parseInt(partesPer[2])
            );

            nuevo = new ClienteMovil(dni, nom, FechaNac, FechaAlta, FechaPer, mins, precio);
        } else if (tipo == 2) { //Cliente TP
            System.out.println("Introduce los Minutos Hablados: ");
            float minutosHablados = sc.nextFloat();
            sc.nextLine();

            System.out.println("Introduce tu Nacionalidad: ");
            String nac = sc.nextLine();

            nuevo = new ClienteTarifaPlana(dni, nom, FechaNac, FechaAlta, minutosHablados, nac);
        }

        //añadimos el cliente al array
        this.alta(nuevo);
    }

    public void baja(String dni) {
        boolean encontrado = false;
        int i = 0;
        while (!encontrado && i < n) {
            if (dni.equals(clientes[i].getNif())) {
                encontrado = true;
            } else {
                i++;
            }
        }

        if (!encontrado) {
            return;
        }

        //borramos el cliente del array
        Cliente[] aux = new Cliente[n - 1];

        int k = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                aux[k] = clientes[j];
                k++;
            }

        }

        clientes = aux;
        n--;
    }

    public void baja() {
        System.out.println("Introduce el NIF a borrar:");
        String dni = sc.nextLine();

        boolean encontrado = false;
        int i = 0;

        // Buscar cliente
        while (!encontrado && i < n) {
            if (dni.equals(clientes[i].getNif())) {
                encontrado = true;
            } else {
                i++;
            }
        }

        if (!encontrado) {
            System.out.println("No existe ningún cliente con ese nif");
            return;
        }

        // Mostrar cliente 
        System.out.println(clientes[i].toString());

        // Pedir confirmación
        System.out.println("¿Seguro que desea eliminarlo (s/n)?");
        char letra = sc.nextLine().charAt(0);

        if (letra == 's' || letra == 'S') {

            // Guardar nombre antes de borrar
            String nombre = clientes[i].getNombre();

            // Borrar llamando al otro método
            this.baja(dni);

            System.out.println("El cliente " + nombre + " con nif " + dni + " ha sido eliminado");
        } else {
            System.out.println("El cliente con nif " + dni + " no se elimina");
        }
    }

    public float factura() {
        float total = 0f;

        for (int i = 0; i < n; i++) {
            total += clientes[i].factura();
        }
        return total;
    }

    public void descuento(int dto) {
        float total = 0f;

        for (int i = 0; i < n; i++) {
            //vemos si el cliente es de tipo movil
            if (clientes[i] instanceof ClienteMovil) {
                ClienteMovil cm = (ClienteMovil) clientes[i];

                float precioActual = cm.getPrecio();
                float precioNuevo = precioActual - (precioActual * dto / 100f);

                cm.setPrecio(precioNuevo);
            }
        }
    }

    public int nClienteMovil() {
        int contador = 0;

        for (int i = 0; i < n; i++) {
            //vemos si el cliente es de tipo movil
            if (clientes[i] instanceof ClienteMovil) {
                contador++;
            }
        }

        return contador;
    }

    public Object clone() {
        Object obj = null;
        obj = new Empresa(this);
        return obj;
    }

    public String toString() {
        String s = "";

        for (int i = 0; i < n; i++) {
            s = s + clientes[i].toString() + "\n";
        }

        return s;
    }
}
