#include "Actions/AddVariableAssign.h"
#include <iostream>
#include"Actions\Action.h"
#include "D:\PT_finalphase2\Phase 2 (1)\Phase 2\Phase2_Code\Statements\Statement.h"
#include "Statements\Statement.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Statements/VariableAssign.h"
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void AddVariableAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Add the LHS for the statment");
	LHS = pIn->GetVariable(pOut);
	pOut->PrintMessage("Add the RHS for the statment");
	RHS = pIn->GetVariable(pOut);
}

void AddVariableAssign::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
	VariableAssign* pAssign = new VariableAssign(Corner, LHS, RHS);
	pManager->AddStatement(pAssign);            
}

