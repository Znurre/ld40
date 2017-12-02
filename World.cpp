#include "MapLoader.h"
#include "World.h"

World::World()
	: m_level(0)
{
	MapLoader mapLoader;

	mapLoader.load("map1.tmx", m_maps[0]);
	mapLoader.load("map2.tmx", m_maps[1]);
}

void World::advance()
{
	m_level++;
}

void World::draw(QPainter &painter)
{
	Map &map = m_maps[m_level];

	map.draw(painter);
}

void World::update(long delta)
{
	Map &map = m_maps[m_level];

	map.update(delta);
}
