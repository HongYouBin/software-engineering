#pragma once
#include "ManageMember.h"
#include <string>
using namespace std;

// Function: getSellerID()
// Description: 판매자의 ID정보를 받아와 return해 줌
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::getSellerID()
{
	return loggedMembers[0].getID();
}


// Function: createMember(string name, string SSN, string ID, string password)
// Description: 새 회원을 memberDB에 저장
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: void
// Author: 이정인
void ManageMember::createMember(string name, string SSN, string ID, string password)
{
	Member* newMember = new Member(name, SSN, ID, password);
	memberDB.push_back(*newMember);
}


// Function: checkMember(string ID, string password)
// Description: 회원가입된 사용자가 맞는지 확인
// Parameter: string ID - 회원 ID, string password - 비밀번호
// Return Value: int
// Author: 이정인
int ManageMember::checkMember(string ID, string password)
{
	int checkedMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == ID)
		{
			checkedMemberIndex = i;
			break;
		}
	}
	if (checkedMemberIndex < 0)
	{
		return 0;
	}
	else
	{
		Member* loginMember = memberDB[checkedMemberIndex].registerLoggedMember();
		loggedMembers.push_back(*loginMember);
		return 1;
	}
}


// Function: deleteMember()
// Description: 회원정보 삭제
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::deleteMember()
{
	string deleteMemberID = loggedMembers.back().getID();
	int deleteMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == deleteMemberID)
		{
			deleteMemberIndex = i;
			break;
		}
	}
	memberDB.erase(memberDB.begin() + deleteMemberIndex);
	loggedMembers.pop_back();
	return deleteMemberID;
}


// Function: deleteLoggedMember()
// Description: 로그인된 멤버 리스트에서 현재 로그인 멤버 삭제
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::deleteLoggedMember()
{
	string logoutMemberID = loggedMembers.back().getID();
	loggedMembers.pop_back();
	return logoutMemberID;
}