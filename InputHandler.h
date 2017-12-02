#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QKeyEvent>

class TurnHandler;
class Player;

class InputHandler
{
	public:
		InputHandler(TurnHandler &turnHandler, Player &player);

		void onKeyPress(QKeyEvent *event);
		void onKeyRelease(QKeyEvent *event);

	private:
		TurnHandler &m_turnHandler;
		Player &m_player;
};

#endif // INPUTHANDLER_H
