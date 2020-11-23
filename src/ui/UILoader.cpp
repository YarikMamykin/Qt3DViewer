#include "ui/UILoader.h"
#include <QWidget>
#include <QObject>
#include <memory>

namespace ui {
  UILoader::UILoader()
  : window(new QWidget) { 
    auto windowLayout = new layouts::WindowLayout;
    auto headerLayout = new layouts::HeaderLayout;

    setUIConnections(windowLayout, headerLayout);

    auto layout = new QVBoxLayout;
    layout->addLayout(headerLayout);
    layout->addLayout(windowLayout);

    window->setLayout(layout);
    window->setStyleSheet("background-color:black;");
    window->showMaximized();
  }


  void UILoader::setUIConnections(layouts::WindowLayout* windowLayout, layouts::HeaderLayout* headerLayout) {
    auto removeModelButton = windowLayout->getControlElementsLayout()->getRemoveModelButton();
    auto loadFileButton = windowLayout->getControlElementsLayout()->getLoadFileButton();
    auto selectedFileLabel = windowLayout->getControlElementsLayout()->getSelectedFileLabel();
    auto closeButton = headerLayout->getCloseButton();
    auto modelView = windowLayout->getModelView();

    QObject::connect(removeModelButton, &QPushButton::pressed, modelView, &view::ModelView::resetMesh);
    QObject::connect(removeModelButton, &QPushButton::pressed, selectedFileLabel, &QLabel::clear);
    QObject::connect(loadFileButton, &QPushButton::pressed, modelView, &view::ModelView::loadMeshFromFile);
    QObject::connect(closeButton, &QPushButton::pressed, window.get(), &QWidget::close);
    QObject::connect(modelView, &view::ModelView::meshFileSelected, selectedFileLabel, &QLabel::setText);
  }
}
