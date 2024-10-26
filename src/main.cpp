#include <iostream>

#include "FractalCreator.hpp"

int main()
{
	std::cout << "Running 'Fractals'..." << std::endl;

	const int WIDTH = 800;
	const int HEIGHT = 600;

	Fractals::FractalCreator fractalCreator(WIDTH, HEIGHT);
	fractalCreator.run();

	return 0;
}
