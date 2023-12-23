#include "..\Actions\AddOperAssign.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Statements\OperAssign.h"
AddOperAssign::AddOperAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void AddOperAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Point dummyp;
	bool conti = false;
	while (conti == false)
	{
		pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

		pIn->GetPointClicked(Position);
		if ((((Position.x) + UI.ASSGN_WDTH / 2) >= 0.75 * UI.width) || (Position.y <= UI.ToolBarHeight) || (Position.y + UI.ASSGN_HI >= UI.height - UI.StatusBarHeight))
		{
			pOut->PrintMessage("you cannot draw in this area,click to continue");
			pIn->GetPointClicked(dummyp);
		}
		else
		{
			conti = true;
		}
	}

	pOut->ClearStatusBar();

	pOut->PrintMessage("Add the LHS for the statment");
	LHS = pIn->GetVariable(pOut);
	/*pOut->PrintMessage("Add the RHS for the statment");
	RHS = pIn->GetVariable(pOut);*/
	bool Continue = false;
	string RHS1;
	while (Continue == false)
	{
		//cout << "enter the RHS of the statment" << endl;
		pOut->PrintMessage("Add the RHS for the statment");

		
		Point dummy;
		string BeforeArithmaticOperator;
		string BeforeArithmaticOperator_WithotSpaces;
		string AfterArithmaticOperator;
		string AfterArithmaticOperator_WithotSpaces;
		int arithmaticoperator = 0;
		int ArithmaticOperator_Index = 0;
		int BAOWScount = 0;
		int AAOWScount = 0;
		RHS1 = pIn->GetString(pOut);

		for (int i = 0; i < RHS1.length(); i++)
		{
			if (RHS1[i] == '+' || RHS1[i] == '/' || RHS1[i] == '*' || RHS1[i] == '-')
			{
				arithmaticoperator++;
				ArithmaticOperator_Index = i;
			}
		}
		if (arithmaticoperator > 1)
		{

			pOut->PrintMessage( "there can only be ONE arithmatic operator,click anywhere to continue") ;
			pIn->GetPointClicked(dummy);
		}
		else if (arithmaticoperator == 0)
		{
			pOut->PrintMessage("there must be exactly one arihtmatic operator,click anywhere to continue");
			pIn->GetPointClicked(dummy);
		}
		else if (arithmaticoperator == 1)
		{
			if (ArithmaticOperator_Index != 0 && ArithmaticOperator_Index != RHS1.length()-1)
			{
				BeforeArithmaticOperator = RHS1.substr(0, ArithmaticOperator_Index);
				int leadingzerosbefore = BeforeArithmaticOperator.find_first_not_of(" \t");
				int endingzerosbefore = BeforeArithmaticOperator.find_last_not_of(" \t");
				BeforeArithmaticOperator_WithotSpaces = BeforeArithmaticOperator.substr(leadingzerosbefore, endingzerosbefore - leadingzerosbefore + 1);
				if (ValueOrVariable(BeforeArithmaticOperator_WithotSpaces) == 2)
				{
					pOut->PrintMessage("what you entered Before the Arithmatic Operator is neither a varibale nor a value,click anywhere to continue");
					pIn->GetPointClicked(dummy);
				}
				AfterArithmaticOperator = RHS1.substr(ArithmaticOperator_Index + 1);
				int leadingzerosafter = AfterArithmaticOperator.find_first_not_of(" \t");
				int endingzerosafter = AfterArithmaticOperator.find_last_not_of(" \t");
				AfterArithmaticOperator_WithotSpaces = AfterArithmaticOperator.substr(leadingzerosafter, endingzerosafter - leadingzerosafter + 1);
				if (ValueOrVariable(AfterArithmaticOperator_WithotSpaces) == 2)
				{
					pOut->PrintMessage("what you entered After the Arithmatic Operator is neither a varibale nor a value,click anywhere to continue");
					pIn->GetPointClicked(dummy);
				}
				if (ValueOrVariable(AfterArithmaticOperator_WithotSpaces) != 2 && ValueOrVariable(BeforeArithmaticOperator_WithotSpaces) != 2)
				{
					Continue = true;
				}
			}
			else
			{
				if(ArithmaticOperator_Index == 0)
				pOut->PrintMessage("there is nothing before the arithmatic operator,click anywhere to continue");
				else
					pOut->PrintMessage("there is nothing after the arithmatic operator,click anywhere to continue");

				pIn->GetPointClicked(dummy);
			}
		}
	}
	RHS = RHS1;
}

void AddOperAssign::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
	OperAssign* pAssign = new OperAssign(Corner, LHS, RHS);
	pManager->AddStatement(pAssign);
}




