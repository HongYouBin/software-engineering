#pragma once
#include "ProductList.h"
#include <string>

class ProductList;

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: 새로운 Product를 생성해 ProductDB에 저장.
// Parameter: string seller- 판매자 ID, string name - 물품명, string company - 제조회사명, string price - 물품가격, 
//            string quentity - 남은수량
// Return Value: void
// Author: 이정인
void ProductList::createProduct(string seller, string name, string company, string price, int quentity)
{
	Product* newProduct = new Product(seller, name, company, price, stoi(quentity));
	productDB.push_back(*newProduct);
}
