#include "EvaluationUI.h"
#include "Evaluation.h"
#include "ManageMember.h"
#include "ProductList.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Product.h"
#define MAX_STRING 32

EvaluationUI::EvaluationUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	evaluationPtr = new Evaluation(/*manageMemberAddress, */productListAddress);
}

void EvaluationUI::evaluateProduct(FILE* in_fp, FILE* out_fp)
{
	char charProductName[MAX_STRING];
	int evaluation;
	fscanf(in_fp, "%s %d", charProductName, evaluation);
	string productName(charProductName);
	Product evaluatedProduct = evaluationPtr->saveEvaluation(productName, evaluation);
	//fprintf(... )
}
