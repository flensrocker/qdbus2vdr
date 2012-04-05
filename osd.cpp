#include "osd.h"

#include <QPixmap>
#include <QTextStream>

using namespace dbus2vdr;

cOsd::cOsd(QDBusConnection& conn)
{
  setStyleSheet("background:transparent;");
  setAttribute(Qt::WA_TranslucentBackground);
  setWindowFlags(Qt::FramelessWindowHint);

  interface = new QDBusInterface("de.tvdr.vdr", "/OSD", "de.tvdr.vdr.osd", conn, this);
  connect(interface, SIGNAL(Open(QString, int, int)), this, SLOT(Open(QString, int, int)));
  connect(interface, SIGNAL(Display(QString, int, int, int, int)), this, SLOT(Display(QString, int, int, int, int)));
  connect(interface, SIGNAL(Close(QString)), this, SLOT(Close(QString)));

  image = new QLabel(this);
  image->setStyleSheet("background:transparent;");
  image->setAttribute(Qt::WA_TranslucentBackground);
  image->setWindowFlags(Qt::FramelessWindowHint);
  
  this->setCentralWidget(image);
}

cOsd::~cOsd(void)
{
}

void cOsd::Open(QString osdid, int left, int top)
{
  QTextStream out(stdout);
  out << "Open " << osdid << " at " << left << "," << top << endl;
  out.flush();
}

void cOsd::Display(QString filename, int left, int top, int vx, int vy)
{
  QTextStream out(stdout);
  out << "Display " << filename << " at " << left << "," << top << " at " << vx << "," << vy << endl;
  out.flush();

  QPixmap pixmap(filename);
  out << "Display w = " << pixmap.width() << ", h = " << pixmap.height() << endl;
  out.flush();
  image->setPixmap(pixmap);
}

void cOsd::Close(QString osdid)
{
  QTextStream out(stdout);
  out << "Close " << osdid << endl;
  out.flush();
}

#include "osd.moc"
