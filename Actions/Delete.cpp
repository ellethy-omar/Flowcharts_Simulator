
#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

Delete::Delete(ApplicationManager* pAppManager):Action(pAppManager)
{}


void Delete::ReadActionParameters()
{
	

	S = pManager->GetSelectedStatement();
	if (S == NULL)
	{
		C = pManager->GetSelectedCon();
	}
}


void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (S == NULL && C == NULL)
	{
		pOut->PrintMessage("No Connecotor or Statement is selected");
		return;
	}
	else
	{
		if (S != NULL)
		{
			
			pOut->PrintMessage("Deleting the selected statement");
			pManager->GetConnector(S->getInlet())->~Connector();
			S->~Statement();
		}
		else
		{
			pOut->PrintMessage("Deleting the selected connector");
			C->~Connector();
		}
	}
}
