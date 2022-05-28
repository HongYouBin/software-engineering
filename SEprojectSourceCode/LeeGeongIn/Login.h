#pragma once

class Login
{
	LoginUI* loginUIPtr;
	ManageMember* manageMemberPtr;
public:
	Login(ManageMember* manageMemberPtr);
	LoginUI* getLoginUIPtr();
	int checkMember(string ID, string password);

};

