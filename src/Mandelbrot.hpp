#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

namespace Fractals
{
	class Mandelbrot
	{
	private:

	public:
		Mandelbrot() = default;
		virtual ~Mandelbrot() = default;

		/**
		* @brief Computes the number of iterations for a given point (x, y) in the Mandelbrot set.
		*
		* This function calculates how many iterations it takes for the complex number
		* corresponding to the point (x, y) to escape the Mandelbrot set. The escape
		* condition is defined as the magnitude of the complex number exceeding 2.
		*
		* @param x The real part of the complex number.
		* @param y The imaginary part of the complex number.
		* @return The number of iterations before the point escapes the Mandelbrot set.
		*/
		static int getIterations(double x, double y);

	public:
		static const int MAX_ITERATIONS = 1000;
	};
}

#endif // MANDELBROT_HPP
