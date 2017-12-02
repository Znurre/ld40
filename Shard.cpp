#include "Shard.h"
#include "Player.h"
#include "World.h"

Shard::Shard(Player &player, World &world, int x, int y)
	: m_player(player)
	, m_world(world)
	, m_x(x)
	, m_y(y)
	, m_picked(false)
{

}

void Shard::step()
{
	if (m_picked)
	{
		return;
	}

	if (m_x == m_player.x() &&
		m_y == m_player.y())
	{
		m_world.advance();

		m_picked = true;
	}
}

void Shard::draw(QPainter &painter)
{
	if (m_picked)
	{
		return;
	}

	const QRect rect(m_x * TILE_SIZE, m_y * TILE_SIZE, TILE_SIZE, TILE_SIZE);

	painter.fillRect(rect, Qt::yellow);
}

void Shard::update(long delta)
{
	Q_UNUSED(delta);
}
