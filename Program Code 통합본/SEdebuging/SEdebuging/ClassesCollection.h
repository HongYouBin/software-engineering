#pragma once
#include <vector>
#include <string>
using namespace std;

class JoinMembership;
class JoinMembershipUI;
class Login;
class LoginUI;
class Logout;
class LogoutUI;
class ManageMember;
class Member;
class ProductList;
class Product;
class RegisterSellingClothing;
class RegisterSellingClothingUI;
class Withdrawal;
class WithdrawalUI;
class Search;
class SearchUI;
class PurchaseList;
class PurchaseListUI;
class Evaluation;
class EvaluationUI;

// Class : JoinMembership
// Description: 회원가입 기능의 Control Class
class JoinMembership
{
	JoinMembershipUI* joinMembershipUIPtr;     // JoinMembership 기능의 boundary class pointer
	ManageMember* manageMemberPtr;             // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	JoinMembership(ManageMember* manageMemberPtr);
	JoinMembershipUI* getJoinMembershipUIPtr();
	void addNewMember(string name, string SSN, string ID, string password);
};

// Class : JoinMembershipUI
// Description: 회원가입 기능의 Boundary Class
class JoinMembershipUI
{
	JoinMembership* joinMembershipPtr;      // JoinMembership 기능의 control class pointer
public:
	JoinMembershipUI(JoinMembership* joinMembershipPtr);
	void startInterface();
	void inputPersonalInfo(FILE* in_fp, FILE* out_fp);
};

// Class : Login
// Description: 로그인 기능의 Control Class
class Login
{
	LoginUI* loginUIPtr;                // Login 기능의 boundary class pointer
	ManageMember* manageMemberPtr;      // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Login(ManageMember* manageMemberPtr);
	LoginUI* getLoginUIPtr();
	int checkMember(string ID, string password);

};

// Class : LoginUI
// Description: 로그인 기능의 Boundary Class
class LoginUI
{
	Login* loginPtr;           // Login 기능의 control class pointer
public:
	LoginUI(Login* loginPtr);

	void InputIDPW(FILE* in_fp, FILE* out_fp);
	void startInterface();
};

// Class : Logout
// Description: 로그아웃 기능의 Control Class
class Logout
{
	ManageMember* manageMemberPtr;       // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Logout(ManageMember* manageMemberPtr);
	string logout();
};

// Class : LogoutUI
// Description: 로그아웃 기능의 Boundary Class
class LogoutUI
{
	Logout* logoutPtr;     // Logout 기능의 control class pointer
public:
	LogoutUI(Logout* logoutPtr, FILE* out_fp);
	void selectLogout(FILE* out_fp);
};


// Class : ManageMember
// Description: 시스템 내 회원 리스트 관리 및 로그인 회원 정보 관리, 회원 정보 확인을 위한 Class
class ManageMember
{
	vector<Member> memberDB;          // 쇼핑몰 프로그램에 존재하는 전체 회원 저장 vector
	vector<Member> loggedMembers;     // 현재 쇼핑몰 프로그램에 로그인한 회원 저장 vector
public:
	string getSellerID();
	void createMember(string name, string SSN, string ID, string password);
	int checkMember(string ID, string password);
	string deleteMember();
	string deleteLoggedMember();
	void addPurchaseList(string productName);
	vector<string> getPurchaseList();
};

// Class : Member
// Description: 회원 정보 저장 Class
class Member
{
	string name;                        // 회원명
	string ID;                          // 회원 ID
	string SSN;                         // 주민번호
	string password;                    // 비밀번호
	vector<string> purchaseList;        // 해당 회원의 구매 물품명을 저장하는 vector
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
	void addPurchaseList(string productName);
};

// Class : ProductList
// Description: 시스템 내 물품 리스트 관리 Class
class ProductList
{
	vector<Product> productDB;          // 쇼핑몰 프로그램에 존재하는 전체 물품 저장 vector
public:
	void createProduct(string seller, string name, string company, string price, string quentity);
	Product* getProductInfo(string productName);
	void purchase(Product* productName);
	Product* saveEvaluationInfo(string productName, int evaluation);
};

