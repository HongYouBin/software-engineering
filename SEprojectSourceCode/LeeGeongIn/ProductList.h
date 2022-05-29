#pragma once
using namespace std;

class ProductList
{
	vector<Product> productDB;          // 쇼핑몰 프로그램에 존재하는 전체 물품 저장 vector
public:
	void createProduct(string seller, string name, string company, string price, string quentity);
	Product getProductInfo(string productName);
	Product purchase(string productName);
	void saveEvaluationInfo(string productName, int evaluation);
};

