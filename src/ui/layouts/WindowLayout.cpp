#include "ui/layouts/WindowLayout.h"
#include "ui/3D/ModelView.h"

namespace ui {
  namespace layouts {
    WindowLayout::WindowLayout()
      : QHBoxLayout() 
        , controlElementsLayout(new layouts::ControlElementsLayout) 
        , modelView(new view::ModelView) {
          this->addLayout(controlElementsLayout);
          this->addWidget(modelView->asWidget());
        }

    ControlElementsLayout* WindowLayout::getControlElementsLayout() const {
      return controlElementsLayout;
    }

    view::ModelView* WindowLayout::getModelView() const {
      return modelView;
    }
  }
}
