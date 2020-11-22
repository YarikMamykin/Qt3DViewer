#ifndef INCLUDE_UI_BUTTONS_LOADFILEBUTTON_H
#define INCLUDE_UI_BUTTONS_LOADFILEBUTTON_H

#include <QPushButton>

namespace ui {
  namespace buttons {
    class LoadFileButton : public QPushButton {
      public:
        explicit LoadFileButton(const QString& name = "Load");
        ~LoadFileButton() = default;
    };
  }
}
#endif /* INCLUDE_UI_BUTTONS_LOADFILEBUTTON_H */
