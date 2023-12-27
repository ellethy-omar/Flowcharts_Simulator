#include "Write.h"
#include"..\GUI/Output.h"
#include <sstream>
#include"..\HelperFn.h"
#include<fstream>



Write::Write(Point corner, string text) {
	print = text;
	UpdateStatementText();
	Center = corner;
	pOutConn = NULL;

	Inlet.y = Center.y - UI.ASSGN_HI / 2;
	Inlet.x = Center.x;

	Outlet.x = Inlet.x;
	Outlet.y = Center.y + UI.ASSGN_HI;
};


void Write::Draw(Output* pOut) const {
	pOut->DrawWritestat(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
};
void Write::UpdateStatementText() {
	ostringstream T;
	T << "write " << print;
	Text = T.str();
};
//save
void Write::Save(ofstream& OutFile) {
	OutFile << "WRITE   " << ID << "  " << Center.x << "  " << Center.y << "    " << print;
};
void Write::Load(ifstream& InFile) {
	InFile >> print;
	UpdateStatementText();
}
Point Write::getInlet() {
	return Inlet;
}
Point Write::getOutlet(int x) {
	return Outlet;
};
bool Write::Is_In_Region(Point& p1) {
	if (p1.x >= Center.x - UI.ASSGN_WDTH && p1.x <= Center.x + UI.ASSGN_WDTH && p1.y >= Center.y - UI.ASSGN_HI && p1.y <= Center.y + UI.ASSGN_HI) {
		return true;
	}
	return false;
};
void Write::SetConnector(Connector* pOutConn) {
	this->pOutConn = pOutConn;
};
Connector* Write::GetConnector(int checker) {
	return pOutConn;
};
string Write::GetPrint() {
	return print;
};
