#pragma once
#include "LogoutUI.h"
#include "ManageMember.h"
#include "Logout.h"
#include <string>
using namespace std;

LogoutUI::LogoutUI(ManageMember* manageMemberPtr, FILE* out_fp)
{
	Logout* logoutPtr = new Logout(manageMemberPtr);
	this->selectLogout(out_fp);
}

void LogoutUI::selectLogout(FILE* out_fp)
{
	string logoutID = this->logoutPtr->logout();
	fprintf(out_fp, "2.2. ·Î±×¾Æ¿ô\n");
	fprintf(out_fp, "%s\n", logoutID);
}
