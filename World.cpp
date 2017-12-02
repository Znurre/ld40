#include "MapLoader.h"
#include "World.h"
#include "CollisionHandler.h"

World::World(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler)
	: m_collisionHandler(collisionHandler)
	, m_level(0)
{
	MapLoader mapLoader(player, turnHandler, collisionHandler, *this);

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

	const QTransform &transform = QTransform::fromScale(TILE_SIZE, TILE_SIZE);

	for (const QRect &rect : m_collisionHandler.collidables())
	{
		const QRect &mapped = transform.mapRect(rect);

		painter.fillRect(mapped, Qt::black);
	}
}

void World::update(long delta)
{
	Map &map = m_maps[m_level];

	map.update(delta);
}
