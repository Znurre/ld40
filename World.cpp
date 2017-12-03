#include <QDebug>

#include "MapLoader.h"
#include "World.h"
#include "CollisionHandler.h"

World::World(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler)
	: m_mapLoader(player, turnHandler, collisionHandler, *this)
	, m_collisionHandler(collisionHandler)
	, m_level(0)
{
	for (int y = 0 ; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			m_objects << new MapTile(x, y);
		}
	}

	advance();
}

void World::advance()
{
	static QStringList mapNames =
	{
		"map1.tmx",
		"map2.tmx",
		"map3.tmx",
		"map4.tmx",
	};

	if (m_level < mapNames.count())
	{
		const QString &fileName = mapNames[m_level++];

		qDebug() << fileName;

		m_mapLoader.load(fileName);
	}
}

MapTile *World::tileAt(int x, int y)
{
	return (MapTile *)m_objects[x + (y * MAP_SIZE)];
}

void World::addObject(IDrawable *drawable)
{
	m_objects << drawable;
}

void World::draw(QPainter &painter)
{
	for (IDrawable *drawable : m_objects)
	{
		drawable->draw(painter);
		drawable->update(0);
	}

//	const QTransform &transform = QTransform::fromScale(TILE_SIZE, TILE_SIZE);

//	for (const QRect &rect : m_collisionHandler.collidables())
//	{
//		const QRect &mapped = transform.mapRect(rect);

//		painter.fillRect(mapped, Qt::black);
//	}
}

void World::update(long delta)
{
	for (IDrawable *drawable : m_objects)
	{
		drawable->update(delta);
	}
}
