#include "PurchaseListUI.h"


PurchaseListUI::PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->purchaseListPtr = new PurchaseList(manageMemberAddress, productListAddress);
}

void PurchaseListUI::showProductList(FILE* out_fp)
{
	fprintf(out_fp, "4.3 상품 구매 내역 조회\n");
	vector<Product> selectedProductList = this->purchaseListPtr->getPurchaseList();
	for (int i = 0; i < selectedProductList.size(); ++i) 
	{
		fprintf(out_fp, "> %s %s %s %s %s %s \n", selectedProductList[i].getSeller(), selectedProductList[i].getName(), selectedProductList[i].getCompany(), selectedProductList[i].getPrice(), selectedProductList[i].getQuentity(), selectedProductList[i].getAverageEvaluation());
	}
	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
}
