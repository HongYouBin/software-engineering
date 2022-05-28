#pragma once
#include "RegisterSellingClothing.h"
#include "ManageMember.h"
#include "ProductList.h"
#include "RegisterSellingClothingUI.h"
#include <string>

RegisterSellingClothing::RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
{
	this->productListPtr = ProductListPtr;
	this->manageMemberPtr = manageMemberPtr;
	this->registerSellingClothingUIPtr = new RegisterSellingClothingUI(this);
	registerSellingClothingUIPtr->startInterface();
}

RegisterSellingClothingUI* RegisterSellingClothing::getRegisterSellingClothingUIPtr()
{
	return this->registerSellingClothingUIPtr;
}

void RegisterSellingClothing::addNewProduct(string name, string company, string price, string quentity)
{
	string seller = this->manageMemberPtr->getSellerID();
	this->productListPtr->createProduct(seller, name, company, price, quentity);
}
