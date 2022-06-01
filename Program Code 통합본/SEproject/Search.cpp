#include "Search.h"


Search::Search(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product* Search::searchProduct(string productName)
{
	return productListPtr->getProductInfo(productName);
}

void Search::purchaseProduct(Product* productPtr)
{
	productListPtr->purchase(productPtr);
	manageMemberPtr->addPurchaseList(productPtr->getName());
}
