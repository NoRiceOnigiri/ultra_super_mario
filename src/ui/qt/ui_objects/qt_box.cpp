#include "qt_box.hpp"

using nro::QtBox;

QtBox::QtBox(const Coord& top_left, const int width, const int height) 
	: Box(top_left, width, height) {}

char QtBox::get_brush() const noexcept {
	return '-';
}
