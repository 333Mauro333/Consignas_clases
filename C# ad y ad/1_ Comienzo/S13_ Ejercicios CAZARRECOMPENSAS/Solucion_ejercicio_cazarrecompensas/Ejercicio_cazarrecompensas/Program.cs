using System;


namespace Ejercicio_cazarrecompensas
{
	class Program
	{
		enum Pantalla { Batalla, Descanso, Tienda };

		static void Main()
		{
			Random generar = new Random();

			Pantalla pantallaActual = Pantalla.Batalla; // Variable para identificar la pantalla actual.

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



			// Loop del juego completo.
			while (enJuego)
			{
				// Se verifica cuál es la pantalla actual.
				switch (pantallaActual)
				{
					case Pantalla.Batalla:

						#region Batalla

						// Seteo de valores random para el enemigo.
						enemigoVida = generar.Next(50, 76); // Entre 50 y 75.
						enemigoArmadura = generar.Next(50, 76); // Entre 50 y 75.
						enemigoDanio = generar.Next(5, 21); // Entre 5 y 20.

						Console.Clear();

						// Loop de batalla.
						while (jugadorVida > 0 && enemigoVida > 0)
						{
							// Se muestran las estadísticas de la batalla.
							Console.WriteLine("                         ----- BATALLA -----\n");
							Console.WriteLine("Vida del jugador: " + jugadorVida + "                         Vida del enemigo: " + enemigoVida);
							Console.WriteLine("Armadura del jugador: " + jugadorArmadura + "                     Armadura del enemigo: " + enemigoArmadura);
							Console.WriteLine("Damage del jugador: " + jugadorDanio + "                       Damage del enemigo: " + enemigoDanio + "\n\n");

							// Se verifica de quién es el turno.
							if (turnoDelJugador)
							{
								// Se obtiene el daño aleatorio. FÓRMULA: (max - min + 1) + min.
								danioDefinitivo = generar.Next(jugadorDanio - diffRandom, jugadorDanio + diffRandom + 1);

								// Se verifica si el daño lo recibe la armadura o la vida del enemigo.
								if (enemigoArmadura > 0)
								{
									// Se verifica si la armadura resiste el daño.
									if (enemigoArmadura - danioDefinitivo > 0)
									{
										enemigoArmadura -= danioDefinitivo;
										Console.WriteLine("El jugador ha atacado al enemigo, restandole " + danioDefinitivo + " de armadura.\n");
									}
									else
									{
										enemigoArmadura = 0;
										Console.WriteLine("El jugador ha atacado al enemigo, destruyendo su armadura con " + danioDefinitivo + " de damage.\n");
									}
								}
								else
								{
									// Se verifica si el enemigo resiste el daño.
									if (enemigoVida - danioDefinitivo > 0)
									{
										enemigoVida -= danioDefinitivo;
										Console.WriteLine("El jugador ha atacado al enemigo, restandole " + danioDefinitivo + " de vida.\n");
									}
									else
									{
										enemigoVida = 0;
										Console.WriteLine("El jugador ha derrotado al enemigo con " + danioDefinitivo + " de damage.\n\n");
									}
								}
							}
							else
							{
								// Se obtiene el daño aleatorio. FÓRMULA: (max - min + 1) + min.
								danioDefinitivo = generar.Next(enemigoDanio - diffRandom, enemigoDanio + diffRandom + 1);

								// Se verifica si el daño lo recibe la armadura o la vida del jugador.
								if (jugadorArmadura > 0)
								{
									// Se verifica si la armadura resiste el daño.
									if (jugadorArmadura - danioDefinitivo > 0)
									{
										jugadorArmadura -= danioDefinitivo;
										Console.WriteLine("El enemigo ha atacado al jugador, restandole " + danioDefinitivo + " de armadura.\n");
									}
									else
									{
										jugadorArmadura = 0;
										Console.WriteLine("El enemigo ha atacado al jugador, destruyendo su armadura con " + danioDefinitivo + " de damage.\n");
									}
								}
								else
								{
									// Se verifica si el jugador resiste el daño.
									if (jugadorVida - danioDefinitivo > 0)
									{
										jugadorVida -= danioDefinitivo;
										Console.WriteLine("El enemigo ha atacado al jugador, restandole " + danioDefinitivo + " de vida.\n");
									}
									else
									{
										jugadorVida = 0;
										Console.WriteLine("El enemigo ha derrotado al jugador con " + danioDefinitivo + " de damage.\n");
									}
								}
							}

							// Se intercambia el turno.
							turnoDelJugador = !turnoDelJugador;

							Console.Write("Presione cualquier tecla para continuar... ");
							Console.ReadKey(true);
							Console.Clear();
						}

						// Resultados de la batalla.
						if (jugadorVida > 0)
						{
							// Se crea una cantidad aleatoria de oro ganado por la victoria del jugador.
							oroGanado = generar.Next(150, 201);

							// Se verifica si se compró el trébol de 4 hojas.
							if (tieneTrebol)
							{
								oroGanado *= 2;
								tieneTrebol = false;
							}

							Console.WriteLine("El jugador ha ganado la batalla y " + oroGanado + " de oro!");
							jugadorOro += oroGanado;
						}
						else
						{
							Console.WriteLine("El enemigo ha ganado la batalla.");
							enJuego = false;
						}

						turnoDelJugador = true;
						Console.Write("Presione cualquier tecla para continuar... ");
						Console.ReadKey(true);
						Console.Clear();

						#endregion

						pantallaActual = Pantalla.Descanso;

						break;


					case Pantalla.Descanso:

						#region Descanso

						Console.Clear();
						Console.WriteLine("        --- DESCANSO ---\n");
						Console.WriteLine("1. BATALLA");
						Console.WriteLine("2. TIENDA");
						Console.WriteLine("3. RETIRARSE (oro guardado: " + jugadorOro + ")");
						Console.WriteLine("4. ABANDONAR LA PARTIDA\n");

						do
						{
							Console.Write("Opción elegida: ");
							opcion = int.Parse(Console.ReadLine());

						} while (opcion < 1 || opcion > 4);

						// Acción según opción elegida.
						switch (opcion)
						{
							case 1:
								// Mensaje de preparación para la batalla.
								Console.WriteLine("Prepárese para la batalla...");
								Console.Write("Presione cualquier tecla para comenzar... ");
								Console.ReadKey(true);
								Console.Clear();
								pantallaActual = Pantalla.Batalla;
								break;

							case 2:
								// Cambio inmediato de pantalla.
								pantallaActual = Pantalla.Tienda;
								break;

							case 3:
								// Condición de retirarse.
								if (jugadorOro >= 2000)
								{
									Console.WriteLine("El cazarrecompensas ha decidido retirarse de su vida como cazarrecompensas.");
									enJuego = false;
								}
								else
								{
									Console.WriteLine("Para poder retirarse, el jugador debe tener al menos 2000 de oro acumulado.");
								}

								Console.Write("Presione cualquier tecla para continuar... ");
								Console.ReadKey(true);
								Console.Clear();
								break;

							case 4:
								// Finalizado de programa.
								enJuego = false;
								break;
						}

						#endregion

						break;


					case Pantalla.Tienda:

						#region Tienda

						// Se muestran todos los datos (Items y valores actuales del jugador).
						Console.Clear();
						Console.WriteLine("     -----TIENDA-----\n\n");
						Console.WriteLine("¡Bienvenido a la tienda! ¿Qué desea comprar?\n");
						Console.WriteLine("Vida: " + jugadorVida + ".");
						Console.WriteLine("Armadura: " + jugadorArmadura + ".");
						Console.WriteLine("Oro disponible: " + jugadorOro + ".\n");

						Console.WriteLine("1. POCION DE VIDA                  Precio: " + precioPocion + " de oro.");
						Console.WriteLine("2. REPARACION DE ARMADURA          Precio: " + precioArmadura + " de oro.");
						Console.WriteLine("3. TREBOL DE 4 HOJAS               Precio: " + precioTrebol + " de oro.");
						Console.WriteLine("4. VOLVER AL MENÚ DE DESCANSO\n");

						do
						{
							Console.Write("Opción elegida: ");
							opcion = int.Parse(Console.ReadLine());

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
										Console.WriteLine("El jugador ya tiene la salud al máximo.");
									}
									else
									{
										// Se compra el ítem.
										jugadorOro -= precioPocion;

										// Se evalúa si tras la compra de la poción se llena la vida al máximo.
										if (jugadorVida + 50 >= 100)
										{
											jugadorVida = 100;
											Console.WriteLine("El jugador se ha recuperado en su totalidad.");
										}
										else
										{
											jugadorVida += 50;
											Console.WriteLine("El jugador ha restaurado 50 de vida.");
										}
									}
								}
								else
								{
									Console.WriteLine("Oro insuficiente.");
								}
								break;

							case 2:
								// Verifica que se tenga oro suficiente.
								if (jugadorOro >= precioArmadura)
								{
									// Se verifica si el jugador tiene la armadura intacta. En ese caso, no se repara.
									if (jugadorArmadura >= 100)
									{
										Console.WriteLine("El jugador no necesita reparar su armadura debido a que esta en perfectas condiciones.");
									}
									else
									{
										// Se compra el ítem y se aplica la reparación.
										jugadorOro -= precioArmadura;
										jugadorArmadura = 100;
										Console.WriteLine("La armadura fue reparada.");
									}
								}
								else
								{
									Console.WriteLine("Oro insuficiente.");
								}
								break;

							case 3:
								// Verifica que se tenga oro suficiente.
								if (jugadorOro >= precioTrebol)
								{
									// Se verifica si el jugador había comprado el trébol. De haberlo comprado, no se vuelve a comprar.
									if (tieneTrebol)
									{
										Console.WriteLine("El jugador ya tiene un trébol guardado.");
									}
									else
									{
										// Se compra y se aplica efecto tras ganar la próxima batalla.
										jugadorOro -= precioTrebol;
										tieneTrebol = true;
										Console.WriteLine("El trébol de 4 hojas ha sido comprado.");
									}
								}
								else
								{
									Console.WriteLine("Oro insuficiente.");
								}
								break;

							case 4:
								// Se vuelve al menú anterior.
								Console.WriteLine("Se volverá al menú de descanso.");
								pantallaActual = Pantalla.Descanso;
								break;
						}

						Console.Write("Presiona cualquier tecla para continuar... ");
						Console.ReadKey(true);

						#endregion

						break;
				}
			}

			Console.Write("¡Gracias por jugar! Presione cualquier tecla para cerrar la ventana. ");



			Console.ReadKey(true);
		}
	}
}
