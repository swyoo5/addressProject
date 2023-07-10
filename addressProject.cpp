/************************************************************************************************************************************************************************/
// 1. 프로그램 이름 : 주소록 관리 프로그램
// 2. 작성자 : 유상원
// 3. 프로그램 설명 : 이름, 전화번호 등 사람의 정보를 저장, 조회, 추가, 수정, 삭제하는 주소록 관리 프로그램
// 4. 사용된 기술 : 입력받는 정보의 클래스와 정보를 입력받아 저장하는 주소록 클래스를 만들어 입력받은 정보를 주소록 클래스에 저장하고 정보들을 조회, 추가, 수정, 삭제한다.
/************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "address.h"

using namespace std;

void getCommand(AddressBook& addressBook);

int main(void)
{
	AddressBook addressBook;
	getCommand(addressBook);
	return 0;
}

void getCommand(AddressBook& addressBook)
{
	while (1)
	{
		cout << "=========================================" << endl;
		cout << "1. 주소록 조회" << endl;
		cout << "2. 주소록 추가" << endl;
		cout << "3. 주소록 수정" << endl;
		cout << "4. 주소록 삭제" << endl;
		cout << "5. 개별정보 조회" << endl;
		cout << "6. 종료" << endl;
		cout << "=========================================" << endl;
		cout << "메뉴를 선택하세요 (1 ~ 6): ";

		int command;
		cin >> command;

		if (command == 1) {
			addressBook.showInfo();
		}

		else if (command == 2) {
			cin.ignore();

			cout << "이름 : ";
			string name;
			getline(cin, name);

			cout << "이메일 : ";
			string email;
			getline(cin, email);

			cout << "주소 : ";
			string address;
			getline(cin, address);

			cout << "전화번호 : ";
			string phoneNumber;
			getline(cin, phoneNumber);

			cout << "성별 : ";
			bool gender;
			cin >> gender;
			cin.ignore();

			Information info1 = Information(name, email, address, phoneNumber, gender);
			addressBook.addInfo(info1);
		}

		else if (command == 3) {
			cin.ignore();

			cout << "수정할 사람의 이름 : ";
			string name;
			getline(cin, name);

			cout << "새 이메일 : ";
			string email;
			getline(cin, email);

			cout << "새 주소 : ";
			string address;
			getline(cin, address);

			cout << "새 전화번호 : ";
			string phoneNumber;
			getline(cin, phoneNumber);

			addressBook.updateInfo(name, email, address, phoneNumber);
		}

		else if (command == 4) {
			cout << "삭제할 사람의 이름 : ";
			string name;
			cin >> name;

			addressBook.deleteInfo(name);
		}

		else if (command == 5) {
			cout << "조회할 사람의 이름 : ";
			string name;
			cin >> name;

			addressBook.searchInfo(name);
		}

		else if (command == 6) {
			cout << "프로그램 종료" << endl;
			break;
		}

		else {
			cout << "메뉴를 다시 선택하세요(1 ~ 6)" << endl;
		}
	}
}