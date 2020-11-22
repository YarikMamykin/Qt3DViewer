#ifndef INCLUDE_UI_LABELS_SELECTEDFILELABEL_H
#define INCLUDE_UI_LABELS_SELECTEDFILELABEL_H

#include <QLabel>

namespace ui {
  namespace labels {
    class SelectedFileLabel : public QLabel {
      public:
        explicit SelectedFileLabel();
        ~SelectedFileLabel() = default;
    };
  }
}


#endif /* INCLUDE_UI_LABELS_SELECTEDFILELABEL_H */
