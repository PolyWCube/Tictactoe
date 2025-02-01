#ifndef VISUALIZER
#define VISUALIZER

#include <iostream>
#include <cstdint>
#include <string>
#include <array>

const std::string GAME_NAME = "[===== T I C - T A C - T O E =====]\n\n";
const std::string MAIN = "          [1] [START GAME]\n             [2] [EXIT]\n\n* THIS A CONSOLE GAME, use [NUMPAD]\nand press [ENTER] to register\ninput...\n";

class Visualizer {
	public:
		Visualizer();
		void DisplayMain();
		void DisplayTable(const std::array<uint8_t, 9> table);
		void Display(std::string message);
		void ClearDisplay();
	private:
		std::string displayBuffer = "";
};

#endif