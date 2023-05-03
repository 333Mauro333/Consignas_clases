#include <iostream>
#include <string>

using namespace std;


struct FECHA
{
	int dia;
	int mes;
	int anio;
};

struct HORA
{
	int horas;
	int minutos;
};

struct JUGADOR
{
	string nombre;
	int vida;
	int escudo;
	int danio;
};

struct PACIENTE
{
	string nombre;
	string apellido;
	FECHA fechaTurno;
	HORA horaTurno;
	string motivo;
};

void mostrarEnMps(float velocidadEnKmh);

void mostrarDatosDelJugador(JUGADOR jugador);

void mostrarAguanteDelJugador(int vida, int danioRecibido);

void mostrarFecha(FECHA fecha);
void mostrarHora(HORA hora);
void mostrarDatosDelPaciente(PACIENTE paciente);

int main()
{
	float kmH = 0.0f;

	JUGADOR jugador = {};

	int jugadorVida = 0;
	int enemigoDanio = 0;

	PACIENTE paciente = {};



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese una velocidad (en km/h): ";
	cin >> kmH;
	cout << endl;

	mostrarEnMps(kmH);

	cout << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese el nombre del jugador: ";
	cin >> jugador.nombre;

	do
	{
		cout << "Ingrese la vida (entre 50 y 100): ";
		cin >> jugador.vida;

	} while (jugador.vida < 50 || jugador.vida > 100);

	do
	{
		cout << "Ingrese el escudo (entre 0 y 100): ";
		cin >> jugador.escudo;

	} while (jugador.escudo < 0 || jugador.escudo > 100);

	do
	{
		cout << "Ingrese el danio (entre 5 y 30): ";
		cin >> jugador.danio;

	} while (jugador.danio < 5 || jugador.danio > 30);
	cout << endl;

	mostrarDatosDelJugador(jugador);

	cout << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese la vida del jugador: ";
	cin >> jugadorVida;

	cout << "Ingrese los puntos de danio del enemigo: ";
	cin >> enemigoDanio;

	mostrarAguanteDelJugador(jugadorVida, enemigoDanio);

	cout << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese el nombre del paciente: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, paciente.nombre);

	cout << "Ingrese el apellido: ";
	getline(cin, paciente.apellido);
	cout << endl;

	// Se omite el proceso de validez de fecha, que fue aplicado en ejercicios anteriores.
	cout << "Fecha del turno:\n";
	cout << "Ingrese el dia: ";
	cin >> paciente.fechaTurno.dia;

	cout << "Ingrese el mes: ";
	cin >> paciente.fechaTurno.mes;

	cout << "Ingrese el anio: ";
	cin >> paciente.fechaTurno.anio;
	cout << endl;

	cout << "Hora del turno:\n";
	do
	{
		cout << "Ingrese las horas: ";
		cin >> paciente.horaTurno.horas;

	} while (paciente.horaTurno.horas < 0 || paciente.horaTurno.horas > 23);

	do
	{
		cout << "Ingrese los minutos: ";
		cin >> paciente.horaTurno.minutos;

	} while (paciente.horaTurno.minutos < 0 || paciente.horaTurno.minutos > 59);

	cout << "Describa el motivo de la visita: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, paciente.motivo);
	cout << endl;

	cout << "       --- DATOS DEL PACIENTE ---\n\n";

	mostrarDatosDelPaciente(paciente);

	cout << endl << endl << endl;



	return 0;
}

void mostrarEnMps(float velocidadEnKmh)
{
	cout << "La velocidad es de " << velocidadEnKmh / 3.6f << " m/s.\n\n";
}

void mostrarDatosDelJugador(JUGADOR jugador)
{
	cout << "Estadisticas de " << jugador.nombre << ":\n\n";

	cout << "Vida: " << jugador.vida << ".\n";
	cout << "Escudo: " << jugador.escudo << ".\n";
	cout << "Danio: " << jugador.danio << ".\n\n";
}

void mostrarAguanteDelJugador(int vida, int danioRecibido)
{
	int cantidadGolpes = -1;


	do
	{
		vida -= danioRecibido;
		cantidadGolpes++;

	} while (vida > 0);

	cout << "El jugador ";

	if (cantidadGolpes == 0)
	{
		cout << "no puede aguantar ningun golpe";
	}
	else
	{
		cout << "puede aguantar " << cantidadGolpes << " golpe";

		if (cantidadGolpes > 1)
		{
			cout << "s";
		}
	}

	cout << ".\n\n";
}

void mostrarFecha(FECHA fecha)
{
	if (fecha.dia < 10)
	{
		cout << "0";
	}

	cout << fecha.dia << " de ";

	switch (fecha.mes)
	{
	case 1:
		cout << "enero";
		break;

	case 2:
		cout << "febrero";
		break;

	case 3:
		cout << "marzo";
		break;

	case 4:
		cout << "abril";
		break;

	case 5:
		cout << "mayo";
		break;

	case 6:
		cout << "junio";
		break;

	case 7:
		cout << "julio";
		break;

	case 8:
		cout << "agosto";
		break;

	case 9:
		cout << "septiembre";
		break;

	case 10:
		cout << "octubre";
		break;

	case 11:
		cout << "noviembre";
		break;

	case 12:
		cout << "diciembre";
		break;
	}

	cout << " de " << fecha.anio << ".\n";
}
void mostrarHora(HORA hora)
{
	if (hora.horas < 10)
	{
		cout << "0";
	}

	cout << hora.horas << ":";

	if (hora.minutos < 10)
	{
		cout << "0";
	}

	cout << hora.minutos << " hs.\n";
}
void mostrarDatosDelPaciente(PACIENTE paciente)
{
	cout << "Nombre: " << paciente.nombre << ".\n";
	cout << "Apellido: " << paciente.apellido << ".\n";
	cout << "Fecha del turno: ";
	mostrarFecha(paciente.fechaTurno);
	cout << "Hora del turno: ";
	mostrarHora(paciente.horaTurno);
	cout << "Motivo: " << paciente.motivo << ".\n\n";
}
