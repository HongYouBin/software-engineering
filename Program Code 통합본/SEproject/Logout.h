#pragma once
#include "ManageMember.h"

class ManageMember;

// Class : Logout
// Description: 로그아웃 기능의 Control Class
class Logout
{
	ManageMember* manageMemberPtr;       // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Logout(ManageMember* manageMemberPtr);
	string logout();
};

