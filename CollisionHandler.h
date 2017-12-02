#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <QRegion>
#include <QVector>

class CollisionHandler
{
	public:
		CollisionHandler();

		void setCollidable(int x, int y);

		bool isCollidable(const QPoint &point) const;

		QVector<QRect> collidables() const;

	private:
		QRegion m_collidables;
};

#endif // COLLISIONHANDLER_H
