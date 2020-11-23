#include "ui/UILoader.h"
#include <QApplication>

int main( int argc, char **argv ) 
{
  QApplication application(argc,argv);
  ui::UILoader uiLoader;
  return application.exec();
}
