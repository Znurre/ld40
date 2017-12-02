#ifndef MAP_H
#define MAP_H

#include "IDrawable.h"

class MapTile;

class Map : public IDrawable
{
	public:
		Map();

		void addMapTile(MapTile *mapTile);

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		QList<MapTile *> m_tiles;
};

#endif // MAP_H
