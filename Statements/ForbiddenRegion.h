#pragma once
#include "..\GUI\UI_Info.h"
class ForbiddenReigon
{
	friend class Statement;
	friend class End;
	friend class Start;
	friend class Condition;
	friend class ValueAssign;
	friend class VariableAssign;
	friend class OperAssign;

protected:
	Point pf1;
	Point pf2;
	Point pf3;
	Point pf4;

public:

	bool Isforbidden(Point P) const;

	// . = P
							//.
	//		pf1	____________________________ pf2
	//			|						 |
	//			|	___________________  |
	//			|	|				  |	 |
	//		.	|	|			.	  |	 |	.
	//			|	|		statement |	 |
	//			|	|				  |	 |
	//			|	-------------------	 |
	//			|		forbidden extra	 |
	//			|						 |
	//		pf4	-------------------------- pf3
							//.
	
	ForbiddenReigon();


};
