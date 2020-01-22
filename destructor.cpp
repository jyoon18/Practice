//===============================================================================================
//
// * 소멸자는 객체화된 클래스의 인스턴스가 삭제되기 전 자동으로 실행하는
//   특수 목적 함수를 칭함
// -> 대부분 클래스가 객체화 되면서 생성한 리소스를 삭제시키기 위해 사용
// 
// * 소멸자의 호출
//	 1. 프로그램이 종료되어 객체를 삭제시킬 때
//	 2. 함수 내 지역 변수처럼 특정 지역 내 선언된 변수가 식별자 범위를 벗어나 더이상 사용할 수
//		없을 때
//   3. new 연산자를 사용하여 생성된 클래스의 인스턴스를 삭제시키기 위해 delete 연산자를 
//		호출할 때
// * 소멸자 사용은 구조체보다 클래스가 적합하다
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
//		cout << "계정 생성자 호출됨!" << endl;
//	}
//
//	~Account() {
//		cout << "계정 소멸자 호출됨!" << endl;
//		delete[] account;
//		delete[] name;
//	}
//
//	void print() {
//		cout << "계좌: " << account << "이름: " << name << "잔액: " << balance << endl;
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
//	Account *hongdo = new Account("123456789", "홍길동", 60000);
//
//	if (hongdo == NULL)
//		return -1;
//	
//	// 이 밑 괄호 범위 안에서 생성된 객체는 생성과 소멸이 범위 내에서 이루어진다.
//	{
//		Account kim("987654321", "김홍도", 10000);
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
// * 소멸자의 특징
//	1. 소멸자는 인수를 갖지 않는다
//	2. 소멸자 역시 생성자처럼 하위 클래스로 상속이 이루어지지 않는다/
//	3. 소멸자는 클래스에서 하나 이상으로 존재하는 생성자와 달리 단 하나만 존재
//	4. 하위 클래스의 소멸자가 호출되면 동시에 연관된 상위클래스의 소멸자가 자동으로 호출
//		-> 예외적인 경우는 가상 소멸자
//	5. 소멸자는 객체가 소멸되기 전에 자연스럽게 호출된다. 인위적 호출이 가능하지만 에러발생시킴
//	6. 의미없이 비어있는 소멸자는 만들지 않는 것이 좋다. => 메모리 낭비가 있기 때문
//
// ** 가상 소멸자
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
		cout << "박스 (" << width << ", " << length << ", " << height << ") 가 호출되었습니다." << endl;
	}

	~Box() {
		cout << "박스 소멸자가 호출됨!" << endl;
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
		cout << "스토리지 박스 (" << name << ", " << width << ", " << length << ", " << height << ")가 호출됨" << endl;
	}

	~StorageBox() {
		delete[] name;
		cout << "스토리지 박스 소멸자가 호출됨!" << endl;
	}
};

int main()
{
	Box *b1 = new StorageBox("잘못된 예", 10, 20, 30);
	delete b1;

	cout << "=== 정상적인 예 ===" << endl;
	StorageBox b2("정상적인 예", 100, 20, 30);
	Box &rb = b2;

	cout << "부피: " << rb.vol() << endl;
}

//===============================================================================================
//
// * 위 같은 문제가 발생하는 조건
//	1. new 연산자를 사용하여 하위 클래스의 객체를 생성할 때
//	2. 생성한 객체를 상위 클래스 타입의 포인터에 할당할 때
//	3. 객체를 삭제하기 위해 delete 연산자를 호추랄 때
// ** new 연산자를 사용하더라도 참조( & )를 사용한다면 상위클래스 소멸자와 하위클래스 소멸자가
//	  둘 다 호출 가능함
//	ex)
//		StorageBox *b3 = new StorageBox("예제", 20, 30, 40);
//		Box &b4 = b3;
//		delete b3;
//	** 하위 클래스의 소멸자를 정상적으로 호출시키려면 상위 클래스의 소멸자에 virtual을 붙여
//		가상 소멸자를 만들어주면 된다.
//	** virtual은 상속과 관련된 지정자로 하위 클래스의 함수가 상위 클래스의 함수를 대처하는 기능을 제공
//	** 상속과 관련된 클래스에서 소멸자를 만든다면 사용하든 사용하지 않든 무조건 virtual 지정자를 만들어주자
//
//===============================================================================================