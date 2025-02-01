#include "visualizer.hpp"

#ifdef _WIN32
	#include <windows.h>

	void Visualizer::ClearDisplay() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
			DWORD dwWritten;
			COORD coordScreen = {0, 0};
			DWORD dwSize = csbi.dwSize.X * csbi.dwSize.Y;
			FillConsoleOutputCharacter(hConsole, ' ', dwSize, coordScreen, &dwWritten);
			SetConsoleCursorPosition(hConsole, coordScreen);
		}
		displayBuffer = "";
	}
#else
	void Visualizer::ClearDisplay() {
		std::cout << "\033[2J\033[H";
		displayBuffer = "";
	}
#endif

Visualizer::Visualizer() {}

void Visualizer::DisplayMain() {
	ClearDisplay();

	displayBuffer += GAME_NAME;
	displayBuffer += MAIN;

	std::cout << displayBuffer;
}

void Visualizer::DisplayTable(const std::array<uint8_t, 9> table) {
	ClearDisplay();

	displayBuffer += GAME_NAME;
	displayBuffer += "             ";
	for(size_t i = 0; i < 9; i++) {
		if (table[i] == 0) displayBuffer += std::to_string(i + 1);
		else if (table[i] == 1) displayBuffer += "X";
		else displayBuffer += "O";
		
		if ((i + 1) % 3 == 0 && i < 7) displayBuffer += "\n            ---+---+---\n             ";
		else if (i < 8) displayBuffer += " | ";
	}
	displayBuffer += '\n';
	std::cout << displayBuffer;
}

void Visualizer::Display(std::string message) {
	std::cout << message + '\n';
}