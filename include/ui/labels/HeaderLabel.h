#ifndef INCLUDE_UI_LABELS_HEADERLABEL_H
#define INCLUDE_UI_LABELS_HEADERLABEL_H

#include <QLabel>

namespace ui {
  namespace labels {
    class HeaderLabel : public QLabel {
      public:
        explicit HeaderLabel(const QString& name = "Qt3DViewer");
        ~HeaderLabel() = default;
    };
  }
}



#endif /* INCLUDE_UI_LABELS_HEADERLABEL_H */
