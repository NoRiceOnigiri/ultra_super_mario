#include <iostream>
#include <conio.h>

#include <QPainter>
#include <QImage>

#include "qt_window.hpp"

using biv::SuperMarioWindow;

SuperMarioWindow::SuperMarioWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    setCentralWidget(centralWidget);
    resize(1480, 1200);
}

void SuperMarioWindow::set_game_map(QtGameMap* game_map) {
    this->game_map = game_map;
}

void SuperMarioWindow::refresh_image() {
    char** map = game_map->get_map();
    int height = game_map->get_height();
    int width = game_map->get_width();

    QImage new_image(width, height, QImage::Format_RGB32);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::string hex;
            switch (map[y][x]) {
                case '@': // Марио
                    hex = "#ee0000";
                    break;
                case 'e': // Враг
                    hex = "#7128e6";
                    break;
                case '$': // Монетка
                    hex = "#ffee00";
                    break;
                case '-': // Кирпич
                    hex = "#d06f00";
                    break;
                case '?': // Кирпич-деньга
                    hex = "#ffa600";
                    break;
                case '~': // Волны
                    hex = "#0567b7";
                    break;
                case '#': // Корабль(земля)
                    hex = "#00a521";
                    break;
                case ' ': // Небо
                    hex = "#7cd6f5";
                    break;
                default:  // Дефолт
                    hex = "#ffffff";
                    break;
		    }
		

            QColor color(QString::fromStdString(hex));
            new_image.setPixelColor(x, y, color);
        }
    }

    image = new_image;
    this->update(); 
}

void SuperMarioWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        last_pressed_key = "A";
    } else if (event->key() == Qt::Key_D) {
        last_pressed_key = "D";
    } else if (event->key() == Qt::Key_Space) {
        last_pressed_key = "Space";
    } else if (event->key() == Qt::Key_Escape) {
        last_pressed_key = "Esc";
    }
}

std::string SuperMarioWindow::get_last_pressed_key() {
    std::string to_return = last_pressed_key;
    last_pressed_key = "";
    return to_return;
}

void SuperMarioWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (!image.isNull()) {
        QRect targetRect(10, 10, image.width()*12, image.height()*12);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, false);
        painter.drawImage(targetRect, image);
        painter.setPen(Qt::black);
        painter.drawRect(targetRect);
    }
}