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

	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
	/*
	char ch
	string a
	string to char -> strcpy(ch, a.c_str())
	*/
}

void SearchUI::purchase()
{
	searchPtr->purchaseProduct(selectedProduct.getName());
}
