#pragma once
#include "RegisterSellingClothingUI.h"
#include "RegisterSellingClothing.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

class RegisterSellingClothing;
class RegisterSellingClothingUI;

// Function: RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
// Description: RegisterSellingClothingUI Class의 매개변수 생성자
// Parameter: RegisterSellingClothing* registerSellingClothingPtr- RegisterSellingClothing Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
RegisterSellingClothingUI::RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
{
	this->registerSellingClothingPtr = registerSellingClothingPtr;
}


// Function: startInterface()
// Description: RegisterSellingClothing 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void RegisterSellingClothingUI::startInterface()
{
	cout << "등록할 의류정보를 입력하세요." << endl;
}


// Function: registerNewProduct(FILE* in_fp, FILE* out_fp)
// Description: 사용자로부터 등록할 물품 정보를 입력받고, Control Class의 addNewProduct 함수 호출
//              물품 등록 이후 결과를 사용자에게 출력
// Parameter: FILE* in_fp - 입력 파일 포인터, FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void RegisterSellingClothingUI::registerNewProduct(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], company[MAX_STRING], price[MAX_STRING], quentity[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, company, price, quentity);

	this->registerSellingClothingPtr->addNewProduct(name, company, price, quentity);

	fprintf(out_fp, "3.1 판매 의류 등록\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, company, price, quentity);
}