#include "logic.hpp"
#include <sstream>

uint8_t string_to_uint8_t(const std::string& input) {
	if (input.length() != 1) return 0;

	uint8_t output = 0;
	if (input[0] <= '9' && input[0] >= '0') output =  static_cast<uint8_t>(input[0] - '0');
	return output;
}

int main() {
	Game game;
	game.Start();

	while (true) {
		std::string command;
		std::cin >> command;

		uint8_t input = string_to_uint8_t(command);

		bool status = game.RegisterInput(input);
		if (!status) break;
	}
	return 0;
}