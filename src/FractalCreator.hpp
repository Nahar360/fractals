#ifndef FRACTALCREATOR_HPP
#define FRACTALCREATOR_HPP

#include "Bitmap.hpp"
#include "Zoom.hpp"
#include "ZoomList.hpp"

#include <memory>
#include <string>

namespace Fractals
{
	class FractalCreator
	{
	private:
		int m_width;
		int m_height;

		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;

		Bitmap m_bitmap;

		ZoomList m_zoomList;

		int m_total = 0;

	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator() = default;

		void calculateIterations();
		void calculateTotalIterations();
		void drawFractal();
		void addZoom(const Zoom& zoom);
		void writeBitmap(const std::string& filename);

		void run();
	};
}

#endif // FRACTALCREATOR_HPP
