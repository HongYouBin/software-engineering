#pragma once

class JoinMembershipUI
{
	JoinMembership *joinMembershipPtr;
public:
	JoinMembershipUI(JoinMembership *joinMembershipPtr);
	void startInterface();
	void inputPersonalInfo(FILE* in_fp, FILE* out_fp);
};

