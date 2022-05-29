#pragma once
class Product
{
	string seller;          // 판매자 ID
	string name;            // 상품명
	string company;         // 상품 생산 회사명
	string price;           // 상품 가격
	int quentity;        // 수량
	int evaluation = 0;     // 구매만족도
	int numberOfEvaluation;		//구매만족도에 참여한 인원
public:
	Product(string seller, string name, string company, string price, int quentity);

	// 테스트용 함수
	void printInfo();
	string getName();
	void purchase();
	void addEvaluation(int evaluation);
	float getAverageEvaluation();
};

