#pragma once
#include "WithdrawalUI.h"
#include "ManageMember.h"

class WithdrawalUI;
class ManageMember;

// Class : Withdrawal
// Description: 회원탈퇴 기능의 Control Class
class Withdrawal
{
	WithdrawalUI* withdrawalUIPtr;       // Withdrawal 기능의 boundary class pointer
	ManageMember* manageMemberPtr;       // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Withdrawal(ManageMember* manageMemberPtr);
	WithdrawalUI* getWithdrawalUIPtr();
	string cancelMembership();
};
