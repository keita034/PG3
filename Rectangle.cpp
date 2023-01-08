#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() :
	width(0), height(0)
{
}

Rectangle::Rectangle(const float& width, const float& height) :
	width(width), height(height)
{
}


void Rectangle::Draw()
{
	float area = width * height;
	printf("矩形の面積は%f平方センチメートル\n", area);
}

float Rectangle::GetSize()
{
	return width * height;
}
