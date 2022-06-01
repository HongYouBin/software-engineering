#pragma once
#include "Member.h"
#include <string>
using namespace std;

// Function: Member(string name, string SSN, string ID, string password)
// Description: Member Class의 매개변수 생성자
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: None
// Author: 이정인
Member::Member(string name, string SSN, string ID, string password)
{
	this->name = name;
	this->SSN = SSN;
	this->ID = ID;
	this->password = password;
}


// Function: getID()
// Description: ID 멤버변수의 getter function
// Parameter: None
// Return Value: string
// Author: 이정인
string Member::getID()
{
	return this->ID;
}

// Function: registerLoggedMember()
// Description: 현재 로그인한 회원 객체의 주소를 받아옴.
// Parameter: None
// Return Value: Member*
// Author: 이정인
Member* Member::registerLoggedMember()
{
	return this;
}


vector<string> Member::getPurchaseList()
{
	return (this->purchaseList);
}

void Member::addPurchaseList(string productName)
{
	this->purchaseList.push_back(productName);
}
