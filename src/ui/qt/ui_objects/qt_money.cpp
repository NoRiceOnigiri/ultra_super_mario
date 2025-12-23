#include "qt_money.hpp"

using nro::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height) 
	: Money(top_left, width, height) {}

char QtMoney::get_brush() const noexcept {
	return '$';
}
