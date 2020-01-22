//===============================================================================================
//
// * public 지정자로 선언되지 않은 멤버에 대한 접근은 원칙적으로 차단
//	 => 클래스 내부에 friend 지정자를 사용하여 함수나 클래스를 친구로 선언한다면 상속관계가 없는 
//		친구 클래스나 친구 함수를 클래스 멤버인것처럼 클래스 내부 모든 멤버에 대한 접근을 허용함
// 
//
//===============================================================================================

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
//
//// 함수 friend 지정 
//
//class Ours;		// 전방 선언
//
//class Friends {
//private:
//	int Func2(Ours &b);
//
//public:
//	int Func1(Ours &b);
//};
//
//class Ours {
//private:
//	int _b;
//
//	friend int Friends::Func1(Ours &);	// Freinds::Func1 함수는 class Ours의 친구
//	// =>  Friends::Func1 함수는 프로그램을 구현할 때 class Ours의 모든 멤버 접근이 가능하다
//};
//
//int Friends::Func1(Ours &b) { return b._b; }		// class Ours의 private 멤버에 접근가능띠
//int Friends::Func2(Ours &b) { return b._b; }		// 친구가 아니기 때문에 접근 시 에러가 발생


// calss friend 지정

class OtherClass;

class MyClass {
private:
	int top;

public:
	friend class OtherClass;

};

class OtherClass {
private:
	int otherSecret;

public:
	void change(MyClass & yc, int x) {
		yc.top = x;
	}
};

// MyClass는 OtherClass를 친구라고 생각해서 MyClass의 private멤버에 접근권한을 줬지만
// OtherClass는 MyClass를 친구라고 생각안해서 OtherClass의 private or protected 멤버에 접근 못하게 한다