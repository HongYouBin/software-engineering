#pragma once
#include "ClassesCollection.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 32

// Function: JoinMembership(ManageMember* manageMemberPtr)
// Description: JoinMembership Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
JoinMembership::JoinMembership(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	JoinMembership* thisClassPtr = this;
	this->joinMembershipUIPtr = new JoinMembershipUI(thisClassPtr);
	this->joinMembershipUIPtr->startInterface();
}


// Function: getJoinMembershipUIPtr()
// Description: JoinMembershipUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: JoinMembershipUI*
// Author: 이정인
JoinMembershipUI* JoinMembership::getJoinMembershipUIPtr()
{
	return this->joinMembershipUIPtr;
}


// Function: addNewMember(string name, string SSN, string ID, string password)
// Description: 새 회원을 등록시키는 ManageMember의 createMember 함수 호출
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: void
// Author: 이정인
void JoinMembership::addNewMember(string name, string SSN, string ID, string password)
{
	this->manageMemberPtr->createMember(name, SSN, ID, password);
}

//----------------------------------------------------------------------------------------

// Function: JoinMembershipUI(JoinMembership* joinMembershipPtr)
// Description: JoinMembershipUI Class의 매개변수 생성자
// Parameter: JoinMembership* joinMembershipPtr- JoinMembership Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
JoinMembershipUI::JoinMembershipUI(JoinMembership* joinMembershipPtr)
{
	this->joinMembershipPtr = joinMembershipPtr;
}


// Function: startInterface()
// Description: JoinMembership 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void JoinMembershipUI::startInterface()
{
	cout << "회원가입 정보를 입력해주세요" << endl;
}


// Function: inputPersonalInfo(FILE* in_fp, FILE* out_fp)
// Description: 사용자로부터 회원 정보를 입력받고, Control Class의 addNewMember 함수 호출
//              회원 등록 이후 결과를 사용자에게 출력
// Parameter: FILE* in_fp - 입력 파일 포인터, FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void JoinMembershipUI::inputPersonalInfo(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

	this->joinMembershipPtr->addNewMember(name, SSN, ID, password);

	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, SSN, ID, password);
}

//----------------------------------------------------------------------------------------------

// Function: Login(ManageMember* manageMemberPtr)
// Description: Login Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Login::Login(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->loginUIPtr = new LoginUI(this);
	this->loginUIPtr->startInterface();
}


// Function: getLoginUIPtr()
// Description: LoginUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: LoginUI*
// Author: 이정인
LoginUI* Login::getLoginUIPtr()
{
	return this->loginUIPtr;
}


// Function: checkMember(string ID, string password)
// Description: 회원가입된 사용자가 맞는지 확인하는 ManageMember의 checkMember함수 호출
// Parameter: string ID - 회원 ID, string password - 비밀번호
// Return Value: int
// Author: 이정인
int Login::checkMember(string ID, string password)
{
	return (this->manageMemberPtr->checkMember(ID, password));
}

//------------------------------------------------------------------------------------------

// Function: LoginUI(Login* loginPtr)
// Description: LoginUI Class의 매개변수 생성자
// Parameter: Login* loginPtr- Login Control Class 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
LoginUI::LoginUI(Login* loginPtr)
{
	this->loginPtr = loginPtr;
}


// Function: InputIDPW(FILE* in_fp, FILE* out_fp)
// Description: 사용자로부터 ID, password 정보를 입력받고, Control Class의 checkMember 함수 호출
//              회원 여부 체크 이후 로그인 결과를 사용자에게 출력
// Parameter: FILE* in_fp - 입력 파일 포인터, FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void LoginUI::InputIDPW(FILE* in_fp, FILE* out_fp)
{
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	int isMember = 0;
	isMember = this->loginPtr->checkMember(ID, password);

	if (isMember == 1)
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> %s %s\n", ID, password);
	}
	else
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> \n");
	}
}


// Function: startInterface()
// Description: Login 기능의 첫 시작 화면을 출력
// Parameter: None
// Return Value: void
// Author: 이정인
void LoginUI::startInterface()
{
	cout << "아이디와 비밀번호를 입력해주세요." << endl;
}

//--------------------------------------------------------------------------------------------

// Function: Logout(ManageMember* manageMemberPtr)
// Description: Logout Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Logout::Logout(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;

}


// Function: logout()
// Description: 현재 저장된 로그인 정보를 삭제하기 위해 ManageMember class의 deleteLoggedMember함수 호출
// Parameter: None
// Return Value: string
// Author: 이정인
string Logout::logout()
{
	return this->manageMemberPtr->deleteLoggedMember();
}

//----------------------------------------------------------------------------------------------

