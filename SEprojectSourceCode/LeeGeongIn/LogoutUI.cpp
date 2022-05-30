#pragma once
#include "LogoutUI.h"
#include "Logout.h"
#include <string>
using namespace std;
#define MAX_STRING 32

class Logout;

// Function: LogoutUI(Logout* logoutPtr, FILE* out_fp)
// Description: LogoutUI Class의 매개변수 생성자
// Parameter: Logout* logoutPtr- Logout Control Class 객체의 주소를 받는 포인터 매개변수, FILE* out_fp - 출력 파일 포인터
// Return Value: None
// Author: 이정인
LogoutUI::LogoutUI(Logout* logoutPtr, FILE* out_fp)
{
	this->logoutPtr = logoutPtr;
	this->selectLogout(out_fp);
}


// Function: selectLogout(FILE* out_fp)
// Description: 현재 로그인된 회원을 로그아웃 처리하는 Control Class의 logout 함수 호출
//              로그아웃 처리 이후 탈퇴 회원 ID를 사용자에게 출력
// Parameter: FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void LogoutUI::selectLogout(FILE* out_fp)
{
	char logoutID[MAX_STRING];
	strcpy(logoutID, (this->logoutPtr->logout()).c_str());
	fprintf(out_fp, "2.2. 로그아웃\n");
	fprintf(out_fp, "> %s\n", logoutID);
}
