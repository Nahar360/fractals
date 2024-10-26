#include "FractalCreator.hpp"

#include "Mandelbrot.hpp"

#include <filesystem>
#include <iostream>

using namespace Fractals;

FractalCreator::FractalCreator(int width, int height) :
	m_width(width),
	m_height(height),
	m_histogram(new int[Mandelbrot::MAX_ITERATIONS]),
	m_fractal(new int[width * height]),
	m_bitmap(width, height),
	m_zoomList(width, height),
	m_total(0)
{
	// initialising m_histogram with zeros
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_histogram[i] = 0;
	}

	// initialising m_fractal with zeros
	for (int i = 0; i < m_width * m_height; i++)
	{
		m_fractal[i] = 0;
	}

	// default zoom
	addZoom(Zoom(width / 2, height / 2, 4.0 / width));
}

void FractalCreator::calculateIterations()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			// get the coordinates after zooming
			const std::pair<double, double> coords = m_zoomList.doZoom(x, y);
			// get the number of iterations for the given coordinates
			const int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			// if the number of iterations is not the maximum number of iterations, increment the histogram
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				m_histogram[iterations]++;
			}

			// store the number of iterations for the given coordinates
			m_fractal[y * m_width + x] = iterations;
		}
	}
}

void FractalCreator::calculateTotalIterations()
{
	// calculate the total number of iterations
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total += m_histogram[i];
	}
}

void FractalCreator::drawFractal()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			// default colour
			const uint8_t red = 100;
			uint8_t green = 0;
			const uint8_t blue = 200;

			const int iterations = m_fractal[y * m_width + x];
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				// colouring the fractal
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++)
				{
					hue += (static_cast<double>(m_histogram[i]) / m_total);
				}

				green = hue * 255;
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom)
{
	// add zoom to the list
	m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(const std::string& filename)
{
	// write the bitmap file
	if (m_bitmap.write(filename))
	{
		std::cout << "Fractal created successfully: " << filename << std::endl;
	}
	else
	{
		std::cerr << "Failed to create fractal: " << filename << std::endl;
	}
}

void FractalCreator::run()
{
	// add zooms
	addZoom(Zoom(295, m_height - 202, 0.1));
	addZoom(Zoom(312, m_height - 304, 0.1));

	calculateIterations();
	calculateTotalIterations();
	drawFractal();

	// create ./images directory if it doesn't exist
	std::filesystem::create_directory("./images");

	writeBitmap("./images/fractal.bmp");
}
