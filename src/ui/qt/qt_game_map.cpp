#include "qt_game_map.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>

using nro::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width) 
	: GameMap(height, width) {

	map = new char*[height];
	for (int i = 0; i < height; i++) {
		map[i] = new char[width + 1];
	}
		
	clear();
}

QtGameMap::~QtGameMap() {
	for (int i = 0; i < height; i++) {
		delete [] map[i];
	}
	delete [] map;
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {
	// Воздух
	for (int i = 0; i < width; i++) {
		map[0][i] = ' ';
	}
	map[0][width] = '\0';
	
	for (int i = 1; i < height - 3; i++) {
		std::sprintf(map[i], map[0]);
	}
	
	// Вода
	for (int i = 0; i < width; i++) {
		map[height - 3][i] = '~';
	}
	map[height - 3][width] = '\0';
	
	for (int i = height - 2; i < height; i++) {
		std::sprintf(map[i], map[height - 3]);
	}
}

void QtGameMap::refresh() noexcept {
	clear();
	
	for (QtUIObject* obj: objs) {
		int left = obj->get_left();
		int top = obj->get_top();
		int right = obj->get_right();
		int bottom = obj->get_bottom();
		
		char brush = obj->get_brush();
		
		for (int i = left; i < right; i++) {
			for (int j = top; j < bottom; j++) {
				if (is_on_map(i, j)) {
					map[j][i] = brush;
				}
			}
		}
	}
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
}

void QtGameMap::show() const noexcept {
	for (int i = 0; i < height; i++) {
		std::cout << map[i];
	}
}
