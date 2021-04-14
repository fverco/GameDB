QT += quick sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        sources/database.cpp \
        sources/game.cpp \
        sources/gameinterm.cpp \
        sources/imagedatabase.cpp \
        sources/infodatabase.cpp \
        sources/main.cpp

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
    headers/game.h \
    headers/gameinterm.h \
    headers/imagedatabase.h \
    headers/infodatabase.h