// Function: LogoutUI(Logout* logoutPtr, FILE* out_fp)
// Description: LogoutUI Class의 매개변수 생성자
// Parameter: Logout* logoutPtr- Logout Control Class 객체의 주소를 받는 포인터 매개변수, FILE* out_fp - 출력 파일 포인터
// Return Value: None
// Author: 이정인
LogoutUI::LogoutUI(Logout* logoutPtr, FILE* out_fp)
{
	this->logoutPtr = logoutPtr;
	this->selectLogout(out_fp);
}


// Function: selectLogout(FILE* out_fp)
// Description: 현재 로그인된 회원을 로그아웃 처리하는 Control Class의 logout 함수 호출
//              로그아웃 처리 이후 탈퇴 회원 ID를 사용자에게 출력
// Parameter: FILE* out_fp - 출력 파일 포인터
// Return Value: void
// Author: 이정인
void LogoutUI::selectLogout(FILE* out_fp)
{
	char logoutID[MAX_STRING];
	strcpy(logoutID, (this->logoutPtr->logout()).c_str());
	fprintf(out_fp, "2.2. 로그아웃\n");
	fprintf(out_fp, "> %s\n", logoutID);
}

//----------------------------------------------------------------------------------------------

// Function: getSellerID()
// Description: 판매자의 ID정보를 받아와 return해 줌
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::getSellerID()
{
	return loggedMembers[0].getID();
}


// Function: createMember(string name, string SSN, string ID, string password)
// Description: 새 회원을 memberDB에 저장
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: void
// Author: 이정인
void ManageMember::createMember(string name, string SSN, string ID, string password)
{
	Member* newMember = new Member(name, SSN, ID, password);
	memberDB.push_back(*newMember);
}


// Function: checkMember(string ID, string password)
// Description: 회원가입된 사용자가 맞는지 확인
// Parameter: string ID - 회원 ID, string password - 비밀번호
// Return Value: int
// Author: 이정인
int ManageMember::checkMember(string ID, string password)
{
	int checkedMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == ID)
		{
			checkedMemberIndex = i;
			break;
		}
	}
	if (checkedMemberIndex < 0)
	{
		return 0;
	}
	else
	{
		Member* loginMember = memberDB[checkedMemberIndex].registerLoggedMember();
		loggedMembers.push_back(*loginMember);
		return 1;
	}
}


// Function: deleteMember()
// Description: 회원정보 삭제
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::deleteMember()
{
	string deleteMemberID = loggedMembers.back().getID();
	int deleteMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == deleteMemberID)
		{
			deleteMemberIndex = i;
			break;
		}
	}
	memberDB.erase(memberDB.begin() + deleteMemberIndex);
	loggedMembers.pop_back();
	return deleteMemberID;
}


// Function: deleteLoggedMember()
// Description: 로그인된 멤버 리스트에서 현재 로그인 멤버 삭제
// Parameter: None
// Return Value: string
// Author: 이정인
string ManageMember::deleteLoggedMember()
{
	string logoutMemberID = loggedMembers.back().getID();
	loggedMembers.pop_back();
	return logoutMemberID;
}

void ManageMember::addPurchaseList(string productName)        //
{
	loggedMembers[0].addPurchaseList(productName);
}

vector<string> ManageMember::getPurchaseList()            //
{
	return loggedMembers[0].getPurchaseList();
}

//------------------------------------------------------------------------------------------------

// Function: Member(string name, string SSN, string ID, string password)
// Description: Member Class의 매개변수 생성자
// Parameter: string name - 회원명, string SSN - 주민번호, string ID - 회원 ID, string password - 비밀번호
// Return Value: None
// Author: 이정인
Member::Member(string name, string SSN, string ID, string password)
{
	this->name = name;
	this->SSN = SSN;
	this->ID = ID;
	this->password = password;
}


// Function: getID()
// Description: ID 멤버변수의 getter function
// Parameter: None
// Return Value: string
// Author: 이정인
string Member::getID()
{
	return this->ID;
}

// Function: registerLoggedMember()
// Description: 현재 로그인한 회원 객체의 주소를 받아옴.
// Parameter: None
// Return Value: Member*
// Author: 이정인
Member* Member::registerLoggedMember()
{
	return this;
}

vector<string> Member::getPurchaseList()
{
	return (this->purchaseList);
}

void Member::addPurchaseList(string productName)
{
	this->purchaseList.push_back(productName);
}

