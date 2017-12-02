#include "Enemy.h"
#include "Player.h"
#include "CollisionHandler.h"

Enemy::Enemy(CollisionHandler &collisionHandler, Player &player, int x, int y)
	: m_collisionHandler(collisionHandler)
	, m_player(player)
	, m_x(x)
	, m_y(y)
{
}

int sign(int i)
{
	return i > 0 ? 1 : i < 0 ? -1 : 0;
}

void Enemy::step()
{
	const int px = m_player.x();
	const int py = m_player.y();

	const int dx = m_x - px;
	const int dy = m_y - py;

	const QList<QPoint> &candidates = getCandidates(dx, dy);

	for (const QPoint &candidate : candidates)
	{
		if (!m_collisionHandler.isCollidable(candidate))
		{
			m_x = candidate.x();
			m_y = candidate.y();

			return;
		}
	}
}

void Enemy::draw(QPainter &painter)
{
	const QRect rect(m_x * TILE_SIZE, m_y * TILE_SIZE, TILE_SIZE, TILE_SIZE);

	painter.fillRect(rect, Qt::blue);
}

void Enemy::update(long delta)
{
	Q_UNUSED(delta);
}

QList<QPoint> Enemy::getCandidates(int dx, int dy) const
{
	if (qAbs(dx) > qAbs(dy))
	{
		return
		{
			QPoint(m_x - sign(dx), m_y),
			QPoint(m_x, m_y - sign(dy))
		};
	}

	return
	{
		QPoint(m_x, m_y - sign(dy)),
		QPoint(m_x - sign(dx), m_y)
	};
}
