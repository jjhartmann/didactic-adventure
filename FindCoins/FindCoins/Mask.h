#pragma once
#include "Image.h"
class Mask : public Image
{
public:
    // Create a circular mask with a given radius. 
    Mask(int radius);
    ~Mask();
};

