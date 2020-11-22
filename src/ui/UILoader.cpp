#include "ui/UILoader.h"
#include "ui/layouts/ControlElementsLayout.h"
#include "ui/layouts/WindowLayout.h"
#include "ui/buttons/CloseButton.h"
#include <QWidget>
#include <QObject>
#include <memory>

namespace ui {
  UILoader::UILoader()
  : window(new QWidget) { }

  void UILoader::load() {
    auto closeButtonLayout = new QHBoxLayout;
    closeButtonLayout->setAlignment(Qt::AlignRight);
    auto closeButton = new buttons::CloseButton;
    closeButtonLayout->addWidget(closeButton);

    QObject::connect(closeButton, &QPushButton::pressed, window.get(), &QWidget::close);

    auto windowLayout = new layouts::WindowLayout;
    setUIConnections(windowLayout);

    auto allLayout = new QVBoxLayout;
    allLayout->addLayout(closeButtonLayout);
    allLayout->addLayout(windowLayout);

    window->setLayout(allLayout);
    window->setStyleSheet("background-color:black;");
    window->show();
  }

  void UILoader::setUIConnections(layouts::WindowLayout* windowLayout) {
    auto removeModelButton = windowLayout->getControlElementsLayout()->getRemoveModelButton();
    auto loadFileButton = windowLayout->getControlElementsLayout()->getLoadFileButton();
    auto selectedFileLabel = windowLayout->getControlElementsLayout()->getSelectedFileLabel();

    QObject::connect(removeModelButton, &QPushButton::pressed, windowLayout, &layouts::WindowLayout::resetModelView);
    QObject::connect(removeModelButton, &QPushButton::pressed, selectedFileLabel, &QLabel::clear);
    QObject::connect(loadFileButton, &QPushButton::pressed, windowLayout, &layouts::WindowLayout::resetAndLoadModelView);
  }
}
