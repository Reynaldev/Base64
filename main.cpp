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
	}

	//std::cout << std::endl;

	// Turn ASCII code into binary
	for (int i = 0; i < binary.size(); i++) {
		// Declaration
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

	// We clear the vector so we can use it later
	binary.clear();

	// We divide the binaries and put it into four group of 6 elements
	while (bits.length() > 0) {
		// If a group has less than 6 element, add a 0 in the last index
		while (bits.length() < 6) {
			bits += "0";
		}

		// Take 6 elements
		std::string temp = bits.substr(0, 6);
		// Insert it into a vector
		binaryText.push_back(temp);
		// We make it simple to take 6 element without having to change the substr
		bits.erase(0, 6);
	}

	// Now we convert it to decimal using a loop, this will be converted into Base64 alphabet code (It looks like ASCII code)
	// Size loop
	for (int i = 0; i < binaryText.size(); i++) {
		// Declaration
		int result = 0;

		// Inner loop
		for (int j = binaryText[i].length() - 1; j >= 0; j--) {
			// If the binary equals 1, we calculate it using the power of (binary length - 1 - index). It is the same as power of two.
			if (binaryText[i].at(j) % 2 == 1) {
				result += pow(2, binaryText[i].length() - 1 - j);
			}
		}

		// Insert it into the vector we already cleared
		binary.push_back(result);
	}

	// Declaration
	std::string output;
	// Last but not least, we combine all Base64 alphabet code into a readable words.
	for (int i = 0; i < binary.size(); i++) {
		// We call the char array that already have been declared and match it with the order.
		output += alphabet[binary[i]];
	}

	// Declaration
	int padding = 0;
	// We put a padding or two if one segment has less than 4 group 
	if (binaryText.size() % 4 != 0) {
		padding = 4 - (binaryText.size() % 4);
		abs(padding);
	}

	while (padding > 0) {
		output += "=";
		padding--;
	}

	// Now we output the result
	std::cout << output;
}

void decode() {}

int main() {
	encode();

	return 0;
}