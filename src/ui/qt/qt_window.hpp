#pragma once

#include "qt_game_map.hpp"
#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QVBoxLayout>
#include <QKeyEvent>

namespace biv {
    class SuperMarioWindow : public QMainWindow {
        Q_OBJECT
        public:
            SuperMarioWindow(QWidget *parent = nullptr);

            void set_game_map(QtGameMap* game_map);
            void refresh_image();

            std::string get_last_pressed_key();
        protected:
            void keyPressEvent(QKeyEvent *event) override;
            void paintEvent(QPaintEvent *event) override;
        private:
            QtGameMap* game_map;

            int height;
            int width;
            QImage image;
            std::string last_pressed_key = "";
    };
}
