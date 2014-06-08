#include <QDebug>
#include <typeinfo>

#define FUNCTION qDebug() << __DATE__ << ";" << typeid(this).name() << ";" << __FUNCTION__;
#define DEBUG qDebug() << __FUNCTION__ << ";"
