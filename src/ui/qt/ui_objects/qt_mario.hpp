#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "mario.hpp"

namespace nro {
	class QtMario : public Mario, public QtUIObjectRectAdapter {
		public:
			QtMario(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
