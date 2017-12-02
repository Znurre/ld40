#ifndef MAP_H
#define MAP_H

#include "IDrawable.h"

class MapTile;

class Map : public IDrawable
{
	public:
		Map();

		void addChild(IDrawable *drawable);

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		QList<IDrawable *> m_children;
};

#endif // MAP_H
