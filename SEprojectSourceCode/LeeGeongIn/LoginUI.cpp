#pragma once
#include "LoginUI.h"
#include "Login.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

// Function: LoginUI(Login* loginPtr)
// Description: LoginUI Class의 매개변수 생성자
// Parameter: Login* loginPtr- Login Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
LoginUI::LoginUI(Login* loginPtr)
{
	this->loginPtr = loginPtr;
}


// Function: InputIDPW(FILE* in_fp, FILE* out_fp)
// Description: 사용자로부터 ID, password 정보를 입력받고, Control Class의 checkMember 함수 호출
//              회원 여부 체크 이후 로그인 결과를 사용자에게 출력
// Parameter: FILE* in_fp - 입력 파일 포인터, FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void LoginUI::InputIDPW(FILE* in_fp, FILE* out_fp)
{
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	int isMember = 0;
	isMember = this->loginPtr->checkMember(ID, password);

	if (isMember == 1)
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> %s %s\n", ID, password);
	}
	else
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> 회원가입되지 않은 사용자입니다. 회원가입을 진행해주세요.\n");
	}
}


// Function: startInterface()
// Description: Login 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void LoginUI::startInterface()
{
	cout << "아이디와 비밀번호를 입력해주세요." << endl;
}