#ifndef MGTV_LIBRARY_H
#define MGTV_LIBRARY_H

#include <string>

using std::string;


namespace mgtv_library
{
	namespace console
	{
		enum class COLOR
		{
			C_BLACK,
			C_BLUE,
			C_GREEN,
			C_CYAN,
			C_RED,
			C_MAGENTA,
			C_BROWN,
			C_WHITE,
			C_GRAY,
			C_LBLUE,
			C_LGREEN,
			C_LCYAN,
			C_LRED,
			C_LMAGENTA,
			C_YELLOW,
			C_BWHITE
		};
		enum class GENDER { FEMININE, MASCULINE };

		const int KEY_ESC = 27;
		const int KEY_UP = 256 + 72;
		const int KEY_DOWN = 256 + 80;
		const int KEY_LEFT = 256 + 75;
		const int KEY_RIGHT = 256 + 77;
		const int KEY_DELETE = 256 + 83;
		const int KEY_INSERT = 256 + 82;
		const int KEY_ENTER = 13;
		const int KEY_BEG = 256 + 71;
		const int KEY_END = 256 + 79;

		const int LEFT_UP = 201;
		const int LEFT_DW = 200;
		const int RIGHT_UP = 187;
		const int RIGHT_DW = 188;
		const int LINE_HOR = 205;
		const int LINE_VER = 186;

		class ConsoleExt
		{
		public:
			#pragma region CONTROL DEL CURSOR

			/// <summary>
			/// Ubica al cursor en las coordenadas correspondientes.
			/// </summary>
			/// <param name="x: ">La posición sobre el eje X.</param>
			/// <param name="y: ">La posición sobre el eje Y.</param>
			static void goToCoordinates(int x, int y);

			/// <summary>
			/// Oculta el cursor.
			/// </summary>
			static void hideCursor();

			/// <summary>
			/// Muestra el cursor.
			/// </summary>
			static void showCursor();

			#pragma endregion

			#pragma region VENTANA DE LA CONSOLA

			/// <summary>
			/// Se le establece un nuevo título a la ventana de la consola.
			/// </summary>
			/// <param name="title: ">El título que va a tener la ventana de la consola</param>
			static void setConsoleTitle(const char* title);

			/// <returns>El espacio en ancho de la ventana de la consola.</returns>
			static int getScreenWidth();

			/// <returns>El espacio en alto de la ventana de la consola.</returns>
			static int getScreenHeight();

			#pragma endregion

			#pragma region ACCIONES EN LA CONSOLA

			/// <returns>El color establecido para el fondo.</returns>
			static COLOR getBackgroundColor();

			/// <returns>El color establecido para el texto.</returns>
			static COLOR getForegroundColor();

			/// <summary>
			/// Cambia el color del fondo del texto que se escriba después.
			/// </summary>
			/// <param name="color: ">El nuevo color del fondo.</param>
			static void setBackgroundColor(COLOR color);

			/// <summary>
			/// Cambia el color del texto que se escriba después.
			/// </summary>
			/// <param name="color: ">El nuevo color del texto.</param>
			static void setForegroundColor(COLOR color);

			/// <param name="wait: ">Determina si la ejecución se debe detener hasta que el jugador presione una tecla.</param>
			/// <returns>El valor numérico de la tecla presionada.</returns>
			static int getKey(bool wait);

			/// <summary>
			/// Se detiene la ejecución del programa por un tiempo determinado.
			/// </summary>
			/// <param name="miliseconds">La cantidad de milisegundos que se va a detener la ejecución.</param>
			static void sleep(int miliseconds);

			/// <summary>
			/// Se detiene la ejecución del programa por un tiempo determinado.
			/// </summary>
			/// <param name="seconds">La cantidad de segundos que se va a detener la ejecución.</param>
			static void sleep(float seconds);

			#pragma endregion

			#pragma region MUESTRA DE DATOS EN LA CONSOLA

			/// <summary>
			/// Dibuja un marco en la consola.
			/// </summary>
			/// <param name="x1">La posición sobre el eje X de la esquina superior izquierda.</param>
			/// <param name="y1">La posición sobre el eje Y de la esquina superior derecha.</param>
			/// <param name="x2">La posición sobre el eje X de la esquina inferior derecha.</param>
			/// <param name="y2">La posición sobre el eje Y de la esquina inferior derecha.</param>
			static void drawFrame(int x1, int y1, int x2, int y2);

			/// <summary>
			/// Dibuja un marco en la consola con un color determinado.
			/// </summary>
			/// <param name="x1">La posición sobre el eje X de la esquina superior izquierda.</param>
			/// <param name="y1">La posición sobre el eje Y de la esquina superior izquierda.</param>
			/// <param name="x2">La posición sobre el eje X de la esquina inferior derecha.</param>
			/// <param name="y2">La posición sobre el eje Y de la esquina inferior derecha.</param>
			/// <param name="foregroundColor">El color del marco.</param>
			static void drawFrame(int x1, int y1, int x2, int y2, COLOR foregroundColor);

			/// <summary>
			/// Dibuja un marco en la consola con un color y fondo determinados.
			/// </summary>
			/// <param name="x1">La posición sobre el eje X de la esquina superior izquierda.</param>
			/// <param name="y1">La posición sobre el eje Y de la esquina superior izquierda.</param>
			/// <param name="x2">La posición sobre el eje X de la esquina inferior derecha.</param>
			/// <param name="y2">La posición sobre el eje Y de la esquina inferior derecha.</param>
			/// <param name="foregroundColor">El color del marco.</param>
			/// <param name="backgroundColor">El color del fondo del marco.</param>
			static void drawFrame(int x1, int y1, int x2, int y2, COLOR foregroundColor, COLOR backgroundColor);

			/// <summary>
			/// Escribe un texto con un color determinado.
			/// </summary>
			/// <param name="message: ">El texto a escribir.</param>
			/// <param name="foreColor: ">El color del texto.</param>
			static void writeWithColor(string message, COLOR foreColor);

			/// <summary>
			/// Escribe un texto con color y fondo determinados.
			/// </summary>
			/// <param name="message: ">El texto a escribir.</param>
			/// <param name="foreColor: ">El color del texto.</param>
			/// <param name="backColor: ">El color del fondo del texto.</param>
			static void writeWithColor(string message, COLOR foreColor, COLOR backColor);

			/// <summary>
			/// Escribe un mensaje de creación de objeto.
			/// </summary>
			/// <param name="gender">Género gramatical del objeto.</param>
			/// <param name="objectName">Nombre del objeto.</param>
			/// <param name="endLines">Saltos de línea después del mensaje.</param>
			static void writeCreationMessage(GENDER gender, string objectName, int endLines = 1);

			/// <summary>
			/// Escribe un mensaje de destrucción de objeto.
			/// </summary>
			/// <param name="gender">Género gramatical del objeto.</param>
			/// <param name="objectName">Nombre del objeto.</param>
			/// <param name="endLines">Saltos de línea después del mensaje.</param>
			static void writeDestructionMessage(GENDER gender, string objectName, int endLines = 1);

			#pragma endregion

		private:
			static COLOR actualBackColor;
			static COLOR actualForeColor;
		};
	}
}

#endif // !MGTV_LIBRARY_H
