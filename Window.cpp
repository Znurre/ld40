#include <QKeyEvent>

#include "Window.h"

Window::Window()
	: m_inputHandler(m_turnHandler, m_player)
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

	m_world.draw(painter);
	m_player.draw(painter);

	update();
}
