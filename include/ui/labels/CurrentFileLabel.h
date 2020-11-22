#ifndef INCLUDE_UI_LABELS_CURRENTFILELABEL_H
#define INCLUDE_UI_LABELS_CURRENTFILELABEL_H

#include <QLabel>

namespace ui {
  namespace labels {
    class CurrentFileLabel : public QLabel {
      public:
        CurrentFileLabel(const QString& name = "Current file: ");
        ~CurrentFileLabel() = default;
    };
  }
}

#endif /* INCLUDE_UI_LABELS_CURRENTFILELABEL_H */
