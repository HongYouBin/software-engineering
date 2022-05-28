#pragma once
#include "LoginUI.h"

#define MAX_STRING 32

LoginUI::LoginUI(Login* loginPtr)
{
	this->loginPtr = loginPtr;
}

void LoginUI::InputIDPW(FILE* in_fp, FILE* out_fp)
{
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	int isMember = 0;
	isMember = this->loginPtr->checkMember(ID, password);
	
	if (isMember == 1)
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "%s %s\n", ID, password);
	}
	else
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "회원가입되지 않은 사용자입니다. 회원가입을 진행해주세요.\n");
	}
}

void LoginUI::startInterface()
{
	cout << "아이디와 비밀번호를 입력해주세요." << endl;
}
