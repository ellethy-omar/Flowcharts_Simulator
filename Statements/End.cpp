#include "End.h"


void End::Draw(Output* pOut)  const 
{
	pOut->DrawEnd(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Text);

};

void End::UpdateStatementText() {};

End::End(Point Center)
{
	kounter = 0;
	Connector* pOutConn=NULL;
	kounter++;
	Text = "END";
	this->Center = Center;

};

End::~End()
{
	kounter--;
}