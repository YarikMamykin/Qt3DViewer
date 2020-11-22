INCLUDEPATH += $$system(pwd)/include

SOURCES += main.cpp
SOURCES += src/ui/3D/ModelView.cpp
SOURCES += src/ui/buttons/LoadFileButton.cpp
SOURCES += src/ui/buttons/RemoveModelButton.cpp
SOURCES += src/ui/labels/LoadFileLabel.cpp
SOURCES += src/ui/labels/SelectedFileLabel.cpp
SOURCES += src/ui/layouts/ControlElementsLayout.cpp
SOURCES += src/ui/layouts/WindowLayout.cpp
SOURCES += src/ui/UILoader.cpp
SOURCES += src/ui/buttons/CloseButton.cpp

HEADERS += include/ui/3D/ModelView.h
HEADERS += include/ui/buttons/LoadFileButton.h
HEADERS += include/ui/buttons/RemoveModelButton.h
HEADERS += include/ui/labels/LoadFileLabel.h
HEADERS += include/ui/labels/SelectedFileLabel.h
HEADERS += include/ui/layouts/ControlElementsLayout.h
HEADERS += include/ui/layouts/WindowLayout.h
HEADERS += include/ui/UILoader.h
HEADERS += include/ui/buttons/CloseButton.h

QT += core widgets
QT += 3dcore 3dextras 3drender 3dinput
