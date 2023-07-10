/************************************************************************************************************************************************************************/
// 1. ���α׷� �̸� : �ּҷ� ���� ���α׷�
// 2. �ۼ��� : �����
// 3. ���α׷� ���� : �̸�, ��ȭ��ȣ �� ����� ������ ����, ��ȸ, �߰�, ����, �����ϴ� �ּҷ� ���� ���α׷�
// 4. ���� ��� : �Է¹޴� ������ Ŭ������ ������ �Է¹޾� �����ϴ� �ּҷ� Ŭ������ ����� �Է¹��� ������ �ּҷ� Ŭ������ �����ϰ� �������� ��ȸ, �߰�, ����, �����Ѵ�.
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
		cout << "1. �ּҷ� ��ȸ" << endl;
		cout << "2. �ּҷ� �߰�" << endl;
		cout << "3. �ּҷ� ����" << endl;
		cout << "4. �ּҷ� ����" << endl;
		cout << "5. �������� ��ȸ" << endl;
		cout << "6. ����" << endl;
		cout << "=========================================" << endl;
		cout << "�޴��� �����ϼ��� (1 ~ 6): ";

		int command;
		cin >> command;

		if (command == 1) {
			addressBook.showInfo();
		}

		else if (command == 2) {
			cin.ignore();

			cout << "�̸� : ";
			string name;
			getline(cin, name);

			cout << "�̸��� : ";
			string email;
			getline(cin, email);

			cout << "�ּ� : ";
			string address;
			getline(cin, address);

			cout << "��ȭ��ȣ : ";
			string phoneNumber;
			getline(cin, phoneNumber);

			cout << "���� : ";
			bool gender;
			cin >> gender;
			cin.ignore();

			Information info1 = Information(name, email, address, phoneNumber, gender);
			addressBook.addInfo(info1);
		}

		else if (command == 3) {
			cin.ignore();

			cout << "������ ����� �̸� : ";
			string name;
			getline(cin, name);

			cout << "�� �̸��� : ";
			string email;
			getline(cin, email);

			cout << "�� �ּ� : ";
			string address;
			getline(cin, address);

			cout << "�� ��ȭ��ȣ : ";
			string phoneNumber;
			getline(cin, phoneNumber);

			addressBook.updateInfo(name, email, address, phoneNumber);
		}

		else if (command == 4) {
			cout << "������ ����� �̸� : ";
			string name;
			cin >> name;

			addressBook.deleteInfo(name);
		}

		else if (command == 5) {
			cout << "��ȸ�� ����� �̸� : ";
			string name;
			cin >> name;

			addressBook.searchInfo(name);
		}

		else if (command == 6) {
			cout << "���α׷� ����" << endl;
			break;
		}

		else {
			cout << "�޴��� �ٽ� �����ϼ���(1 ~ 6)" << endl;
		}
	}
}