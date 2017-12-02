#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <QPainter>

class IDrawable
{
	public:
		virtual void draw(QPainter *painter) = 0;
		virtual void update(long delta) = 0;
};

#endif // IDRAWABLE_H
