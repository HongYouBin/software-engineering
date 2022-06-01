#pragma once
#include "ProductList.h"
#include "ManageMember.h"

class Evaluation
{
private:
	ProductList* productListPtr;
public:
	Evaluation(ProductList* productList);
	Product* saveEvaluation(string productName, int evaluation);
};

