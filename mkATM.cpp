#include<iostream>
#include<string>
#include<ctime>
#include<typeinfo>
using namespace std;

template <typename T>
size_t countDigits(T n) {
  string tmp;

  tmp = to_string(n);
  if (n < 0) return tmp.size() - 1;
  return tmp.size();
}
int main() {
	int studentNumber = 122214240;
	int balance=50000;
	int erroru=3,errorp=3;				  //�b���K�X�i���զ��� 
	int ip=0,iu=0;						 //�b���K�X��l 
	int u12,u89,p34,p56;				//�b���K�X�e�G��G	
	int pl,ul;						   //�b���K�X���� 
	int pp;							  //�ΨӧP�O�b���᤻�X�O�_�P��J���K�X�ۦP 
	int exit,count=0;			  	
	int username, password;
	string menu; 
	string oplogs[100], ts;
	char e;
	bool check;
	cout << "�w����{��_�@ATM�A�`�N�b���K�X���~�W���U��3���A�нT�{��A�o�e" ;
	while (errorp != 0 && erroru != 0) {				//�b���K�X�i���զ��Ƥ��F0���� 
			cout << "\n�п�J�b��:";
			cin >> username;
		//	ul = username.length();						  //�W�l���� 
		//	iu = stoi(username);						 //iu = username�r������ 
			const type_info &uType = typeid(username);
			u12 = iu / 10000000;						//�e��� = 12,2214240	
			u89 = iu % 100;							   //���� = ��100���l�� 1222142,40 
			if (uType != typeid(int)){
				cout << "��J���b����������ơA�Ѿl���Ƭ�:" << --erroru;
				if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; }
			}
			else if (countDigits(username)!=9) {
				cout << "�`��ƻ�9�X�Э��s��J�A�Ѿl���Ƭ�:" << --erroru;
				if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
			}
			else if (u12 < 9 || u12 > 12) {
				cout << "�e��X�ݤ���09~12�Э��s��J�A�Ѿl���Ƭ�:" << --erroru;
				if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
			}
			else if (u89  <1 || u89 > 50) {
				cout << "����X�ݤ���01~50�Э��s��J�A�Ѿl���Ƭ�:" << --erroru;
				if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
			}
			else if (username == studentNumber) {
				cout << "�b�����T";
				while (errorp != 0 && erroru != 0) {
					cout << "\n�п�J�K�X:";
					cin >> password;
				//	pl = password.length();
				//	ip = stoi(password);
				    const type_info &pType = typeid(username);
					pp = studentNumber % 1000000;			 //pp�����T�K�X122,214240 ����6 
					p34 = (ip % 10000) / 100;				//21,4240��1000���l �b/100 42,40 
					p56 = ip % 100;
					if (pType != typeid(int)){
						cout << "��J���K�X��������ơA�Ѿl���Ƭ�:" << --erroru;
						if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; }
		 			}  
					else if (countDigits(password) != 6) {
						cout << "�`��ƻ�6�X�Э��s��J�A�Ѿl���Ƭ�:" << --errorp;
						if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
					}
					else if (p34 < 41 || p34 > 42) {
						cout << "�ĤT�ܲĥ|�X�ݤ���41~42�Э��s��J�A�Ѿl���Ƭ�:" << --errorp;
						if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
					}
					else if (p56 < 1 || p56 > 50) {
						cout << "����X�ݤ���01~50�Э��s��J�A�Ѿl���Ƭ�:" << --errorp;
						if (erroru < 0){cout << "�Э��s���d�n�J" ; return 1; } 
					}
					else if (ip == pp) {
						cout << "�K�X���T \n�w����{���|���P��";
						while (errorp != 0 && erroru != 0) {
							cout << "\n[1.�l�B�d��]"; 
							cout << "\n[2.�s��]"; 
							cout << "\n[3.����]";
							cout << "\n[4.���}]";
							cout << "\n[5.��ܾާ@����]";
							cout << "\n�п�J�\\��:";
							cin >> menu;
							if (menu == "1") {
								cout << "\n�l�B:" << balance;
								string bb;
								bb = to_string(balance);
								oplogs[count] = "�ﶵ:1 �ާ@����B"+bb;
								count += 1;	
							}
							else if (menu =="2") {
								bool validInput = false;
								int money = 0;
								string s2;
								while (!validInput ) {
									bool n = true;
									cout << "\n�ثe�l�B:" << balance << "\n�п�J�s�ڪ��B:";
									cin >> s2;
									//cout << "s2:" << s2;
									int len2 = s2.length();
									for (int x = 0; x < len2; x++) {
										if (!isdigit(s2[x])) {
											n = false;
											break;
										}
									}
									if (n) {
										
											money = stoi(s2);
											//cout << "money:" << money;
											validInput = true;
											if (money < 100001 && money>0) {
												balance = balance + money;
												cout << "�s�ڦ��\\,�ثe�l�B:" << balance;
												string bb;
												bb = to_string(balance);
												oplogs[count] = "�ﶵ:2 ���\\�ާ@���B:"+s2+"�ާ@����B" + bb;
												count += 1;
												
											}
											else {
												cout << "�W�L�W�� �п�J���T���B:";
												validInput = false;
											}
									}
									else {
										cout << "�п�J���T���B:";
										validInput = false;
									}
								}
							}
							else if (menu == "3") {
								bool validInput = false ;
								int money = 0;
								string s3;
								while (!validInput ) {
									bool n = true;
									cout << "\n�ثe�l�B:" << balance << "\n�п�J���ڪ��B:";
									cin >> s3;
									int len3 = s3.length();
									for (int x = 0; x < len3; x++) {
										if (!isdigit(s3[x])) {
											n = false;
											break;
										}
									}
									if (n) {
										money = stoi(s3);
										validInput = true;
										if (money < 30001 && money>0 && money < balance) {
											balance = balance - money;
											cout << "���ڦ��\\ �ثe�l�B:" << balance;
											string bb;
											bb = to_string(balance);
											oplogs[count] = "�ﶵ:3 ���\\�ާ@���B:" + s3 + "�ާ@����B" + bb;
											count += 1;
										}
										else {
											cout << "�W�L�W�� �п�J���T���B:";
											validInput = false;
										}
									}
									else {
										cout << "�п�J���T���B:";
									}
								}
							}
							else if (menu == "4") {
								while (menu == "4") {
									cout << "�O�_���}(y/n)";
									cin >> e;
									if (e == 'Y' || e == 'y') {
										errorp = 0;
										erroru = 0;
										exit = 1;
										break;
									}
									else if (e == 'n' || e == 'N') {
										break;
									}
									else {
										cout << "��J���~";
									}
								}
							}
							else if (menu == "5") {
								for (int y = 0; y <= count; y++)
								{
									cout << oplogs[y]<<"\n";
								}	
							}
							else {
								cout << "��J���~";
							}	
						}
					}
					else {
						cout << "�K�X���~�Э��s��J�A�Ѿl���Ƭ�:" << --errorp << "�Э��s���d�n�J";
						errorp -= 1;
						if (erroru < 0) { return 1; }
					}
				}
			}
			else {
				cout << "�b�����~�Э��s��J�A�Ѿl���Ƭ�:" << --errorp << "�Э��s���d�n�J";
				erroru -= 1;
				if (erroru < 0) { return 1; }
			}		
	}
	if (exit < 0)
	{
		cout << "�A��";
	}
	return 0;
}
