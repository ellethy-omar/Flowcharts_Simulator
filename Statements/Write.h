#pragma once
#include"Statement.h"
class Write :public Statement
{
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point Center;
	string print;
	int Type;
public:
	Write(Point corner, string text);
	virtual void Draw(Output* pOut) const;
	void UpdateStatementText();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point getInlet();
	virtual Point getOutlet(int x = 0);
	bool Is_In_Region(Point& p1);
	void SetConnector(Connector* pOutConn);
	Connector* GetConnector(int checker = 0);
	string GetPrint();
	void Simulate(string(&allvariables)[200], double(&corespondingarray)[200], int& CountOfVariables, Output* pOut, Input* pIn, int writecount);
	bool IsWriteVariable();
	string getprint();
};

