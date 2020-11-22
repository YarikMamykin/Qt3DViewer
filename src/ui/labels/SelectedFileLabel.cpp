#include "ui/labels/SelectedFileLabel.h"

namespace ui {
  namespace labels {
    SelectedFileLabel::SelectedFileLabel() 
      : QLabel() {
        const QStringList styleSheet = {
          "color: #C8C8C8;", 
          "background-color:black;",
          "border: 1px solid white;",
          "border-color: gray;"
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
