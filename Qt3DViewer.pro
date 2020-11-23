INCLUDEPATH += $$PWD/include

SOURCES += ./main.cpp
SOURCES += ./src/ui/3D/ModelView.cpp
SOURCES += ./src/ui/buttons/LoadFileButton.cpp
SOURCES += ./src/ui/buttons/RemoveModelButton.cpp
SOURCES += ./src/ui/labels/LoadFileLabel.cpp
SOURCES += ./src/ui/labels/SelectedFileLabel.cpp
SOURCES += ./src/ui/labels/HeaderLabel.cpp
SOURCES += ./src/ui/labels/CurrentFileLabel.cpp
SOURCES += ./src/ui/layouts/ControlElementsLayout.cpp
SOURCES += ./src/ui/layouts/WindowLayout.cpp
SOURCES += ./src/ui/layouts/HeaderLayout.cpp
SOURCES += ./src/ui/UILoader.cpp
SOURCES += ./src/ui/buttons/CloseButton.cpp

HEADERS += ./include/ui/3D/ModelView.h
HEADERS += ./include/ui/buttons/LoadFileButton.h
HEADERS += ./include/ui/buttons/RemoveModelButton.h
HEADERS += ./include/ui/labels/LoadFileLabel.h
HEADERS += ./include/ui/labels/SelectedFileLabel.h
HEADERS += ./include/ui/labels/HeaderLabel.h
HEADERS += ./include/ui/labels/CurrentFileLabel.h
HEADERS += ./include/ui/layouts/ControlElementsLayout.h
HEADERS += ./include/ui/layouts/WindowLayout.h
HEADERS += ./include/ui/layouts/HeaderLayout.h
HEADERS += ./include/ui/UILoader.h
HEADERS += ./include/ui/buttons/CloseButton.h

QT += core widgets
QT += 3dcore 3dextras 3drender 3dinput

install_it.path = $$OUT_PWD/debug
install_it.files += ./additional/close_icon.jpg
INSTALLS += install_it
