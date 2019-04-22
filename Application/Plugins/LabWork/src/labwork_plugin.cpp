#include "labwork_plugin.h"
#include "task1.h"

#include <qqml.h>

void LabWorkPlugin::registerTypes(const char *uri)
{
    // @uri vsdt.lab.work
    qmlRegisterType<Task1>(uri, 1, 0, "Task1");
}
