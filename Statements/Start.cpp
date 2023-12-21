#include "Start.h"


void Start::Draw(Output* pOut)  const
{
	pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text);

};

void Start::UpdateStatementText() {};

Start::Start(Point Center)
{
	kounter = 0;
	Connector* pOutConn = NULL;
	kounter++;
	Text = "START";
	this->Center = Center;

};

Start::~Start()
{
	kounter--;
}