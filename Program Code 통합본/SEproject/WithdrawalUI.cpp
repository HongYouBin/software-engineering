#pragma once
#include "WithdrawalUI.h"
#include "Withdrawal.h"
using namespace std;
#include <iostream>
#define MAX_STRING 32

class Withdrawal;
class WithdrawalUI;

// Function: WithdrawalUI(Withdrawal* withdrawalPtr)
// Description: WithdrawalUI Class의 매개변수 생성자
// Parameter: Withdrawal* withdrawalPtr- Withdrawal Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
WithdrawalUI::WithdrawalUI(Withdrawal* withdrawalPtr)
{
	this->withdrawalPtr = withdrawalPtr;
}


// Function: startInterface()
// Description: Withdrawal 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void WithdrawalUI::startInterface()
{
	cout << "탈퇴하시겠습니까?" << endl;
}


// Function: selectMembershipCancel(FILE* out_fp)
// Description: 현재 회원의 회원정보를 삭제하는 Control Class의 cancelMembership 함수 호출
//              회원 탈퇴 처리 이후 탈퇴 회원 ID를 사용자에게 출력
// Parameter: FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void WithdrawalUI::selectMembershipCancel(FILE* out_fp)
{
	char deletedMemberID[MAX_STRING];
	strcpy(deletedMemberID, (this->withdrawalPtr->cancelMembership()).c_str());

	fprintf(out_fp, "1.2. 회원탈퇴\n");
	fprintf(out_fp, "> %s\n", deletedMemberID);
}
