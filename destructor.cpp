//===============================================================================================
//
// * �Ҹ��ڴ� ��üȭ�� Ŭ������ �ν��Ͻ��� �����Ǳ� �� �ڵ����� �����ϴ�
//   Ư�� ���� �Լ��� Ī��
// -> ��κ� Ŭ������ ��üȭ �Ǹ鼭 ������ ���ҽ��� ������Ű�� ���� ���
// 
// * �Ҹ����� ȣ��
//	 1. ���α׷��� ����Ǿ� ��ü�� ������ų ��
//	 2. �Լ� �� ���� ����ó�� Ư�� ���� �� ����� ������ �ĺ��� ������ ��� ���̻� ����� ��
//		���� ��
//   3. new �����ڸ� ����Ͽ� ������ Ŭ������ �ν��Ͻ��� ������Ű�� ���� delete �����ڸ� 
//		ȣ���� ��
// * �Ҹ��� ����� ����ü���� Ŭ������ �����ϴ�
//
//===============================================================================================

//#include <iostream>
//#include <Windows.h>
//#include <cstring>
//#include <cstdlib>
//
//using namespace std;
//
//class Account {
//public:
//	char *account;
//	char *name;
//	int balance;
//
//	Account(const char *id, const char *name, int bal) : account(new char[strlen(id) + 1]), name(new char[strlen(name) + 1]), balance(bal) {
//		strcpy(this->account, id);
//		strcpy(this->name, name);
//
//		cout << "���� ������ ȣ���!" << endl;
//	}
//
//	~Account() {
//		cout << "���� �Ҹ��� ȣ���!" << endl;
//		delete[] account;
//		delete[] name;
//	}
//
//	void print() {
//		cout << "����: " << account << "�̸�: " << name << "�ܾ�: " << balance << endl;
//	}
//	void deposit(int money) {
//		balance += money;
//	}
//	void withdraw(int money) {
//		balance -= money;
//	}
//};
//
//int main()
//{
//	Account *hongdo = new Account("123456789", "ȫ�浿", 60000);
//
//	if (hongdo == NULL)
//		return -1;
//	
//	// �� �� ��ȣ ���� �ȿ��� ������ ��ü�� ������ �Ҹ��� ���� ������ �̷������.
//	{
//		Account kim("987654321", "��ȫ��", 10000);
//		hongdo->withdraw(2000);
//		kim.deposit(10000);
//		hongdo->print();
//		kim.print();
//	}
//	delete hongdo;
//	return 0;
//}


//===============================================================================================
//
// * �Ҹ����� Ư¡
//	1. �Ҹ��ڴ� �μ��� ���� �ʴ´�
//	2. �Ҹ��� ���� ������ó�� ���� Ŭ������ ����� �̷������ �ʴ´�/
//	3. �Ҹ��ڴ� Ŭ�������� �ϳ� �̻����� �����ϴ� �����ڿ� �޸� �� �ϳ��� ����
//	4. ���� Ŭ������ �Ҹ��ڰ� ȣ��Ǹ� ���ÿ� ������ ����Ŭ������ �Ҹ��ڰ� �ڵ����� ȣ��
//		-> �������� ���� ���� �Ҹ���
//	5. �Ҹ��ڴ� ��ü�� �Ҹ�Ǳ� ���� �ڿ������� ȣ��ȴ�. ������ ȣ���� ���������� �����߻���Ŵ
//	6. �ǹ̾��� ����ִ� �Ҹ��ڴ� ������ �ʴ� ���� ����. => �޸� ���� �ֱ� ����
//
// ** ���� �Ҹ���
//
//===============================================================================================


#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Box {
private:
	int width;
	int length;
	int height;

public:
	Box(int width, int length, int height) : width(width), length(length), height(height) {
		cout << "�ڽ� (" << width << ", " << length << ", " << height << ") �� ȣ��Ǿ����ϴ�." << endl;
	}

	~Box() {
		cout << "�ڽ� �Ҹ��ڰ� ȣ���!" << endl;
	}

	int vol() { return width * length*height; }
};

class StorageBox : public Box {
private:
	char *name;

public:
	StorageBox(const char *name, int width, int length, int height) : Box(width, length, height) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		cout << "���丮�� �ڽ� (" << name << ", " << width << ", " << length << ", " << height << ")�� ȣ���" << endl;
	}

	~StorageBox() {
		delete[] name;
		cout << "���丮�� �ڽ� �Ҹ��ڰ� ȣ���!" << endl;
	}
};

int main()
{
	Box *b1 = new StorageBox("�߸��� ��", 10, 20, 30);
	delete b1;

	cout << "=== �������� �� ===" << endl;
	StorageBox b2("�������� ��", 100, 20, 30);
	Box &rb = b2;

	cout << "����: " << rb.vol() << endl;
}

//===============================================================================================
//
// * �� ���� ������ �߻��ϴ� ����
//	1. new �����ڸ� ����Ͽ� ���� Ŭ������ ��ü�� ������ ��
//	2. ������ ��ü�� ���� Ŭ���� Ÿ���� �����Ϳ� �Ҵ��� ��
//	3. ��ü�� �����ϱ� ���� delete �����ڸ� ȣ�߶� ��
// ** new �����ڸ� ����ϴ��� ����( & )�� ����Ѵٸ� ����Ŭ���� �Ҹ��ڿ� ����Ŭ���� �Ҹ��ڰ�
//	  �� �� ȣ�� ������
//	ex)
//		StorageBox *b3 = new StorageBox("����", 20, 30, 40);
//		Box &b4 = b3;
//		delete b3;
//	** ���� Ŭ������ �Ҹ��ڸ� ���������� ȣ���Ű���� ���� Ŭ������ �Ҹ��ڿ� virtual�� �ٿ�
//		���� �Ҹ��ڸ� ������ָ� �ȴ�.
//	** virtual�� ��Ӱ� ���õ� �����ڷ� ���� Ŭ������ �Լ��� ���� Ŭ������ �Լ��� ��ó�ϴ� ����� ����
//	** ��Ӱ� ���õ� Ŭ�������� �Ҹ��ڸ� ����ٸ� ����ϵ� ������� �ʵ� ������ virtual �����ڸ� ���������
//
//===============================================================================================