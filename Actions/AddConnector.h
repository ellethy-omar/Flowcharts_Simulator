#pragma once
#ifndef ADD_CONNECTOR_H
#define ADD_CONNECTOR_H

#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"
#include "..\Connector.h"

class AddConnector : public Action
{
private:
	Point Position;

public:
	AddConnector(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

	Statement* ReadActionParametersConnectors(Statement*& s1);
};
#endif
