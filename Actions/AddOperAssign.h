#pragma once
#ifndef ADD_OPERATOR_ASSIGN_H
#define ADD_OPERATOR_ASSIGN_H
#include "Action.h"
#include "..\ApplicationManager.h"
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

#endif
