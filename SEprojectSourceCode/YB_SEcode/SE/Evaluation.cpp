#include "Evaluation.h"

Evaluation::Evaluation(ProductList* productList)
{
	this->productListPtr = productList;
}

Product* Evaluation::saveEvaluation(string productName, int evaluation)
{
	return productListPtr->saveEvaluationInfo(productName, evaluation);
}
