#pragma once

class WithdrawalUI
{
	Withdrawal* withdrawalPtr;
public:
	WithdrawalUI(Withdrawal* withdrawalPtr);
	void startInterface();
	void selectMembershipCancel(FILE* out_fp);
};

