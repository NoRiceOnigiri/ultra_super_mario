#pragma once

#include <vector>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"

namespace nro {
	class QtGameMap : public GameMap {
		private:
			char** map;
			
			std::vector<QtUIObject*> objs;
			
		public:
			QtGameMap(const int height, const int width);
			~QtGameMap();
			
			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;
	};
}
