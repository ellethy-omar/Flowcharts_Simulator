#pragma once
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"
#include "..\Actions/AddVariableAssign.h"
class VariableAssign :  public Statement
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
	VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);

	void setRHS(string R);

	Point getInlet();

	Point getOutlet(int x = 0);

	virtual void Draw(Output* pOut) const;

	bool Is_In_Region(Point& p1);

	void SetConnector(Connector* pOutConn);

	Connector* GetConnector(int checker = 0);

	~VariableAssign();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);


};

