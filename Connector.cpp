#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	setSrcStat(Src);
	setDstStat(Dst);
	Start = SrcStat->getOutlet();
	End = DstStat->getInlet();

}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}

void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	pOut->DrawConnector(Start, End);
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
}

bool Connector::IsSelectedCon(Point P) const
{
	//			End
	//	pxn	------------pxp
	//		 \		  /
	//		  \		P/
	//		   \  . /
	//			\  /
	//			 \/
	//			end


	if (End.x +5 >= P.x && End.x - 5 <= P.x)
	{
		Point pxn;
		pxn.x = End.x - 5; pxn.y = End.y -5;
		Point pxp;
		pxp.x = End.x + 5; pxp.y = End.y -5;

		float slope1 = float(pxn.y - P.y) / (pxn.x - P.x);
		float slope2 = float(pxn.y - End.y) / (pxn.x - End.x);
		float slope3 = float(pxp.y - P.y) / (pxp.x - P.x);
		float slope4 = float(pxp.y - End.y) / (pxp.x - End.x);
		if (
			(slope1 <= 0.0) && (slope2 <= slope1) && (slope3 >= slope4)
			)
		{
			return true;
		}
	}

	if (Start.y <= End.y)
	{
		for (int j = Start.y -1 ; j < Start.y + 6; j++)
		{
			for (int i = Start.x - 1; i < Start.x + 1; i++)
			{
				if (P.x == i && P.y == j)
					return true;
			}
		}

		for (int j = Start.y + 4; j < Start.y + 6; j++)
		{
			for (int i = Start.x - 1; i < End.x+1; i++) 
			{
				if (P.x == i && P.y == j)
					return true;
			}
		}

		for (int j = Start.y + 4; j < End.y + 1; j++)
		{
			for (int i = End.x-1; i < End.x + 1; i++)
			{

			}
		}
	}

	else {
		if (Start.x >= End.x && Start.y > End.y)
		{
			for (int j = Start.y - 1; j < Start.y + 6; j++)
			{
				for (int i = Start.x - 1; i < Start.x + 1; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = Start.y + 4; j < Start.y + 6; j++)
			{
				for (int i = Start.x - 1; i < End.x + 1; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = Start.y + 4; j < End.y + UI.ASSGN_HI + 11; j++)
			{
				for (int i = End.x - 1; i < End.x + 1; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = End.y + UI.ASSGN_HI + 9; j < End.y + UI.ASSGN_HI + 11; j++)
			{
				for (int i = End.x - 1; i < End.x + UI.ASSGN_WDTH / 2 + 11; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = End.y + UI.ASSGN_HI + 11; j > End.y - 10; j--)
			{
				for (int i = End.x + UI.ASSGN_WDTH / 2 + 9; i < End.x + UI.ASSGN_WDTH / 2 + 11; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = End.y - 9; j > End.y - 11; j--)
			{
				for (int i = End.x + UI.ASSGN_WDTH / 2 + 11; i > End.x - 1; i--)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}

			for (int j = End.y - 11; j < End.y + 1; j++)
			{
				for (int i = End.x + 1; i < End.x - 1; i++)
				{
					if (P.x == i && P.y == j)
						return true;
				}
			}
		}
		else {
			if (Start.x < End.x && Start.y > End.y)
			{
				for (int j = Start.y - 1; j < Start.y + 6; j++)
				{
					for (int i = Start.x - 1; i < Start.x + 1; i++)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = Start.y + 4; j < Start.y + 6; j++)
				{
					for (int i = Start.x - 1; i < End.x + 1; i++)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = Start.y + 4; j < End.y + UI.ASSGN_HI + 11; j++)
				{
					for (int i = End.x - 1; i < End.x + 1; i++)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = End.y + UI.ASSGN_HI + 9; j < End.y + UI.ASSGN_HI + 11; j++)
				{
					for (int i = End.x + 1; i > End.x - UI.ASSGN_WDTH / 2 - 11; i--)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = End.y + UI.ASSGN_HI + 11; j > End.y - 10; j--)
				{
					for (int i = End.x - UI.ASSGN_WDTH / 2 - 9; i > End.x - UI.ASSGN_WDTH / 2 - 11; i--)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = End.y - 9; j > End.y - 11; j--)
				{
					for (int i = End.x - UI.ASSGN_WDTH / 2 - 11; i > End.x + 1; i--)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}

				for (int j = End.y - 11; j < End.y + 1; j++)
				{
					for (int i = End.x + 1; i < End.x - 1; i++)
					{
						if (P.x == i && P.y == j)
							return true;
					}
				}
			}
		}
	}

	return false;

}

Connector::~Connector()
{
	SrcStat = NULL;
	DstStat = NULL;
}
