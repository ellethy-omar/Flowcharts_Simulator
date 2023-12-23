#include "Start.h"


void Start::Draw(Output* pOut)  const
{
	pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text);

};

void Start::UpdateStatementText() {};

Start::Start(Point Center)
{
	kounter = 0;
	Connector* pOutConn = NULL;
	kounter++;
	Text = "START";
	this->Center = Center;
	Outlet.x = Center.x;
	Outlet.y= Center.y + UI.ASSGN_HI / 2;

	/*F.pf1.x = Center.x - UI.ASSGN_WDTH / 2 - 10;	F.pf1.y = Center.y - UI.ASSGN_HI / 2 - 5;
	F.pf2.x = Center.x + UI.ASSGN_WDTH / 2 + 10;	F.pf2.y = Center.y - UI.ASSGN_HI / 2 - 5;
	F.pf3.x = Center.x + UI.ASSGN_WDTH / 2 + 10;	F.pf3.y = Center.y + UI.ASSGN_HI / 2 + 5;
	F.pf4.x = Center.x - UI.ASSGN_WDTH / 2 - 10;	F.pf4.y = Center.y + UI.ASSGN_HI / 2 + 5;*/
};

bool Start::Is_In_Region(Point& p1)
{

	if (
		((((p1.x - Center.x) ^ 2) / (UI.ASSGN_WDTH / 2) ^ 2 + (p1.y - Center.y) ^ 2) / (UI.ASSGN_HI / 2) ^ 2) <= 1
		)
	{
		return true;
	}
	return false;
}

Start::~Start()
{
	kounter--;
}