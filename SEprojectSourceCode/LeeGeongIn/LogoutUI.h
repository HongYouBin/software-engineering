#pragma once

// Class : LogoutUI
// Description: 로그아웃 기능의 Boundary Class
class LogoutUI
{
	Logout* logoutPtr;     // Logout 기능의 control class pointer
public:
	LogoutUI(Logout* logoutPtr, FILE* out_fp);
	void selectLogout(FILE* out_fp);
};
