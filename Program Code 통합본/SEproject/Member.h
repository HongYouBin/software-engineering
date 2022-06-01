#pragma once
#include <string>
#include <vector>
using namespace std;

// Class : Member
// Description: 회원 정보 저장 Class
class Member
{
	string name;         // 회원명
	string ID;           // 회원 ID
	string SSN;          // 주민번호
	string password;     // 비밀번호
	vector<string> purchaseList;

public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
	void addPurchaseList(string productName);
};

