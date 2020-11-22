#ifndef INCLUDE_UI_LAYOUTS_CONTROLELEMENTSLAYOUT_H
#define INCLUDE_UI_LAYOUTS_CONTROLELEMENTSLAYOUT_H

#include <QVBoxLayout>
#include <ui/labels/LoadFileLabel.h>
#include <ui/labels/CurrentFileLabel.h>
#include <ui/labels/SelectedFileLabel.h>
#include <ui/buttons/LoadFileButton.h>
#include <ui/buttons/RemoveModelButton.h>


namespace ui {
  namespace layouts {
    class ControlElementsLayout : public QVBoxLayout {
      private:
        labels::LoadFileLabel *loadScansLabel;
        labels::SelectedFileLabel *selectedFileLabel;
        labels::CurrentFileLabel *currentFileLabel;
        buttons::LoadFileButton *loadFileButton;
        buttons::RemoveModelButton *removeModelButton;

      public:
        explicit ControlElementsLayout();
        ~ControlElementsLayout() = default;
        
        buttons::RemoveModelButton* getRemoveModelButton() const;
        labels::SelectedFileLabel* getSelectedFileLabel() const;
        buttons::LoadFileButton* getLoadFileButton() const;
    };
  }
}
#endif /* INCLUDE_UI_LAYOUTS_CONTROLELEMENTSLAYOUT_H */
