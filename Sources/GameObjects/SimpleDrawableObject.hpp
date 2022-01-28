#pragma once

#include "DrawableObject.hpp"

#include <functional>

class SimpleDrawableObject : public DrawableObject
{
private:
    std::function< void() > draw_func;

public:
    SimpleDrawableObject( std::function< void() > draw_func );

    void draw() override;
};