// Class : Product
// Description: 물품 정보 저장 Class
class Product
{
	string seller;                  // 판매자 ID
	string name;                    // 상품명
	string company;                 // 상품 생산 회사명
	string price;                   // 상품 가격
	int quentity;                   // 수량
	int evaluation = 0;             // 구매만족도
	int numberOfEvaluation = 0;		//구매만족도에 참여한 인원 
public:
	Product(string seller, string name, string company, string price, int quentity);
	string getName();
	string getSeller();
	string getPrice();
	string getCompany();
	int getQuentity();
	int getEvaluationAverage();
	void purchase();
	Product addEvaluation(int evaluation);
	float getAverageEvaluation();
};

// Class : RegisterSellingClothing
// Description: 판매 물품 등록 기능의 Control Class
class RegisterSellingClothing
{
	RegisterSellingClothingUI* registerSellingClothingUIPtr;   // RegisterSellingClothing 기능의 boundary class pointer
	ProductList* productListPtr;                               // systemProductDB 객체의 주소를 저장하는 pointer
	ManageMember* manageMemberPtr;                             // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	RegisterSellingClothing(ProductList* productListPtr, ManageMember* manageMemberPtr);
	RegisterSellingClothingUI* getRegisterSellingClothingUIPtr();
	void addNewProduct(string name, string company, string price, string quentity);
};

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

// Class : Withdrawal
// Description: 회원탈퇴 기능의 Control Class
class Withdrawal
{
	WithdrawalUI* withdrawalUIPtr;       // Withdrawal 기능의 boundary class pointer
	ManageMember* manageMemberPtr;       // systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Withdrawal(ManageMember* manageMemberPtr);
	WithdrawalUI* getWithdrawalUIPtr();
	string cancelMembership();
};

// Class : WithdrawalUI
// Description: 회원탈퇴 기능의 Boundary Class
class WithdrawalUI
{
	Withdrawal* withdrawalPtr;       // Withdrawal 기능의 control class pointer
public:
	WithdrawalUI(Withdrawal* withdrawalPtr);
	void startInterface();
	void selectMembershipCancel(FILE* out_fp);
};

// Class : Search
// Description: 검색과 구매 기능의 Control Class
class Search
{
private:
	ProductList* productListPtr;		// systemProductDB 객체의 주소를 저장하는 pointer
	ManageMember* manageMemberPtr;		// systemMemberDB 객체의 주소를 저장하는 pointer
public:
	Search(ManageMember* manageMemberAddress, ProductList* productListAddress);
	Product* searchProduct(string productName);
	void purchaseProduct(Product* productPtr);
};

// Class : SearchUI
// Description: 검색과 구매 기능의 Boundary Class
class SearchUI
{
private:
	Search* searchPtr;		        //SearchUI의 Control Class인 Search Class의 값을 저장하는 포인터
	Product* selectedProduct;		//검색 결과를 통해 받아온 Product값을 저장하는 포인터
public:
	SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr);
	void searchProduct(FILE* productName, FILE* out_fp);
	void purchase(FILE* out_fp);
};

// Class : PurchaseList
// Description: 구매내역 조회 기능을 도와주는 Control Class
class PurchaseList
{
private:
	ProductList* productListPtr;		// systemProductDB 객체의 주소를 저장하는 pointer
	ManageMember* manageMemberPtr;		// systemMemberDB 객체의 주소를 저장하는 pointer
public:
	PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress);
	vector<Product> getPurchaseList();
};

// Class : PurchaseListUI
// Description: 구매내역 조회 기능을 하는 Boundary Class
class PurchaseListUI
{
private:
	PurchaseList* purchaseListPtr;		// PurchaseListUI의 Control Class인 PurchaseList Class값을 저장하는 포인터
public:
	PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress);
	void showProductList(FILE* out_fp);
};

// Class : Evaluation
// Description: 제품 평가 기능의 Control Class
class Evaluation
{
private:
	ProductList* productListPtr;		// systemProductDB 객체의 주소를 저장하는 pointer
public:
	Evaluation(ProductList* productList);
	Product* saveEvaluation(string productName, int evaluation);
};

// Class : EvaluationUI
// Description: 제품 평가 기능의 Boundary Class
class EvaluationUI
{
private:
	Evaluation* evaluationPtr;		// EvaluationUI의 Control Class인 Evaluatijon Class값을 저장하는 포인터
public:
	EvaluationUI(ProductList* productListAddress);
	void evaluateProduct(FILE* in_fp, FILE* out_fp);
};