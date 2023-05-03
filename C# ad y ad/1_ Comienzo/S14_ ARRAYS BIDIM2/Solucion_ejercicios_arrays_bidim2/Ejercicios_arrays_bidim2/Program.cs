using System;


namespace Ejercicios_arrays_bidim2
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			char[,] arregloBidim1 = new char[5, 3] { { 'O', 'O', 'O' },
													 { 'O', 'O', 'O' },
													 { 'O', 'O', 'O' },
													 { 'O', 'O', 'O' },
													 { 'O', 'O', 'O' } };
			int numero = 0;

			char[,] arregloBidim2 = new char[7, 7] { { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
			int posicionX = 0;
			int posicionY = 0;

			char[,] arregloBidim3 = new char[9, 9] { { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
													 { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '?', '-', '?', '-', '?', 'X' },
													 { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
													 { 'X', 'J', '-', '?', '-', '?', '-', '?', 'X' },
													 { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '?', '-', '?', '-', '?', 'X' },
													 { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
													 { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
			char cofre = '$';
			char agujero = 'O';
			char puntosExtra = 'P';
			char tiempoExtra = 'T';



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			// Se muestra el arreglo.
			for (int i = 0; i < arregloBidim1.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim1.GetLength(1); j++)
				{
					Console.Write(arregloBidim1[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine();

			// Se pide el dato.
			do
			{
				Console.Write("Ingrese el número de fila para trazar la línea: ");
				numero = int.Parse(Console.ReadLine());

			} while (numero < 1 || numero > arregloBidim1.GetLength(0));

			Console.WriteLine();

			// Se traza la línea.
			for (int i = 0; i < arregloBidim1.GetLength(1); i++)
			{
				arregloBidim1[numero - 1, i] = 'X';
			}

			// Se vuelve a mostrar el arreglo.
			for (int i = 0; i < arregloBidim1.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim1.GetLength(1); j++)
				{
					Console.Write(arregloBidim1[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			// Se muestra el minimapa.
			for (int i = 0; i < arregloBidim2.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim2.GetLength(1); j++)
				{
					Console.Write(arregloBidim2[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine();

			// Se ingresa la posición X del jugador. Su límite lo va a definir la cantidad de columnas que hayan.
			do
			{
				Console.Write("Ingrese la posición X del jugador: ");
				posicionX = int.Parse(Console.ReadLine());

			} while (posicionX <= 1 || posicionX >= arregloBidim2.GetLength(1));

			// Se ingresa la posición Y del jugador. Su límite lo va a definir la cantidad de filas que hayan.
			do
			{
				Console.Write("Ingrese la posición Y del jugador: ");
				posicionY = int.Parse(Console.ReadLine());

			} while (posicionY <= 1 || posicionY >= arregloBidim2.GetLength(0));

			Console.WriteLine();

			arregloBidim2[posicionY - 1, posicionX - 1] = 'J'; // Se asigna el jugador al mapa.

			// Se muestra el minimapa con el jugador incluido.
			for (int i = 0; i < arregloBidim2.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim2.GetLength(1); j++)
				{
					Console.Write(arregloBidim2[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			// Se asignan los elementos random.
			for (int i = 0; i < arregloBidim3.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim3.GetLength(1); j++)
				{
					if (arregloBidim3[i, j] == '?')
					{
						switch (generar.Next(4))
						{
							case 0:
								arregloBidim3[i, j] = cofre;
								break;

							case 1:
								arregloBidim3[i, j] = agujero;
								break;

							case 2:
								arregloBidim3[i, j] = puntosExtra;
								break;

							case 3:
								arregloBidim3[i, j] = tiempoExtra;
								break;
						}
					}
				}
			}

			// Se muestra el minimapa.
			for (int i = 0; i < arregloBidim3.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim3.GetLength(1); j++)
				{
					Console.Write(arregloBidim3[i, j] + " ");
				}

				Console.WriteLine();
			}



			Console.ReadKey(true);
		}
	}
}
