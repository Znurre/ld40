#ifndef MAPTILE_H
#define MAPTILE_H

#include "IDrawable.h"

class Map;

class MapTile : public IDrawable
{
	public:
		MapTile(int x, int y);

		void setImage(const QPixmap &image);

		void draw(QPainter &painter) override;
		void update(long delta) override;

	private:
		int m_x;
		int m_y;

		QPixmap m_image;
};

#endif // MAPTILE_H
