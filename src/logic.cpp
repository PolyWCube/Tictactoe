#include "logic.hpp"

Game::Game() {}

void Game::Start() {
	visualizer.DisplayMain();
}

bool Game::RegisterInput(uint8_t& input) {
	if (input > 10 || input <= 0) {
		visualizer.Display("Invalid input");
		return true;
	}
	if (gameState == 1) {
		if (table[input - 1] == 0) {
			table[input - 1] = (turn) ? 1 : 2;
			visualizer.DisplayTable(table);
			CheckTable();
			turn = !turn;
		} else {
			visualizer.Display("Player " + (std::string)((table[input - 1] == 1) ? "1" : "2") + " have already ticked.");
			return true;
		}
	} else if (gameState == 0) {
		if (input == 1) {
			gameState = 1;
			visualizer.DisplayTable(table);
			return true;
		}
		else if (input == 2) return false;
		else {
			visualizer.Display("Invalid input");
			return true;
		}
	} else {
		if (input == 1) {
			gameState = 0;
			visualizer.DisplayMain();
			return true;
		} else if (input == 2) {
			gameState = 1;
			visualizer.DisplayTable(table);
			return true;
		} else {
			visualizer.Display("Invalid input");
			return true;
		}
	}
	return true;
}

void Game::CheckTable() {
	for(size_t i = 0; i < 8; i++) {
		uint8_t a = table[WIN_CONDITION[i][0] - 1];
		uint8_t b = table[WIN_CONDITION[i][1] - 1];
		uint8_t c = table[WIN_CONDITION[i][2] - 1];
		if (a == b && a == c) {
			if (a == 0) continue;
			visualizer.DisplayTable(table);
			visualizer.Display("Player " + (std::string)((turn) ? "1" : "2") + " win.");
			visualizer.Display("Combination: " + std::to_string(WIN_CONDITION[i][0]) + ' ' + std::to_string(WIN_CONDITION[i][1]) + ' ' + std::to_string(WIN_CONDITION[i][2]));
			visualizer.Display("[1] [RETURN]          [2] [RETRY]\n");
			table = {};
			gameState = 2;
			break;
		}
	}
	bool moveable = false;
	for(size_t i = 0; i < 9; i++) {
		if (table[i] == 0) {
			moveable = true;
			break;
		}
	}
	if (!moveable) {
		visualizer.DisplayTable(table);
		visualizer.Display("Tie");
		visualizer.Display("[1] [RETURN]          [2] [RETRY]\n");
		table = {};
		gameState = 2;
	}
}