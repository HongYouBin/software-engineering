#pragma once
#include "JoinMembershipUI.h"
#include "JoinMembership.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

// Function: JoinMembershipUI(JoinMembership* joinMembershipPtr)
// Description: JoinMembershipUI Class의 매개변수 생성자
// Parameter: JoinMembership* joinMembershipPtr- JoinMembership Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
JoinMembershipUI::JoinMembershipUI(JoinMembership* joinMembershipPtr)
{
	this->joinMembershipPtr = joinMembershipPtr;
}


// Function: startInterface()
// Description: JoinMembership 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void JoinMembershipUI::startInterface()
{
	cout << "회원가입 정보를 입력해주세요" << endl;
}


// Function: inputPersonalInfo(FILE* in_fp, FILE* out_fp)
// Description: 사용자로부터 회원 정보를 입력받고, Control Class의 addNewMember 함수 호출
//              회원 등록 이후 결과를 사용자에게 출력
// Parameter: FILE* in_fp - 입력 파일 포인터, FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void JoinMembershipUI::inputPersonalInfo(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

	this->joinMembershipPtr->addNewMember(name, SSN, ID, password);

	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, SSN, ID, password);
}
