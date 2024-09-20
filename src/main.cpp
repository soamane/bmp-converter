#include <memory>
#include <iostream>

#include "BmpConverter/BmpConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <path to file>";
		return 1;
	}

	try {
		std::unique_ptr<BMPConverter> converter = std::make_unique<BMPConverter>();

		converter->OpenBMP(argv[1]);
		converter->DisplayBMP();
		converter->CloseBMP();

	}
	catch (std::exception e) {
		std::cerr << e.what();
	}

	return 0;
}