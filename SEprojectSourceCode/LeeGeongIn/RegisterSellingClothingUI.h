#pragma once

// Class : RegisterSellingClothingUI
// Description: 판매 물품 등록 기능의 Boundary Class
class RegisterSellingClothingUI
{
	RegisterSellingClothing* registerSellingClothingPtr;     // RegisterSellingClothing 기능의 control class pointer

public:
	RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr);
	void startInterface();
	void registerNewProduct(FILE* in_fp, FILE* out_fp);

};