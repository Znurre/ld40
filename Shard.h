#ifndef SEAL_H
#define SEAL_H

#include "IDrawable.h"
#include "IPawn.h"

class Player;
class World;

class Shard : public IDrawable
{
	public:
		Shard(Player &player, World &world, int x, int y);

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		QImage m_image;

		Player &m_player;
		World &m_world;

		int m_x;
		int m_y;

		bool m_picked;
};

#endif // SEAL_H
