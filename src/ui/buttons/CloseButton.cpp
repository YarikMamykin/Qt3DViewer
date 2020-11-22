#include "ui/buttons/CloseButton.h"
#include <QPixmap>

namespace ui {
  namespace buttons {
    CloseButton::CloseButton()
      : QPushButton() { 
        auto icon = QIcon("./close_icon.jpg");
        auto iconSize = QSize(65, 65);
        this->setIcon(icon);
        this->setIconSize(iconSize);
        this->setFixedSize(iconSize);
        this->setMouseTracking(true);
        this->setFocus(false);
      }

    void CloseButton::enterEvent( QEvent* e ) {
      this->setFocus(true);
      QWidget::enterEvent( e );
    }

    void CloseButton::leaveEvent( QEvent* e ) {
      this->setFocus(false);
      QWidget::leaveEvent( e );
    }

    void CloseButton::setFocus(bool focus) {
      if(focus)
        this->setStyleSheet("border: 1px solid cyan;");
      else
        this->setStyleSheet("border: 1px solid black;");
    }
  }
}
