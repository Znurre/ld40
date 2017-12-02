#ifndef WORLD_H
#define WORLD_H

#include "IDrawable.h"
#include "Map.h"

class World : public IDrawable
{
	public:
		World();

		void advance();

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		Map m_maps[2];

		int m_level;
};

#endif // WORLD_H
