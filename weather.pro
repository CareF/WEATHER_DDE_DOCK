QT              += widgets svg network
TEMPLATE         = lib
CONFIG          += plugin c++11 link_pkgconfig
PKGCONFIG       += dtkwidget

#TARGET          = $$qtLibraryTarget(datetime)
TARGET           = HTYWeather
#DESTDIR          = $$_PRO_FILE_PWD_/../
DISTFILES       += weather.json

HEADERS += \
    weatherplugin.h \
    weatherwidget.h \
    forcastapplet.h

SOURCES += \
    weatherplugin.cpp \
    weatherwidget.cpp \
    forcastapplet.cpp

target.path = $${PREFIX}/lib/dde-dock/plugins/
INSTALLS += target

RESOURCES += res.qrc
