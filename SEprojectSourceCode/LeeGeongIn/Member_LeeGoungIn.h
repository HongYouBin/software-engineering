#pragma once

// Class : Member
// Description: 회원 정보 저장 Class
class Member
{
<<<<<<< HEAD
	string name;         // 회원명
	string ID;           // 회원 ID
	string SSN;          // 주민번호
	string password;     // 비밀번호
=======
	string name;
	string ID;
	string SSN;
	string password;
	vector<string> purchaseList;
>>>>>>> 692692f77fa93467b94b8bb76c6d7577f8b1ec02
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
};

