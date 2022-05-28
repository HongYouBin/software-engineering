#pragma once

using namespace std;

class RegisterSellingClothing
{
	RegisterSellingClothingUI* registerSellingClothingUIPtr;
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	RegisterSellingClothing(ProductList* productListPtr, ManageMember* manageMemberPtr);
	RegisterSellingClothingUI* getRegisterSellingClothingUIPtr();
	void addNewProduct(string name, string company, string price, string quentity);
};

