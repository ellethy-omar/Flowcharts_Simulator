#include "ValueAssign.h"
#include <sstream>
#include <iostream>
using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	

	/*F.pf1.x = Inlet.x - UI.ASSGN_WDTH / 2 - 10;		F.pf1.y = Inlet.y - 5;
	F.pf2.x = Inlet.x + UI.ASSGN_WDTH / 2 + 10;		F.pf2.y = Inlet.y - 5;
	F.pf3.x = Outlet.x + UI.ASSGN_WDTH / 2 + 10;	F.pf3.y = Outlet.y + 5;
	F.pf4.x = Outlet.x - UI.ASSGN_WDTH / 2 - 10;	F.pf4.y = Outlet.y + 5;*/
}

void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

Point ValueAssign::getInlet()
{
	return Inlet;
}

Point ValueAssign::getOutlet()
{
	return Outlet;
}


void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

bool ValueAssign::Is_In_Region(Point& p1)
{
	if ((p1.x >= (LeftCorner.x - UI.ASSGN_WDTH / 2)) && (p1.x <= (LeftCorner.x + UI.ASSGN_WDTH / 2)) && (p1.y >= LeftCorner.y) && (p1.y <= LeftCorner.y + UI.ASSGN_HI))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ValueAssign::SetOutlet()
{

}

//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS;	
	Text = T.str();	 
}
