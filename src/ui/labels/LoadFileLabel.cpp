#include "ui/labels/LoadFileLabel.h"
#include <QString>

namespace ui {
  namespace labels {
    LoadFileLabel::LoadFileLabel(const QString& name)
      : QLabel(name) { 
        this->setFixedHeight(50);
        this->setFixedWidth(300);
        this->setStyleSheet("background-color:red;");
      }
  }
}
