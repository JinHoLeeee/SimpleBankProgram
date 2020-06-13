#include <iostream>
#include <string>
using namespace std;

/*다음 기능을 제공하는 계좌 관리 프로그램(account class를 정의)을 작성하라.

 

account class에는 계좌 번호, 이름, 주소, 전화 번호 등의 정보와 잔고가 저장되며, 계좌 개설, 변경, 해지, 입금, 출금, 잔액 확인, 거래 내역 확인 등의 기능이 제공되어야 함.

 
*/

class Account {
public:
	int accno = 0;
	int password = 0;
	char name[101];
	char address[101];
	double phone = 0;
	
	
	string totalsend;
	string totalin;
	string totalout;

	double money = 0;

	void showmoney() {
		cout << this->name << " 님의 현재 통장 잔고는 " << this->money << " 원 입니다.^^ 부자이시네요~" << endl;
	}

	
	void setaccount() {
		

		cout << "원하는 계좌번호를 입력해주세요 >> (9자 이하)";
		cin >> this->accno;
		
		
		cout << "계좌의 비밀번호를 설정해주세요 >> (9자 이하, 숫자만 가능합니다.)";
		cin >> this->password;
		

		cout << "성함을 입력해주세요 >> (100자 이하)";
		cin >> name;
		
		for (int i = 0; i < 101; i++) {
			this->name[i] = name[i];

		}
		cout << "주소를 입력해주세요 >> (10자 이하)";
		cin >> address;
		for (int i = 0; i < 101; i++) {
			this->address[i] = address[i];
		}
		cout << "전화번호를 입력해주세요 >> ( - 없이 입력해주세요!)";
		cin >> this->phone;
		

		
		cout << "계좌가 생성되었습니다." << endl;
	}

	

	void changeaccount() {
		int change = 0;
		cout << "변경하고자 하는 항목을 입력해주세요." << endl;
		cout << "1. 성함" << endl;
		cout << "2. 주소" << endl;
		cout << "3. 전화번호" << endl;
		cout << "4. 비밀번호" << endl;
		cin >> change;
		switch (change)
		{
		case 1:
			char name2[101];
			cout << "새로운 성함을 입력해주세요. (100자 이하)";
			cin >> name2;
			for (int i = 0; i < 101; i++) {
				this->name[i] = name2[i];
			}
			cout << "변경되었습니다. 반가워요 " << name2 << " 님~~" << endl;
			break;
			
		case 2:
			char address2[101];
			cout << "새로운 주소를 입력해주세요. (100자 이하)";
			cin >> address2;
			for (int i = 0; i < 101; i++) {
				this->address[i] = address2[i];
			}
			cout << "변경되었습니다~!" << endl;
			break;

		case 3:
			double phone2;
			cout << "새로운 전화번호를 입력해주세요.";
			cin >> phone2;
			this->phone = phone2;
			cout << "변경되었습니다~!" << endl;
			break;
		
		case 4:
			int password2 = 0;
			cout << "새로운 비밀번호를 입력해주세요.";
			cin >> password2;
			this->password = password2;
			cout << "변경되었습니다~!" << endl;
			break;
		}
	}
	void moneyIn() {
		double Input = 0;
		string inin;
		string next = "\n";
		string won = " 원";
		cout << "입금할 금액을 입력해주세요.최대 8자리 >>";
		cin >> Input;
		cout << "한 번 더 입력해주세요.>>";
		cin >> inin;
		if(Input < 0) {
			cout << "숫자를 잘못 입력하셨습니다." << endl;
		}
		else {
			
		this->money += Input;
		cout << "입금 완료되었습니다." << endl;
		cout <<this->name<< " 님의 현재 잔액은 " << this->money << " 원 입니다." << endl;
		this->totalin += next;
		this->totalin += inin;
		this->totalin += won;

		}
}
	/*void sendmoney(Account &Account1, Account &Account2) {
		double sendm = 0;
		int right = 0;
		int rf = 1;
		while (rf == 1) {
			cout << "송금할 금액을 입력해주세요. >>";
			cin >> sendm;
			if (sendm < 0 || Account1->money < sendm) {
				cout << "금액이 잘못 입력되었거나, 통장의 잔고가 부족합니다."<<endl;
			}
			else {

				cout << "돈을 받는 사람의 성함이 " << Account2->name << " 이 맞습니까?" << endl;
				cout << "맞으면 1, 아니면 2를 입력해주세요>>"<<endl;
				cin >> right;
				if (right == 1) {
					Account1->money -= sendm;
					Account2->money += sendm;

					cout << "입금이 완료되었습니다." << endl;
					rf = 2;
				}
				


			}
		}
		
	}*/

