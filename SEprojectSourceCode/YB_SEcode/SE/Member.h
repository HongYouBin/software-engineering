#pragma once
class Member
{
	string name;
	string ID;
	string SSN;
	string password;
	vector<string> purchaseList;
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
	void addPurchaseList(string productName);
};

