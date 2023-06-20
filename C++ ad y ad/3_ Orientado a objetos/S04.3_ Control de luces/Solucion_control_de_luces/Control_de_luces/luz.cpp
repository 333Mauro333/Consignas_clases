#include "luz.h"


int Luz::lucesEncendidas = 0;


Luz::Luz()
{
	estaEncendida = false;
	posicion = {};
}
Luz::~Luz()
{
	cout << "Una luz ha sido eliminada de la memoria." << endl << endl;
}

// FUNCIONES PUBLICAS.
int Luz::getLucesEncendidas()
{
	return lucesEncendidas;
}

void Luz::draw()
{
	const char topLeft = (char)201; // ╔
	const char hztLine = (char)205; // ═
	const char topRght = (char)187; // ╗
	const char topCntr = (char)203; // ╦
	const char vrtLine = (char)186; // ║
	const char botLeft = (char)200; // ╚
	const char botRght = (char)188; // ╝
	const char vrtCtRg = (char)204; // ╠
	const char vrtCtLf = (char)185; // ╣
	const char botCntr = (char)202; // ╩
	const char cenCntr = (char)206; // ╬

	const char block1 = (char)219;  // █
	const char block2 = (char)178;  // ▓
	const char block3 = (char)177;  // ▒
	const char block4 = (char)176;  // ░

	string primeraFilaDeColor = obtenerCaracteres(block1, 4);
	string segundaFilaDeColor = obtenerCaracteres(block2, 6);
	string terceraFilaDeColor = obtenerCaracteres(block3, 8);
	string cuartaFilaDeColor = obtenerCaracteres(block4, 10);


	//cout << "    ╔═╦════════╦══╗";
	//cout << "    ║ ╠════════╣  ║";
	//cout << "    ║ ║        ╚══╝";
	//cout << "    ║ ║        ████";
	//cout << "    ║ ║       ▓▓▓▓▓▓";
	//cout << "    ║ ║      ▒▒▒▒▒▒▒▒";
	//cout << "    ║ ║     ░░░░░░░░░░";
	//cout << "    ║ ║";
	//cout << " ╔══╩═╩══╗";
	//cout << " ╚═══════╝";

	ConsoleExt::goToCoordinates(posicion.x, posicion.y);
	cout << "    " << topLeft << hztLine << topCntr << obtenerCaracteres(hztLine, 8) << topCntr << hztLine << hztLine << topRght;

	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 1);
	cout << "    " << vrtLine << " " << vrtCtRg << obtenerCaracteres(hztLine, 8) << vrtCtLf << "  " << vrtLine;

	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 2);
	cout << "    " << vrtLine << " " << vrtLine << "        " << botLeft << hztLine << hztLine << botRght;

	for (int i = 3; i <= 7; i++)
	{
		ConsoleExt::goToCoordinates(posicion.x, posicion.y + i);
		cout << "    " << vrtLine << " " << vrtLine;
	}

	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 8);
	cout << " " << topLeft << hztLine << hztLine << botCntr << hztLine << botCntr << hztLine << hztLine << topRght;

	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 9);
	cout << " " << botLeft << obtenerCaracteres(hztLine, 7) << botRght;

	if (estaEncendida)
	{
		ConsoleExt::goToCoordinates(posicion.x + 15, posicion.y + 3);
		ConsoleExt::writeWithColor(primeraFilaDeColor, COLOR::C_YELLOW);

		ConsoleExt::goToCoordinates(posicion.x + 14, posicion.y + 4);
		ConsoleExt::writeWithColor(segundaFilaDeColor, COLOR::C_YELLOW);

		ConsoleExt::goToCoordinates(posicion.x + 13, posicion.y + 5);
		ConsoleExt::writeWithColor(terceraFilaDeColor, COLOR::C_YELLOW);

		ConsoleExt::goToCoordinates(posicion.x + 12, posicion.y + 6);
		ConsoleExt::writeWithColor(cuartaFilaDeColor, COLOR::C_YELLOW);
	}

	ConsoleExt::goToCoordinates(1, posicion.y + 10);
}

void Luz::encender()
{
	estaEncendida = true;

	lucesEncendidas++;
}
void Luz::apagar()
{
	estaEncendida = false;

	lucesEncendidas--;
}

bool Luz::getEstaEncendida()
{
	return estaEncendida;
}
void Luz::setPosicion(int x, int y)
{
	posicion = { x, y };
}


// FUNCIONES PRIVADAS.
string Luz::obtenerCaracteres(char character, int cantidad)
{
	string texto = "";

	for (int i = 0; i < cantidad; i++)
	{
		texto += character;
	}

	return texto;
}
