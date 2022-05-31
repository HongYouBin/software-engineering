#pragma once
#include "RegisterSellingClothingUI.h"
#include "ProductList.h"
#include "ManageMember.h"
using namespace std;

class RegisterSellingClothingUI;
class ManageMember;
class Product;

// Class : RegisterSellingClothing
// Description: 판매 물품 등록 기능의 Control Class
class RegisterSellingClothing
{
	RegisterSellingClothingUI* registerSellingClothingUIPtr;   // RegisterSellingClothing 기능의 boundary class pointer
	ProductList* productListPtr;                               // systemProductDB 객체의 주소를 저장하는 pointer
	ManageMember* manageMemberPtr;                             // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	RegisterSellingClothing(ProductList* productListPtr, ManageMember* manageMemberPtr);
	RegisterSellingClothingUI* getRegisterSellingClothingUIPtr();
	void addNewProduct(string name, string company, string price, string quentity);
};

