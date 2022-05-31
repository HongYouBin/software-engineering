#include "Member.h"

using namespace std;

Member::Member(string name, string SSN, string ID, string password)
{
	this->name = name;
	this->SSN = SSN;
	this->ID = ID;
	this->password = password;
}

string Member::getID()
{
	return this->ID;
}

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
