#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst, ForbiddenReigon* F, int x)
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;
	FUCK = F;
	/*for (int i = 0; i < x; i++)
	{
		FUCK[i] = F[i];
	}*/
	Fuck_length = x;
	Start = SrcStat->getOutlet();
	End = DstStat->getInlet();

}

Connector::Connector(Statement* Src, Statement* Dst)
{
	SrcStat = Src;
	DstStat = Dst;
	FUCK = NULL;
	Fuck_length = 0;
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

	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window

	Point dummy = Start;
	Point lag = Start;
	lag.y += 10;
	dummy.y += 10;
	pOut->Drawline(dummy, Start);

	while (dummy.x != End.x || dummy.y != (End.y - 10))
	{
		if (End.x != dummy.x)
		{
			if (End.x > Start.x)
			{
				for (int i = dummy.x; i < End.x; i++)
				{
					dummy.x++;
					for (int j = 0; j < Fuck_length; j++)
					{
						if (FUCK != NULL)
						{
							if (FUCK[i].Isforbidden(dummy) == true)
							{
								dummy.x--;
								break;
							}
						}
					}
					if (dummy.x == lag.x)
					{
						break;
					}
					else
					{
						pOut->Drawline(dummy, lag);
					}
					lag.x++;
				}
			}
			else
			{
				for (int i = dummy.x; i > End.x; i--)
				{
					dummy.x--;
					for (int j = 0; j < Fuck_length; j++)
					{
						if (FUCK != NULL)
						{
							if (FUCK[i].Isforbidden(dummy) == true)
							{
								dummy.x++;
								break;
							}
						}
					}
					if (dummy.x == lag.x)
					{
						break;
					}
					else
					{
						pOut->Drawline(dummy, lag);
					}
					lag.x--;
				}
			}
		}
		if ((End.y - 10) != dummy.y)
		{
			if (End.y > Start.y)
			{
				for (int i = dummy.y; i < (End.y - 10); i++)
				{
					dummy.y++;
					for (int j = 0; j < Fuck_length; j++)
					{
						if (FUCK != NULL)
						{
							if (FUCK[i].Isforbidden(dummy) == true)
							{
								dummy.y--;
								break;
							}
						}
					}
					if (dummy.y == lag.y)
					{
						break;
					}
					else
					{
						pOut->Drawline(dummy, lag);
					}
					lag.y++;
				}
			}
			else
			{
				for (int i = dummy.y; i > (End.y - 10); i--)
				{
					dummy.y--;
					for (int j = 0; j < Fuck_length; j++)
					{
						if (FUCK != NULL)
						{
							if (FUCK[i].Isforbidden(dummy) == true)
							{
								dummy.y++;
								break;
							}
						}
					}
					if (dummy.y == lag.y)
					{
						break;
					}
					else
					{
						pOut->Drawline(dummy, lag);
					}
					lag.y--;
				}
			}

		}
		dummy.y = End.y - 5;

		pOut->DrawConnector(lag, dummy);
	}
}

bool Connector::IsSelectedCon(Point P)
{
	Point dummy = Start;
	Point lag = Start;
	//			End
	//	pxn	------.-----pxp
	//		 \		  /
	//		  \		P/
	//		   \  . /
	//			\  /
	//			 \/
	//			pxd


	if (End.x +5 <= P.x && End.x - 5 >= P.x)
	{
		Point pxn;
		pxn.x = End.x - 5; pxn.y = End.y;
		Point pxp;
		pxp.x = End.x + 5; pxp.y = End.y;
		Point pxd;
		pxd.x = End.x; pxp.y = End.y + 7; //5 root(2)

		float slope1 = float(pxn.y - P.y) / (pxn.x - P.x);
		float slope2 = float(pxn.y - pxd.y) / (pxn.x - pxd.x);
		float slope3 = float(pxp.y - P.y) / (pxp.x - P.x);
		float slope4 = float(pxp.y - pxd.y) / (pxp.x - pxd.x);
		if (
			(slope1 <= 0.0) && (slope2 <= slope1) && (slope3 >= slope4)
			)
		{
			return true;
		}
	}

	while (dummy.x != End.x || dummy.y != End.y)
	{
		if (End.x > Start.x)
		{
			for (int i = Start.x; i < End.x; i++)
			{
				for (int j = 0; j < Fuck_length; j++)
				{
					if (P.x == dummy.x)
					{
						break;
					}
					if (FUCK[i].Isforbidden(dummy) == true)
					{
						dummy.x--;
						break;
					}
				}
				lag.x++;
				dummy.x++;
				if (dummy.x == lag.x)
				{
					break;
				}
			}
		}
		else
		{
			for (int i = Start.x; i > End.x; i--)
			{
				for (int j = 0; j < Fuck_length; j++)
				{
					if (P.y == dummy.y)
					{
						break;
					}
					if (FUCK[i].Isforbidden(dummy) == true)
					{
						dummy.x++;
						break;
					}
				}
				lag.x--;
				dummy.x--;
				if (dummy.x == lag.x)
				{
					break;
				}
			}
		}
		if (End.y > Start.y)
		{
			for (int i = Start.y; i < End.y; i++)
			{
				for (int j = 0; j < Fuck_length; j++)
				{
					if (FUCK[i].Isforbidden(dummy) == true)
					{
						dummy.y--;
						break;
					}
				}
				lag.y++;
				dummy.y++;
				if (dummy.y == lag.y)
				{
					break;
				}
			}
		}
		else
		{
			for (int i = Start.y; i > End.y; i--)
			{
				for (int j = 0; j < Fuck_length; j++)
				{
					if (FUCK[i].Isforbidden(dummy) == true)
					{
						dummy.y++;
						break;
					}
				}
			}
			lag.y--;
			dummy.y--;
			if (dummy.y == lag.y)
			{
				break;
			}
		}
		if (P.x == dummy.x && P.y == dummy.y)
		{
			return true;
		}
	}	
	return false;
}

Connector::~Connector()
{
	delete []FUCK;
}
