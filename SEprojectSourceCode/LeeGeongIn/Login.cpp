#pragma once
#include "Login.h"
#include "ManageMember.h"
#include "LoginUI.h"
#include <string>
using namespace std;

Login::Login(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->loginUIPtr = new LoginUI(this);
	this->loginUIPtr->startInterface();
}

LoginUI* Login::getLoginUIPtr()
{
	return this->loginUIPtr;
}

int Login::checkMember(string ID, string password)
{
	return (this->manageMemberPtr->checkMember(ID, password));
}
