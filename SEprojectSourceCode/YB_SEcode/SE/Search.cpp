#include "Search.h"
#include "ManageMember.h"
#include "ProductList.h"
#include "Product.h"
#include "stdio.h"
#include <string>

Search::Search(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product Search::searchProduct(string productName)
{
	return productListPtr->getProductInfo(productName);
}

void Search::purchaseProduct(string productName)
{
	productListPtr->purchase(productName);
	manageMemberPtr->addPurchaseList(productName);
}
