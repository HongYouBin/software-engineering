#include "EvaluationUI.h"
#include "Evaluation.h"
#include "ManageMember.h"
#include "ProductList.h"
#include <stdio.h>
#include <iostream>
#define MAX_STRING 32

EvaluationUI::EvaluationUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	evaluationPtr = new Evaluation(manageMemberAddress, productListAddress);
}

void EvaluationUI::evaluateProduct(FILE* in_fp, FILE* out_fp)
{
	char productName[MAX_STRING];
	int evaluation;
	fscanf(in_fp, "%s %d", productName, evaluation);
	//evaluationPtr->saveEvaluation(productName, evaluation);
	//fprintf(... )
}
