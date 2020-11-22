#include "ui/layouts/ControlElementsLayout.h"
#include <QHBoxLayout>

namespace ui {
  namespace layouts {
    ControlElementsLayout::ControlElementsLayout() 
      : QVBoxLayout() 
      , loadScansLabel(new labels::LoadFileLabel)
      , selectedFileLabel(new labels::SelectedFileLabel)
      , currentFileLabel(new labels::CurrentFileLabel)
      , loadFileButton(new buttons::LoadFileButton)
      , removeModelButton(new buttons::RemoveModelButton) {

          auto buttonsLayout = new QHBoxLayout;
          buttonsLayout->addWidget(loadFileButton);
          buttonsLayout->addWidget(removeModelButton);

          this->addWidget(loadScansLabel);
          this->addLayout(buttonsLayout);
          this->addWidget(currentFileLabel);
          this->addWidget(selectedFileLabel);

          this->setSpacing(10);
          this->setAlignment(Qt::AlignTop);
      }

    buttons::RemoveModelButton* ControlElementsLayout::getRemoveModelButton() const {
      return removeModelButton;
    }
     
    labels::SelectedFileLabel* ControlElementsLayout::getSelectedFileLabel() const {
      return selectedFileLabel;
    }

    buttons::LoadFileButton* ControlElementsLayout::getLoadFileButton() const {
      return loadFileButton;
    }
  }
}
