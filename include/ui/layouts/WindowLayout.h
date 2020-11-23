#ifndef INCLUDE_UI_LAYOUTS_WINDOWLAYOUT_H
#define INCLUDE_UI_LAYOUTS_WINDOWLAYOUT_H

#include <QHBoxLayout>
#include <Qt3DExtras/Qt3DWindow>
#include <QWidget>
#include "ui/layouts/ControlElementsLayout.h"
#include "ui/3D/ModelView.h"

namespace ui {
  namespace layouts {
    class WindowLayout : public QHBoxLayout {
      ControlElementsLayout *controlElementsLayout;
      view::ModelView* modelView;

      public:
        explicit WindowLayout();
        ~WindowLayout() = default;
        ControlElementsLayout* getControlElementsLayout() const;
        view::ModelView* getModelView() const;
    };
  }
}
#endif /* INCLUDE_UI_LAYOUTS_WINDOWLAYOUT_H */
