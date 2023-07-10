#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Information {
private :
	string name;
	string email;
	string address;
	string phoneNumber;
	bool gender; // true : ����, false : ����

public :
	Information()
	{
		name = "ȫ�浿";
		email = "ȫ�浿@naver.com";
		address = "���ﱤ����";
		phoneNumber = "01012345678";
		gender = true;
	}

	Information(string _name, string _email, string _address, string _phoneNumber, bool _gender)
	{
		this->name = _name;
		this->email = _email;
		this->address = _address;
		this->phoneNumber = _phoneNumber;
		this->gender = _gender;
	}

	~Information()
	{

	}

	void setEmail(string newEmail) { this->email = newEmail; }
	void setAddress(string newAddress) { this->address = newAddress; }
	void setPhoneNumber(string newPhoneNumber) { this->phoneNumber = newPhoneNumber; }
	
	string getName(void) { return name; }
	string getEmail(void) { return email; }
	string getAddress(void) { return address; }
	string getPhoneNumber(void) { return phoneNumber; }
	string getGender(void) { return (1 ? "����" : "����"); }
};

class AddressBook {
private:
	vector<Information> info;
public:
	void addInfo(const Information information)
	{
		info.push_back(information);
	}

	void showInfo(void)
	{
		cout << "�ּҷ� ��� : " << endl;
		for (auto i : info)
		{
			cout << "-------------" << endl;
			cout << "�̸� : " << i.getName() << endl;
			cout << "�̸��� : " << i.getEmail() << endl;
			cout << "�ּ� : " << i.getAddress() << endl;
			cout << "��ȭ��ȣ : " << i.getPhoneNumber() << endl;
			cout << "���� : " << i.getGender() << endl;
			cout << "-------------" << endl << endl;
		}
	}

	void searchInfo(string& name)
	{
		for (auto i : info)
		{
			if (i.getName() == name)
			{
				cout << "-------------" << endl;
				cout << name << "�� �����Դϴ�." << endl;
				cout << "�̸��� : " << i.getEmail() << endl;
				cout << "�ּ� : " << i.getAddress() << endl;
				cout << "��ȭ��ȣ : " << i.getPhoneNumber() << endl;
				cout << "���� : " << i.getGender() << endl;
				cout << "-------------" << endl;
				return;
			}
		}
		cout << name << "�� ������ �����ϴ�" << endl;
	}

	void updateInfo(string& name, string& newEmail, string& newAddress, string& newPhoneNumber)
	{
		for (auto& i : info)
		{
			if (i.getName() == name)
			{
				i.setEmail(newEmail);
				i.setPhoneNumber(newPhoneNumber);
				i.setAddress(newAddress);
				cout << "������ ������Ʈ �ƽ��ϴ�." << endl;
				return;
			}
		}
		cout << name << "�� ������ �����ϴ�." << endl;
	}

	void deleteInfo(string& name)
	{
		for (auto i = info.begin(); i != info.end(); i++)
		{
			if (i->getName() == name)
			{
				info.erase(i);
				cout << "����ó�� �����Ǿ����ϴ�." << endl;
				return;
			}
		}
		cout << name << "�� ������ �����ϴ�." << endl;
	}
};