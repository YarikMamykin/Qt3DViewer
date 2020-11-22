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

    void WindowLayout::resetModelView() {
      this->removeWidget(this->modelView->asWidget());
      delete this->modelView;
      this->modelView = new view::ModelView;
      this->addWidget(this->modelView->asWidget());
    }

    void WindowLayout::resetAndLoadModelView() {
      resetModelView();
      auto selectedFileLabel = this->getControlElementsLayout()->getSelectedFileLabel();
      QObject::connect(this->modelView, &view::ModelView::displayMeshFilePath, selectedFileLabel, &QLabel::setText);
      this->modelView->loadMeshFromFile();
    }
  }
}
