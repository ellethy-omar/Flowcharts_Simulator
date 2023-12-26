#include "OperAssign.h"
#include <sstream>
#include <iostream>
using namespace std;

void OperAssign::UpdateStatementText()
{
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

OperAssign::OperAssign(Point Lcorner, string LeftHS, string RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;
	UpdateStatementText();
	LeftCorner = Lcorner;
	pOutConn = NULL;
	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OperAssign::setLHS(const string& L)
{
	LHS = L;
}

void OperAssign::setRHS(string R)
{
	RHS = R;
}

Point OperAssign::getInlet()
{
	return Inlet;
}

Point OperAssign::getOutlet(int x)
{
	return Outlet;
}

void OperAssign::SetConnector(Connector* pOutConn)
{
	if (this->pOutConn != NULL)
	{
		delete this->pOutConn;
	}
	this->pOutConn = pOutConn;
}

Connector* OperAssign::GetConnector(int checker)
{
	return pOutConn;
}

bool OperAssign::Is_In_Region(Point& p1)
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

void OperAssign::Draw(Output* pOut) const
{
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

OperAssign::~OperAssign()
{
	if (pOutConn != NULL)
	{
		delete pOutConn;
	}
}




/*
void OperAssign::Save(ofstream &OutFile){
	OutFile<<"OP_ASSIGN  "<<ID<<"  "<<LeftCorner.x<<"  "<<LeftCorner.y<<"  "<<LHS<<"  "<<LHS_Of_Arithmaticoperator<<"  ";
	
	if(Arithmaticoperator=="+"){
		OutFIle<<"ADD";
	}
	if(Arithmaticoperator=="-"){
		OutFIle<<"SUB";
	}
	if(Arithmaticoperator=="*"){\
		OutFIle<<"MUL";
	}
	if(Arithmaticoperator=="/"){
		OutFIle<<"DIV";
	}
	
	OutFile<<"  "<<RHS_Of_Arithmaticoperator;                              
};

void OperAssign::Load(ifstream &OutFile){
	OutFile>>ID>>LeftCorner.x>>LeftCorner.y>>LHS>>LHS_Of_Arithmaticoperator>>Arithmaticoperator>>RHS_Of_Arithmaticoperator;

	if(Arithmaticoperator=="ADD"){
		Arithmaticoperator="+"
	};
	if(Arithmaticoperator=="SUB"){
		Arithmaticoperator="-"
	};
	if(Arithmaticoperator=="MUL"){\
		Arithmaticoperator="*"
	};
	if(Arithmaticoperator=="DIV"){
		Arithmaticoperator="/"
	};
	UpdateStatementText();


}






*/


