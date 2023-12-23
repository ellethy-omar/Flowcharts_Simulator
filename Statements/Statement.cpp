#include "Statement.h"

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;
	Point P;
	P.x = 400, P.y = 500;
	 F.pf1 = P;
	 F.pf2 = P;
	 F.pf3 = P;
	 F.pf4 = P;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

bool Statement::isForbidden(Point & p1) const
{
	return F.Isforbidden(p1);
}

 ForbiddenReigon Statement::GetForbiddenReigon() const
 {
	 return F;
 }