#include "ui/3D/ModelView.h"
#include "ui/layouts/ControlElementsLayout.h"
#include <QUrl>
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
      , modelViewContainer(QWidget::createWindowContainer(modelView)) 
      , model(loadModel()) 
      , mesh(new Qt3DRender::QMesh) {

        auto material = loadMaterial();
        auto camera = loadCamera();
        // this->model = loadModel();

        loadLight(camera);
        loadCameraController(model, camera);

        this->model->addComponent(material);
        this->model->addComponent(this->mesh);
        modelView->setRootEntity(this->model);
    }

    QWidget* ModelView::asWidget() const {
      return modelViewContainer;
    }

    void ModelView::resetMesh() {
      this->model->removeComponent(this->mesh);
      delete this->mesh;
      this->mesh = new Qt3DRender::QMesh;
      this->model->addComponent(this->mesh);
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
          this->model->removeComponent(this->mesh);
          delete this->mesh;
          this->mesh = this->loadMesh(meshFilePath);
          this->model->addComponent(this->mesh);

          QFileInfo fileInfo(meshFilePath);
          emit displayMeshFilePath(fileInfo.fileName());
        }
    }
    
    Qt3DExtras::QPhongMaterial* ModelView::loadMaterial() {
        Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
        material->setDiffuse(QColor(254, 254, 254));
        return material;
    }

    Qt3DRender::QCamera* ModelView::loadCamera() {
        Qt3DRender::QCamera *camera = modelView->camera();
        camera->setViewCenter(QVector3D(0, 0, 0));
        camera->setPosition(QVector3D(0, 0, 100.0f));
        return camera;
    }

    void ModelView::loadLight(Qt3DRender::QCamera* camera) {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(camera);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("#CFB53B");
        light->setIntensity(0.8f);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0,0,0));
        lightEntity->addComponent(lightTransform);
    }

    void ModelView::loadCameraController(Qt3DCore::QEntity *model, Qt3DRender::QCamera *camera) {
        Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(model);
        camController->setCamera(camera);
    }

    Qt3DCore::QEntity* ModelView::loadModel() {
        Qt3DCore::QEntity *model = new Qt3DCore::QEntity;
        return model;
    }

   Qt3DRender::QMesh* ModelView::loadMesh(const QString &meshFilePath) {
        Qt3DRender::QMesh *mesh = new Qt3DRender::QMesh;
        QUrl data = QUrl::fromLocalFile(meshFilePath);
        mesh->setSource(data);
        return mesh;
    }

    ModelView::~ModelView() {
      delete modelViewContainer;
    }
  }
}
