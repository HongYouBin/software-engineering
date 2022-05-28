#pragma once
#include "JoinMembership.h"
#include "ManageMember.h"
#include "JoinMembershipUI.h"
#include <string>

JoinMembership::JoinMembership(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	JoinMembership *thisClassPtr = this;
	this->joinMembershipUIPtr = new JoinMembershipUI(thisClassPtr);
	this->joinMembershipUIPtr->startInterface();
}

JoinMembershipUI* JoinMembership::getJoinMembershipUIPtr()
{
	return this->joinMembershipUIPtr;
}

void JoinMembership::addNewMember(string name, string SSN, string ID, string password)
{
	this->manageMemberPtr->createMember(name, SSN, ID, password);
}
