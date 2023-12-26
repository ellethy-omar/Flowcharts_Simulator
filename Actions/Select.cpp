#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"


Select::Select(ApplicationManager* pAppManager):Action(pAppManager)
{
	S = NULL;
	C = NULL;
}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Select action: click on a statement or a connector to select / unselect");
	pIn->GetPointClicked(Position);

	while (pManager->GetStatement(Position) == NULL && pManager->GetConnector(Position))
	{
		pOut->PrintMessage("Please click on a statement or a connector to select / unslect");
		pIn->GetPointClicked(Position);
	}
	if (pManager->GetStatement(Position) != NULL)
	{
		S = pManager->GetStatement(Position);
		for (int i = 0; i < pManager->GetStatCount(); i++)
		{
			if (S == pManager->GetStatementIteration(i))
			{
				ID = pManager->GetStatementIteration(i)->GetID();
			}
		}
	}
	else if (pManager->GetConnector(Position) != NULL)
	{
		C = pManager->GetConnector(Position);
		for (int i = 0; i < pManager->GetConnectorCount(); i++)
		{
			if (C == pManager->GetConnector(i))
			{
				ID = pManager->GetConnector(i)->GetID();
			}
		}
	}

}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (S != NULL)
	{
		S->SetSelected(!(S->GetSelected()));
		S->Draw(pOut);
	}
	if (C != NULL)
	{
		C->SetSelected(!(C->GetSelected()));
		S->Draw(pOut);
	}
}
