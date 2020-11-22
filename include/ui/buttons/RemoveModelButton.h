#ifndef INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H
#define INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H

#include <QPushButton>

namespace ui {
  namespace buttons {
    class RemoveModelButton : public QPushButton {
      public:
        explicit RemoveModelButton(const QString& name = "Remove");
        ~RemoveModelButton() = default;
    };
  }
}
#endif /* INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H */