	void sendmoney(Account &A2) {
		string receiver = A2.name;
		string sender = this->name;
		string next = "\n";
		string to = " 에게 ";
		string won = " 원";
		string sendsend;
		string from = " 로부터 ";
		double sendm = 0;
		int right = 0;
		cout << "송금하려는 금액을 입력해주세요.>>";
		cin >> sendm;
		cout << "한 번 더 입력해주세요.>>";
		cin >> sendsend;
		if (sendm < 0 || this->money < sendm) {
			cout << "잘못된 숫자이거나 통장의 잔고가 부족합니다." << endl;
		}
		else {
			cout << "받는 사람의 성함이 " << A2.name << " 이 맞습니까? 맞으면 1, 아니면 2를 입력하세요.>>" << endl;
			cin >> right;
			if (right = 1) {
				this->money -= sendm;
				A2.money += sendm;
				cout << "송금 완료됐습니다.ㅎㅎ" << endl;
				cout << "현재 " << this->name << " 님의 통장의 잔액은 " << this->money << " 원 입니다." << endl;
				this->totalsend += next;
				this->totalsend += receiver;
				this->totalsend += to;
				this->totalsend += sendsend;
				this->totalsend += won;

				A2.totalsend += next;
				A2.totalsend += sender;
				A2.totalsend += from;
				A2.totalsend += sendsend;
				A2.totalsend += won;
				
			}
			else {
				cout << "다시 시도해 주세요.ㅠㅠ" << endl;
			}
		}
	}

	void moneyOut() {
		double output = 0;
		string outout;
		string next = "\n";
		string won = " 원";
		cout << "출금할 금액을 입력해주세요.>>";
		cin >> output;
		cout << "한 번 더 입력해주세요.>>";
		cin >> outout;
		
		if (output < 0 || this->money < output) {
			cout << "잘못된 숫자를 입력하였거나, 통장의 잔고가 부족합니다." << endl;
		}
		else {
			this->money = this->money - output;
			cout << "출금이 완료되었습니다." << endl;
			cout << "현재 잔액은 " <<this->money << " 원 입니다." << endl;
			this->totalout += next;
			this->totalout += outout;
			this->totalout += won;
		}
	}

	void checkmoney(Account *Account) {
		cout <<this->name<< " 님의 현재 잔액은 " << Account->money << " 원 입니다." << endl;
	}


};

