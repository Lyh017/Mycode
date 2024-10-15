#define _CRT_SECURE_NO_WARNINGS
#include"PersonalFinanaceManager.h"
#include"userInterface.h"

int main()
{
	FinanceManager fm;
	userInterface ui;
	ui.handleUserInterface(fm);
	
	return 0;
}