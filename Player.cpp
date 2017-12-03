#include <QtMath>

#include "Player.h"
#include "CollisionHandler.h"

Player::Player(CollisionHandler &collisionHandler)
	: m_image("player.png")
	, m_collisionHandler(collisionHandler)
	, m_direction(1)
	, m_x(25)
	, m_y(25)
{

}

int Player::x() const
{
	return m_x;
}

int Player::y() const
{
	return m_y;
}

void Player::setDirection(int direction)
{
	m_direction = direction;
}

void Player::draw(QPainter &painter)
{
	painter.drawImage((m_x - 1) * TILE_SIZE, (m_y - 1) * TILE_SIZE, m_image);
}

void Player::update(long delta)
{
	Q_UNUSED(delta);
}

void Player::step()
{
	const int tx = m_x + qSin(m_direction * M_PI / 2);
	const int ty = m_y - qCos(m_direction * M_PI / 2);

	const QPoint candidate(tx, ty);

	if (!m_collisionHandler.isCollidable(candidate))
	{
		m_x = tx;
		m_y = ty;
	}
}
