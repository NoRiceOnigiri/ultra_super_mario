#include "qt_ship.hpp"

using nro::QtShip;

QtShip::QtShip(const Coord& top_left, const int width, const int height) 
	: Ship(top_left, width, height) {}

char QtShip::get_brush() const noexcept {
	return '#';
}
