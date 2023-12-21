#pragma once
#ifndef END_H
#define END_H

#include "Statement.h"


class End : public Statement 
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)

	Connector* pOutConn;
	int kounter;
	//Value Assignment Stat. has one Connector to next statement
	//Each statement type in flowchart has a predefined number of (output) connectors
	//For example, conditional statement always has 2 output connectors

	//Note: We don't need to keep track with input connectors
	//      Whenever we want to iterate on all statements of the flowchart
	//      we will begin with start statement then its output connector
	//      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors

	Point Center;	//Center of the statement block.

	virtual void UpdateStatementText();


public:

	End(Point Center);

	virtual void Draw(Output* pOut) const;

	~End();

};
#endif