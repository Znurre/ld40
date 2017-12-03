#include "MapTile.h"
#include "Map.h"

MapTile::MapTile(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

void MapTile::setImage(const QPixmap &image)
{
	m_image = image;
}

void MapTile::draw(QPainter &painter)
{
	painter.drawPixmap(m_x * TILE_SIZE, m_y * TILE_SIZE, m_image);
}

void MapTile::update(long delta)
{
	Q_UNUSED(delta);
}
