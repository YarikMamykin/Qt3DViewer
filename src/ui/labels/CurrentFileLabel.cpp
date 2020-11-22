#include "ui/labels/CurrentFileLabel.h"
#include <QFont>

namespace ui {
  namespace labels {
    CurrentFileLabel::CurrentFileLabel(const QString& name) 
      : QLabel(name) {
        const QStringList styleSheet = {
          "color: white;", 
          "background-color:black;",
        };

        this->setFixedHeight(20);
        this->setFixedWidth(310);
        this->setStyleSheet(styleSheet.join(" "));

        QFont font("Courier New");
        font.setStyleHint(QFont::Monospace);
        font.setPixelSize(12);
        font.setBold(true);
       
        this->setFont(font);
        this->setFixedHeight(this->sizeHint().height());
    }
  }
}

