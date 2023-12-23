#ifndef CONDITION_H
#define CONDITION_H

#include "Statement.h"
<<<<<<< Updated upstream
#include "../HelperFn.h"
=======
#include "..\HelperFn.h"
>>>>>>> Stashed changes

class Condition : public Statement
{
private:
	string RHS;
	string LHS;
	string CompOperator;
	Connector* pOutConnTrue;
	Connector* pOutConnFalse;
	Point Inlet;
	Point Outlet;
	Point UpperPoint;

	virtual void UpdateStatementText();

public:
	Condition(Point UPpoint, string LeftHS = "", string ComparisonOperator = "", string RightHS = "");

	void setCompOperator(const string& C);

	void setLHS(const string& L);

	void setRHS(const string& R);

	Point getInlet();
	Point getOutletTrue();
	Point getOutletFalse();

	virtual void Draw(Output* pOut) const;

	virtual bool Is_In_Region(Point& p1);
};

#endif