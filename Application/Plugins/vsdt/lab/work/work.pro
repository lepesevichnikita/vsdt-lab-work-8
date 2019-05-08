TEMPLATE = lib
TARGET = work
QT += qml quick
CONFIG += plugin c++17

TARGET = $$qtLibraryTarget($$TARGET)
uri = vsdt.lab.work

INCLUDEPATH += src \
               include
# Input
SOURCES += \
        src/task2.cpp \
        src/labwork_plugin.cpp \
        src/task1.cpp

HEADERS += \
        include/labwork_plugin.h \
        include/task1.h \
        include/task2.h

DISTFILES = qmldir

RESOURCES +=

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

OTHER_FILES += README.md

qmldir.files = qmldir

defineReplace(libNameByTarget) {
  targetName = $$1
  result += lib $$targetName .so
  result = $$join(result)
  return($$result)
}

android {
  libPath = $$[QT_INSTALL_PREFIX]/libs/$$ANDROID_TARGET_ARCH
  libName = $$libNameByTarget($$TARGET)
  libFullPath += $$libPath $$libName
  libFullPath = $$join(libFullPath, /)

  libCopyPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
  libCopyName = $$libName
  libCopyFullPath += $$libCopyPath $$libCopyName
  libCopyFullPath = $$join(libCopyFullPath, /)

  target.extra = $$QMAKE_COPY_FILE $$libName $$libCopyFullPath
}

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
