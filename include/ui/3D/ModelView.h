#ifndef INCLUDE_UI_3D_MODELVIEW_H
#define INCLUDE_UI_3D_MODELVIEW_H

#include <Qt3DExtras/Qt3DWindow>
#include <QWidget>
#include <QObject>
#include <Qt3DCore/QNode>

namespace ui {
  namespace view {
    class ModelView : public QObject {
      Q_OBJECT
      Qt3DExtras::Qt3DWindow* modelView;
      QWidget* modelViewContainer;
      Qt3DCore::QEntity *rootEntity;
      
      public:
      explicit ModelView();
      ~ModelView();
      QWidget* asWidget() const;
      void loadMesh(const QString &meshFilePath);
      void loadMeshFromFile();

signals:
      void displayMeshFilePath(const QString&);
    };
  }
}
#endif /* INCLUDE_UI_3D_MODELVIEW_H */
