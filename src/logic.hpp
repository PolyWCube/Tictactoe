#ifndef LOGIC
#define LOGIC

#include "visualizer.hpp"

const uint8_t WIN_CONDITION[8][3] =
{
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{1, 4, 7},
	{2, 5, 8},
	{3, 6, 9},
	{1, 5, 9},
	{3, 5, 7}
};

class Game {
	public:
		Game();
		void Start();
		bool RegisterInput(uint8_t& input);
	private:
		void CheckTable();

		Visualizer visualizer;
		uint8_t gameState = 0;
		bool turn = true;
		std::array<uint8_t, 9> table = {0};
};

#endif