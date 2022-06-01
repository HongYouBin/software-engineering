#pragma once
#include "PurchaseList.h"
#include "ManageMember.h"
#include "ProductList.h"

class PurchaseListUI
{
private:
	PurchaseList* purchaseListPtr;
public:
	PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress);
	void showProductList(FILE* out_fp);
};

