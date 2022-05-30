#include "Search.h"
#include "ManageMember.h"
#include "ProductList.h"
#include "Product.h"
#include "stdio.h"

Search::Search(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product Search::searchProduct(char* productName)
{
	return productListPtr->getProductInfo(productName);
}

void Search::purchaseProduct(char* productName)
{
	productListPtr->purchase(productName);
	manageMemberPtr->addPurchaseList(productName);
}
