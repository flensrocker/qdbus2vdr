#include "qdbus2vdr.h"
#include "osd.h"

#include <QApplication>


int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QDBusConnection system = QDBusConnection::systemBus();
  dbus2vdr::cOsd osd(system);
  return app.exec();
}
