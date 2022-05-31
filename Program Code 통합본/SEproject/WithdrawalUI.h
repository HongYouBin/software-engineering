#pragma once

// Class : WithdrawalUI
// Description: 회원탈퇴 기능의 Boundary Class
class WithdrawalUI
{
	Withdrawal* withdrawalPtr;       // Withdrawal 기능의 control class pointer
public:
	WithdrawalUI(Withdrawal* withdrawalPtr);
	void startInterface();
	void selectMembershipCancel(FILE* out_fp);
};

