#pragma once

class Withdrawal
{
	WithdrawalUI* withdrawalUIPtr;
	ManageMember* manageMemberPtr;
public:
	Withdrawal(ManageMember* manageMemberPtr);
	WithdrawalUI* getWithdrawalUIPtr();
	string cancelMembership();
};

