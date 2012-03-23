#include <QtGui/QApplication>
#include "my_chat.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    my_chat foo;
    foo.show();
    return app.exec();
}
