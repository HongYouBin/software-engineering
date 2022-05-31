#include"PurchaseList.h"

PurchaseList::PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

vector<Product> PurchaseList::getPurchaseList()
{
	vector<string> purchaseListString = manageMemberPtr->getPurchaseList();
	vector<Product> purchasedProductList;
	for (int i = 0; i < purchaseListString.size(); ++i) {
		purchasedProductList.push_back((*productListPtr->getProductInfo(purchaseListString[i])));
		//purchasedProductList.push_back((*productListPtr->getProductInfo((*purchaseListString)[i])));
	}
	return purchasedProductList;
}
