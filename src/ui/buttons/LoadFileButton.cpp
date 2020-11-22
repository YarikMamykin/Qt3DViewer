#include "ui/buttons/LoadFileButton.h"

namespace ui {
  namespace buttons {
    LoadFileButton::LoadFileButton(const QString& name) 
      : QPushButton(name) { 
        this->setStyleSheet("background-color: gray;");
        this->setFixedWidth(300);
      }
  }
}
