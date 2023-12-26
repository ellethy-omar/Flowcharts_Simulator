#pragma once
#ifndef END_H
#define END_H

#include "Statement.h"


class End : public Statement 
{
private:
	Point Inlet;

	Point Center;	//Center of the statement block.

	virtual void UpdateStatementText();

public:

	End(Point Center);

	Point getOutlet(int x = 0);

	Point getInlet();

	virtual void Draw(Output* pOut) const;

	~End();

	virtual bool Is_In_Region(Point& p1);

	void SetConnector(Connector* pOutConn);

	Connector* GetConnector(int checker = 0);

};
#endif
