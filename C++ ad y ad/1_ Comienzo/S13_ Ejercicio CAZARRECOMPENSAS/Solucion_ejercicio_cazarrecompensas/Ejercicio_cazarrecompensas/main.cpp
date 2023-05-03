#include <iostream>

using namespace std;


enum class PANTALLA { BATALLA, DESCANSO, TIENDA };

int main()
{
	PANTALLA pantallaActual = PANTALLA::BATALLA; // Variable para identificar la pantalla actual.

	bool enJuego = true;

	int jugadorVida = 100;
	int jugadorArmadura = 100;
	int jugadorDanio = 25;
	int diffRandom = 3;
	int jugadorOro = 0;
	int oroGanado = 0;

	int enemigoVida = 0;
	int enemigoArmadura = 0;
	int enemigoDanio = 0;

	int danioDefinitivo = 0;

	bool turnoDelJugador = true;

	int opcion = 0; // Variable para obtener la opción elegida por el usuario.

	// Precios de los ítems de la tienda.
	int precioPocion = 40;
	int precioArmadura = 75;
	int precioTrebol = 150;

	bool tieneTrebol = false; // Booleano para comprobar si se compró el trébol de 4 hojas.


	srand(time(NULL));


	// Loop del juego completo.
	while (enJuego)
	{
		// Se verifica cuál es la pantalla actual.
		switch (pantallaActual)
		{
		case PANTALLA::BATALLA:

			#pragma region BATTLE

			// Seteo de valores random para el enemigo.
			enemigoVida = rand() % (75 - 50 + 1) + 50; // Entre 50 y 75.
			enemigoArmadura = rand() % (75 - 50 + 1) + 50; // Entre 50 y 75.
			enemigoDanio = rand() % (20 - 5 + 1) + 5; // Entre 5 y 20.

			system("cls");

			// Loop de batalla.
			while (jugadorVida > 0 && enemigoVida > 0)
			{
				// Se muestran las estadísticas de la batalla.
				cout << "                         ----- BATALLA -----\n\n";
				cout << "Vida del jugador: " << jugadorVida << "                         Vida del enemigo: " << enemigoVida << "\n";
				cout << "Armadura del jugador: " << jugadorArmadura << "                     Armadura del enemigo: " << enemigoArmadura << "\n";
				cout << "Damage del jugador: " << jugadorDanio << "                       Damage del enemigo: " << enemigoDanio << "\n\n\n";

				// Se verifica de quién es el turno.
				if (turnoDelJugador)
				{
					// Se obtiene el daño aleatorio. FÓRMULA: (max - min + 1) + min.
					danioDefinitivo = rand() % ((jugadorDanio + diffRandom) - (jugadorDanio - diffRandom) + 1) + (jugadorDanio - diffRandom);

					// Se verifica si el daño lo recibe la armadura o la vida del enemigo.
					if (enemigoArmadura > 0)
					{
						// Se verifica si la armadura resiste el daño.
						if (enemigoArmadura - danioDefinitivo > 0)
						{
							enemigoArmadura -= danioDefinitivo;
							cout << "El jugador ha atacado al enemigo, restandole " << danioDefinitivo << " de armadura.\n\n";
						}
						else
						{
							enemigoArmadura = 0;
							cout << "El jugador ha atacado al enemigo, destruyendo su armadura con " << danioDefinitivo << " de damage.\n\n";
						}
					}
					else
					{
						// Se verifica si el enemigo resiste el daño.
						if (enemigoVida - danioDefinitivo > 0)
						{
							enemigoVida -= danioDefinitivo;
							cout << "El jugador ha atacado al enemigo, restandole " << danioDefinitivo << " de vida.\n\n";
						}
						else
						{
							enemigoVida = 0;
							cout << "El jugador ha derrotado al enemigo con " << danioDefinitivo << " de damage.\n\n";
						}
					}
				}
				else
				{
					// Se obtiene el daño aleatorio. FÓRMULA: (max - min + 1) + min.
					danioDefinitivo = rand() % ((enemigoDanio + diffRandom) - (enemigoDanio - diffRandom) + 1) + (enemigoDanio - diffRandom);

					// Se verifica si el daño lo recibe la armadura o la vida del jugador.
					if (jugadorArmadura > 0)
					{
						// Se verifica si la armadura resiste el daño.
						if (jugadorArmadura - danioDefinitivo > 0)
						{
							jugadorArmadura -= danioDefinitivo;
							cout << "El enemigo ha atacado al jugador, restandole " << danioDefinitivo << " de armadura.\n\n";
						}
						else
						{
							jugadorArmadura = 0;
							cout << "El enemigo ha atacado al jugador, destruyendo su armadura con " << danioDefinitivo << " de damage.\n\n";
						}
					}
					else
					{
						// Se verifica si el jugador resiste el daño.
						if (jugadorVida - danioDefinitivo > 0)
						{
							jugadorVida -= danioDefinitivo;
							cout << "El enemigo ha atacado al jugador, restandole " << danioDefinitivo << " de vida.\n\n";
						}
						else
						{
							jugadorVida = 0;
							cout << "El enemigo ha derrotado al jugador con " << danioDefinitivo << " de damage.\n\n";
						}
					}
				}

				// Se intercambia el turno.
				turnoDelJugador = !turnoDelJugador;

				system("pause");
				system("cls");
			}

			// Resultados de la batalla.
			if (jugadorVida > 0)
			{
				// Se crea una cantidad aleatoria de oro ganado por la victoria del jugador.
				oroGanado = rand() % (200 - 150 + 1) + 150;

				// Se verifica si se compró el trébol de 4 hojas.
				if (tieneTrebol)
				{
					oroGanado *= 2;
					tieneTrebol = false;
				}

				cout << "El jugador ha ganado la batalla y " << oroGanado << " de oro!\n";
				jugadorOro += oroGanado;
			}
			else
			{
				cout << "El enemigo ha ganado la batalla.\n";
				enJuego = false;
			}

			turnoDelJugador = true;
			system("pause");
			system("cls");

			#pragma endregion

			pantallaActual = PANTALLA::DESCANSO;

			break;


		case PANTALLA::DESCANSO:

			#pragma region BREAK

			system("cls");
			cout << "        --- DESCANSO ---\n\n";
			cout << "1. BATALLA\n";
			cout << "2. TIENDA\n";
			cout << "3. RETIRARSE (Oro guardado: " << jugadorOro << ")\n";
			cout << "4. ABANDONAR LA PARTIDA.\n\n";
			do
			{
				cout << "Opcion elegida: ";
				cin >> opcion;

			} while (opcion < 1 || opcion > 4);

			// Acción según opción elegida.
			switch (opcion)
			{
			case 1:
				// Mensaje de preparación para la batalla.
				cout << "\nPreparese para la batalla...\n";
				system("pause");
				system("cls");
				pantallaActual = PANTALLA::BATALLA;
				break;

			case 2:
				// Cambio inmediato de pantalla.
				pantallaActual = PANTALLA::TIENDA;
				break;

			case 3:
				// Condición de retirarse.
				if (jugadorOro >= 2000)
				{
					cout << "El cazarrecompensas ha decidido retirarse de su vida como cazarrecompensas.\n";
					enJuego = false;
				}
				else
				{
					cout << "Para poder retirarse, el jugador debe tener al menos 2000 de oro acumulado.\n";
				}

				system("pause");
				system("cls");
				break;

			case 4:
				// Finalizado de programa.
				enJuego = false;
				break;
			}

			#pragma endregion

			break;


		case PANTALLA::TIENDA:

			#pragma region SHOP

			// Se muestran todos los datos (Items y valores actuales del jugador).
			system("cls");
			cout << "     ----- TIENDA -----\n\n\n";
			cout << "Bienvenido a la tienda! Que desea comprar?\n\n";
			cout << "Vida: " << jugadorVida << ".\n";
			cout << "Armadura: " << jugadorArmadura << ".\n";
			cout << "Oro disponible: " << jugadorOro << ".\n\n";
			cout << "1. POCION DE VIDA                  Precio: " << precioPocion << " de oro.\n";
			cout << "2. REPARACION DE ARMADURA          Precio: " << precioArmadura << " de oro.\n";
			cout << "3. TREBOL DE 4 HOJAS               Precio: " << precioTrebol << " de oro.\n";
			cout << "4. VOLVER AL MENU DE DESCANSO\n\n";
			do
			{
				cout << "Opcion elegida: ";
				cin >> opcion;
			} while (opcion < 1 || opcion > 4);

			// Se toma acción en base a la elección del jugador.
			switch (opcion)
			{
			case 1:
				// Verifica que se tenga oro suficiente.
				if (jugadorOro >= precioPocion)
				{
					// Se verifica si el jugador tiene toda la vida. En ese caso, la poción no se compra.
					if (jugadorVida >= 100)
					{
						cout << "El jugador ya tiene la salud al maximo.\n";
					}
					else
					{
						// Se compra el ítem.
						jugadorOro -= precioPocion;

						// Se evalúa si tras la compra de la poción se llena la vida al máximo.
						if (jugadorVida + 50 >= 100)
						{
							jugadorVida = 100;
							cout << "El jugador se ha recuperado en su totalidad.\n";
						}
						else
						{
							jugadorVida += 50;
							cout << "El jugador ha restaurado 50 de vida.\n";
						}
					}
				}
				else
				{
					cout << "Oro insuficiente.\n";
				}
				break;

			case 2:
				// Verifica que se tenga oro suficiente.
				if (jugadorOro >= precioArmadura)
				{
					// Se verifica si el jugador tiene la armadura intacta. En ese caso, no se repara.
					if (jugadorArmadura >= 100)
					{
						cout << "El jugador no necesita reparar su armadura debido a que esta en perfectas condiciones.\n";
					}
					else
					{
						// Se compra el ítem y se aplica la reparación.
						jugadorOro -= precioArmadura;
						jugadorArmadura = 100;
						cout << "La armadura fue reparada.\n";
					}
				}
				else
				{
					cout << "Oro insuficiente.\n";
				}
				break;

			case 3:
				// Verifica que se tenga oro suficiente.
				if (jugadorOro >= precioTrebol)
				{
					// Se verifica si el jugador había comprado el trébol. De haberlo comprado, no se vuelve a comprar.
					if (tieneTrebol)
					{
						cout << "El jugador ya tiene un trebol guardado.\n";
					}
					else
					{
						// Se compra y se aplica efecto tras ganar la próxima batalla.
						jugadorOro -= precioTrebol;
						tieneTrebol = true;
						cout << "El trebol de 4 hojas ha sido comprado.\n";
					}
				}
				else
				{
					cout << "Oro insuficiente.\n";
				}
				break;

			case 4:
				// Se vuelve al menú anterior.
				cout << "Se volvera al menu de descanso.\n";
				pantallaActual = PANTALLA::DESCANSO;
				break;
			}

			system("pause");

			#pragma endregion

			break;
		}
	}

	cout << "Gracias por jugar.\n";
	system("pause");


	return 0;
}
