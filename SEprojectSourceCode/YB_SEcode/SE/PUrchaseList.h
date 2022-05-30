#pragma once
class PurchaseList
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress);
	Product getPurchaseList();
};

