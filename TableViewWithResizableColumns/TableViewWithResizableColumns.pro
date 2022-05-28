QT += quick quickcontrols2

QT_FORCE_STDERR_LOGGING = 1

SOURCES += \
        main.cpp \
        multicasttablemodel.cpp

resources.files = $$files(*.qml)
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    multicasttablemodel.h

DISTFILES += \
    ResizableColumnsTableView.qml
