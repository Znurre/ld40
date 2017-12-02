#include "World.h"

World::World()
	: m_level(0)
{

}

void World::advance()
{
	m_level++;
}

void World::draw(QPainter *painter)
{
	Q_UNUSED(painter);
}

void World::update(long delta)
{
	Q_UNUSED(delta);
}
