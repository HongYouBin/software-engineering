#pragma once
#include "Logout.h"
#include "ManageMember.h"
#include <string>
using namespace std;

Logout::Logout(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
}

string Logout::logout()
{
	return this->manageMemberPtr->deleteLoggedMember();
}
