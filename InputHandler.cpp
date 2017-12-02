#include "InputHandler.h"
#include "TurnHandler.h"
#include "Player.h"

InputHandler::InputHandler(TurnHandler &turnHandler, Player &player)
	: m_turnHandler(turnHandler)
	, m_player(player)
{

}

void InputHandler::onKeyPress(QKeyEvent *event)
{
	Q_UNUSED(event);
}

void InputHandler::onKeyRelease(QKeyEvent *event)
{
	static QList<int> input =
	{
		Qt::Key_W,
		Qt::Key_D,
		Qt::Key_S,
		Qt::Key_A
	};

	const int key = event->key();
	const int direction = input.indexOf(key);

	if (direction > -1)
	{
		m_player.setDirection(direction);

		m_turnHandler.step();
	}
}
