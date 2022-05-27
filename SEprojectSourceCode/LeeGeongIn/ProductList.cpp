#include "ProductList.h"

void ProductList::createProduct(string seller, string name, string company, string price, string quentity)
{
	Product* newProduct = new Product(seller, name, company, price, quentity);
	productDB.push_back(*newProduct);
}
