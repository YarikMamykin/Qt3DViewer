#include "ui/3D/ModelView.h"
#include "ui/layouts/ControlElementsLayout.h"
#include <QUrl>
#include <QMesh>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QOrbitCameraController>
#include <QFileDialog>
#include <QFileInfo>
#include <memory>

namespace ui {
  namespace view {
    ModelView::ModelView()
      : modelView(new Qt3DExtras::Qt3DWindow) 
      , modelViewContainer(QWidget::createWindowContainer(modelView)) {
    }

    QWidget* ModelView::asWidget() const {
      return modelViewContainer;
    }

    void ModelView::loadMeshFromFile() {
        std::unique_ptr<QFileDialog> selectDialog(new QFileDialog);
        selectDialog->setFileMode(QFileDialog::AnyFile);
        selectDialog->setNameFilter("Mesh file *.stl");
        selectDialog->setViewMode(QFileDialog::Detail);

        QString meshFilePath;
        if(selectDialog->exec()) { 
          meshFilePath = selectDialog->selectedFiles()[0];
        }

        if(!meshFilePath.isEmpty()) {
          this->loadMesh(meshFilePath);

          QFileInfo fileInfo(meshFilePath);
          emit displayMeshFilePath(fileInfo.fileName());
        }
    }

    void ModelView::loadMesh(const QString &meshFilePath) {
        QUrl data = QUrl::fromLocalFile(meshFilePath);

        rootEntity = new Qt3DCore::QEntity;
        
        Qt3DCore::QEntity *flyingwedge = new Qt3DCore::QEntity(rootEntity);

        Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
        material->setDiffuse(QColor(254, 254, 254));

        Qt3DRender::QMesh *flyingwedgeMesh = new Qt3DRender::QMesh;
        flyingwedgeMesh->setMeshName("FlyingWedge");
        flyingwedgeMesh->setSource(data);
        flyingwedge->addComponent(flyingwedgeMesh);
        flyingwedge->addComponent(material);

        Qt3DRender::QCamera *camera = modelView->camera();
        camera->setViewCenter(QVector3D(0, 0, 0));
        camera->setPosition(QVector3D(0, 0, 100.0f));

        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(camera);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("purple");
        light->setIntensity(0.8f);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0,0,0));
        lightEntity->addComponent(lightTransform);

        Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
        camController->setCamera(camera);

        modelView->setRootEntity(rootEntity);
        modelView->show();
    }

    ModelView::~ModelView() {
      delete modelViewContainer;
    }
  }
}
