#include <QKeyEvent>

#include "Window.h"

Window::Window()
	: m_player(m_collisionHandler)
	, m_world(m_player, m_turnHandler, m_collisionHandler)
	, m_inputHandler(m_turnHandler, m_player)
{
	m_turnHandler.add(m_player);
}

void Window::keyPressEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
	{
		return;
	}

	m_inputHandler.onKeyPress(event);
}

void Window::keyReleaseEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
	{
		return;
	}

	if (event->key() == Qt::Key_Space)
	{
		m_world.advance();
	}

	m_inputHandler.onKeyRelease(event);
}

void Window::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter painter(this);

	const QRect &viewport = painter.viewport();

	painter.fillRect(viewport, Qt::black);

	const int cx = viewport.width() / 2 - (m_player.x() * TILE_SIZE);
	const int cy = viewport.height() / 2 - (m_player.y() * TILE_SIZE);

	painter.translate(cx, cy);

	m_world.draw(painter);
	m_player.draw(painter);

	update();
}
