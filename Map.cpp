#include "Map.h"
#include "MapTile.h"

Map::Map()
{
}

void Map::addMapTile(MapTile *mapTile)
{
	m_tiles << mapTile;
}

void Map::draw(QPainter &painter)
{
	for (MapTile *tile : m_tiles)
	{
		tile->draw(painter);
	}
}

void Map::update(long delta)
{
	Q_UNUSED(delta);
}
