#ifndef CONDITION_H
#define CONDITION_H

#include "Statements/Statement.h"
#include "HelperFn.h"

class Condition : public Statement
{
private:
	string RHS;
	string LHS;
	string CompOperator;
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point UpperPoint;

	virtual void UpdateStatementText();

public:
	Condition(Point UPpoint, string LeftHS = "", string ComparisonOperator = "", string RightHS = "");

	void setCompOperator(const string& C);

	void setLHS(const string& L);

	void setRHS(const string& R);

	virtual void Draw(Output* pOut) const;

	virtual bool Is_In_Region(Point& p1);
};

#endif