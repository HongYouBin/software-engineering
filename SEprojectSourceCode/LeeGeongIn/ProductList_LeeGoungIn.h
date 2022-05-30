#pragma once
#include "Product.h"
#include <vector>
using namespace std;

class Product;

// Class : ProductList
// Description: 시스템 내 물품 리스트 관리 Class
class ProductList
{
	vector<Product> productDB;          // 쇼핑몰 프로그램에 존재하는 전체 물품 저장 vector
public:
	void createProduct(string seller, string name, string company, string price, string quentity);
	Product getProductInfo(string productName);
	Product purchase(string productName);
	void saveEvaluationInfo(string productName, int evaluation);
};
