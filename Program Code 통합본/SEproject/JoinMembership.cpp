#pragma once
#include "JoinMembership.h"
#include <string>

// Function: JoinMembership(ManageMember* manageMemberPtr)
// Description: JoinMembership Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
JoinMembership::JoinMembership(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	JoinMembership* thisClassPtr = this;
	this->joinMembershipUIPtr = new JoinMembershipUI(thisClassPtr);
	this->joinMembershipUIPtr->startInterface();
}


// Function: getJoinMembershipUIPtr()
// Description: JoinMembershipUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: JoinMembershipUI*
// Author: 이정인
JoinMembershipUI* JoinMembership::getJoinMembershipUIPtr()
{
	return this->joinMembershipUIPtr;
}


// Function: addNewMember(string name, string SSN, string ID, string password)
// Description: 새 회원을 등록시키는 ManageMember의 createMember 함수 호출
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: void
// Author: 이정인
void JoinMembership::addNewMember(string name, string SSN, string ID, string password)
{
	this->manageMemberPtr->createMember(name, SSN, ID, password);
}
