#pragma once
#include "config.h"
#include "graphics.h"

class Widget
{
protected:
	float posX, posY, width, height;
	float coords[4];
public:
	void setPosX(float x)
	{
		this->posX = x;
	}

	void setPosY(float y)
	{
		this->posY = y;
	}

	void setWidth(float w)
	{
		this->width = w;
	}

	void setHeight(float h)
	{
		this->height = h;
	}

	float getPosX()
	{
		return posX;
	}

	float getPosY()
	{
		return posY;
	}

	float getWidth()
	{
		return width;
	}

	float getHeight()
	{
		return height;
	}

	virtual void draw() = 0;
};