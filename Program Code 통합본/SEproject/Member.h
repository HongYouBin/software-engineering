#pragma once

// Class : Member
// Description: 회원 정보 저장 Class
class Member
{
	string name;         // 회원명
	string ID;           // 회원 ID
	string SSN;          // 주민번호
	string password;     // 비밀번호
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
};

