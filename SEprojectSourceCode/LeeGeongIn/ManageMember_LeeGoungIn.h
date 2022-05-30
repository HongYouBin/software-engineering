#pragma once
#include <vector>
#include "Member.h"

class Member;

// Class : ManageMember
// Description: 시스템 내 회원 리스트 관리 및 로그인 회원 정보 관리, 회원 정보 확인을 위한 Class
class ManageMember
{
	vector<Member> memberDB;          // 쇼핑몰 프로그램에 존재하는 전체 회원 저장 vector
	vector<Member> loggedMembers;     // 현재 쇼핑몰 프로그램에 로그인한 회원 저장 vector
public:
	string getSellerID();
	void createMember(string name, string SSN, string ID, string password);
	int checkMember(string ID, string password);
	string deleteMember();
	string deleteLoggedMember();
	void addPurchaseList(string productName);
	string getPurchaseList();
};
