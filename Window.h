#ifndef WINDOW_H
#define WINDOW_H

#include <QRasterWindow>

#include "World.h"

class Window : public QRasterWindow
{
	public:
		Window();

	private:
		void keyPressEvent(QKeyEvent *event) override;
		void keyReleaseEvent(QKeyEvent *event) override;

		World m_world;
};

#endif // WINDOW_H
