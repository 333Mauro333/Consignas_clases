#pragma once

#include "tipo_de_calculadora.h"


class Calculadora
{
public:
	static float sumar(float numero1, float numero2);
	static float restar(float numero1, float numero2);
	static float multiplicar(float numero1, float numero2);
	static float dividir(float numero1, float numero2);

	static float obtenerPotencia(float numeroAElevar, int aCuantoElevar);
	static float obtenerRaiz(float numeroAEstablecerRaiz, int tipoDeRaiz);

	static void cambiarTipoDeCalculadora();
	static void restablecerEstadisticas();

	static int getCuentasHechasComun();
	static int getCuentasHechasCientifica();
	static TIPO_DE_CALCULADORA getTipoDeCalculadora();

private:
	static int cuentasHechasComun;
	static int cuentasHechasCientifica;

	static TIPO_DE_CALCULADORA tipoDeCalculadora;

};
