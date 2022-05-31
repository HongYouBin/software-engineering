#pragma once
#include "Logout.h"
#include <string>
using namespace std;

// Function: Logout(ManageMember* manageMemberPtr)
// Description: Logout Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Logout::Logout(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;

}


// Function: logout()
// Description: 현재 저장된 로그인 정보를 삭제하기 위해 ManageMember class의 deleteLoggedMember함수 호출
// Parameter: None
// Return Value: string
// Author: 이정인
string Logout::logout()
{
	return this->manageMemberPtr->deleteLoggedMember();
}
