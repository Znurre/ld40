#ifndef WORLD_H
#define WORLD_H

#include "IDrawable.h"
#include "Map.h"

class Player;
class TurnHandler;
class CollisionHandler;

class World : public IDrawable
{
	public:
		World(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler);

		void advance();

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		Map m_maps[2];

		CollisionHandler &m_collisionHandler;

		int m_level;
};

#endif // WORLD_H
