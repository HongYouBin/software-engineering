#pragma once
class Member
{
	string name;
	string ID;
	string SSN;
	string password;
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
};

