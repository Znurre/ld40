#ifndef ENEMY_H
#define ENEMY_H

#include "IDrawable.h"
#include "IPawn.h"

class Player;
class CollisionHandler;

class Enemy : public IDrawable, public IPawn
{
	public:
		Enemy(CollisionHandler &collisionHandler, Player &player, int x, int y);

		void step() override;
		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		QImage m_image;

		QList<QPoint> getCandidates(int dx, int dy) const;

		CollisionHandler &m_collisionHandler;
		Player &m_player;

		int m_x;
		int m_y;
};

#endif // ENEMY_H
