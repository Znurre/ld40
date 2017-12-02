#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{

}

void CollisionHandler::setCollidable(int x, int y)
{
	m_collidables += QRect(x, y, 1, 1);
}

bool CollisionHandler::isCollidable(const QPoint &point) const
{
	return m_collidables.contains(point);
}

QVector<QRect> CollisionHandler::collidables() const
{
	return m_collidables.rects();
}
