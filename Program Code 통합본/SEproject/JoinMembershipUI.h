#pragma once

// Class : JoinMembershipUI
// Description: 회원가입 기능의 Boundary Class
class JoinMembershipUI
{
	JoinMembership* joinMembershipPtr;      // JoinMembership 기능의 control class pointer
public:
	JoinMembershipUI(JoinMembership* joinMembershipPtr);
	void startInterface();
	void inputPersonalInfo(FILE* in_fp, FILE* out_fp);
};

