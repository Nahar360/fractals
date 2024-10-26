#ifndef BITMAPINFOHEADER_HPP
#define BITMAPINFOHEADER_HPP

#include <cstdint>

namespace Fractals
{
	/*
	#pragma pack(2):
	This directive tells the compiler to align the members of the structure on 2-byte boundaries.
	This means that the compiler will not add any padding between members that are already aligned on 2-byte boundaries, ensuring that the structure's size in memory matches the expected size in the file format.

	Example:
	struct Example
	{
		char a;    // 1 byte
		int b;     // 4 bytes
	};

	- Without #pragma pack, the compiler might add padding between a and b to align b on a 4-byte boundary:
	  | a (1 byte) | padding (3 bytes) | b (4 bytes) |
	  The total size of the structure would be 8 bytes instead of the expected 5 bytes.
	
	- With #pragma pack(2), the compiler aligns the members on 2-byte boundaries:
	  | a (1 byte) | padding (1 byte) | b (4 bytes) |
	  The total size of the structure would be 6 bytes, reducing unnecessary padding.
	*/

	// Ensures that the structure is packed correctly to avoid padding issues, making sure the size of the structure in memory matches the expected size in the BMP file format (40 bytes).
	// This alignment is crucial for correctly writing and reading binary data to and from files, ensuring compatibility with the BMP file format specification.
	#pragma pack(2)
	struct BitmapInfoHeader
	{
		// int32_t = 4 bytes * 9 = 36
		// int16_t = 2 bytes * 2 = 4
		// actual size of the struct = 36 + 4 = 40 bytes
		int32_t headerSize{ 40 };

		int32_t width; // width of bitmap
		int32_t height; // height of bitmap
		int16_t planes{ 1 };
		int16_t bitsPerPixel{ 24 }; // 1 byte per pixel (R, G, B)
		int32_t compression{ 0 }; // no compression
		int32_t dataSize{ 0 }; // the size of the data written to the bitmap file
		int32_t horizontalResolution{ 2400 }; // 2400 bits per pixel
		int32_t verticalResolution{ 2400 }; // 2400 bits per pixel
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };
	};
	#pragma pack()
}

#endif // BITMAPINFOHEADER_HPP
