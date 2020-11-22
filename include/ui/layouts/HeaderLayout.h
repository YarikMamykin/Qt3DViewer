#ifndef INCLUDE_UI_LAYOUTS_HEADERLAYOUT_H
#define INCLUDE_UI_LAYOUTS_HEADERLAYOUT_H

#include <QHBoxLayout>
#include "ui/buttons/CloseButton.h"
#include "ui/labels/HeaderLabel.h"

namespace ui {
  namespace layouts {
    class HeaderLayout : public QHBoxLayout {
      private:
        buttons::CloseButton* closeButton;
        labels::HeaderLabel* headerLabel;

      public:
        explicit HeaderLayout();
        ~HeaderLayout() = default;
        
      buttons::CloseButton* getCloseButton() const;
    };
  }
}

#endif /* INCLUDE_UI_LAYOUTS_HEADERLAYOUT_H */
