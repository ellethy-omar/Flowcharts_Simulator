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


bool Write::IsWriteVariable()
{
	bool variable, valid;
	int checklast = -1, checkfirst = -1;
	string check = "\"";
	checklast = print.find_last_not_of(check);
	checkfirst = print.find_first_not_of(check);
	if (checklast != print.length() - 1 && checkfirst != 0)
	{
		return false;
	}
	else 
	{
		valid = IsVariable(print);
		if (valid == true) {
			return true;
		}
	}
}
string Write::getprint()
{
	return print;
}

void Write::Simulate(string(&allvariables)[200], double(&corespondingarray)[200], int& CountOfVariables, Output* pOut, Input* pIn, int writecount)
{
	if (IsWriteVariable() == true)
	{
		int y = 100 + writecount * 20;
		for (int i = 0; i < CountOfVariables; i++)
		{
			if (allvariables[i] == print)
			{
				string printdouble = to_string(corespondingarray[i]);
				pOut->DrawRunString(0.77 * UI.width, y, printdouble);
			}
		}
	}
	else
	{
		int y = 100 + writecount * 20;
		pOut->DrawRunString(0.75 * UI.width, y, print);
	}
}
