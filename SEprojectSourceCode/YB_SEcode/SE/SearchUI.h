#pragma once

class SearchUI
{
private:
	Search* searchPtr;
	Product selectedProduct;
public:
	SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr);
	void searchProduct(FILE* productName, FILE* out_fp);
	void purchase();
};

