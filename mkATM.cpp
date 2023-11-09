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
	int erroru=3,errorp=3;				  //帳號密碼可嘗試次數 
	int ip=0,iu=0;						 //帳號密碼初始 
	int u12,u89,p34,p56;				//帳號密碼前二後二	
	int pl,ul;						   //帳號密碼長度 
	int pp;							  //用來判別帳號後六碼是否與輸入的密碼相同 
	int exit,count=0;			  	
	int username, password;
	string menu; 
	string oplogs[100], ts;
	char e;
	bool check;
	cout << "歡迎光臨國北護ATM，注意帳號密碼錯誤上限各為3次，請確認後再發送" ;
	while (errorp != 0 && erroru != 0) {				//帳號密碼可嘗試次數不達0次時 
			cout << "\n請輸入帳號:";
			cin >> username;
		//	ul = username.length();						  //名子長度 
		//	iu = stoi(username);						 //iu = username字串轉整數 
			const type_info &uType = typeid(username);
			u12 = iu / 10000000;						//前兩位 = 12,2214240	
			u89 = iu % 100;							   //後兩位 = 跟100拿餘數 1222142,40 
			if (uType != typeid(int)){
				cout << "輸入的帳號必須為整數，剩餘次數為:" << --erroru;
				if (erroru < 0){cout << "請重新插卡登入" ; return 1; }
			}
			else if (countDigits(username)!=9) {
				cout << "總位數需9碼請重新輸入，剩餘次數為:" << --erroru;
				if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
			}
			else if (u12 < 9 || u12 > 12) {
				cout << "前兩碼需介於09~12請重新輸入，剩餘次數為:" << --erroru;
				if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
			}
			else if (u89  <1 || u89 > 50) {
				cout << "末兩碼需介於01~50請重新輸入，剩餘次數為:" << --erroru;
				if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
			}
			else if (username == studentNumber) {
				cout << "帳號正確";
				while (errorp != 0 && erroru != 0) {
					cout << "\n請輸入密碼:";
					cin >> password;
				//	pl = password.length();
				//	ip = stoi(password);
				    const type_info &pType = typeid(username);
					pp = studentNumber % 1000000;			 //pp為正確密碼122,214240 取到6 
					p34 = (ip % 10000) / 100;				//21,4240跟1000拿餘 在/100 42,40 
					p56 = ip % 100;
					if (pType != typeid(int)){
						cout << "輸入的密碼必須為整數，剩餘次數為:" << --erroru;
						if (erroru < 0){cout << "請重新插卡登入" ; return 1; }
		 			}  
					else if (countDigits(password) != 6) {
						cout << "總位數需6碼請重新輸入，剩餘次數為:" << --errorp;
						if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
					}
					else if (p34 < 41 || p34 > 42) {
						cout << "第三至第四碼需介於41~42請重新輸入，剩餘次數為:" << --errorp;
						if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
					}
					else if (p56 < 1 || p56 > 50) {
						cout << "末兩碼需介於01~50請重新輸入，剩餘次數為:" << --errorp;
						if (erroru < 0){cout << "請重新插卡登入" ; return 1; } 
					}
					else if (ip == pp) {
						cout << "密碼正確 \n歡迎光臨李育民同學";
						while (errorp != 0 && erroru != 0) {
							cout << "\n[1.餘額查詢]"; 
							cout << "\n[2.存款]"; 
							cout << "\n[3.提款]";
							cout << "\n[4.離開]";
							cout << "\n[5.顯示操作紀錄]";
							cout << "\n請輸入功\能:";
							cin >> menu;
							if (menu == "1") {
								cout << "\n餘額:" << balance;
								string bb;
								bb = to_string(balance);
								oplogs[count] = "選項:1 操作後金額"+bb;
								count += 1;	
							}
							else if (menu =="2") {
								bool validInput = false;
								int money = 0;
								string s2;
								while (!validInput ) {
									bool n = true;
									cout << "\n目前餘額:" << balance << "\n請輸入存款金額:";
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
												cout << "存款成功\,目前餘額:" << balance;
												string bb;
												bb = to_string(balance);
												oplogs[count] = "選項:2 成功\操作金額:"+s2+"操作後金額" + bb;
												count += 1;
												
											}
											else {
												cout << "超過上限 請輸入正確金額:";
												validInput = false;
											}
									}
									else {
										cout << "請輸入正確金額:";
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
									cout << "\n目前餘額:" << balance << "\n請輸入提款金額:";
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
											cout << "提款成功\ 目前餘額:" << balance;
											string bb;
											bb = to_string(balance);
											oplogs[count] = "選項:3 成功\操作金額:" + s3 + "操作後金額" + bb;
											count += 1;
										}
										else {
											cout << "超過上限 請輸入正確金額:";
											validInput = false;
										}
									}
									else {
										cout << "請輸入正確金額:";
									}
								}
							}
							else if (menu == "4") {
								while (menu == "4") {
									cout << "是否離開(y/n)";
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
										cout << "輸入錯誤";
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
								cout << "輸入錯誤";
							}	
						}
					}
					else {
						cout << "密碼錯誤請重新輸入，剩餘次數為:" << --errorp << "請重新插卡登入";
						errorp -= 1;
						if (erroru < 0) { return 1; }
					}
				}
			}
			else {
				cout << "帳號錯誤請重新輸入，剩餘次數為:" << --errorp << "請重新插卡登入";
				erroru -= 1;
				if (erroru < 0) { return 1; }
			}		
	}
	if (exit < 0)
	{
		cout << "再見";
	}
	return 0;
}
