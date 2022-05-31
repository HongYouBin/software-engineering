#include "EvaluationUI.h"

#define MAX_STRING 32

EvaluationUI::EvaluationUI(ProductList* productListAddress)
{
	evaluationPtr = new Evaluation(productListAddress);
}

void EvaluationUI::evaluateProduct(FILE* in_fp, FILE* out_fp)
{
	//char charProductName[MAX_STRING];
	string productName;// (charProductName);
	int evaluation;
	fscanf(in_fp, "%s %d", productName, evaluation);
	Product* evaluatedProduct = evaluationPtr->saveEvaluation(productName, evaluation);
	fprintf(out_fp, "> %s %s %s\n", evaluatedProduct->getSeller(), evaluatedProduct->getName(), evaluatedProduct->getAverageEvaluation());
}
