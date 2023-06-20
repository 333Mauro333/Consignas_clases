using System;

using Mgtv_Library.Console;


namespace Calculadora
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;

			int anchoConsola = ConsoleExt.GetScreenWidth();
			int altoConsola = ConsoleExt.GetScreenHeight();

			Pantalla pantallaActual = Pantalla.MenuPrincipal;
			Operacion operacionElegida = Operacion.Suma;

			string opcion1 = "1. REALIZAR UNA OPERACIÓN";
			string opcion2 = "2. CAMBIAR EL TIPO DE CALCULADORA";
			string opcion3 = "3. ESTADÍSTICAS";
			string opcion4 = "4. APAGAR";

			string mensajeFinal = "¡Gracias por utilizar! Presione cualquier tecla para cerrar la ventana... ";

			float primerNumero = 0.0f;
			float segundoNumero = 0.0f;
			float resultado = 0.0f;

			int opcionIngresada = 0;


			while (enPrograma)
			{
				Console.Clear();

				switch (pantallaActual)
				{
					case Pantalla.MenuPrincipal:

						#region Menú principal

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 10, altoConsola / 2 - 6);
						Console.Write("--- CALCULADORA ---");

						if (Calculadora.GetTipoDeCalculadora() == TipoDeCalculadora.Comun)
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 6, altoConsola / 2 - 5);
							Console.Write("Tipo: Común.");
						}
						else
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 8, altoConsola / 2 - 5);
							Console.Write("Tipo: Científica.");
						}

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 9, altoConsola / 2 - 2);
						Console.Write("Elija una opción: ");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion1.Length / 2, altoConsola / 2);
						Console.Write(opcion1);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion2.Length / 2, altoConsola / 2 + 1);
						Console.Write(opcion2);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion3.Length / 2, altoConsola / 2 + 2);
						Console.Write(opcion3);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion4.Length / 2, altoConsola / 2 + 3);
						Console.Write(opcion4);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 + 6);
						Console.Write("Opción elegida: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						switch (opcionIngresada)
						{
							case 1:

								#region Carga del menú de operaciones

								if (Calculadora.GetTipoDeCalculadora() == TipoDeCalculadora.Comun)
								{
									pantallaActual = Pantalla.MenuComun;
								}
								else
								{
									pantallaActual = Pantalla.MenuCientifica;
								}

								#endregion

								break;

							case 2:

								// Se cambia el tipo de calculadora inmediatamente.
								Calculadora.CambiarTipoDeCalculadora();

								break;

							case 3:

								// Se cambia la pantalla a la de las estadísticas.
								pantallaActual = Pantalla.Estadisticas;

								break;

							case 4:

								#region Finalización del programa

								enPrograma = false;

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - mensajeFinal.Length / 2, altoConsola / 2 + 8);
								ConsoleExt.WriteInColor(mensajeFinal, ConsoleColor.Green);

								#endregion

								break;
						}

						#endregion

						break;

					case Pantalla.MenuComun:

						#region Operaciones con calculadora común

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 12);
						Console.Write("--- REALIZAR OPERACIÓN ---");

						// 1. SE PIDE EL PRIMER NÚMERO.
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 9);
						Console.Write("Ingrese el primer número: ");
						primerNumero = float.Parse(Console.ReadLine());

						// 2. SE PIDE EL TIPO DE OPERACIÓN.
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 7);
						Console.Write("Elija una operación:");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 5);
						Console.Write("1. SUMA");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 4);
						Console.Write("2. RESTA");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 3);
						Console.Write("3. MULTIPLICACIÓN");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 2);
						Console.Write("4. DIVISIÓN");

						do
						{
							BorrarPantalla(altoConsola / 2);

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2);
							Console.Write("Opción elegida: ");
							opcionIngresada = int.Parse(Console.ReadLine());

						} while (opcionIngresada < 1 || opcionIngresada > 4);

						operacionElegida = (Operacion)opcionIngresada;

						// Se pide el segundo número.
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 + 2);
						Console.Write("Ingrese el segundo número: ");
						segundoNumero = float.Parse(Console.ReadLine());

						// Se realiza la operación con la ayuda de la calculadora.
						switch (operacionElegida)
						{
							case Operacion.Suma:
								resultado = Calculadora.Sumar(primerNumero, segundoNumero);
								break;

							case Operacion.Resta:
								resultado = Calculadora.Restar(primerNumero, segundoNumero);
								break;

							case Operacion.Multiplicacion:
								resultado = Calculadora.Multiplicar(primerNumero, segundoNumero);
								break;

							case Operacion.Division:
								resultado = Calculadora.Dividir(primerNumero, segundoNumero);
								break;
						}

						BorrarPantalla(altoConsola / 2 - 12);

						// Se muestra el resultado.
						MostrarMenuDeResultado(primerNumero, segundoNumero, resultado, operacionElegida);

						do
						{
							BorrarPantalla(altoConsola / 2 + 3);

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
							Console.Write("Opción elegida: ");
							opcionIngresada = int.Parse(Console.ReadLine());

						} while (opcionIngresada < 1 || opcionIngresada > 2);

						if (opcionIngresada == 2)
						{
							pantallaActual = Pantalla.MenuPrincipal;
						}

						#endregion

						break;

					case Pantalla.MenuCientifica:

						#region Operaciones con calculadora científica

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 12);
						Console.Write("--- REALIZAR OPERACIÓN ---");

						// 1. SE PIDE EL NÚMERO.
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 9);
						Console.Write("Ingrese un número: ");
						primerNumero = float.Parse(Console.ReadLine());

						// 2. SE PIDE EL TIPO DE OPERACIÓN.
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 7);
						Console.Write("Elija una operación:");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 5);
						Console.Write("1. POTENCIA");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 4);
						Console.Write("2. RAÍZ");

						do
						{
							BorrarPantalla(altoConsola / 2 - 2);

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 2);
							Console.Write("Opción elegida: ");
							opcionIngresada = int.Parse(Console.ReadLine());

						} while (opcionIngresada < 1 || opcionIngresada > 2);

						operacionElegida = (Operacion)(opcionIngresada + 4);

						// Se pide el número y se realiza la operación correspondiente.
						switch (operacionElegida)
						{
							case Operacion.Potencia:

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, altoConsola / 2);
								Console.Write("Ingrese a cuánto lo quiere elevar: ");
								segundoNumero = float.Parse(Console.ReadLine());

								resultado = Calculadora.ObtenerPotencia(primerNumero, segundoNumero);

								break;

							case Operacion.Raiz:

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 37, altoConsola / 2);
								Console.Write("Ingrese el tipo de raíz (2 = Cuadrada; 3 = Cúbica. 4 = Cuarta; etcétera): ");
								segundoNumero = float.Parse(Console.ReadLine());

								resultado = Calculadora.ObtenerRaiz(primerNumero, segundoNumero);

								break;
						}

						BorrarPantalla(altoConsola / 2 - 12);

						// Se muestra el resultado.
						MostrarMenuDeResultado(primerNumero, segundoNumero, resultado, operacionElegida);

						do
						{
							BorrarPantalla(altoConsola / 2 + 3);

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
							Console.Write("Opción elegida: ");
							opcionIngresada = int.Parse(Console.ReadLine());

						} while (opcionIngresada < 1 || opcionIngresada > 2);

						if (opcionIngresada == 2)
						{
							pantallaActual = Pantalla.MenuPrincipal;
						}

						#endregion

						break;

					case Pantalla.Estadisticas:

						#region Muestra de estadísticas

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 10, altoConsola / 2 - 10);
						Console.Write("--- ESTADÍSTICAS ---");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 - 8);
						Console.Write("Cantidad de cuentas hechas: ");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 11, altoConsola / 2 - 5);
						Console.Write("Calculadora común: " + Calculadora.GetCuentasHechasComun() + ".");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 3);
						Console.Write("Calculadora científica: " + Calculadora.GetCuentasHechasCientifica() + ".");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2);
						Console.Write("1. RESTABLECER ESTADÍSTICAS");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 1);
						Console.Write("2. VOLVER AL MENÚ PRINCIPAL");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 3);
						Console.Write("Opción elegida: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						switch (opcionIngresada)
						{
							case 1:

								Calculadora.RestablecerEstadisticas();
								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 34, altoConsola / 2 + 5);
								Console.Write("¡Estadísticas restablecidas! Presione cualquier tecla para continuar... ");
								Console.ReadKey(true);

								break;

							case 2:
								pantallaActual = Pantalla.MenuPrincipal;
								break;
						}

						#endregion

						break;
				}
			}



			Console.ReadKey(true);
		}

		static void BorrarLinea(int linea)
		{
			for (int i = 0; i < ConsoleExt.GetScreenWidth(); i++)
			{
				ConsoleExt.GoToCoordinates(i + 1, linea);
				Console.Write(" ");
			}
		}
		static void BorrarPantalla(int lineaDesdeDondeBorrar)
		{
			for (int i = lineaDesdeDondeBorrar; i < ConsoleExt.GetScreenHeight(); i++)
			{
				BorrarLinea(i);
			}
		}

		static string ObtenerOperacionEnString(Operacion operacion, bool enMayuscula = true)
		{
			string nombreOperacion = "";


			switch (operacion)
			{
				case Operacion.Suma:
					nombreOperacion = enMayuscula == true ? "SUMA" : "Suma";
					break;

				case Operacion.Resta:
					nombreOperacion = enMayuscula == true ? "RESTA" : "Resta";
					break;

				case Operacion.Multiplicacion:
					nombreOperacion = enMayuscula == true ? "MULTIPLICACIÓN" : "Multiplicación";
					break;

				case Operacion.Division:
					nombreOperacion = enMayuscula == true ? "DIVISIÓN" : "División";
					break;

				case Operacion.Potencia:
					nombreOperacion = enMayuscula == true ? "POTENCIA" : "Potencia";
					break;

				case Operacion.Raiz:
					nombreOperacion = enMayuscula == true ? "RAÍZ" : "Raíz";
					break;
			}

			return nombreOperacion;
		}
		static void MostrarMenuDeResultado(float primerNumero, float segundoNumero, float resultado, Operacion operacion)
		{
			// Se muestra el resultado.
			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 19, ConsoleExt.GetScreenHeight() / 2 - 12);
			Console.Write("--- RESULTADO DE LA OPERACIÓN ---");

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 25, ConsoleExt.GetScreenHeight() / 2 - 10);
			Console.Write("Primer número: " + primerNumero);

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 25, ConsoleExt.GetScreenHeight() / 2 - 8);
			Console.Write("Operación realizada: " + ObtenerOperacionEnString(operacion));

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 25, ConsoleExt.GetScreenHeight() / 2 - 6);
			Console.Write("Segundo número: " + segundoNumero);

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 25, ConsoleExt.GetScreenHeight() / 2 - 3);
			Console.Write("Resultado: " + resultado);

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 24, ConsoleExt.GetScreenHeight() / 2);
			Console.Write("1. REALIZAR OTRA OPERACIÓN");
			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - 24, ConsoleExt.GetScreenHeight() / 2 + 1);
			Console.Write("2. VOLVER AL MENÚ PRINCIPAL");
		}
	}
}
