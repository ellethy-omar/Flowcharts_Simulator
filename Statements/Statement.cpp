#include "Statement.h"

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;
	
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

void Statement::setID(int id)
{
	ID = id;
}

int Statement::GetID() const
{
	return ID;
}

bool Statement::GetSelected()
{
	return Selected;
}

void Statement::Simulate(string(&allvariables)[200], double(&corespondingarray)[200], int& CountOfVariables, Output* pOut, Input* pIn, int writecount)
{
}

Statement::~Statement()
{
}
