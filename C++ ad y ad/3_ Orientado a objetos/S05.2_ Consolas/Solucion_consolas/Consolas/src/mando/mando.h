#pragma once

#include "consola/consola.h"


class Mando
{
public:
	Mando();
	~Mando();

	void cambiarVolumenConsola(int nuevoVolumen);
	void cambiarBrilloConsola(int nuevoBrillo);

	void conectarALaConsola(Consola* consola);
	void desconectar();

	bool estaConectado();

	Consola* getConsola();

private:
	Consola* consola;
};
