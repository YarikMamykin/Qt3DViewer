#include "ui/labels/HeaderLabel.h"

namespace ui {
  namespace labels {
    HeaderLabel::HeaderLabel(const QString& name) 
      : QLabel(name) {
        const QStringList styleSheet = {
          "color: lawngreen;", 
          "background-color:black;",
        };

        this->setFixedHeight(65);
        this->setFixedWidth(310);
        this->setStyleSheet(styleSheet.join(" "));

        QFont font("Courier New");
        font.setStyleHint(QFont::Monospace);
        font.setPixelSize(32);
        font.setBold(true);

        this->setFont(font);
        // this->setFixedHeight(this->sizeHint().height());
      }
  }
}
