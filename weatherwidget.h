#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QSettings>
#include "forcastwidget.h"

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(const ForcastWidget *wgt, QWidget *parent = nullptr);
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
    const ForcastWidget *forcastwidget;
};

#endif // WEATHERWIDGET_H
