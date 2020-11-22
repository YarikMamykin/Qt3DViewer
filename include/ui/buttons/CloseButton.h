#ifndef INCLUDE_UI_BUTTONS_CLOSEBUTTON_H
#define INCLUDE_UI_BUTTONS_CLOSEBUTTON_H

#include <QPushButton>
#include <QEvent>

namespace ui {
  namespace buttons {
    class CloseButton : public QPushButton {
      public:
        explicit CloseButton ();
        ~CloseButton() = default;

      protected:
          virtual void enterEvent( QEvent* e ) override;
          virtual void leaveEvent( QEvent* e ) override;

      private:
        void setFocus(bool focus);
    };
  }
}
#endif /* INCLUDE_UI_BUTTONS_CLOSEBUTTON_H */
