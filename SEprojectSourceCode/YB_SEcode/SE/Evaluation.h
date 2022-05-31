#pragma once
class Evaluation
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	Evaluation(ProductList* productList);
	Product saveEvaluation(string productName, int evaluation);
};

