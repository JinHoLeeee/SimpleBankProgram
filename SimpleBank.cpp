#include <iostream>
#include <string>
using namespace std;

/*���� ����� �����ϴ� ���� ���� ���α׷�(account class�� ����)�� �ۼ��϶�.

 

account class���� ���� ��ȣ, �̸�, �ּ�, ��ȭ ��ȣ ���� ������ �ܰ� ����Ǹ�, ���� ����, ����, ����, �Ա�, ���, �ܾ� Ȯ��, �ŷ� ���� Ȯ�� ���� ����� �����Ǿ�� ��.

 
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
		cout << this->name << " ���� ���� ���� �ܰ�� " << this->money << " �� �Դϴ�.^^ �����̽ó׿�~" << endl;
	}

	
	void setaccount() {
		

		cout << "���ϴ� ���¹�ȣ�� �Է����ּ��� >> (9�� ����)";
		cin >> this->accno;
		
		
		cout << "������ ��й�ȣ�� �������ּ��� >> (9�� ����, ���ڸ� �����մϴ�.)";
		cin >> this->password;
		

		cout << "������ �Է����ּ��� >> (100�� ����)";
		cin >> name;
		
		for (int i = 0; i < 101; i++) {
			this->name[i] = name[i];

		}
		cout << "�ּҸ� �Է����ּ��� >> (10�� ����)";
		cin >> address;
		for (int i = 0; i < 101; i++) {
			this->address[i] = address[i];
		}
		cout << "��ȭ��ȣ�� �Է����ּ��� >> ( - ���� �Է����ּ���!)";
		cin >> this->phone;
		

		
		cout << "���°� �����Ǿ����ϴ�." << endl;
	}

	

	void changeaccount() {
		int change = 0;
		cout << "�����ϰ��� �ϴ� �׸��� �Է����ּ���." << endl;
		cout << "1. ����" << endl;
		cout << "2. �ּ�" << endl;
		cout << "3. ��ȭ��ȣ" << endl;
		cout << "4. ��й�ȣ" << endl;
		cin >> change;
		switch (change)
		{
		case 1:
			char name2[101];
			cout << "���ο� ������ �Է����ּ���. (100�� ����)";
			cin >> name2;
			for (int i = 0; i < 101; i++) {
				this->name[i] = name2[i];
			}
			cout << "����Ǿ����ϴ�. �ݰ����� " << name2 << " ��~~" << endl;
			break;
			
		case 2:
			char address2[101];
			cout << "���ο� �ּҸ� �Է����ּ���. (100�� ����)";
			cin >> address2;
			for (int i = 0; i < 101; i++) {
				this->address[i] = address2[i];
			}
			cout << "����Ǿ����ϴ�~!" << endl;
			break;

		case 3:
			double phone2;
			cout << "���ο� ��ȭ��ȣ�� �Է����ּ���.";
			cin >> phone2;
			this->phone = phone2;
			cout << "����Ǿ����ϴ�~!" << endl;
			break;
		
		case 4:
			int password2 = 0;
			cout << "���ο� ��й�ȣ�� �Է����ּ���.";
			cin >> password2;
			this->password = password2;
			cout << "����Ǿ����ϴ�~!" << endl;
			break;
		}
	}
	void moneyIn() {
		double Input = 0;
		string inin;
		string next = "\n";
		string won = " ��";
		cout << "�Ա��� �ݾ��� �Է����ּ���.�ִ� 8�ڸ� >>";
		cin >> Input;
		cout << "�� �� �� �Է����ּ���.>>";
		cin >> inin;
		if(Input < 0) {
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�." << endl;
		}
		else {
			
		this->money += Input;
		cout << "�Ա� �Ϸ�Ǿ����ϴ�." << endl;
		cout <<this->name<< " ���� ���� �ܾ��� " << this->money << " �� �Դϴ�." << endl;
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
			cout << "�۱��� �ݾ��� �Է����ּ���. >>";
			cin >> sendm;
			if (sendm < 0 || Account1->money < sendm) {
				cout << "�ݾ��� �߸� �ԷµǾ��ų�, ������ �ܰ� �����մϴ�."<<endl;
			}
			else {

				cout << "���� �޴� ����� ������ " << Account2->name << " �� �½��ϱ�?" << endl;
				cout << "������ 1, �ƴϸ� 2�� �Է����ּ���>>"<<endl;
				cin >> right;
				if (right == 1) {
					Account1->money -= sendm;
					Account2->money += sendm;

					cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
					rf = 2;
				}
				


			}
		}
		
	}*/

	void sendmoney(Account &A2) {
		string receiver = A2.name;
		string sender = this->name;
		string next = "\n";
		string to = " ���� ";
		string won = " ��";
		string sendsend;
		string from = " �κ��� ";
		double sendm = 0;
		int right = 0;
		cout << "�۱��Ϸ��� �ݾ��� �Է����ּ���.>>";
		cin >> sendm;
		cout << "�� �� �� �Է����ּ���.>>";
		cin >> sendsend;
		if (sendm < 0 || this->money < sendm) {
			cout << "�߸��� �����̰ų� ������ �ܰ� �����մϴ�." << endl;
		}
		else {
			cout << "�޴� ����� ������ " << A2.name << " �� �½��ϱ�? ������ 1, �ƴϸ� 2�� �Է��ϼ���.>>" << endl;
			cin >> right;
			if (right = 1) {
				this->money -= sendm;
				A2.money += sendm;
				cout << "�۱� �Ϸ�ƽ��ϴ�.����" << endl;
				cout << "���� " << this->name << " ���� ������ �ܾ��� " << this->money << " �� �Դϴ�." << endl;
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
				cout << "�ٽ� �õ��� �ּ���.�Ф�" << endl;
			}
		}
	}

	void moneyOut() {
		double output = 0;
		string outout;
		string next = "\n";
		string won = " ��";
		cout << "����� �ݾ��� �Է����ּ���.>>";
		cin >> output;
		cout << "�� �� �� �Է����ּ���.>>";
		cin >> outout;
		
		if (output < 0 || this->money < output) {
			cout << "�߸��� ���ڸ� �Է��Ͽ��ų�, ������ �ܰ� �����մϴ�." << endl;
		}
		else {
			this->money = this->money - output;
			cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
			cout << "���� �ܾ��� " <<this->money << " �� �Դϴ�." << endl;
			this->totalout += next;
			this->totalout += outout;
			this->totalout += won;
		}
	}

	void checkmoney(Account *Account) {
		cout <<this->name<< " ���� ���� �ܾ��� " << Account->money << " �� �Դϴ�." << endl;
	}


};

