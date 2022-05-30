#include "PurchaseListUI.h"
#include "PurchaseList.h"
#include "ManageMember.h"
#include "ProductList.h"
#include <stdio.h>

PurchaseListUI::PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->purchaseListPtr = new PurchaseList(manageMemberAddress, productListAddress);
}

void PurchaseListUI::showProductList(FILE* out_fp)
{
	this->purchaseListPtr->getPurchaseList();
	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
}
