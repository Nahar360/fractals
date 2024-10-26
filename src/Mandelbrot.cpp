#include "Mandelbrot.hpp"

#include <complex>

using namespace Fractals;

int Mandelbrot::getIterations(double x, double y)
{
	std::complex<double> z = 0;
	const std::complex<double> c(x, y);

	int iterations = 0;

	while (iterations < MAX_ITERATIONS)
	{
		z = (z * z) + c;

		if (std::abs(z) > 2)
		{
			break;
		}

		iterations++;
	}

	return iterations;
}
