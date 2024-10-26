#include "ZoomList.hpp"

using namespace Fractals;

ZoomList::ZoomList(int width, int height) :
	m_width(width), m_height(height)
{
}

void ZoomList::add(const Zoom& zoom)
{
	// add zoom to the list
	m_zooms.push_back(zoom);

	// update the center and scale
	m_xCenter += (zoom.x - (static_cast<double>(m_width) / 2)) * m_scale;
	m_yCenter += (zoom.y - (static_cast<double>(m_height) / 2)) * m_scale;

	// update the scale
	m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
	// calculate the fractal coordinates after zooming
	const double xFractal = (x - (static_cast<double>(m_width) / 2)) * m_scale + m_xCenter;
	const double yFractal = (y - (static_cast<double>(m_height) / 2)) * m_scale + m_yCenter;

	// return the new coordinates
	return std::pair<double, double>(xFractal, yFractal);
}
