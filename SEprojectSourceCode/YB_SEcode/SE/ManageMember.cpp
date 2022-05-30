#pragma once
#include "ManageMember.h"
#include "Member.h"
#include <string>
#include <vector>
using namespace std;

string ManageMember::getSellerID()
{
	return loggedMembers.back().getID();
}

void ManageMember::createMember(string name, string SSN, string ID, string password)
{
	Member* newMember = new Member(name, SSN, ID, password);
	memberDB.push_back(*newMember);
}

int ManageMember::checkMember(string ID, string password)
{
	int checkedMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == ID)
		{
			checkedMemberIndex = i;
			break;
		}
	}
	if (checkedMemberIndex < 0)
	{
		return 0;
	}
	else
	{
		Member* loginMember = memberDB[checkedMemberIndex].registerLoggedMember();
		loggedMembers.push_back(*loginMember);
		return 1;
	}
}

string ManageMember::deleteMember()
{
	string deleteMemberID = loggedMembers.back().getID();
	int deleteMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == deleteMemberID)
		{
			deleteMemberIndex = i;
			break;
		}
	}
	memberDB.erase(memberDB.begin() + deleteMemberIndex);
	loggedMembers.pop_back();
	return deleteMemberID;
}

string ManageMember::deleteLoggedMember()
{
	string logoutMemberID = loggedMembers.back().getID();
	loggedMembers.pop_back();
	return logoutMemberID;
}

void ManageMember::addPurchaseList(char* productName)
{
	Member modifiedMember = loggedMembers.pop_back();
	modifiedMember.purchaseList.push(productName);
	loggedMember.push(modifiedMember);
}

string ManageMember::getPurchaseList()
{
	return loggedMembers.back().getPurchaseList();
}
