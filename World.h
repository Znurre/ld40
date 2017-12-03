#ifndef WORLD_H
#define WORLD_H

#include "IDrawable.h"
#include "MapTile.h"
#include "MapLoader.h"

class Player;
class TurnHandler;
class CollisionHandler;

class World : public IDrawable
{
	public:
		World(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler);

		void advance();

		MapTile *tileAt(int x, int y);

		void addObject(IDrawable *drawable);

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		MapLoader m_mapLoader;
		CollisionHandler &m_collisionHandler;

		QList<IDrawable *> m_objects;

		int m_level;
};

#endif // WORLD_H
