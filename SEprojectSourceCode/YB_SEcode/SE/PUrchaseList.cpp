#include"PurchaseList.h"
#include"ManageMember.h"
#include"ProductList.h"
#include"Product.h"

PurchaseList::PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product PurchaseList::getPurchaseList()
{
	manageMemberPtr->getPurchaseList();
	//getProductInfo();
	//return Product();
}
