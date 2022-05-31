#pragma once
#include "Member.h"
//#include <string>
//#include <vector>
class ManageMember
{
	vector<Member> memberDB;
	vector<Member> loggedMembers;
public:
	string getSellerID();
	void createMember(string name, string SSN, string ID, string password);
	int checkMember(string ID, string password);
	string deleteMember();
	string deleteLoggedMember();
	void addPurchaseList(string productName);
	vector<string> getPurchaseList();
};

