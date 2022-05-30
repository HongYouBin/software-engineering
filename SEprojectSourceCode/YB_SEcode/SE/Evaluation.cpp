#include "Evaluation.h"
#include "ProductList.h"
#include "ManageMember.h"
#include "Product.h"
#include <string>

Evaluation::Evaluation(/*ManageMember* manageMember, */ProductList* productList)
{
	//this->manageMemberPtr = manageMember;
	this->productListPtr = productList;
}

Product Evaluation::saveEvaluation(string productName, int evaluation)
{
	return productListPtr->saveEvaluationInfo(productName, evaluation);
}
