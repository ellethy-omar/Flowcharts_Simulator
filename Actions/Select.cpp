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
	}
	else
	{
		C = pManager->GetConnector(Position);
	}

}


void Select::Execute()
{
	ReadActionParameters();
	if (pManager->GetStatement(Position) != NULL)
	{
		S->SetSelected(!(S->GetSelected()));
	}
	else
	{
		C->SetSelected(!(C->GetSelected()));
	}
}
