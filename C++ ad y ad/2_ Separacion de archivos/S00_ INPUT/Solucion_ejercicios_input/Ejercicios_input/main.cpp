#include <iostream>

#include "funciones.h"

using namespace std;


int main()
{
	int numero = 0;

	int dia = 0;
	int mes = 0;
	int anio = 0;

	int vida = 0;
	int escudo = 0;

	string nombre = "";
	int edad = 0;
	float altura = 0.0f;



	mostrarTituloEjercicio(1);
	
	mostrarMensajePidiendoNumero();
	numero = pedirNumero();
	mostrarMensajeNumeroIngresado(numero);


	mostrarTituloEjercicio(2);

	dia = pedirNumeroConMensaje("Ingrese el dia: ");
	mes = pedirNumeroConMensaje("Ingrese el mes: ");
	anio = pedirNumeroConMensaje("Ingrese el anio: ");
	mostrarFecha(dia, mes, anio, "Fecha ingresada: ");


	mostrarTituloEjercicio(3);

	vida = pedirVida();
	escudo = pedirEscudo();
	mostrarDatosDelJugador(vida, escudo);


	mostrarTituloEjercicio(4);

	nombre = pedirNombre();
	edad = pedirEdad();
	altura = pedirAltura();
	mostrarDatosPedidos(nombre, edad, altura);



	return 0;
}
