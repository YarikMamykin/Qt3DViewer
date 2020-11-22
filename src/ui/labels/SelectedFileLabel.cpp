#include "ui/labels/SelectedFileLabel.h"

namespace ui {
  namespace labels {
    SelectedFileLabel::SelectedFileLabel() 
      : QLabel() {
        this->setFixedHeight(50);
        this->setFixedWidth(300);
        this->setStyleSheet("background-color:cyan;");
      }
  }
}
