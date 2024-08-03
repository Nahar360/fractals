#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <cstdint>
#include <memory>
#include <string>

namespace Fractals
{
	class Bitmap
	{
	private:
		int m_width{ 0 };
		int m_height{ 0 };

		std::unique_ptr<uint8_t[]> m_pPixels{ nullptr }; // no need to delete it in the destructor

	public:
		Bitmap(int width, int height);
		virtual ~Bitmap() = default;

		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
		bool write(std::string filename);
	};
}

#endif // BITMAP_HPP
