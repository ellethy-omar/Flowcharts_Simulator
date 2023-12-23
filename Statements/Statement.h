#pragma once
#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"
#include "ForbiddenRegion.h"
//Base class for all Statements
class ForForbiddenReigon;

class Statement
{
protected:

	int ID;			//Each Statement has an ID --> must be unique

	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)

	bool Selected;	//true if the statement is selected on the folwchart

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.
	/*ForbiddenReigon F;*/

public:

	Statement();
	virtual Point getInlet() = 0;
	virtual Point getOutlet() = 0;
	void SetSelected(bool s);

	bool IsSelected() const;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement

	virtual bool Is_In_Region(Point & p1) = 0;
	
	virtual bool isForbidden(Point & p1) const;

	//virtual ForbiddenReigon GetForbiddenReigon() const;

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed

};

#endif
