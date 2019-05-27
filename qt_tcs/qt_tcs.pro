QT += quick sql
QT += core network
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/functions/gui.cpp \
    src/functions/funcs.cpp \
    src/functions/events.cpp \
    src/classes/record.cpp \
    src/classes/database.cpp \
    src/classes/dispatcher.cpp \
    src/classes/testlistrow.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/functions/gui.hpp \
    src/functions/funcs.hpp \
    src/functions/events.hpp \
    src/classes/globals.hpp \
    src/classes/record.hpp \
    src/classes/database.hpp \
    src/classes/dispatcher.hpp \
    src/classes/testlistrow.hpp

DISTFILES +=
LIBS += -lsqlite3
