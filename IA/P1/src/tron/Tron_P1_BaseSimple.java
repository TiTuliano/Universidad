package tron;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Tron_P1_BaseSimple {

	public static void main(String[] args) throws InterruptedException {

		// Podéis editar este mapa para las pruebas
		String mapaTexto = "########\n" + "#A     #\n" + "#      #\n" + "#    S #\n" + "########";

		// 1. Inicializar Entorno
		Entorno juego = new Entorno(mapaTexto);

		// 2. Elegir Agente (Descomenta el que quieras probar)
		AgenteReactivo agente = new AgenteReactivo();
		// AgenteDeliberativo agente = new AgenteDeliberativo(juego.filas, juego.cols);

		System.out.println("--- Inicio de la Simulación ---");

		int ciclos = 0;
		boolean juegoActivo = true;

		// BUCLE DE SIMULACIÓN
		while (juegoActivo && ciclos < 200) {

			juego.dibujar();

			// El agente decide
			String accion = agente.pensar(juego);

			// El entorno aplica el movimiento
			boolean movimientoExitoso = juego.moverAgente(accion);

			System.out.println("Ciclo " + ciclos + " | Acción: " + accion);

			if (!movimientoExitoso) {
				System.out.println(">>> ¡CRASH! El agente se ha chocado.");
				juegoActivo = false;

			} else if (juego.hemosGanado()) {
				System.out.println(">>> ¡VICTORIA! Salida encontrada.");
				juego.dibujar();
				juegoActivo = false;
			}

			Thread.sleep(600); // Retardo para animación
			ciclos++;
		}
	}
}

/*
 * ===================================================== CLASE ENTORNO
 * (INFRAESTRUCTURA) Gestiona la matriz del mapa y las reglas físicas. NO
 * MODIFICAR. =====================================================
 */

class Entorno {

	char[][] grid;
	int filas, cols;

	int agenteF, agenteC; // Coordenadas del agente
	int metaF, metaC; // Coordenadas de la meta

	public Entorno(String mapa) {

		String[] lineas = mapa.trim().split("\n");

		filas = lineas.length;
		cols = lineas[0].length();

		grid = new char[filas][cols];

		for (int i = 0; i < filas; i++) {

			for (int j = 0; j < cols; j++) {

				char celda = lineas[i].charAt(j);
				grid[i][j] = celda;

				if (celda == 'A') {
					agenteF = i;
					agenteC = j;
				}

				if (celda == 'S') {
					metaF = i;
					metaC = j;
				}
			}
		}
	}

	// Comprueba si una casilla es segura para moverse
	public boolean esTransitable(int f, int c) {

		if (f < 0 || f >= filas)
			return false;

		if (c < 0 || c >= cols)
			return false;

		char celda = grid[f][c];

		// Es transitable si no es Muro (#) ni Rastro (.)
		return celda != '#' && celda != '.';
	}

	public boolean esMeta(int f, int c) {
		return f == metaF && c == metaC;
	}

	public boolean hemosGanado() {
		return esMeta(agenteF, agenteC);
	}

	// Aplica el movimiento y deja el rastro
	public boolean moverAgente(String accion) {

		int sigF = agenteF;
		int sigC = agenteC;

		if (accion.equals("N"))
			sigF--;

		if (accion.equals("S"))
			sigF++;

		if (accion.equals("E"))
			sigC++;

		if (accion.equals("O"))
			sigC--;

		if (!esTransitable(sigF, sigC))
			return false;

		// Dejar rastro en la posición anterior
		grid[agenteF][agenteC] = '.';

		// Actualizar posición
		agenteF = sigF;
		agenteC = sigC;

		if (!esMeta(agenteF, agenteC)) {
			grid[agenteF][agenteC] = 'A';
		}

		return true;
	}

	public void dibujar() {

		System.out.println("----------");

		for (int i = 0; i < filas; i++) {
			System.out.println(new String(grid[i]));
		}
	}
}

/*
 * ===================================================== ZONA DEL ALUMNO:
 * AGENTES =====================================================
 */

class AgenteReactivo {

	public String pensar(Entorno mapa) {

		int f = mapa.agenteF;
		int c = mapa.agenteC;

		List<String> opcionesValidas = new ArrayList<>();

		if (mapa.esTransitable(f - 1, c)) {
			opcionesValidas.add("N");
		}
		if (mapa.esTransitable(f + 1, c)) {
			opcionesValidas.add("S");
		}
		if (mapa.esTransitable(f, c - 1)) {
			opcionesValidas.add("O");
		}
		if (mapa.esTransitable(f, c + 1)) {
			opcionesValidas.add("E");
		}

		if (opcionesValidas.isEmpty()) {
			return "N";
		} else {
			Random rand = new Random();
			int indiceAleatorio = rand.nextInt(opcionesValidas.size());
			return opcionesValidas.get(indiceAleatorio);
		}
	}
}

class AgenteDeliberativo {

	boolean[][] memoria;

	public AgenteDeliberativo(int filas, int cols) {
		// Inicializamos la memoria (Tarea 2.B)
		memoria = new boolean[filas][cols];
	}

	public String pensar(Entorno mapa) {
		// Por ahora solo para que compile
		return "N";
	}
}

/*
 * class AgenteDeliberativo {
 * 
 * public AgenteDeliberativo(int filas, int cols) { memoria = new
 * xxxxx[filas][cols]; }
 * 
 * public String pensar(Entorno mapa) {
 * 
 * // TAREA 2: Implementar lógica deliberativa // 1. Mirar vecinos. // 2. Si
 * esTransitable -> añadir a opcionesSeguras. // 3. Valorar opciones sobre la
 * memoria
 * 
 * // --- INICIO CODIGO ALUMNO --- // ... // --- FIN CODIGO ALUMNO ---
 * 
 * // Prioridad: transitable, movimiento favorable …
 * 
 * return; // "acción más favorable" } }
 */
