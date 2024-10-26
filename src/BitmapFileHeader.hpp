#ifndef BITMAPFILEHEADER_HPP
#define BITMAPFILEHEADER_HPP

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
	struct BitmapFileHeader
	{
		char header[2]{'B', 'M'}; // "BM" = Bitmap
		int32_t fileSize; // size of the file in bytes
		int32_t reserved{ 0 }; // reserved for future use
		int32_t dataOffset; // how long into the file the data actually begins
	};
	#pragma pack()
}

#endif // BITMAPFILEHEADER_HPP
