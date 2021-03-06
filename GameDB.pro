QT += quick sql widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        sources/gamelistmodel.cpp \
        sources/database.cpp \
        sources/developer.cpp \
        sources/developerchanges.cpp \
        sources/entry.cpp \
        sources/entrychanges.cpp \
        sources/game.cpp \
        sources/gamechanges.cpp \
        sources/gameinterm.cpp \
        sources/imagedatabase.cpp \
        sources/infodatabase.cpp \
        sources/main.cpp \
        sources/platform.cpp \
        sources/platformchanges.cpp \
        sources/publisher.cpp \
        sources/publisherchanges.cpp \
        sources/service.cpp \
        sources/servicechanges.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    GameDB_af_ZA.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    headers/database.h \
    headers/developer.h \
    headers/developerchanges.h \
    headers/entry.h \
    headers/entrychanges.h \
    headers/game.h \
    headers/gamechanges.h \
    headers/gameinterm.h \
    headers/gamelistmodel.h \
    headers/imagedatabase.h \
    headers/infodatabase.h \
    headers/platform.h \
    headers/platformchanges.h \
    headers/publisher.h \
    headers/publisherchanges.h \
    headers/service.h \
    headers/servicechanges.h
