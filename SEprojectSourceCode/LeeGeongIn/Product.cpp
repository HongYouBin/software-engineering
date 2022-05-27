#include "Product.h"
#include <string>
using namespace std;

Product::Product(string seller, string name, string company, string price, string quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity;
}
