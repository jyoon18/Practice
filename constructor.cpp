//===============================================================================================
//
// * 생성자 주의사항
//   1. 생성자 내부에서 클래스의 가상함수를 호출하지 말아야한다
//      가상함수는 상속과 관련된 함수이기 때문에 하위 클래스가 가상 함수를 수정한다면 에러발생가능
//   2. 생성자 내부에서는 가급적 예외를 발생시키지 않도록 한다.
//   3. 인수를 생성하기 위한 계산 작업이나 '값으로 데이터를 전달'하기 위해 변수를 복사하는 ㄴ작업은
//		객체를 생성하기 이전에 수행하거나 생성자의 인수 리스트에서 수행해야한다
//		=> 따라서 작업 도중에 에러나 예외가 발생하지 않도록 한다
//   4. 생성자는 일반 함수와 달리 주소를 알 수 없다.
//		=> 따라서 함수 포인터에 생성자를 할당하거나 호출할 수 없다.
//
//===============================================================================================


//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <cstdio>
//
//using namespace std;
//
//class Complex {
//private:
//	double silsoo;
//	double heosoo;
//
//public:
//	Complex(double x) : silsoo(x), heosoo(0.0) {
//		printf("Complex(double %.2f) 호출띠\n", x);
//	}
//
//	Complex(double x, double y) : silsoo(x), heosoo(y) {
//		printf("Complex(double %.2f, double %.2f) 호출띠\n", x, y);
//	}
//};
//
//int main()
//{
//	Complex a1 = 1;
//	Complex a2(2);
//	Complex a3{ 4,5 };
//	Complex a4 = { 4,5 };
//	Complex a5 = (Complex)1;			
//	Complex *a6 = new Complex(4, 5);
//
//	delete a6;
//}

//===============================================================================================
//
// * 컴파일러는 위와 같이 다양한 조건을 만족시키면서 객체를 생성할 수 있는 암시적 변환을 사용
//	 => 암시적 변환을 사용 & 이러한 기능을 수행하는 생성자를 암시적 변환 생성자라고 함
// ** 사용자 정의 생성자가 암시적 변환 생성자의 역할을 수행
// 암시적 변환 생성자는 자칫하면 에러를 발생시킬 수도 있기 때문에 명시적 생성자를 써서
// 명확하게 해줄 수도 있음
//
//===============================================================================================

//#include <iostream>
//#include <string>
//#include <cstdio>
//
//using namespace std;
//
//class Complex {
//private:
//	double real;
//	double imaginary;
//
//public:
//	explicit Complex(double x) : real(x), imaginary(0) {
//		printf("Complex(double %.2f) 호출\n", x);
//	}
//
//	explicit Complex(double x, double y) : real(x), imaginary(y) {
//		printf("Complex(double %.2f, double %.2f) 호출\n", x, y);
//	}
//};
//
//int main()
//{
//	// Complex b1= 1; => 해석이 금지되서 못해석함! 에러
//	Complex b2(2);
//	Complex b3{ 4,5 };
//	// Complex b4 = { 4,5 }; => 에러남
//	Complex b5 = (Complex)1;		// 이건 생성자의 호출이 아닌 데이터 타입 변환이기 때문에 에러가 안남
//	Complex *b6 = new Complex(4, 5);
//
//	delete b6;
//
//	// 대부분 대입 연산자를 사용하여 객체를 생성하면 에러가 남
//}

//===============================================================================================
//
// * 생성자 상속
//   클래스의 상속에 있어서 기본 클래스의 멤버는 원칙적으로 하위 클래스에 그대로 물려줌
//	 ** 그러나 멤버 가운데 생성자, 소멸자, 대입 연산자는 안 물려줌
//
//===============================================================================================

#include <iostream>
#include <string>

using namespace std;

class Box {
private:
	int width;
	int height;
	int length;

public:
	Box(int width = 0, int height = 0, int length = 0) : width(width), height(height), length(length) {};
	inline int Volume() { return width * length*height; }
};

class WoodBox : public Box {
public:
	// 생성자 역시 상위 클래스에서 제공하는 생성자를 일일이 명시해 주어야한다.
	WoodBox(int w, int h, int l) : Box(w,h,l) {}
};

int main()
{
	WoodBox *b = new WoodBox(5, 10, 3);
	cout << "나무 상자의 크기: " << b->Volume() << endl;
	delete b;
}

// 만약 하위 클래스 내 생성자와 사우이 클래스의 생성자가 별 차이가 없다면 
// using Box::Box로 대체할 수 있다