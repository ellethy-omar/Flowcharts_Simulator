#pragma once
#include "Statement.h"
#include "..\GUI/UI_Info.h"
#include <sstream>
class Read:public Statement
{
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;
	string variable_name;
	double value;
public:
	Read(Point corner, string text, double value);
	void Draw(Output* pOut) const ;
	virtual void UpdateStatementText();


};

