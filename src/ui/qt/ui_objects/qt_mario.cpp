#include "qt_mario.hpp"

using biv::QtMario;

QtMario::QtMario(const Coord& top_left, const int width, const int height) 
	: Mario(top_left, width, height) {}

char QtMario::get_brush() const noexcept {
	return '@';
}
