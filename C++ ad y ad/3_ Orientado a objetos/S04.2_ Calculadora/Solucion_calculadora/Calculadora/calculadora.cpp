#include "calculadora.h"

#include <cmath>


int Calculadora::cuentasHechasComun = 0;
int Calculadora::cuentasHechasCientifica = 0;

TIPO_DE_CALCULADORA Calculadora::tipoDeCalculadora = TIPO_DE_CALCULADORA::COMUN;


float Calculadora::sumar(float numero1, float numero2)
{
	cuentasHechasComun++;

	return numero1 + numero2;
}
float Calculadora::restar(float numero1, float numero2)
{
	cuentasHechasComun++;

	return numero1 - numero2;
}
float Calculadora::multiplicar(float numero1, float numero2)
{
	cuentasHechasComun++;

	return numero1 * numero2;
}
float Calculadora::dividir(float numero1, float numero2)
{
	cuentasHechasComun++;

	return numero1 / numero2;
}

float Calculadora::obtenerPotencia(float numeroAElevar, int aCuantoElevar)
{
	cuentasHechasCientifica++;

	return pow(numeroAElevar, (float)aCuantoElevar);
}
float Calculadora::obtenerRaiz(float numeroAEstablecerRaiz, int tipoDeRaiz)
{
	cuentasHechasCientifica++;

	return pow(numeroAEstablecerRaiz, 1.0f / (float)tipoDeRaiz);
}

void Calculadora::cambiarTipoDeCalculadora()
{
	if (tipoDeCalculadora == TIPO_DE_CALCULADORA::COMUN)
	{
		tipoDeCalculadora = TIPO_DE_CALCULADORA::CIENTIFICA;
	}
	else
	{
		tipoDeCalculadora = TIPO_DE_CALCULADORA::COMUN;
	}
}
void Calculadora::restablecerEstadisticas()
{
	cuentasHechasComun = 0;
	cuentasHechasCientifica = 0;
}

int Calculadora::getCuentasHechasComun()
{
	return cuentasHechasComun;
}
int Calculadora::getCuentasHechasCientifica()
{
	return cuentasHechasCientifica;
}
TIPO_DE_CALCULADORA Calculadora::getTipoDeCalculadora()
{
	return tipoDeCalculadora;
}
