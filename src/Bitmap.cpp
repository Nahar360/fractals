#include "Bitmap.hpp"

#include "BitmapInfoHeader.hpp"
#include "BitmapFileHeader.hpp"

#include <fstream>
#include <iostream>

namespace Fractals
{
	Bitmap::Bitmap(int width, int height) :
		m_width(width),
		m_height(height),
		m_pPixels(new uint8_t[width * height * 3]{})
	{
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		uint8_t* pPixel = m_pPixels.get();
		// y * m_width = number of pixels/bytes (if each pixel is 1 byte) in all the rows before the one we are actually interested in
		// + x = moving it forward the number of columns specified by x
		// y * 3 = because we have r, g, b
		pPixel += (y * 3) * m_width + (x * 3);

		// reversed format because the bitmap is a little endian format
		// little endian: storing least significant byte in the area of memory that has the smallest memory addressed
		// 0xFF8844
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	bool Bitmap::write(const std::string& filename)
	{
		// create the bitmap file header
		BitmapFileHeader fileHeader;
		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		// create the bitmap info header
		BitmapInfoHeader infoHeader;
		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;

		// open the file in binary mode
		file.open(filename, std::ios::out | std::ios::binary);
		if (!file)
		{
			std::cerr << "Could not open file: " << filename << std::endl;
			return false;
		}

		// write the headers to the file
		file.write((char*)&fileHeader, sizeof(fileHeader));
		if (!file)
		{
			std::cerr << "Could not write file header to file: " << filename << std::endl;
			return false;
		}

		// write the info header to the file
		file.write((char*)&infoHeader, sizeof(infoHeader));
		if (!file)
		{
			std::cerr << "Could not write info header to file: " << filename << std::endl;
			return false;
		}

		// write the pixel data to the file
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);
		if (!file)
		{
			std::cerr << "Could not write pixel data to file: " << filename << std::endl;
			return false;
		}

		// close the file
		file.close();
		if (!file)
		{
			std::cerr << "Could not close file: " << filename << std::endl;
			return false;
		}

		return true;
	}
}
