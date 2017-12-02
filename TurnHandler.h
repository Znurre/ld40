#ifndef TURNHANDLER_H
#define TURNHANDLER_H

#include <QList>

class IPawn;

class TurnHandler
{
	public:
		TurnHandler();

		void add(IPawn &pawn);

		void step();

	private:
		QList<IPawn *> m_pawns;
};

#endif // TURNHANDLER_H
