#pragma once
class LoginUI
{
	Login* loginPtr;
public:
	LoginUI(Login* loginPtr);

	void InputIDPW(FILE* in_fp, FILE* out_fp);
	void startInterface();
};

