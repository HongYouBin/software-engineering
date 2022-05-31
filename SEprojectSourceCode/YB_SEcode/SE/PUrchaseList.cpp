#include"PurchaseList.h"
#include"ManageMember.h"
#include"ProductList.h"
#include"Product.h"
#include <vector>
#include <string>

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
		purchasedProductList.push_back(productListPtr->getProductInfo(purchaseListString[i]));
	}
	return purchasedProductList;
}
