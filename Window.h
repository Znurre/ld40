#ifndef WINDOW_H
#define WINDOW_H

#include <QRasterWindow>

#include "World.h"
#include "Player.h"
#include "TurnHandler.h"
#include "InputHandler.h"
#include "CollisionHandler.h"

class Window : public QRasterWindow
{
	public:
		Window();

	private:
		void keyPressEvent(QKeyEvent *event) override;
		void keyReleaseEvent(QKeyEvent *event) override;
		void paintEvent(QPaintEvent *event) override;

		CollisionHandler m_collisionHandler;
		Player m_player;
		TurnHandler m_turnHandler;
		World m_world;
		InputHandler m_inputHandler;
};

#endif // WINDOW_H
