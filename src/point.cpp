#include "point.hpp"

double Point::x() const
{
    return this->_x;
}


double Point::y() const
{
    return this->_y;
}


QString Point::description() const
{
    return this->_description;
}