//--------------------------------------------------------------------------------------------------

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: 새로운 Product를 생성해 ProductDB에 저장.
// Parameter: string seller- 판매자 ID, string name - 물품명, string company - 제조회사명, string price - 물품가격, 
//            string quentity - 남은수량
// Return Value: void
// Author: 이정인
void ProductList::createProduct(string seller, string name, string company, string price, string quentity)
{
	Product* newProduct = new Product(seller, name, company, price, stoi(quentity));
	productDB.push_back(*newProduct);
}

Product* ProductList::getProductInfo(string productName)
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName() == productName)
		{
			return &productDB[i];
		}
	}
}

void ProductList::purchase(Product* productPtr)
{
	// Product tmpProduct = getProductInfo(productName);
	//tmpProduct.purchase();
	productPtr->purchase();
}

Product* ProductList::saveEvaluationInfo(string productName, int evaluation)
{
	Product* productPtr = getProductInfo(productName);
	productPtr->addEvaluation(evaluation);
	return productPtr;
}

//-----------------------------------------------------------------------------------------------------

// Function: Product(string seller, string name, string company, string price, string quentity)
// Description: Product Class의 매개변수 생성자
// Parameter: string seller- 판매자 ID, string name - 물품명, string company - 제조회사명, string price - 물품가격, 
//            int quentity - 남은수량
// Return Value: None
// Author: 이정인
Product::Product(string seller, string name, string company, string price, int quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity; 
}

string Product::getName()
{
	return this->name;
}

string Product::getSeller()
{
	return seller;
}

string Product::getPrice()
{
	return price;
}

string Product::getCompany()
{
	return company;
}

int Product::getQuentity()
{
	return quentity;
}

int Product::getEvaluationAverage()
{
	if (numberOfEvaluation == 0) return 0;
	return evaluation / numberOfEvaluation;
}

void Product::purchase()
{
	this->quentity--;
}

Product Product::addEvaluation(int evaluation)
{
	this->evaluation += evaluation;
	this->numberOfEvaluation++;
	return *this;
}

float Product::getAverageEvaluation()
{
	return (static_cast<float>(this->evaluation) / this->numberOfEvaluation);
}

//---------------------------------------------------------------------------------------------------------

// Function: RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
// Description: RegisterSellingClothing Class의 매개변수 생성자
// Parameter: ProductList* ProductListPtr- 시스템 전체 물품 리스트 객체의 주소를 받는 포인터 매개변수, 
//            ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
RegisterSellingClothing::RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
{
	this->productListPtr = ProductListPtr;
	this->manageMemberPtr = manageMemberPtr;
	this->registerSellingClothingUIPtr = new RegisterSellingClothingUI(this);
	registerSellingClothingUIPtr->startInterface();
}


// Function: getRegisterSellingClothingUIPtr()
// Description: RegisterSellingClothingUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: RegisterSellingClothingUI*
// Author: 이정인
RegisterSellingClothingUI* RegisterSellingClothing::getRegisterSellingClothingUIPtr()
{
	return this->registerSellingClothingUIPtr;
}


// Function: addNewProduct(string name, string company, string price, string quentity)
// Description: 판매자의 ID정보를 받아와 새 Product를 ProductDB에 저장하는 ProductList의 createProduct함수를 호출
// Parameter: string name - 물품명, string company - 제조회사명, string price - 물품가격, string quentity - 남은수량
// Return Value: void
// Author: 이정인
void RegisterSellingClothing::addNewProduct(string name, string company, string price, string quentity)
{
	string seller = this->manageMemberPtr->getSellerID();
	this->productListPtr->createProduct(seller, name, company, price, quentity);
}

//-----------------------------------------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------------------------------

// Function: Withdrawal(ManageMember* manageMemberPtr)
// Description: Withdrawal Class의 매개변수 생성자
// Parameter: ManageMember* manageMemberPtr - 시스템 전체 회원 관리 객체의 주소를 받는 포인터 매개변수
// Return Value: None
// Author: 이정인
Withdrawal::Withdrawal(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->withdrawalUIPtr = new WithdrawalUI(this);
	withdrawalUIPtr->startInterface();
}


// Function: getWithdrawalUIPtr()
// Description: WithdrawalUIPtr 멤버변수의 getter function
// Parameter: None
// Return Value: WithdrawalUI*
// Author: 이정인
WithdrawalUI* Withdrawal::getWithdrawalUIPtr()
{
	return this->withdrawalUIPtr;
}


// Function: cancelMembership()
// Description: 회원 정보를 삭제하는 ManageMember의 deleteMember함수 호출
// Parameter: None
// Return Value: string
// Author: 이정인
string Withdrawal::cancelMembership()
{
	return this->manageMemberPtr->deleteMember();
}

//----------------------------------------------------------------------------------------------------------

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


// -----------------------------추가된 .cpp----------------------

