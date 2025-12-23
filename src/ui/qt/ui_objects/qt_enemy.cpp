#include "qt_enemy.hpp"

using nro::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height) {}

char QtEnemy::get_brush() const noexcept {
	return 'e';
}
