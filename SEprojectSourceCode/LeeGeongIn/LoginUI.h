#pragma once

// Class : LoginUI
// Description: 로그인 기능의 Boundary Class
class LoginUI
{
	Login* loginPtr;           // Login 기능의 control class pointer
public:
	LoginUI(Login* loginPtr);

	void InputIDPW(FILE* in_fp, FILE* out_fp);
	void startInterface();
};

