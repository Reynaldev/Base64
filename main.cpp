#include <iostream>
#include <string>
#include <vector>
#include <math.h>;

void encode() {
	// Declaration
	char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

	std::string text, bits;
	std::vector<int> binary;
	std::vector<std::string> binaryText;

	// User input
	std::cout << "Input a text: "; std::getline(std::cin, text);

	// Get the ASCII code for each letter and put it inside octets vector
	for (int i = 0; i < text.length(); i++) {
		binary.push_back(int(text[i]));

		//std::cout << std::to_string(octets[i]) + " ";
	}

	//std::cout << std::endl;

	// Turn ASCII code into binary
	for (int i = 0; i < binary.size(); i++) {
		std::string temp, revTemp;
		int bit = binary[i];

		// While the ASCII is bigger than 0
		while (bit > 0) {
			// We calculate the ASCII number with modulo, so the results will be 0 or 1
			int x = bit % 2;

			// Put it inside a string that we already declared
			temp += std::to_string(x);

			// We divide the ASCII until it reaches zero
			bit /= 2;
		}

		// If the binary number length is less than 8, we put a 0 behind
		while (temp.length() < 8) {
			temp += "0";
		}

		// We reversed the binary code, because the order is incorrect when we insert it
		for (int j = temp.length() - 1; j >= 0; j--) {
			revTemp += temp[j];
		}

		bits += revTemp;
	}

	binary.clear();

	/*std::cout << bits;
	std::cout << std::endl;*/

	while (bits.length() > 0) {
		while (bits.length() < 6) {
			bits += "0";
		}

		std::string temp = bits.substr(0, 6);
		binaryText.push_back(temp);

		bits.erase(0, 6);
	}

	/*for (auto str : binaries) {
		std::cout << str << " ";
	}*/

	for (int i = 0; i < binaryText.size(); i++) {
		int result = 0;

		for (int j = binaryText[i].length() - 1; j >= 0; j--) {
			if (binaryText[i].at(j) % 2 == 1) {
				result += pow(2, binaryText[i].length() - 1 - j);
			}
		}

		binary.push_back(result);
	}

	std::string result;
	for (int i = 0; i < binary.size(); i++) {
		result += alphabet[binary[i]];
	}

	int padding = 0;

	if (binaryText.size() % 4 != 0) {
		padding = 4 - (binaryText.size() % 4);
		abs(padding);
	}

	while (padding > 0) {
		result += "=";
		padding--;
	}

	std::cout << result;
}

void decode() {}

int main() {
	encode();

	return 0;
}