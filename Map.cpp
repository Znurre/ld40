#include "Map.h"
#include "MapTile.h"

Map::Map()
{
}

void Map::addChild(IDrawable *drawable)
{
	m_children << drawable;
}

void Map::draw(QPainter &painter)
{
	for (IDrawable *drawable : m_children)
	{
		drawable->draw(painter);
	}
}

void Map::update(long delta)
{
	Q_UNUSED(delta);
}
