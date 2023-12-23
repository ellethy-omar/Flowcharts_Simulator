#pragma once
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"

class OperAssign : public Statement
{
private:
	string LHS;
	string RHS;
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;
	virtual void UpdateStatementText();
public:
	OperAssign(Point Lcorner, string LeftHS = "", string RightHS = "");
	void setLHS(const string& L);
	void setRHS(string R);
	Point getInlet();
	Point getOutlet();
	bool Is_In_Region(Point& p1);
	virtual void Draw(Output* pOut) const;
};

