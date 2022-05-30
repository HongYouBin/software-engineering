#pragma once
#include "LoginUI.h"
#include "ManageMember.h"

class LoginUI;
class ManageMember;

// Class : Login
// Description: 로그인 기능의 Control Class
class Login
{
	LoginUI* loginUIPtr;                // Login 기능의 boundary class pointer
	ManageMember* manageMemberPtr;      // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Login(ManageMember* manageMemberPtr);
	LoginUI* getLoginUIPtr();
	int checkMember(string ID, string password);

};
