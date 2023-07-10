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
	bool gender; // true : 남성, false : 여성

public :
	Information()
	{
		name = "홍길동";
		email = "홍길동@naver.com";
		address = "서울광역시";
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
	string getGender(void) { return (1 ? "남성" : "여성"); }
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
		cout << "주소록 목록 : " << endl;
		for (auto i : info)
		{
			cout << "-------------" << endl;
			cout << "이름 : " << i.getName() << endl;
			cout << "이메일 : " << i.getEmail() << endl;
			cout << "주소 : " << i.getAddress() << endl;
			cout << "전화번호 : " << i.getPhoneNumber() << endl;
			cout << "성별 : " << i.getGender() << endl;
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
				cout << name << "의 정보입니다." << endl;
				cout << "이메일 : " << i.getEmail() << endl;
				cout << "주소 : " << i.getAddress() << endl;
				cout << "전화번호 : " << i.getPhoneNumber() << endl;
				cout << "성별 : " << i.getGender() << endl;
				cout << "-------------" << endl;
				return;
			}
		}
		cout << name << "의 정보가 없습니다" << endl;
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
				cout << "정보가 업데이트 됐습니다." << endl;
				return;
			}
		}
		cout << name << "의 정보가 없습니다." << endl;
	}

	void deleteInfo(string& name)
	{
		for (auto i = info.begin(); i != info.end(); i++)
		{
			if (i->getName() == name)
			{
				info.erase(i);
				cout << "연락처가 삭제되었습니다." << endl;
				return;
			}
		}
		cout << name << "의 정보가 없습니다." << endl;
	}
};