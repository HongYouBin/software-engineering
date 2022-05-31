#pragma once
#include "JoinMembershipUI.h"
#include "ManageMember.h"
#include <string>
using namespace std;

class ManageMember;
class JoinMembershipUI;

// Class : JoinMembership
// Description: 회원가입 기능의 Control Class
class JoinMembership
{
	JoinMembershipUI* joinMembershipUIPtr;     // JoinMembership 기능의 boundary class pointer
	ManageMember* manageMemberPtr;             // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	JoinMembership(ManageMember* manageMemberPtr);
	JoinMembershipUI* getJoinMembershipUIPtr();
	void addNewMember(string name, string SSN, string ID, string password);
};

