#ifndef INCLUDE_UI_BUTTONS_CLOSEBUTTON_H
#define INCLUDE_UI_BUTTONS_CLOSEBUTTON_H

#include <QPushButton>

namespace ui {
  namespace buttons {
    class CloseButton : public QPushButton {
      public:
        explicit CloseButton (const QString& name = "Close");
        ~CloseButton() = default;
    };
  }
}
#endif /* INCLUDE_UI_BUTTONS_CLOSEBUTTON_H */
