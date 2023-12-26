#include "Actions\AddRead.h"
#include "Actions\AddWrite.h"
#include "Actions\AddCondition.h"
#include "Actions\AddEnd.h"
#include "Actions\AddOperAssign.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddStart.h"
#include "Actions\AddValueAssign.h"
//#include "Actions/Select.h"
//#include "Actions/Delete.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <fstream>
//Constructor

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	Point P;
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;

		case ADD_OPER_ASSIGN:
			pAct = new AddOperAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new AddCondition(this);
			break;

		case ADD_READ:
			/*pAct = new AddRead(this);
			break;*/

		case ADD_WRITE:
			/*pAct = new AddWrite(this);
			break;*/

		case ADD_CONNECTOR:
			if (StatCount < 2)
			{
				pOut->PrintMessage("please , add 2 statements in the drawing area to be able to use the connectors");
			}
			else
			{
				AddConnector(ConnList[ConnCount]);
			}	
			break;

		case SELECT:
			pOut->PrintMessage("Action: select action, Click anywhere");
			break;

		case EDIT_STAT:
			pOut->PrintMessage("Action: edit statement action, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: delete action, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case COPY:
			pOut->PrintMessage("Action: copy action, Click anywhere");
			break;

		case CUT:
			pOut->PrintMessage("Action: cut action, Click anywhere");
			break;

		case PASTE:
			pOut->PrintMessage("Action: paste action, Click anywhere");
			break;

		case SAVE:
			pOut->PrintMessage("Action: save action, Click anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: load action, Click anywhere");
			break;

		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
			break;

		case SWITCH_DSN_MODE:
			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the drawing area, click to continue");
			break;

		case OUTPUT_AREA:
			pOut->PrintMessage("Action: a click on the output area, click to continue");
			break;

		case VALIDATE:
			pOut->PrintMessage("Action: validate, click to continue");
			break;

		case RUN:
			pOut->PrintMessage("Action: run, click to continue");
			break;

		case SIM_TOOL:
			pOut->PrintMessage("Action: a click on the Simulation Tool Bar, Click anywhere");
			break;

		case EXIT:
			break;

		case STATUS:
			return;
	}
	//Execute the created action	
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		
	}	
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	StatList[StatCount - 1]->setID(StatCount);
	
}

int ApplicationManager::GetStatCount() const
{
	return StatCount;
}

int ApplicationManager::GetConnectorCount() const
{
	return ConnCount;
}

void ApplicationManager::AddConnector(Connector* pConn)
{

	Point Position;
	Statement* s1 = NULL;
	Statement* s2 = NULL;

	pOut->PrintMessage("Connector : Click on the first delivering statment");
	pIn->GetPointClicked(Position);
	s1 = GetStatement(Position);

	Statement* test;
	test = dynamic_cast<End*>(s1);

	while (GetStatement(Position) == NULL || test != NULL)
	{
		pOut->PrintMessage("Please, select on the delivering statment such that it isn't a start statement");
		pIn->GetPointClicked(Position);
	
		s1 = GetStatement(Position);
		test = dynamic_cast<End*>(s1);
	}
	int x = 0;
	test = dynamic_cast<Condition*>(s1);
	if (test != NULL) 
	{
		pOut->PrintMessage("Selected a Condion statement  Enter 1 for true, Enter 2 for false, then click on the conditonal again to continue");
		pIn->GetPointClicked(Position);
		x = int(pIn->GetValue(pOut));
		while (GetStatement(Position) != s1)
		{
			pOut->PrintMessage("Click on the same conditional to confirm");
			pIn->GetPointClicked(Position);
		}
		while ((x != 1) && (x != 2))
		{
			x = int(pIn->GetValue(pOut));
		}
	}

	pOut->PrintMessage("Successfully made delivering statment, now click on recieveing statment");
	pIn->GetPointClicked(Position);

	s2 = GetStatement(Position);
	test = dynamic_cast<Start*>(s1);


	while ((GetStatement(Position) == NULL || GetStatement(Position) == s1) || test != NULL)
	{
		pOut->PrintMessage("Please, select on the recieveing statment");
		pIn->GetPointClicked(Position);
		s2 = GetStatement(Position);
		test = dynamic_cast<Start*>(s1);
	}
	
	s2 = GetStatement(Position);
	pConn = new Connector(s1, s2);
	ConnList[ConnCount] = pConn;
	pConn->setID(ConnCount);
	ConnCount++;
}

Connector* ApplicationManager::GetConnector(Point P) const
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->Is_In_Region(P) == true)
		{
			return ConnList[i];
		}
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
Statement* ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->Is_In_Region(P) == true)
		{
			return StatList[i];
		}
	}
	return NULL;
}

Statement* ApplicationManager::GetStatementIteration(int i)
{
	if (i< StatCount)
	{
		return StatList[i];
	}
	return NULL;
}


////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{
	if (pSelectedStat != NULL)
	{
		pSelectedStat->SetSelected(false);
	}
	if (ConSelected != NULL)
	{
		ConSelected->SetSelected(false);
	}
	pSelectedStat = pStat;
	pSelectedStat->SetSelected(true);
}

Connector* ApplicationManager::GetSelectedCon() const
{
	return ConSelected;
}

void ApplicationManager::SetSelectedCon(Connector* pCon)
{
	if (pSelectedStat != NULL)
	{
		pSelectedStat->SetSelected(false);
	}
	if (ConSelected != NULL)
	{
		ConSelected->SetSelected(false);
	}
	ConSelected = pCon;
	ConSelected->SetSelected(true);
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		if (StatList[i] != NULL)
			StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		if (StatList[i] != NULL)
			ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
	{
		if (StatList[i]!= NULL)
			delete StatList[i];
	}
	for(int i=0; i<ConnCount; i++)
	{
		if (StatList[i] != NULL)
			delete ConnList[i];
	}
	delete pIn;
	delete pOut;
}
//save
void ApplicationManager::SaveAll(ofstream& OutFile) {
	OutFile << StatCount<<endl;
	for (int i = 0; i < StatCount; i++) {
		StatList[i]->Save(OutFile);
	}
	/*for (int i = 0; i < ConnCount; i++) {
		ConnList[i]->save(OutFile);
	}
