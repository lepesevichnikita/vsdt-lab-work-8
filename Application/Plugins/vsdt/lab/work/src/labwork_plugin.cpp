#include "labwork_plugin.h"

#include <qqml.h>

void LabWorkPlugin::registerTypes(const char *uri)
{
    // @uri vsdt.lab.work
    qmlRegisterType<Task1>(uri, 1, 0, "Task1");
    qmlRegisterType<Task2>(uri, 1, 0, "Task2");
}
