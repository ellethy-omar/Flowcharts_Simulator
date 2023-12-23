#pragma once
#include"Statement.h"
class Write:public Statement
{
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;
	string print;
	int type;
public:
	Write(Point corner, string text);
	virtual void Draw(Output* pOut) const;
	void UpdateStatementText();
};

