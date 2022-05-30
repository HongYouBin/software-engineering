#pragma once
class Member
{
	char* name;
	char* ID;
	char* SSN;
	char* password;
	vector<string> purchaseList;
public:
	Member(char* name, char* SSN, char* ID, char* password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
};

