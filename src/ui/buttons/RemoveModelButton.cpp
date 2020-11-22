#include "ui/buttons/RemoveModelButton.h"

namespace ui {
  namespace buttons {
    RemoveModelButton::RemoveModelButton(const QString& name)
      : QPushButton(name) { 
        this->setStyleSheet("background-color: gray;");
        this->setFixedWidth(300);
      }
  }
}
