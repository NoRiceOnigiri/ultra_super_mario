#include <iostream>
#include <conio.h>

#include "qt_window.hpp"

using biv::SuperMarioWindow;

SuperMarioWindow::SuperMarioWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    label = new QLabel(this);
   
    layout->addWidget(label);
    setCentralWidget(centralWidget);
    resize(300, 200);

    updateDisplay();
}

void SuperMarioWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        if (score < 5) score++;
    } 
    else if (event->key() == Qt::Key_S) {
        if (score > 1) score--;
    }

    updateDisplay();
}

void SuperMarioWindow::updateDisplay() {
    QString text = QString("Score: %1").arg(score);

    label->setText(text);
}