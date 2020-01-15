#include <iostream>
#include <Windows.h>
#include <string>

#define PI 3.141592

using namespace std;
//=====================================================================================================================================
//
// 객체 지향 언어의 가장 큰 특성 중 하나는 다형성 (polymorphism)
// 상속 관계에 있는 클래스라 하더라도 서로 각기 동일한 이름의 1.변수 & 2.함수가 존재한다면
// 클래스 내 함수를 호출할 때 원칙적으로 해당 클래스에서 정의한 함수가 호출
// 
// * 객체 지향 프로그래밍의 다형성의 원칙에 입각하여 상위 Shape 클래스 타입의 포인터에 하위 Rec 클래스의 인스턴스를 할당하더라도
//   하위 클래스에서 정의된 멤버 함수가 호출되기를 바란다면 상위 클래스 내 함수 앞에 virtual 지정자를 선언해주면 됨!!
// 
// * virtual 지정자로 선언된 함수를 가상함수라 하는데,
// **** 가상함수는 객체 지향 언어에서 제공하는 다형성의 원칙을 충족하기 위해 만들어진 함수이다. ****
// 
// * 가상 함수는 다형성의 원칙에 따라 자신의 함수를 호출xxx, 자신의 클래스를 상속받아 가상 함수를 구현한 하위 클래스의
//   함수로 대체되어 호출됨
// * 가상 함수는 객체마다 별도의 가상 테이블을 갖고 있어서
// **** 자체 함수가 아닌 자신을 상속하고 구현한 하위 클래스의 함수를 호출하는 기능을 제공한다 ****
// * c++ 언어에서 사용하는 포인터는 가상함수를 호출하는 데 있어 C언어에서 제공하는 포인터와 기능상 차이가 있당
//
//=====================================================================================================================================


//class Shape	{			// 도형의 면적과 이름을 표현하기 위해 사용
//private:
//	string name;
//
//public:
//	Shape(string n) : name(n) {}
//
//	void GetArea() {
//		cout << "Figure Name; " << GetName() <<"\tfirgure Area: " << Area() << endl;
//	}
//	
//	string GetName() {
//		return name;
//	}
//
//	float Area() { return 0; }		//	도형마다 넓이가 다 다르니까 디폴트 값을 0으로 반환한다
//};
//
//// 직사각형은 class Shape를 기본 클래스로 하여 모든 멤버를 상속받는다
//
//class Rec : public Shape {
//protected:
//	float width;
//	float height;
//
//public:
//
//	Rec(std::string n, float w = 0, float h = 0) : Shape(n), width(w), height(h) {}
//
//	// shape에서 구한 면적은 맞지 않으므로 여기서 다시 면적을 구한다
//		double Area() const {
//		return (width * height);
//	}
//
//	void GetArea() {
//		cout << "Rectangle name: " << GetName() << " figure area: " << Area() << endl;
//	}
//};
//
//int main() {
//	
//	Shape *s = new Rec("직사각형", 10, 5);		// 하위 클래스의 인스턴스를 생성하여 상위 클래스 타입의 포인터에 할당하고 GetArea()함수를 호출한다면 
//												// Rec 클래스의 GetArea() 함수를 호출하는 것이 아니라 Shape 클래스 내의 GetArea()함수를 호출하게 된다
//	s->GetArea();
//
//	Rec *r = (Rec *)s;
//	r->GetArea();
//
//	delete s;
//}

class Shape {
private:
	string name;

public:
	Shape(string n) : name(n) {}

	void GetArea() {
		cout << "도형 이름: " << GetName() << "\t도형 크기: " << Area() << endl;
	}

	string GetName() {
		return name;
	}

	// 함수를 가상함수로 선언
	virtual double Area() { return 0; }

};

class Rec : public Shape {
protected:
	float width; 
	float height;

public:
	Rec(string n, float w = 0, float h = 0) : Shape(n), width(w), height(h) {}

	// 가상 함수는 하위 클래스가 제공하는 멤버를 사용하여 아래와 같이 구현한다
	double Area() {
		return (width*height);
	}
};

class Tri : public Rec {
public:
	Tri(float w = 0, float h = 0) : Rec("삼각형", w, h) {};

	// 더 이상 가상 함수로 상속되지 않도록 막을 때 ** final ** 이란 지정자를 사용함

	virtual double Area() final { return (Rec::Area() / 2); }
};

class Cir : public Shape {
protected:
	float radius;

public:
	Cir(double r = 0) : Shape("원"), radius(r) {}

	double Area() override { return (PI * (radius * radius)); }
};

int main()
{
	Shape *shape[] = {
		new Rec("직사각형", 10, 5),
		new Tri(10, 5),
		new Cir(10)
	};

	for (Shape *s : shape) {
		s->GetArea();
	}

	// * 포인터가 아닌 일반 변수를 사용한다면 전혀다른 결과를 얻게됨
	// * 일반 변수는 c언어로부터 물려받은 유산으로 객체 지향 개념을 지원x
	Rec r("직사각형 일반변수 이용한 것", 10, 15);
	Shape s = r;
	s.GetArea();
	for (Shape *s : shape) {
		delete s;
	}
}


//=====================================================================================================================================
//
// * 가상 함수는 포인트 변수 또는 참조를 사용해야 제대로된 다형성의 결과를 얻을 수 있다!
// * 가상 함수는 다형성의 원칙에 따라 최종적으로 적용된 하위 클래스의 함수가 호출되게 한다!
// 
// * 추상 클래스와 추상 함수 -> 가상 함수를 좀 더 발전시킨 함수가 추상 함수
//	 1. 추상 함수는 함수의 조건을 충족시키지 못하는 가상함수로 오로지 상속만을 목적으로 만들어진 함수
//	 2. 추상 함수는 아래와 같이 대입 연산자를 이용하여 0이란 정수를 할당하고 세미콜론(;)로 마무리하는 형태로 선언된 함수를 말한다
//	    ex) virtual double Area() = 0;
//	 3. 추상 함수는 본문을 뜻하는 시작 중괄호와 끝 중괄호가 들어갈 수 읎다
//	 
//	 **** 만약 추상 함수가 하나라도 존재한다면 해당 클래스는 추상 클래스가 된다	
//
// * 추상 클래스와 추상 함수의 특징
//	 1. 추상 클래스는 상속 목적으로 사용하는 클래스이기 때문에 new연산자를 사용하거나 변수 선언만으로 객체가 될 수 없다
//	 2. 추상 클래스를 상속받은 클래스가 인스턴스화 되기 위해서는 반드시 추상 함수를 구현해야한다.
//	 3. 추상 함수는 상속과 관련된 함수로 static지정자를 사용하여 정적으로 만들거나 사용할 수 없다.
//
// ** 추상 함수는 하위 클래스가 반드시 구현해야 사용할 수 있는 함수이다
// **** 반면 정적 함수는 객체가 아닌 클래스와 관련된 함수(클래스 함수)이므로 원칙적으로 상속되는 함수가 아니다.
//
//=====================================================================================================================================