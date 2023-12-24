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
	Text = "END";
	this->Center = Center;
	Inlet.x = Center.x;
	Inlet.y = Center.y - UI.ASSGN_HI / 2;

};

Point End::getOutlet()
{
	Point P;
	P.x = 0;
	P.y = 0;
	return P;
}

Point End::getInlet()
{
	return Inlet;
}

End::~End()
{

}

