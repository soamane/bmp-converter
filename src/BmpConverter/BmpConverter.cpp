#include "BMPConverter.hpp"

#include <iostream>

BMPConverter::BMPConverter() noexcept
{
}

void BMPConverter::OpenBMP(std::string_view path)
{
	if (path.empty()) {
		throw std::invalid_argument("File path is empty");
	}

	this->m_currentFile.open(path.data(), std::ios::binary);
	if (!this->m_currentFile.is_open()) {
		throw std::runtime_error("Failed to open target file");
	}

	this->ReadBMPHeaders();
	this->ReadImageData();
}

void BMPConverter::DisplayBMP()
{
	int rowSize = this->GetRowByteSize();
	for (int y = this->m_currentImage.m_info.biHeight - 1; y >= 0; --y) {
		for (int x = 0; x < this->m_currentImage.m_info.biWidth; ++x) {
			const int pixel = y * rowSize + x * (this->m_currentImage.m_info.biBitCount / 8);

			unsigned char r = this->m_imageData[pixel + 2];
			unsigned char  g = this->m_imageData[pixel + 1];
			unsigned char  b = this->m_imageData[pixel];

			this->Print(r, g, b);
		}
		std::cout << std::endl;
	}
}

void BMPConverter::CloseBMP()
{
	if (!this->m_imageData.empty()) {
		this->m_imageData.clear();
	}

	if (this->m_currentFile.is_open()) {
		this->m_currentFile.close();
	}
}

BMPConverter::~BMPConverter()
{
	this->CloseBMP();
}

void BMPConverter::Print(unsigned char  r, unsigned char  g, unsigned char  b) const
{
	if (r == 0 && g == 0 && b == 0) {
		std::cout << "*";
	}
	else if (r == 255 && g == 255 && b == 255) {
		std::cout << ".";
	}
	else {
		throw std::runtime_error("Unsupported color palette in file");
	}
}

void BMPConverter::ReadBMPHeaders()
{
	this->m_currentFile.read(reinterpret_cast<char*>(&this->m_currentImage.m_header), sizeof(this->m_currentImage.m_header));
	this->m_currentFile.read(reinterpret_cast<char*>(&this->m_currentImage.m_info), sizeof(this->m_currentImage.m_info));

	if (this->m_currentImage.m_info.biBitCount != 24 && this->m_currentImage.m_info.biBitCount != 32) {
		throw std::runtime_error("Invalid file format. Only 24 or 32-bit files supported");
	}
}

void BMPConverter::ReadImageData()
{
	const int bytesInRow = this->GetRowByteSize();
	const int totalSize = bytesInRow * this->m_currentImage.m_info.biHeight;

	try {
		this->m_imageData.resize(totalSize);
	}
	catch (std::bad_alloc exception) {
		throw exception; 
	}

	this->m_currentFile.read(reinterpret_cast<char*>(this->m_imageData.data()), totalSize);
}

const unsigned int BMPConverter::GetRowByteSize() const
{
	const int offset = 31;
	const int padding = 32; 
	
	int bitesInRow = this->m_currentImage.m_info.biBitCount * this->m_currentImage.m_info.biWidth;

	bitesInRow += offset;

	return (bitesInRow / padding) * 4;
}
