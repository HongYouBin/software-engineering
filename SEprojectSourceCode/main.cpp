// 헤더 선언
#include <stdio.h>
#include <string.h>
#include "RegisterSellingClothing.h"
using namespace std;
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
// 함수 선언
void doTask();
void join();
void RegisterClothing();
void program_exit();
// 변수 선언
FILE* in_fp, * out_fp;

int main()
{ // 파일 입출력을 위한 초기화
	FILE* in_fp = fopen(INPUT_FILE_NAME, "r+"); FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	...
		doTask();
	...
		return 0;
}

void doTask()
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	while (!is_program_exit)
	{ // 입력파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // "1.1. 회원가입“ 메뉴 부분
			{ // join() 함수에서 해당 기능 수행 

				join();
				break;
			}
			case 2: // 임시로 판매의류등록 테스트해봄
			{
				RegisterClothing();
				break;
			}
			//	....
			}
		case 7:
		{
			switch (menu_level_2)
			{
			case 1: // "6.1. 종료“ 메뉴 부분
			{
				..
					program_exit();
				is_program_exit = 1;
				break;
			}
			}
		}
		//.......
		{

			return;
		}
	}
}

void join()
{
	char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING],
		address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	// 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);
	// 해당 기능 수행 

	// 출력 형식
	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}

void RegisterClothing()
{
	char name[MAX_STRING], company[MAX_STRING], price[MAX_STRING],
		quentity[MAX_STRING];
	// 입력 형식 : [상품명] [제작회사명] [가격] [수량]을 파일로부터 읽음
	fscanf(in_fp, "%s %s %s %s", name, company, price, quentity);
	// 해당 기능 수행 
	RegisterSellingClothing* RegisterSellingClothingPointer = new RegisterSellingClothing(ProductList포인터 넣어줘야함);
	RegisterSellingClothingPointer->getRegisterSellingClothingUIPointer()->registerNewProduct(seller, name, company, price, quentity);

	// 출력 형식
	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "%s %s %s %s\n", name, company, price, quentity);
}


	void program_exit()
	{

	}
	
