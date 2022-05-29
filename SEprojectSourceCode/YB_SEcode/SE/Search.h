#pragma once
class Search
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	Product searchProduct(string productName);
	void purchaseProduct(string productName);
	
};

