#include "LoadAction.h"
#include "ApplicationManager.h"
#include<fstream>
#include<iostream>
#include<string.h>
#include"Statements/statement.h"
#include"Read.h"
#include"Write.h"
#include"Actions/Action.h"
LoadAction::LoadAction(ApplicationManager* pAppManager) :Action(pAppManager) {};

void LoadAction::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if(invalid=true){
		pOut->PrintMessage("Enter A Valid File Name To Load From");
		File_Name = pIn->GetString(pOut);
		File_Name += ".txt";
	}
	else {
		pOut->PrintMessage("Enter File Name To Load From");
		File_Name = pIn->GetString(pOut);
		File_Name += ".txt";
	}
};
void LoadAction::Execute() {
	Point ptdummy;
	string strdummy;
	Action* pAct;
	Statement* pstat;
	invalid = false;
	int value=0 ;
	bool valid = false;
	ifstream MyFile;
	while (valid==false) {
		ReadActionParameters();
		MyFile.open(File_Name);
		if (MyFile.is_open()) {
			valid = true;
		}
		else {
			invalid = true;
		}
	}
	string StatType;
	int count;
	if (MyFile.is_open()) { 
		MyFile >> count; 
	}
	for (int i = 0; i < count; i++) {
		MyFile >> StatType;

		if (StatType == "READ") {
			pstat = new Read(ptdummy, strdummy, value);
			pstat->Load(MyFile);
			pManager->AddStatement(pstat);
		}
		if (StatType == "WRITE") {
			pstat = new Write(ptdummy, strdummy);
			pstat->Load(MyFile);
			pManager->AddStatement(pstat);
		}



	}
	pManager->UpdateInterface();

};
