#include <QtMath>

#include "Player.h"

Player::Player()
	: m_direction(1)
	, m_x(0)
	, m_y(0)
{

}

void Player::setDirection(int direction)
{
	m_direction = direction;
}

void Player::draw(QPainter &painter)
{
	const QRect rect(m_x * TILE_SIZE, m_y * TILE_SIZE, TILE_SIZE, TILE_SIZE);

	painter.fillRect(rect, Qt::green);
}

void Player::update(long delta)
{
	Q_UNUSED(delta);
}

void Player::step()
{
	m_x += qSin(m_direction * M_PI / 2);
	m_y -= qCos(m_direction * M_PI / 2);
}