Search::Search(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product* Search::searchProduct(string productName)
{
	return productListPtr->getProductInfo(productName);
}

void Search::purchaseProduct(Product* productPtr)
{
	productListPtr->purchase(productPtr);
	manageMemberPtr->addPurchaseList(productPtr->getName());
}

//------------------------------------------------------------

SearchUI::SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr)
{
	this->searchPtr = new Search(manageMemberPtr, productListPtr);
}

void SearchUI::searchProduct(FILE* productName, FILE* out_fp)
{
	char charSearchName[MAX_STRING];
	fscanf(productName, "%s", charSearchName);
	string searchName(charSearchName);

	selectedProduct = searchPtr->searchProduct(searchName);
	fprintf(out_fp, "4.1 상품 정보 검색\n");

	char sellerName[MAX_STRING], name[MAX_STRING], companyName[MAX_STRING], price[MAX_STRING];
	strcpy(sellerName, (selectedProduct->getSeller()).c_str());
	strcpy(name, (selectedProduct->getName()).c_str());
	strcpy(companyName, (selectedProduct->getCompany()).c_str());
	strcpy(price, (selectedProduct->getPrice()).c_str());
	fprintf(out_fp, "> %s %s %s %s %d %.1f \n", sellerName, name, companyName, price, selectedProduct->getQuentity(), selectedProduct->getAverageEvaluation());
}

void SearchUI::purchase(FILE* out_fp)
{
	searchPtr->purchaseProduct(selectedProduct);

	fprintf(out_fp, "4.2 상품 구매\n");
	char sellerName[MAX_STRING], name[MAX_STRING];
	strcpy(sellerName, (selectedProduct->getSeller()).c_str());
	strcpy(name, (selectedProduct->getName()).c_str());
	fprintf(out_fp, "> %s %s\n", sellerName, name);
}

//----------------------------------------------------------

PurchaseList::PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

vector<Product> PurchaseList::getPurchaseList()
{
	vector<string> purchaseListString = manageMemberPtr->getPurchaseList();
	vector<Product> purchasedProductList;
	for (int i = 0; i < purchaseListString.size(); ++i) {
		purchasedProductList.push_back((*productListPtr->getProductInfo(purchaseListString[i])));
		//purchasedProductList.push_back((*productListPtr->getProductInfo((*purchaseListString)[i])));
	}
	return purchasedProductList;
}

//---------------------------------------------------------

PurchaseListUI::PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->purchaseListPtr = new PurchaseList(manageMemberAddress, productListAddress);
}

void PurchaseListUI::showProductList(FILE* out_fp)
{
	fprintf(out_fp, "4.3 상품 구매 내역 조회\n");
	vector<Product> selectedProductList = this->purchaseListPtr->getPurchaseList();

	char sellerName[MAX_STRING], name[MAX_STRING], companyName[MAX_STRING], price[MAX_STRING];
	for (int i = 0; i < selectedProductList.size(); ++i)
	{
		strcpy(sellerName, (selectedProductList[i].getSeller()).c_str());
		strcpy(name, (selectedProductList[i].getName()).c_str());
		strcpy(companyName, (selectedProductList[i].getCompany()).c_str());
		strcpy(price, (selectedProductList[i].getPrice()).c_str());
		fprintf(out_fp, "> %s %s %s %s %d %.1f \n", sellerName, name, companyName, price, selectedProductList[i].getQuentity(), selectedProductList[i].getAverageEvaluation());
	}
	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
}

//----------------------------------------------------------

Evaluation::Evaluation(ProductList* productList)
{
	this->productListPtr = productList;
}

Product* Evaluation::saveEvaluation(string productName, int evaluation)
{
	return productListPtr->saveEvaluationInfo(productName, evaluation);
}

//--------------------------------------------------------

EvaluationUI::EvaluationUI(ProductList* productListAddress)
{
	evaluationPtr = new Evaluation(productListAddress);
}

void EvaluationUI::evaluateProduct(FILE* in_fp, FILE* out_fp)
{
	char charProductName[MAX_STRING], evaluation[MAX_STRING];
	fscanf(in_fp, "%s %s", charProductName, evaluation);

	Product* evaluatedProduct = evaluationPtr->saveEvaluation(charProductName, stoi(evaluation));

	fprintf(out_fp, "4.4 상품 구매만족도 평가\n");
	char sellerName[MAX_STRING], name[MAX_STRING];
	strcpy(sellerName, (evaluatedProduct->getSeller()).c_str());
	strcpy(name, (evaluatedProduct->getName()).c_str());
	fprintf(out_fp, "> %s %s %s\n", sellerName, name, evaluation);
}