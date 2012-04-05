#ifndef osd_h
#define osd_h

#include <QObject>

#include <QDBusConnection>
#include <QDBusInterface>

namespace dbus2vdr
{
  class cOsd : public QObject
  {
    Q_OBJECT

  private:
    QDBusInterface *interface;

  public Q_SLOTS:
    void Open(QString osdid, int left, int top);
    void Display(QString filename, int left, int top, int vx, int vy);
    void Close(QString osdid);

  public:
    cOsd(QDBusConnection& conn);
    virtual ~cOsd(void);
  };
};
#endif
