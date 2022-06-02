#pragma once
#include <stdio.h>
#include "ClassesCollection.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
// 함수 선언
void doTask();
void program_exit(FILE* out_fp);
// 변수 선언
FILE* in_fp, * out_fp;

int main()
{
	doTask();
	return 0;
}

void doTask()
{
	ProductList* systemProductDB = new ProductList;
	ManageMember* systemMemberDB = new ManageMember;
	SearchUI* searchUIPtr = new SearchUI(systemMemberDB, systemProductDB);                                                 // 추가
	in_fp = fopen(INPUT_FILE_NAME, "r+"); out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	// 메뉴 파싱을 위한 level 구분을 위한 변수
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
			case 1: // "1.1. 회원가입" 메뉴 부분
			{
				JoinMembership* joinMembershipPtr = new JoinMembership(systemMemberDB);
				joinMembershipPtr->getJoinMembershipUIPtr()->inputPersonalInfo(in_fp, out_fp);
				break;
			}
			case 2: // "1.2. 회원탈퇴" 메뉴 부분
			{
				Withdrawal* withdrawalPtr = new Withdrawal(systemMemberDB);
				withdrawalPtr->getWithdrawalUIPtr()->selectMembershipCancel(out_fp);
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1: // "2.1. 로그인" 메뉴 부분
			{
				Login* loginPtr = new Login(systemMemberDB);
				loginPtr->getLoginUIPtr()->InputIDPW(in_fp, out_fp);
				break;
			}
			case 2: // "2.2. 로그아웃" 메뉴 부분
			{
				Logout* logoutPtr = new Logout(systemMemberDB);
				LogoutUI* logoutUIPtr = new LogoutUI(logoutPtr, out_fp);
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // "3.1. 판매 의류 등록" 메뉴 부분
			{
				RegisterSellingClothing* RegisterSellingClothingPtr = new RegisterSellingClothing(systemProductDB, systemMemberDB);
				RegisterSellingClothingPtr->getRegisterSellingClothingUIPtr()->registerNewProduct(in_fp, out_fp);
				break;
			}
			}
			break;
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1: // "4.1. 상품 정보 검색" 메뉴 부분
			{
				searchUIPtr->searchProduct(in_fp, out_fp);
				break;
			}
			case 2: // "4.2. 상품 구매" 메뉴 부분
			{
				searchUIPtr->purchase(out_fp);
				break;
			}
			case 3: // "4.3. 상품 구매 내역 조회" 메뉴 부분
			{
				PurchaseListUI* purchaseListUIPtr = new PurchaseListUI(systemMemberDB, systemProductDB);
				purchaseListUIPtr->showProductList(out_fp);
				break;
			}
			case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분
			{
				EvaluationUI* evaluationUIPtr = new EvaluationUI(systemProductDB);
				evaluationUIPtr->evaluateProduct(in_fp, out_fp);
				break;
			}
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1: // "6.1. 종료" 메뉴 부분
			{
				program_exit(out_fp);
				is_program_exit = 1;
				break;
			}
			}
			break;
		}
		}
	}
	return;
}

void program_exit(FILE* out_fp)
{
	fprintf(out_fp, "6.1. 종료\n");
}
