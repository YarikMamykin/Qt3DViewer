#include "ui/labels/LoadFileLabel.h"
#include <QString>
#include <QFont>
#include <QStringList>

namespace ui {
  namespace labels {
    LoadFileLabel::LoadFileLabel(const QString& name)
      : QLabel(name) { 
        const QStringList styleSheet = {
          "color: #FF8C00;", 
          "background-color:black;",
        };

        this->setFixedWidth(310);
        this->setStyleSheet(styleSheet.join(" "));

        QFont font("Courier New");
        font.setStyleHint(QFont::Monospace);
        font.setPixelSize(15);
        font.setBold(true);

        this->setFont(font);
        this->setFixedHeight(this->sizeHint().height());
      }
  }
}
