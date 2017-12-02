#include <tiled/mapreader.h>
#include <tiled/map.h>
#include <tiled/tilelayer.h>
#include <tiled/objectgroup.h>
#include <tiled/tile.h>
#include <tiled/mapobject.h>

#include "MapLoader.h"
#include "MapTile.h"
#include "Map.h"
#include "Enemy.h"
#include "TurnHandler.h"
#include "CollisionHandler.h"
#include "Shard.h"

MapLoader::MapLoader(Player &player, TurnHandler &turnHandler, CollisionHandler &collisionHandler, World &world)
	: m_player(player)
	, m_turnHandler(turnHandler)
	, m_collisionHandler(collisionHandler)
	, m_world(world)
{

}

void MapLoader::load(const QString &fileName, Map &map)
{
	Tiled::MapReader mapReader;

	Tiled::Map *tiledMap = mapReader.readMap(fileName);

	for (int i = 0; i < tiledMap->layerCount(); i++)
	{
		Tiled::Layer *layer = tiledMap->layerAt(i);

		Tiled::TileLayer *tileLayer = dynamic_cast<Tiled::TileLayer *>(layer);

		if (tileLayer)
		{
			for (int x = 0; x < tiledMap->width(); x++)
			{
				for (int y = 0; y < tiledMap->height(); y++)
				{
					Tiled::Cell cell = tileLayer->cellAt(x, y);
					Tiled::Tile *tile = cell.tile();

					if (tileLayer->property("collidable") == true)
					{
						if (tile)
						{
							m_collisionHandler.setCollidable(x, y);
						}
					}
					else
					{
						MapTile *mapTile = new MapTile(map, x, y);

						const QPixmap &image = tile->image();

						mapTile->setImage(image);

						map.addChild(mapTile);
					}
				}
			}
		}

		Tiled::ObjectGroup *objectGroup = dynamic_cast<Tiled::ObjectGroup *>(layer);

		if (objectGroup)
		{
			for (int j = 0; j < objectGroup->objectCount(); j++)
			{
				Tiled::MapObject *object = objectGroup->objectAt(j);

				const int x = object->x() / TILE_SIZE;
				const int y = object->y() / TILE_SIZE;

				if (object->type() == "enemy")
				{
					Enemy *enemy = new Enemy(m_collisionHandler, m_player, x, y);

					map.addChild(enemy);

					m_turnHandler.add(*enemy);
				}

				if (object->type() == "shard")
				{
					Shard *shard = new Shard(m_player, m_world, x, y);

					map.addChild(shard);

					m_turnHandler.add(*shard);
				}
			}
		}
	}

	delete tiledMap;
}
