#ifndef INCLUDE_UI_LABELS_LOADFILELABEL_H
#define INCLUDE_UI_LABELS_LOADFILELABEL_H

#include <QLabel>

namespace ui {
  namespace labels {
    class LoadFileLabel : public QLabel {
      public:
        LoadFileLabel(const QString& name = "Load scans");
        ~LoadFileLabel() = default;
    };
  }
}

#endif /* INCLUDE_UI_LABELS_LOADFILELABEL_H */
