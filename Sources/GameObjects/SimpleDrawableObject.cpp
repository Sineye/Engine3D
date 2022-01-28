#include "SimpleDrawableObject.hpp"

SimpleDrawableObject::SimpleDrawableObject( std::function< void() > draw_func ) 
{
    this->draw_func = draw_func;
}

void SimpleDrawableObject::draw() 
{
    draw_func();
}
