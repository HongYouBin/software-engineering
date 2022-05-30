#include "SearchUI.h"
#include "Search.h"
#include <iostream>
#include <stdio.h>
#include "ManageMember.h"
#include "ProductList.h"
#include "Product.h"

#define MAX_STRING 32
using namespace std;

SearchUI::SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr)
{
	this->searchPtr = new Search(manageMemberPtr, productListPtr);
}

void SearchUI::searchProduct(FILE* productName, FILE* out_fp)
{
	char searchName[MAX_STRING];
	fscanf(productName, "%s", searchName);
	selectedProduct = searchPtr->searchProduct(searchName);

	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
}

void SearchUI::purchase()
{
	searchPtr->purchaseProduct(selectedProduct.getName());
}
