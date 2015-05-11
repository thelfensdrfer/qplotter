#include "mathjs.hpp"
#include "math.h"

const double MathJs::PI = 3.14159265358979323846;
const double MathJs::E = 2.7182818284590452354;

QScriptValue MathJs::sin(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function sin");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function sin has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::sin((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::cos(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function cos");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function cos has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::cos((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::tan(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function tan");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function tan has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::tan((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::asin(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function asin");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function asin has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::asin((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::acos(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function acos");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function acos has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::acos((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::atan(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function atan");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function atan has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::atan((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::atan2(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 2) {
        qWarning("Wrong number of parameters for function atan2");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function atan2 has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::atan2((double) context->argument(0).toNumber(), (double) context->argument(1).toNumber()));
}

QScriptValue MathJs::sinh(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function sinh");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function sinh has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::sinh((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::cosh(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function cosh");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function cosh has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::cosh((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::tanh(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function tanh");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function tanh has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::tanh((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::exp(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function exp");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function exp has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::sin((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::log(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function log");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function log has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::log((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::log10(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function log10");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function log10 has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::log10((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::pow(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 2) {
        qWarning("Wrong number of parameters for function pow");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function pow has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::pow((double) context->argument(0).toNumber(), (double) context->argument(1).toNumber()));
}

QScriptValue MathJs::sqrt(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function sqrt");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function sqrt has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::sqrt((double) context->argument(0).toNumber()));
}

QScriptValue MathJs::fabs(QScriptContext *context, QScriptEngine *engine)
{
    if (context->argumentCount() != 1) {
        qWarning("Wrong number of parameters for function fabs");
        return QScriptValue::NullValue;
    }

    if (!context->argument(0).isNumber()) {
        qWarning("Argument for function fabs has to be a number!");
        return QScriptValue::NullValue;
    }

    return QScriptValue(engine, ::fabs((double) context->argument(0).toNumber()));
}
