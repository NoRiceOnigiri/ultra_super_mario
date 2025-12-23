#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left, 
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

char QtFullBox::get_brush() const noexcept {
	if (is_active_) {
		return '?';
	} else {
		return '-';
	}
}
