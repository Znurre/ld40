#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <QString>

class Map;

class MapLoader
{
	public:
		MapLoader();

		void load(const QString &fileName, Map &map);
};

#endif // MAPLOADER_H
