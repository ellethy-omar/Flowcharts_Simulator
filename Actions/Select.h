#ifndef SELECT_H
#define SELECT_H

#include "..\ApplicationManager.h"
#include "Action.h"
class Select : public Action
{
private:
	Point Position;
	Statement* S;
	Connector* C;

public:

	Select(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif