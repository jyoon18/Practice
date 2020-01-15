#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//===============================================================================================
// 
// 1. Ŭ���� �� ����� ������� �ʰ� ���α׷��� �ϴ� ���
// 2. Ŭ���� �� ����� ����Ͽ� ���α׷��� �ϴ� ���
//	* Ŭ������ ����� Ŭ������ �ƴ� ����ü�� ����� ����
// 
//===============================================================================================

// 1 => ���� ��Ҹ� �̾Ƴ��� �ϴ� ���, �������迡�� ���� ����
//      ���⼭�� �л��� ������� �����Ǿ��ִ� ���� �л��� ����̴� �� ���� �ڿ������� ������ ��Ӱ��谡 �� �� ��︲
//
//class Person {
//private:
//	string name;
//
//public:
//	Person(string n) : name(n) {}
//	
//	string GetName() {		// name�� ��ȯ
//		return name;
//	}
//};
//
//class Student {
//private:
//	string id;
//
//public:
//	Person *person;
//
//	Student(string i, string n) : id(i) {
//		person = new Person(n);		// Person�� n ��ŭ ũ�⸦ �Ҵ�޴´� = string n��ŭ �Ҵ�,,
//	}
//
//	~Student() {
//		delete person;
//	}
//
//	string GetID() {
//		return id;
//	}
//};
//
//class Professor {
//private:
//	string id;
//
//public:
//	Person *person;
//
//	Professor(string i, string n) : id(i) {
//		person = new Person(n);
//	}
//
//	~Professor() {
//		delete person;
//	}
//
//	string GetId() {
//		return id;
//	}
//};
//
//int main() {
//	Student st("123456789", "jykim");				// student Ŭ�������� GetName()�Լ��� �������� ������ personŬ���� �� GetName()�Լ��� �ڱ� �Լ�ó�� ȣ�Ⱑ��
//	Professor pr("123456789", "ddddd");
//
//	cout << "student ID; " << st.GetID() << "student Name; " << st.person->GetName() << endl
//		<< "professor ID; " << pr.GetId() << "professor Name; " << pr.person->GetName() << endl;
//
//}

// 2 => ��Ӱ���
//
class Person {
private:
	string name;

public:
	Person(string n) : name(n) {}

	string GetName() {
		return name;
	}
};

class Student : public Person {
private:
	string id;

public:
	Student(string i, string n) : Person(n), id(i) {}

	string GetID() {
		return id;
	}
};

class Professor : public Person {
private:
	string id;

public:
	Professor(string i, string n) : Person(n), id(i) {}

	string GetId() {
		return id;
	}
};

int main() {
	Student st("123456789", "jykim");
	Professor pf("123456789", "dddd");

	cout << "student ID; " << st.GetID() << "student Name; " << st.GetName() << endl
		<< "professor ID; " << pf.GetId() << "professor Name; " << pf.GetName() << endl;
}


//===============================================================================================
// 
// 1. c++ ���� �������̽���� �ϴ� Ÿ���� �������� �ʴ´�
// 2. c++ ���� ����ü�� Ŭ������ ���о��� ����� �����ϴ�
// 3. c++ ���� �ٸ� ��ü ���� ���� �޸� ���߻���� ������
// 4. c++ ���� �ֻ��� Ŭ������ ����x -> Ŭ������ Ư�� ������ ���� �Ϻ� Ŭ������ ���� ������
// 5. c++ ���� Ŭ������ ��� ����� ����Ǿ� �ִ��� ��ӵ��� �ʴ� ����� ����
//		* 1. ������ => �����ڴ� ����Ʈ�� ���x
//		* 2. �Ҹ���
//		* 3.  ���Կ�����
// 
// * ������ �̸��� ������ �Լ�
//   ��� ���Կ� �ִ� Ŭ���� ���� ������ �̸��� ������ �Լ��� �����Ѵٸ� ������ ���� ����ȭ ��
//   �̸��� ����Ͽ� ���� Ŭ���� ������ �Լ��� �ĺ�����
// ex) class Person�� getName()�Լ��� class Student : class Person�� getName()�Լ��� 
//		* Student st �� ��, class Person�� getName()�Լ��� st.Person::getName()
//		  class Student : class Person�� getName()�Լ��� st.getName()���� ȣ��
// 
//===============================================================================================

