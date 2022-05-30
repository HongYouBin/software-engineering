#pragma once
class EvaluationUI
{
private:
	Evaluation* evaluationPtr;
public:
	EvaluationUI(ManageMember* manageMemberAddress, ProductList* productListAddress);
	void evaluateProduct(FILE* in_fp, FILE* out_fp);
};

