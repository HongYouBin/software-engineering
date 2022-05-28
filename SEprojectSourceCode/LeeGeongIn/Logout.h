#pragma once
class Logout
{
	ManageMember* manageMemberPtr;
public:
	Logout(ManageMember* manageMemberPtr);
	string logout();
};

