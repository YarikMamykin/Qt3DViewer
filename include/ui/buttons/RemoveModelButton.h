#ifndef INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H
#define INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H

#include <QPushButton>

namespace ui {
  namespace buttons {
    class RemoveModelButton : public QPushButton {
      public:
        explicit RemoveModelButton(const QString& name = "Remove");
        ~RemoveModelButton() = default;

      protected:
          virtual void enterEvent( QEvent* e ) override;
          virtual void leaveEvent( QEvent* e ) override;

      private:
        void setFocus(bool focus);
    };
  }
}
#endif /* INCLUDE_UI_BUTTONS_REMOVEMODELBUTTON_H */
