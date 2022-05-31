#pragma once
#include "Evaluation.h"
#include "ManageMember.h"
#include "ProductList.h"

class EvaluationUI
{
private:
	Evaluation* evaluationPtr;
public:
	EvaluationUI(ProductList* productListAddress);
	void evaluateProduct(FILE* in_fp, FILE* out_fp);
};

