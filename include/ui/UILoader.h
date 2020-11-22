#ifndef INCLUDE_UI_UILOADER_H
#define INCLUDE_UI_UILOADER_H

#include "ui/layouts/WindowLayout.h"
#include "ui/layouts/HeaderLayout.h"
#include <Qt3DExtras/Qt3DWindow>
#include <QWidget>

namespace ui {

  /*
   * Responsible for creating UI
   */

  class UILoader {
    std::unique_ptr<QWidget> window;
    
    void setUIConnections(layouts::WindowLayout* windowLayout, layouts::HeaderLayout* headerLayout);

    public:
    UILoader();
    void load();
  };
}


#endif /* INCLUDE_UI_UILOADER_H */
