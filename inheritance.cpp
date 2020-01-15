#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//===============================================================================================
// 
// 1. 클래스 간 상속을 사용하지 않고 프로그래밍 하는 방법
// 2. 클래스 간 상속을 사용하여 프로그래밍 하는 방법
//	* 클래스의 상속은 클래스가 아닌 구조체라도 상속이 가능
// 
//===============================================================================================

// 1 => 공통 요소를 뽑아내서 하는 방법, 구성관계에서 많이 쓰임
//      여기서는 학생은 사람으로 구성되어있다 보다 학생은 사람이다 가 좀더 자연스럽기 때문에 상속관계가 좀 더 어울림
//
//class Person {
//private:
//	string name;
//
//public:
//	Person(string n) : name(n) {}
//	
//	string GetName() {		// name을 반환
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
//		person = new Person(n);		// Person의 n 만큼 크기를 할당받는다 = string n만큼 할당,,
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
//	Student st("123456789", "jykim");				// student 클래스에는 GetName()함수가 존재하지 않지만 person클래스 내 GetName()함수를 자기 함수처럼 호출가능
//	Professor pr("123456789", "ddddd");
//
//	cout << "student ID; " << st.GetID() << "student Name; " << st.person->GetName() << endl
//		<< "professor ID; " << pr.GetId() << "professor Name; " << pr.person->GetName() << endl;
//
//}

// 2 => 상속관계
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
// 1. c++ 언어는 인터페이스라고 하는 타입을 제공하지 않는다
// 2. c++ 언어는 구조체와 클래스의 구분없이 상속이 가능하다
// 3. c++ 언어는 다른 객체 지향 언어와 달리 다중상속을 제공함
// 4. c++ 언어는 최상위 클래스가 존재x -> 클래스는 특정 조건을 갖는 일부 클래스들 끼리 모여있음
// 5. c++ 언어에서 클래스간 상속 관계로 연결되어 있더라도 상속되지 않는 멤버가 존재
//		* 1. 생성자 => 생성자는 디폴트로 상속x
//		* 2. 소멸자
//		* 3.  대입연산자
// 
// * 동일한 이름의 변수와 함수
//   상속 관게에 있는 클래스 내에 동일한 이름의 변수와 함수가 존재한다면 다음과 같이 정규화 된
//   이름을 사용하여 각각 클래스 변수와 함수를 식별가능
// ex) class Person의 getName()함수와 class Student : class Person의 getName()함수는 
//		* Student st 일 때, class Person의 getName()함수는 st.Person::getName()
//		  class Student : class Person의 getName()함수는 st.getName()으로 호출
// 
//===============================================================================================

