#include "messagehandler.hpp"

#include <QtCore/QDateTime>
#include <iostream>

void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();

    switch (type) {
    case QtDebugMsg:
        std::cout << QDateTime::currentDateTime().toString("hh:mm:ss").toStdString() << " [DEBUG] " << context.function << ": " << localMsg.constData() << " (" << context.file << ":" << context.line << ")" << std::endl;
        break;
    case QtWarningMsg:
        std::cerr << QDateTime::currentDateTime().toString("hh:mm:ss").toStdString() << " [WARNING] " << context.function << ": " << localMsg.constData() << " (" << context.file << ":" << context.line << ")" << std::endl;
        break;
    case QtCriticalMsg:
        std::cerr << QDateTime::currentDateTime().toString("hh:mm:ss").toStdString() << " [CRITICAL] " << context.function << ": " << localMsg.constData() << " (" << context.file << ":" << context.line << ")" << std::endl;
        break;
    case QtFatalMsg:
        std::cerr << QDateTime::currentDateTime().toString("hh:mm:ss").toStdString() << " [FATAL] " << context.function << ": " << localMsg.constData() << " (" << context.file << ":" << context.line << ")" << std::endl;
        abort();
    }
}
