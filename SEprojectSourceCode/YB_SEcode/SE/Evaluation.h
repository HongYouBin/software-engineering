#pragma once
class Evaluation
{
private:
	ProductList* productListPtr;
	ManageMember* manageMemberPtr;
public:
	Evaluation(/*ManageMember* manageMember, */ProductList* productList);
	Product saveEvaluation(string productName, int evaluation);
};

