#include <tiled/mapreader.h>
#include <tiled/map.h>
#include <tiled/tilelayer.h>
#include <tiled/tile.h>

#include "MapLoader.h"
#include "MapTile.h"
#include "Map.h"

MapLoader::MapLoader()
{

}

void MapLoader::load(const QString &fileName, Map &map)
{
	Tiled::MapReader mapReader;

	Tiled::Map *tiledMap = mapReader.readMap(fileName);

	for (int x = 0; x < tiledMap->width(); x++)
	{
		for (int y = 0; y < tiledMap->height(); y++)
		{
			MapTile *mapTile = new MapTile(map, x, y);

			for (int i = 0; i < tiledMap->layerCount(); i++)
			{
				Tiled::Layer *layer = tiledMap->layerAt(i);

				Tiled::TileLayer *tileLayer = dynamic_cast<Tiled::TileLayer *>(layer);

				if (tileLayer)
				{
					Tiled::Cell cell = tileLayer->cellAt(x, y);
					Tiled::Tile *tile = cell.tile();

					const QPixmap &image = tile->image();

					mapTile->setImage(image);
				}
			}

			map.addMapTile(mapTile);
		}
	}

	delete tiledMap;
}
