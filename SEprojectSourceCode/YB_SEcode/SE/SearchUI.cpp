#include "SearchUI.h"
#include "Search.h"
#include <iostream>
#include <stdio.h>
#include "ManageMember.h"
#include "ProductList.h"
#include "Product.h"
#include <string>

#define MAX_STRING 32
using namespace std;

SearchUI::SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr)
{
	this->searchPtr = new Search(manageMemberPtr, productListPtr);
}

void SearchUI::searchProduct(FILE* productName, FILE* out_fp)
{
	char charSearchName[MAX_STRING];
	fscanf(productName, "%s", charSearchName);
	string searchName(charSearchName);
	selectedProduct = searchPtr->searchProduct(searchName);

	fprintf(out_fp, "4.1 상품 정보 검색\n");
	fprintf(out_fp, "> %s %s %s %s %s %s \n", selectedProduct.getSeller(), selectedProduct.getName(), selectedProduct.getCompany(), selectedProduct.getPrice(), selectedProduct.getQuentity(), selectedProduct.getAverageEvaluation());
	
}

void SearchUI::purchase(FILE* out_fp)
{
	searchPtr->purchaseProduct(selectedProduct.getName());
	fprintf(out_fp, "> %s %s\n", selectedProduct.getSeller(), selectedProduct.getName());

}
