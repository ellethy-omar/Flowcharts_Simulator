#include "Start.h"


void Start::Draw(Output* pOut)  const
{
	pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text);

};

void Start::UpdateStatementText() {};

Start::Start(Point Center)
{
	pOutConn = NULL;
	Text = "START";
	this->Center = Center;
	Outlet.x = Center.x;
	Outlet.y= Center.y + UI.ASSGN_HI / 2;

};

bool Start::Is_In_Region(Point& p1)
{

	if ((p1.x >= (Center.x - UI.ASSGN_WDTH / 2)) && (p1.x <= (Center.x + UI.ASSGN_WDTH / 2)) && (p1.y >= Center.y - UI.ASSGN_HI / 2) && (p1.y <= Center.y + UI.ASSGN_HI / 2))
	{
		return true;
	}
	return false;
}

void Start::SetConnector(Connector* pOutConn)
{
	this->pOutConn = pOutConn;
}

Connector* Start::GetConnector()
{
	return pOutConn;
}

Start::~Start()
{
	if (pOutConn !=NULL)
	{
		delete pOutConn;
	}
}

Point Start::getOutlet(int x)
{
	return Outlet;
}

Point Start::getInlet()
{
	Point P;
	P.x = 0;
	P.y = 0;
	return P;
}