int main() {
	Account *mm = new Account[100];
	int menu = 0;
	int userno = 0;
	int rfrf = 1;
	while (rfrf = 1) {
		cout << "어서오세요~! 과제과제은행입니다. 무엇을 도와드릴까요?" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 계좌 정보 변경" << endl;
		cout << "3. 입금" << endl;
		cout << "4. 출금" << endl;
		cout << "5. 송금" << endl;
		cout << "6. 잔액 확인" << endl;
		cout << "7. 거래 내역 확인" << endl;
		cout << "8. 계좌 해지" << endl;
		cout << "9. 프로그램 종료" << endl;
		cin >> menu;
		if (menu < 1 || menu>9) {
			cout << "숫자를 잘못 입력하셨습니다. 다시 한번 해주세요." << endl;
		}
		switch (menu)
		{
		case 1:
			
				
			mm[userno].setaccount();
					
			userno++;

			break;

		case 2:
			int checkacc;
			int userno2;
			int password2;
			checkacc = 0;
			
			password2 = 0;
			userno2 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc;

			for (int i = 0; i < 100; i++) {

				if (checkacc != mm[userno2].accno) {
					userno2++;
				}
				else { break; }

			}
			cout << "비밀번호를 입력해주세요.>>";
			cin >> password2;
			if (password2 == mm[userno2].password) {
					mm[userno2].changeaccount();
				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}

				break;
			

		case 3:
			int checkacc3;
			int userno3;
			int password3;
			checkacc3 = 0;
			password3 = 0;
			userno3 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc3;

			

			for (int i=0;i<100;i++){
				
				if (checkacc3 != mm[userno3].accno) {
					userno3++;
				}
				else { break; }
				
			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password3;
				if (password3 == mm[userno3].password) {
					mm[userno3].moneyIn();
				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
			
		case 4:
			int checkacc4;
			int userno4;
			int password4;
			
			checkacc4 = 0;
			password4 = 0;
			userno4 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc4;

			

			for (int i = 0; i < 100; i++) {

				if (checkacc4 != mm[userno4].accno) {
					userno4++;
				}
				else { break; }

			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password4;
				if (password4 == mm[userno4].password) {
					mm[userno4].moneyOut();
				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
			
		case 5:
			int checkacc5;
			int userno5;
			int usernono;
			int password5;
			int reaccno;
			
			checkacc5 = 0;
			usernono = 0;
			reaccno = 0;
			password5 = 0;
			userno5 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc5;


			for (int i = 0; i < 100; i++) {

				if (checkacc5 != mm[userno5].accno) {
					userno5++;
				}
				else { break; }

			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password5;
				if (password5 == mm[userno5].password) {
					cout << "받는 사람의 계좌번호를 입력해주세요.>>";
					cin >> reaccno;
					/*while (reaccno != mm[usernono].accno) {
						usernono++;
					}*/
					for (int h = 0; h < 100; h++) {
						if (reaccno != mm[usernono].accno) {
							usernono++;
						}
					}
					mm[userno5].sendmoney(mm[usernono]);

				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
			
		case 6:
			int checkacc6;
			int userno6;
			int password6;
			
			checkacc6 = 0;
			password6 = 0;
			userno6 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc6;

			

			for (int i = 0; i < 100; i++) {

				if (checkacc6 != mm[userno6].accno) {
					userno6++;
				}
				else { break; }

			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password6;
				if (password6 == mm[userno6].password) {
					mm[userno6].showmoney();
				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
			
		case 7:
			int checkacc7;
			int userno7;
			int password7;
			
			checkacc7 = 0;
			password7 = 0;
			userno7 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc7;



			for (int i = 0; i < 100; i++) {

				if (checkacc7 != mm[userno7].accno) {
					userno7++;
				}
				else { break; }

			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password7;
				if (password7 == mm[userno7].password) {
					cout << mm[userno7].name << " 님의 거래 내역 :" << endl;
					cout << "=====출금 내역=====" << endl;
					cout << mm[userno7].totalout << endl;
					cout << "=====입금 내역=====" << endl;
					cout << mm[userno7].totalin << endl;
					cout << "=====송금 내역=====" << endl;
					cout << mm[userno7].totalsend << endl;

				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
			
		case 8:
			int checkacc8;
			int userno8;
			int password8;
			int really;
			really = 0;
			

			checkacc8 = 0;
			password8 = 0;
			userno8 = 0;
			cout << "계좌번호를 입력해주세요.>>";
			cin >> checkacc8;
			

			for (int i = 0; i < 100; i++) {

				if (checkacc8 != mm[userno8].accno) {
					userno8++;
				}
				else { break; }

			}
				cout << "비밀번호를 입력해주세요.>>";
				cin >> password8;
				if (password8 == mm[userno8].password) {
					cout << "정말로 삭제하시겠습니까? 맞으면 1, 아니면 2를 입력해주세요.>>";
					cin >> really;
					if (really == 1) {
						for (int i = 0; i < 101; i++) {
							mm[userno8].name[i] = NULL;
							mm[userno8].address[i] = NULL;

						}
						mm[userno8].password = 0;
						mm[userno8].accno = 0;
						mm[userno8].phone = 0;
					}
				}
				else {
					cout << "비밀번호가 잘못되었습니다." << endl;
				}
				break;
		case 9:
			int choice;
			choice = 0;
			cout << "정말로 종료하시겠습니까? 만드셨던 계좌가 모두 삭제됩니다. 종료하려면 1, 아니면 2를 입력하세요." << endl;
			cin >> choice;
			if (choice == 1) {
				delete[] mm;
				return 0;
			}
			else {
				break;
			}
		}
	}
}