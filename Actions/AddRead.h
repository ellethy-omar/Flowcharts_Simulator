#pragma once
#include "Actions/Action.h"
#include <WinUser.h>
class AddRead:public Action
{
	string variable;
	Point Position;
	double Value;
public:
	AddRead(ApplicationManager* pAppManager) ;
	void Execute();
	void ReadActionParameters();




};

