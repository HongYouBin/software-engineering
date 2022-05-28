#pragma once

class RegisterSellingClothingUI
{
	RegisterSellingClothing* registerSellingClothingPtr;              

public:
	RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr);
	void startInterface();
	void registerNewProduct(FILE* in_fp, FILE* out_fp);
	
};