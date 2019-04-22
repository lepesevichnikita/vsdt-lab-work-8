#ifndef TASK1_PLUGIN_H
#define TASK1_PLUGIN_H

#include <QQmlExtensionPlugin>

class LabWorkPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri) override;
};

#endif // TASK1_PLUGIN_H
