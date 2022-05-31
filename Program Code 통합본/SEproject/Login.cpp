#pragma once
#include "Login.h"
#include <string>
using namespace std;

// Function: Login(ManageMember* manageMemberPtr)
// Description: Login Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Login::Login(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->loginUIPtr = new LoginUI(this);
	this->loginUIPtr->startInterface();
}


// Function: getLoginUIPtr()
// Description: LoginUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: LoginUI*
// Author: 이정인
LoginUI* Login::getLoginUIPtr()
{
	return this->loginUIPtr;
}


// Function: checkMember(string ID, string password)
// Description: 회원가입된 사용자가 맞는지 확인하는 ManageMember의 checkMember함수 호출
// Parameter: string ID - 회원 ID, string password - 비밀번호
// Return Value: int
// Author: 이정인
int Login::checkMember(string ID, string password)
{
	return (this->manageMemberPtr->checkMember(ID, password));
}
