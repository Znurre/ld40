#ifndef PLAYER_H
#define PLAYER_H

#include "IDrawable.h"
#include "IPawn.h"

class Player : public IDrawable, public IPawn
{
	public:
		Player();

		void setDirection(int direction);

		void draw(QPainter &painter) override;
		void update(long delta) override;
		void step() override;

	private:
		int m_direction;
		int m_x;
		int m_y;
};

#endif // PLAYER_H
