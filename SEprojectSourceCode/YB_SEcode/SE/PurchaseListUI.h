#pragma once
class PurchaseListUI
{
private:
	PurchaseList* purchaseListPtr;
public:
	PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress);
	void showProductList(FILE* out_fp);
};

