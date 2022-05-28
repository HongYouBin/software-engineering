#pragma once
class LogoutUI
{
	Logout* logoutPtr;
public:
	LogoutUI(ManageMember* manageMemberPtr, FILE* out_fp);
	void selectLogout(FILE* out_fp);
};

