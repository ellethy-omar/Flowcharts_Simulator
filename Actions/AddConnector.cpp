#include "AddConnector.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

AddConnector::AddConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
{}

Statement* AddConnector::ReadActionParametersConnectors(Statement* & s1)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Connector : Click on the first delivering statment");

	pIn->GetPointClicked(Position);

	while (pManager->GetStatement(Position) == NULL)
	{
		pOut->PrintMessage("Please, select on the delivering statment");
	}
	s1 = pManager->GetStatement(Position);

	Statement* s2 = NULL;

	pOut->PrintMessage("Successfully made delivering statment, now click on recieveing statment");
	pIn->GetPointClicked(Position);

	while (pManager->GetStatement(Position)->Is_In_Region(Position) == false)
	{
		pOut->PrintMessage("Please, select on the recieveing statment");
	}
	s2 = pManager->GetStatement(Position);
	return s2;
}

void AddConnector::Execute()
{
	Statement* stat1 = NULL;
	Statement* stat2 = ReadActionParametersConnectors(stat1);

	int x = pManager->GetStatCount();
	ForbiddenReigon* ForbiddenArr = new ForbiddenReigon[x];

	for (int i = 0; i < x; i++)
	{
		ForbiddenArr[i] = pManager->GetStatementIteration(i)->GetForbiddenReigon();
	}
	Connector* pCond = new Connector(stat1, stat2, ForbiddenArr , x);
	

}

