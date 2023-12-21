#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class AddOperAssign : public Action
{
private:
	Point Position;
	string LHS;
	string RHS;
public:
	AddOperAssign (ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

