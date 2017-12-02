#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <QString>

class Map;
class Player;
class TurnHandler;
class CollisionHandler;
class World;

class MapLoader
{
	public:
		MapLoader(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler, World &world);

		void load(const QString &fileName, Map &map);

	private:
		Player &m_player;
		TurnHandler &m_turnHandler;
		CollisionHandler &m_collisionHandler;
		World &m_world;
};

#endif // MAPLOADER_H
