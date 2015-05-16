#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include <QtCore/QtGlobal>
#include <QtCore/QString>

void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // MESSAGEHANDLER_HPP
