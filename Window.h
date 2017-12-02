#ifndef WINDOW_H
#define WINDOW_H

#include <QRasterWindow>

#include "World.h"
#include "Player.h"
#include "TurnHandler.h"
#include "InputHandler.h"

class Window : public QRasterWindow
{
	public:
		Window();

	private:
		void keyPressEvent(QKeyEvent *event) override;
		void keyReleaseEvent(QKeyEvent *event) override;
		void paintEvent(QPaintEvent *event) override;

		World m_world;
		Player m_player;
		TurnHandler m_turnHandler;
		InputHandler m_inputHandler;
};

#endif // WINDOW_H
