#include "listwidget.h"

#include <QApplication>
#include <QListWidgetItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListWidget w;

    w.show();
    return a.exec();
}
