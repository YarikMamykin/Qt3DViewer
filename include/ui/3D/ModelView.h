#ifndef INCLUDE_UI_3D_MODELVIEW_H
#define INCLUDE_UI_3D_MODELVIEW_H

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QCamera>
#include <QMesh>
#include <QWidget>
#include <QObject>

namespace ui {
  namespace view {
    class ModelView : public QObject {
      Q_OBJECT
      Qt3DExtras::Qt3DWindow* modelView;
      QWidget* modelViewContainer;
      Qt3DCore::QEntity* model;
      Qt3DRender::QMesh* mesh;
      
      Qt3DExtras::QPhongMaterial* loadMaterial();
      Qt3DRender::QCamera* loadCamera();
      void loadLight(Qt3DRender::QCamera* camera);
      void loadCameraController(Qt3DCore::QEntity *model, Qt3DRender::QCamera *camera);
      Qt3DCore::QEntity* loadModel();
      Qt3DRender::QMesh* loadMesh(const QString &meshFilePath);

      public:
      explicit ModelView();
      ~ModelView();
      QWidget* asWidget() const;
      void loadMeshFromFile();
      void resetMesh(); 

signals:
      void displayMeshFilePath(const QString&);
    };
  }
}
#endif /* INCLUDE_UI_3D_MODELVIEW_H */
