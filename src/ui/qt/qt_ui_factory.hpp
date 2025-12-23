#pragma once

#include "qt_box.hpp"
#include "qt_enemy.hpp"
#include "qt_full_box.hpp"
#include "qt_game_map.hpp"
#include "qt_mario.hpp"
#include "qt_money.hpp"
#include "qt_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
	class QtUIFactory : public UIFactory {
		private:
			QtGameMap* game_map = nullptr;
			std::vector<QtBox*> boxes;
			std::vector<QtFullBox*> full_boxes;
			std::vector<QtShip*> ships;
			QtMario* mario = nullptr;
			std::vector<QtEnemy*> enemies;
			std::vector<QtMoney*> moneys;

		public:
			QtUIFactory(Game* game);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			QtGameMap* get_game_map();
			Mario* get_mario() override;
			
		private:
			virtual void create_game_map() override;
	};
}
