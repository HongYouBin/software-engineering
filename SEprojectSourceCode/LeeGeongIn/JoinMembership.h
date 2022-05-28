#pragma once
using namespace std;

class JoinMembership
{
	JoinMembershipUI* joinMembershipUIPtr;
	ManageMember* manageMemberPtr;
public:
	JoinMembership(ManageMember* manageMemberPtr);
	JoinMembershipUI* getJoinMembershipUIPtr();
	void addNewMember(string name, string SSN, string ID, string password);
};

