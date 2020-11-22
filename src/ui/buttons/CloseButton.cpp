#include "ui/buttons/CloseButton.h"

namespace ui {
  namespace buttons {
    CloseButton::CloseButton(const QString& name)
      : QPushButton(name) { 
        this->setStyleSheet("background-color: gray;");
        this->setFixedWidth(60);
        this->setFixedHeight(50);
      }
  }
}
