#pragma once
#include "Withdrawal.h"
#include "ManageMember.h"
#include "WithdrawalUI.h"
#include <string>
using namespace std;

Withdrawal::Withdrawal(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	WithdrawalUI* withdrawalUIPtr = new WithdrawalUI(this);
	withdrawalUIPtr->startInterface();
}

WithdrawalUI* Withdrawal::getWithdrawalUIPtr()
{
	return this->withdrawalUIPtr;
}

string Withdrawal::cancelMembership()
{
	return (this->manageMemberPtr->deleteMember());
}
