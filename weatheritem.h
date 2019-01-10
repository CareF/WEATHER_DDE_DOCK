#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QSettings>
#include "forcastapplet.h"

class WeatherItem : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherItem(const ForcastApplet *wgt, QWidget *parent = nullptr);
    bool enabled();
    void setEnabled(const bool b);
    QString sw, temp;
    QPixmap pixmap;

signals:
    void requestUpdateGeometry() const;

public slots:

private:
    QSize sizeHint() const;
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
    QSettings m_settings;
    const ForcastApplet *forcastwidget;
};

#endif // WEATHERWIDGET_H
