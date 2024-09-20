#pragma once
#ifndef BMP_CONVERTER_H
#define BMP_CONVERTER_H

#include <vector>
#include <fstream>

#include "../BmpImage/BmpImage.hpp"

class BMPConverter {
public:
	BMPConverter() noexcept;

	void OpenBMP(std::string_view path);
	void DisplayBMP();
	void CloseBMP();

	~BMPConverter();

private:
	void Print(unsigned char r, unsigned char g, unsigned char b) const;
	void ReadBMPHeaders();

	void ReadImageData();
	const unsigned int GetRowByteSize() const;

private:
	BmpImage m_currentImage;
	std::ifstream m_currentFile;
	std::vector<unsigned char> m_imageData;
};

#endif // !BMP_CONVERTER_H
