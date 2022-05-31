#pragma once
#include "Search.h"
#include "ManageMember.h"
#include "ProductList.h"

class SearchUI
{
private:
	Search* searchPtr;
	Product* selectedProduct;
public:
	SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr);
	void searchProduct(FILE* productName, FILE* out_fp);
	void purchase(FILE* out_fp);
};

