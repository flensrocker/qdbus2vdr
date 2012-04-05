#ifndef osd_h
#define osd_h

#include <QMainWindow>
#include <QLabel>

#include <QDBusConnection>
#include <QDBusInterface>

namespace dbus2vdr
{
  class cOsd : public QMainWindow
  {
    Q_OBJECT

  private:
    QDBusInterface *interface;

    QLabel *image;

  public slots:
    void Open(QString osdid, int left, int top);
    void Display(QString filename, int left, int top, int vx, int vy);
    void Close(QString osdid);

  public:
    cOsd(QDBusConnection& conn);
    virtual ~cOsd(void);
  };
};
#endif
