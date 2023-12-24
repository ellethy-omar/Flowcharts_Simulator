#include "Write.h"
#include"..\GUI/Output.h"
#include <sstream>
#include"..\HelperFn.h"



Write::Write(Point corner, string text) {
	print = text;
	UpdateStatementText();
	LeftCorner = corner;
	pOutConn = NULL;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
};


void Write::Draw(Output* pOut) const {
	pOut->DrawWritestat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
};
void Write::UpdateStatementText() {
	ostringstream T;
		T << "write " << print;
		Text = T.str();
};
void Write:: SetConnector(Connector* connect){
	pOutConn=connect;
};
