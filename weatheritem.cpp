#include "dde-dock/constants.h"
#include "weatheritem.h"
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <QSvgRenderer>
#include <QMouseEvent>

#define PLUGIN_STATE_KEY    "enable"

WeatherItem::WeatherItem(const ForcastApplet *wgt, QWidget *parent)
    : QWidget(parent),
    m_settings("deepin", "dde-dock-HTYWeather"),
    forcastwidget(wgt)
{
    sw = "Weather";
    temp = "Temp";
    pixmap = QPixmap(QString(":/%1/icon/%1/na.png").arg(forcastwidget->theme()));
}

bool WeatherItem::enabled()
{
    return m_settings.value(PLUGIN_STATE_KEY, true).toBool();
}

void WeatherItem::setEnabled(const bool b)
{
    m_settings.setValue(PLUGIN_STATE_KEY, b);
}

QSize WeatherItem::sizeHint() const
{
    QFontMetrics FM(qApp->font());
    QSize size;
    const Dock::DisplayMode displayMode = qApp->property(PROP_DISPLAY_MODE).value<Dock::DisplayMode>();
    if (displayMode == Dock::Efficient) {
        if(FM.boundingRect(sw).width() >= FM.boundingRect(temp).width()){
            size = FM.boundingRect(sw).size() + QSize(10,FM.boundingRect(sw).height());
        }else{
            size = FM.boundingRect(temp).size() + QSize(10,FM.boundingRect(temp).height());
        }
    }else{
        size = QPixmap(QString(":/%1/icon/%1/na.png").arg(forcastwidget->theme())).size();
    }
    return size;
}

void WeatherItem::resizeEvent(QResizeEvent *e)
{
    const auto ratio = qApp->devicePixelRatio();
    pixmap.setDevicePixelRatio(ratio);
    QWidget::resizeEvent(e);
}

void WeatherItem::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    // QWidget::paintEvent(e);
    const Dock::DisplayMode displayMode = qApp->property(PROP_DISPLAY_MODE).value<Dock::DisplayMode>();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setPen(Qt::white);
    if (displayMode == Dock::Efficient) {
        painter.drawText(rect(), Qt::AlignCenter, sw + "\n" + temp);
    } else {
        const auto ratio = qApp->devicePixelRatio();
        const int iconSize =  static_cast<int> (ratio * std::min(width(), height()));
        QPixmap qpixscaled = pixmap.scaled(iconSize, iconSize, Qt::KeepAspectRatio);
        const QRectF &rf = QRectF(rect());
        const QRectF &rfp = QRectF(qpixscaled.rect());
        painter.drawPixmap(rf.center() - rfp.center() / qpixscaled.devicePixelRatioF(),
                           qpixscaled);
    }


}
