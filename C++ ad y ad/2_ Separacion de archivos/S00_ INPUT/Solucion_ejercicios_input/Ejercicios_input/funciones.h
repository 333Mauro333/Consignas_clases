#pragma once

#include <string>

using std::string;


// General
void mostrarTituloEjercicio(int numeroEjercicio);

// Ejercicio 1.
void mostrarMensajePidiendoNumero();
int pedirNumero();
void mostrarMensajeNumeroIngresado(int numero);

// Ejercicio 2.
int pedirNumeroConMensaje(string mensaje);
void mostrarFecha(int dia, int mes, int anio, string mensajeFecha);

// Ejercicio 3.
int pedirVida();
int pedirEscudo();
void mostrarDatosDelJugador(int vida, int escudo);

// Ejercicio 4.
string pedirNombre();
int pedirEdad();
float pedirAltura();
void mostrarDatosPedidos(string nombre, int edad, float altura);
