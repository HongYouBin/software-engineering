#pragma once
class Search
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	Search(ManageMember* manageMemberAddress, ProductList* productListAddress);
	Product searchProduct(char* productName);
	void purchaseProduct(char* productName);
};

