#include "ui/buttons/LoadFileButton.h"

namespace ui {
  namespace buttons {
    LoadFileButton::LoadFileButton(const QString& name) 
      : QPushButton(name) { 
        const QStringList styleSheet = {
          "color: white;", 
          "background-color:black;",
          "border: 1px solid gray;"
        };

        this->setFixedHeight(this->sizeHint().height());
        this->setFixedWidth(150);
        this->setStyleSheet(styleSheet.join(" "));

        QFont font("Courier New");
        font.setStyleHint(QFont::Monospace);
        font.setPixelSize(12);
        font.setBold(true);

        this->setFont(font);
        this->setMouseTracking(true);
      }

    void LoadFileButton::enterEvent( QEvent* e ) {
      this->setFocus(true);
      QWidget::enterEvent( e );
    }

    void LoadFileButton::leaveEvent( QEvent* e ) {
      this->setFocus(false);
      QWidget::leaveEvent( e );
    }

    void LoadFileButton::setFocus(bool focus) {
      if(focus)
        this->setStyleSheet(this->styleSheet().replace("gray","cyan"));
      else
        this->setStyleSheet(this->styleSheet().replace("cyan", "gray"));
    }
  }
}
