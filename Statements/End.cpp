#include "End.h"


void End::Draw(Output* pOut)  const 
{
	pOut->DrawEnd(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text);

};

void End::UpdateStatementText() {};

bool End::Is_In_Region(Point& p1)
{

	if (
		((((p1.x - Center.x) ^ 2) / (UI.ASSGN_WDTH / 2) ^ 2 + (p1.y - Center.y) ^ 2) / (UI.ASSGN_HI / 2) ^ 2) <= 1
		)
	{
		return true;
	}
	return false;
}

End::End(Point Center)
{
	kounter = 0;
	Connector* pOutConn=NULL;
	kounter++;
	Text = "END";
	this->Center = Center;
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

	/*F.pf1.x = Center.x - UI.ASSGN_WDTH / 2 - 10;	F.pf1.y = Center.y - UI.ASSGN_HI / 2 - 5;
	F.pf2.x = Center.x + UI.ASSGN_WDTH / 2 + 10;	F.pf2.y = Center.y - UI.ASSGN_HI / 2 - 5;
	F.pf3.x = Center.x + UI.ASSGN_WDTH / 2 + 10;	F.pf3.y = Center.y + UI.ASSGN_HI / 2 + 5;
	F.pf4.x = Center.x - UI.ASSGN_WDTH / 2 - 10;	F.pf4.y = Center.y + UI.ASSGN_HI / 2 + 5;*/

};

End::~End()
{
	kounter--;
}