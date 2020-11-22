#include "ui/UILoader.h"
#include <QWidget>
#include <QObject>
#include <memory>

namespace ui {
  UILoader::UILoader()
  : window(new QWidget) { }

  void UILoader::load() {

    auto windowLayout = new layouts::WindowLayout;
    auto headerLayout = new layouts::HeaderLayout;

    setUIConnections(windowLayout, headerLayout);

    auto layout = new QVBoxLayout;
    layout->addLayout(headerLayout);
    layout->addLayout(windowLayout);

    window->setLayout(layout);
    window->setStyleSheet("background-color:black;");
    window->show();
  }

  void UILoader::setUIConnections(layouts::WindowLayout* windowLayout, layouts::HeaderLayout* headerLayout) {
    auto removeModelButton = windowLayout->getControlElementsLayout()->getRemoveModelButton();
    auto loadFileButton = windowLayout->getControlElementsLayout()->getLoadFileButton();
    auto selectedFileLabel = windowLayout->getControlElementsLayout()->getSelectedFileLabel();
    auto closeButton = headerLayout->getCloseButton();

    QObject::connect(removeModelButton, &QPushButton::pressed, windowLayout, &layouts::WindowLayout::resetModelView);
    QObject::connect(removeModelButton, &QPushButton::pressed, selectedFileLabel, &QLabel::clear);
    QObject::connect(loadFileButton, &QPushButton::pressed, windowLayout, &layouts::WindowLayout::resetAndLoadModelView);
    QObject::connect(closeButton, &QPushButton::pressed, window.get(), &QWidget::close);
  }
}
