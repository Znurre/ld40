#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <QPainter>

const int TILE_SIZE = 16;
const int MAP_SIZE = 50;

class IDrawable
{
	public:
		virtual void draw(QPainter &painter) = 0;
		virtual void update(long delta) = 0;
};

#endif // IDRAWABLE_H