int main() {
	Account *mm = new Account[100];
	int menu = 0;
	int userno = 0;
	int rfrf = 1;
	while (rfrf = 1) {
		cout << "�������~! �������������Դϴ�. ������ ���͵帱���?" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ���� ����" << endl;
		cout << "3. �Ա�" << endl;
		cout << "4. ���" << endl;
		cout << "5. �۱�" << endl;
		cout << "6. �ܾ� Ȯ��" << endl;
		cout << "7. �ŷ� ���� Ȯ��" << endl;
		cout << "8. ���� ����" << endl;
		cout << "9. ���α׷� ����" << endl;
		cin >> menu;
		if (menu < 1 || menu>9) {
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. �ٽ� �ѹ� ���ּ���." << endl;
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
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc;

			for (int i = 0; i < 100; i++) {

				if (checkacc != mm[userno2].accno) {
					userno2++;
				}
				else { break; }

			}
			cout << "��й�ȣ�� �Է����ּ���.>>";
			cin >> password2;
			if (password2 == mm[userno2].password) {
					mm[userno2].changeaccount();
				}
				else {
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
				}

				break;
			

		case 3:
			int checkacc3;
			int userno3;
			int password3;
			checkacc3 = 0;
			password3 = 0;
			userno3 = 0;
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc3;

			

			for (int i=0;i<100;i++){
				
				if (checkacc3 != mm[userno3].accno) {
					userno3++;
				}
				else { break; }
				
			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password3;
				if (password3 == mm[userno3].password) {
					mm[userno3].moneyIn();
				}
				else {
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
				}
				break;
			
		case 4:
			int checkacc4;
			int userno4;
			int password4;
			
			checkacc4 = 0;
			password4 = 0;
			userno4 = 0;
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc4;

			

			for (int i = 0; i < 100; i++) {

				if (checkacc4 != mm[userno4].accno) {
					userno4++;
				}
				else { break; }

			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password4;
				if (password4 == mm[userno4].password) {
					mm[userno4].moneyOut();
				}
				else {
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
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
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc5;


			for (int i = 0; i < 100; i++) {

				if (checkacc5 != mm[userno5].accno) {
					userno5++;
				}
				else { break; }

			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password5;
				if (password5 == mm[userno5].password) {
					cout << "�޴� ����� ���¹�ȣ�� �Է����ּ���.>>";
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
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
				}
				break;
			
		case 6:
			int checkacc6;
			int userno6;
			int password6;
			
			checkacc6 = 0;
			password6 = 0;
			userno6 = 0;
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc6;

			

			for (int i = 0; i < 100; i++) {

				if (checkacc6 != mm[userno6].accno) {
					userno6++;
				}
				else { break; }

			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password6;
				if (password6 == mm[userno6].password) {
					mm[userno6].showmoney();
				}
				else {
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
				}
				break;
			
		case 7:
			int checkacc7;
			int userno7;
			int password7;
			
			checkacc7 = 0;
			password7 = 0;
			userno7 = 0;
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc7;



			for (int i = 0; i < 100; i++) {

				if (checkacc7 != mm[userno7].accno) {
					userno7++;
				}
				else { break; }

			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password7;
				if (password7 == mm[userno7].password) {
					cout << mm[userno7].name << " ���� �ŷ� ���� :" << endl;
					cout << "=====��� ����=====" << endl;
					cout << mm[userno7].totalout << endl;
					cout << "=====�Ա� ����=====" << endl;
					cout << mm[userno7].totalin << endl;
					cout << "=====�۱� ����=====" << endl;
					cout << mm[userno7].totalsend << endl;

				}
				else {
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
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
			cout << "���¹�ȣ�� �Է����ּ���.>>";
			cin >> checkacc8;
			

			for (int i = 0; i < 100; i++) {

				if (checkacc8 != mm[userno8].accno) {
					userno8++;
				}
				else { break; }

			}
				cout << "��й�ȣ�� �Է����ּ���.>>";
				cin >> password8;
				if (password8 == mm[userno8].password) {
					cout << "������ �����Ͻðڽ��ϱ�? ������ 1, �ƴϸ� 2�� �Է����ּ���.>>";
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
					cout << "��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
				}
				break;
		case 9:
			int choice;
			choice = 0;
			cout << "������ �����Ͻðڽ��ϱ�? ����̴� ���°� ��� �����˴ϴ�. �����Ϸ��� 1, �ƴϸ� 2�� �Է��ϼ���." << endl;
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