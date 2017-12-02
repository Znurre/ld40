#include "TurnHandler.h"
#include "IPawn.h"

TurnHandler::TurnHandler()
{

}

void TurnHandler::add(IPawn &pawn)
{
	m_pawns << &pawn;
}

void TurnHandler::step()
{
	for (IPawn *pawn : m_pawns)
	{
		pawn->step();
	}
}
