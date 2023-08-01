#pragma once


class Consola
{
public:
	Consola();
	~Consola();

	int getVolumen();
	int getBrillo();

	void setVolumen(int volumen);
	void setBrillo(int brillo);

private:
	int volumen;
	int brillo;
};
