#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>

namespace biv {
    class SuperMarioWindow : public QMainWindow {
        public:
            SuperMarioWindow(QWidget *parent = nullptr);
        protected:
            void keyPressEvent(QKeyEvent *event) override;
        private:
            int score = 0;
            QLabel *label;
            void updateDisplay();
    };
}