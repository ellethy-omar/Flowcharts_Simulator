#pragma once
#include "D:\PT_finalphase2\Phase 2 (1)\Phase 2\Phase2_Code\Actions\Action.h"
#include <iostream>
#include "D:\PT_finalphase2\Phase 2 (1)\Phase 2\Phase2_Code\Statements\Statement.h"

class AddVariableAssign : public Action
{
private:
	
	Point Position;
	string LHS;
	string RHS;
public:
	AddVariableAssign(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();

};

