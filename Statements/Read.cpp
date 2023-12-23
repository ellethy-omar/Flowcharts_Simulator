#include "Read.h"
#include "..\GUI/UI_Info.h"
#include <sstream>

Read::Read(Point corner, string text, double input_value) {
	
	value = input_value;
	variable_name = text;
	UpdateStatementText();
	LeftCorner = corner;
	pOutConn = NULL;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;



};
void Read::Draw(Output* pOut)const {
	pOut->DrawReadstat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
};
void Read:: UpdateStatementText() {
	ostringstream T;
	T << "Read " << variable_name;
	Text=T.str();

};
