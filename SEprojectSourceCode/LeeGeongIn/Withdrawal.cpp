#pragma once
#include "Withdrawal.h"
#include <string>
using namespace std;

// Function: Withdrawal(ManageMember* manageMemberPtr)
// Description: Withdrawal Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Withdrawal::Withdrawal(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->withdrawalUIPtr = new WithdrawalUI(this);
	withdrawalUIPtr->startInterface();
}


// Function: getWithdrawalUIPtr()
// Description: WithdrawalUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: WithdrawalUI*
// Author: 이정인
WithdrawalUI* Withdrawal::getWithdrawalUIPtr()
{
	return this->withdrawalUIPtr;
}


// Function: cancelMembership()
// Description: 회원 정보를 삭제하는 ManageMember의 deleteMember함수 호출
// Parameter: None
// Return Value: string
// Author: 이정인
string Withdrawal::cancelMembership()
{
	return this->manageMemberPtr->deleteMember();
}
