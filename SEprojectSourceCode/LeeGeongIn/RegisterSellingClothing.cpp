#pragma once
#include "RegisterSellingClothing.h"
#include <string>

class RegisterSellingClothing;

// Function: RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
// Description: RegisterSellingClothing Class의 매개변수 생성자
// Parameter: ProductList* ProductListPtr- 시스템 전체 물품 리스트 객체의 주소를 받는 포인터 매개변수, 
//            ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
RegisterSellingClothing::RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
{
	this->productListPtr = ProductListPtr;
	this->manageMemberPtr = manageMemberPtr;
	this->registerSellingClothingUIPtr = new RegisterSellingClothingUI(this);
	registerSellingClothingUIPtr->startInterface();
}


// Function: getRegisterSellingClothingUIPtr()
// Description: RegisterSellingClothingUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: RegisterSellingClothingUI*
// Author: 이정인
RegisterSellingClothingUI* RegisterSellingClothing::getRegisterSellingClothingUIPtr()
{
	return this->registerSellingClothingUIPtr;
}


// Function: addNewProduct(string name, string company, string price, string quentity)
// Description: 판매자의 ID정보를 받아와 새 Product를 ProductDB에 저장하는 ProductList의 createProduct함수를 호출
// Parameter: string name - 물품명, string company - 제조회사명, string price - 물품가격, string quentity - 남은수량
// Return Value: void
// Author: 이정인
void RegisterSellingClothing::addNewProduct(string name, string company, string price, string quentity)
{
	string seller = this->manageMemberPtr->getSellerID();
	this->productListPtr->createProduct(seller, name, company, price, quentity);
}