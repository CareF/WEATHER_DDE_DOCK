#ifndef FORCASTWIDGET_H
#define FORCASTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSettings>

class ForcastWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ForcastWidget(QString theme="hty", QWidget *parent = nullptr);
    void setTheme(const QString& theme);
    const QString& theme() const {return themeName;}

private:
    QVBoxLayout *m_centralLayout;
    QWidget *m_centralWidget;
    QLabel *labelCity, *labelRT, *labelDate[6], *labelWImg[6], *labelTemp[6];
    QString translateWeather(QString s);
    QSettings m_settings;
    QString themeName;

public slots:
    void updateWeather();

signals:
    void weatherNow(QString weather, QString temp, QString stip, QPixmap pixmap);

};

#endif // FORCASTWIDGET_H
