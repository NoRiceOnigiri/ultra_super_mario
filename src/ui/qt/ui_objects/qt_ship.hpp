#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "ship.hpp"

namespace nro {
	class QtShip : public Ship, public QtUIObjectRectAdapter {
		public:
			QtShip(const Coord& top_left, const int width, const int height);
			
			char get_brush() const noexcept override;
	};
}
