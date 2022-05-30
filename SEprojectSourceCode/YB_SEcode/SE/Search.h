#pragma once
class Search
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	Search(ManageMember* manageMemberAddress, ProductList* productListAddress);
	Product searchProduct(string productName);
	void purchaseProduct(string productName);
};

