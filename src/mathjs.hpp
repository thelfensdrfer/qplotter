#ifndef MATHJS_H
#define MATHJS_H

#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>

class MathJs
{
public:
    /**
     * Mathematische Funktionen die von QScriptEngine aufgerufen werden.
     */

    static QScriptValue sin(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue cos(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue tan(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue asin(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue acos(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue atan(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue atan2(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue sinh(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue cosh(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue tanh(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue exp(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue log(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue log10(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue pow(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue sqrt(QScriptContext *context, QScriptEngine *engine);
    static QScriptValue fabs(QScriptContext *context, QScriptEngine *engine);

    /**
     * Mathematische Konstanten die in QScriptEngine eingefügt werden.
     */

    static const double PI;
    static const double E;
};

#endif // MATHJS_H
