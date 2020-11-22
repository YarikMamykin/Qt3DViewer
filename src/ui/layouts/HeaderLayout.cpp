#include "ui/layouts/HeaderLayout.h"

namespace ui {
  namespace layouts {
    HeaderLayout::HeaderLayout() 
      : QHBoxLayout() 
      , closeButton(new buttons::CloseButton)
      , headerLabel(new labels::HeaderLabel) {
        this->addWidget(headerLabel, 0, Qt::AlignLeft);
        this->addWidget(closeButton, 0, Qt::AlignRight);
      }

    buttons::CloseButton* HeaderLayout::getCloseButton() const {
      return closeButton;
    }
  }
}
