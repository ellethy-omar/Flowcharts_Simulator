#include "Condition.h"
#include <sstream>

using namespace std;

Condition::Condition(Point UPpoint, string LeftHS, string ComparisonOperator, string RightHS) {
	LHS = LeftHS;
	RHS = RightHS;
	CompOperator = ComparisonOperator;

	UpdateStatementText();

	UpperPoint = UPpoint;

	pOutConn = NULL;	

	Inlet.x = UpperPoint.x;
	Inlet.y = UpperPoint.y;

	Outlet.x = Inlet.x;
	Outlet.y = UpperPoint.y + UI.COND_HI;/*UI.COND_HI*/
}

void Condition::setLHS(const string& R) {
	RHS = R;
	UpdateStatementText();
}

void Condition::setCompOperator(const string& C) {
	CompOperator = C;
	UpdateStatementText();
}

void Condition::setRHS(const string& R) {
	RHS = R;
	UpdateStatementText();
}

void Condition::Draw(Output* pOut) const {
	pOut->DrawCondtionalStat(UpperPoint, UI.COND_WDTH, UI.COND_HI, Text, Selected);
}

void Condition::UpdateStatementText() {
	ostringstream T;
	T << LHS << " " << CompOperator << " " << RHS;
	Text = T.str();
}


bool Condition::Is_In_Region(Point& p1) {
	Point Upper, Lower, Left, Right;
	Upper = UpperPoint;
	Lower.x = Upper.x;
	Lower.y = Upper.y + UI.COND_HI;
	Left.x = Upper.x - UI.COND_WDTH / 2;
	Left.y = Upper.y + UI.COND_HI / 2;
	Right.x = Upper.x + UI.COND_WDTH / 2;
	Right.y = Upper.y + UI.COND_HI / 2;

	if (p1.x < Left.x || p1.x > Right.x || p1.y < Upper.y || p1.y > Lower.y) {
		return false;
	}
	else {
		if (p1.x > Left.x && p1.x < Upper.x && p1.y < Left.y && p1.y > Upper.y) {

			float slopePwithUpper, slopePwithLeft;
			slopePwithUpper = (float)(p1.y - Upper.y) / (float)(p1.x - Upper.x);
			slopePwithLeft = (float)(p1.y - Left.y) / (float)(p1.x - Left.x);

			if (slopePwithLeft < slopePwithUpper) { return false; }
		}
		else if(p1.x > Upper.x && p1.x < Right.x && p1.y > Upper.y && p1.y < Right.y){

			float slopePwithUpper, slopePwithRight;
			slopePwithUpper = (float)(p1.y - Upper.y) / (float)(p1.x - Upper.x);
			slopePwithRight = (float)(p1.y - Right.y) / (float)(p1.x - Right.x);

			if (slopePwithUpper < slopePwithRight) { return false; }
		}
		else if (p1.x > Left.x && p1.x < Lower.x && p1.y > Left.y && p1.y < Lower.y) {

			float slopePwithLeft, slopePwithLower;
			slopePwithLeft = (float)(p1.y - Left.y) / (float)(p1.x - Left.x);
			slopePwithLower = (float)(p1.y - Lower.y) / (float)(p1.x - Lower.x);

			if (slopePwithLower < slopePwithLeft) { return false; }
		}
		else if (p1.x > Lower.x && p1.x < Right.x && p1.y < Lower.y && p1.y > Right.y) {

			float slopePwithLower, slopePwithRight;
			slopePwithLower = (float)(p1.y - Lower.y) / (float)(p1.x - Lower.x);
			slopePwithRight = (float)(p1.y - Right.y) / (float)(p1.x - Right.x);

			if (slopePwithRight < slopePwithLower) { return false; }
		}
	}

	return true;
}