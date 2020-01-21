//===============================================================================================
//
// * ������ ���ǻ���
//   1. ������ ���ο��� Ŭ������ �����Լ��� ȣ������ ���ƾ��Ѵ�
//      �����Լ��� ��Ӱ� ���õ� �Լ��̱� ������ ���� Ŭ������ ���� �Լ��� �����Ѵٸ� �����߻�����
//   2. ������ ���ο����� ������ ���ܸ� �߻���Ű�� �ʵ��� �Ѵ�.
//   3. �μ��� �����ϱ� ���� ��� �۾��̳� '������ �����͸� ����'�ϱ� ���� ������ �����ϴ� ���۾���
//		��ü�� �����ϱ� ������ �����ϰų� �������� �μ� ����Ʈ���� �����ؾ��Ѵ�
//		=> ���� �۾� ���߿� ������ ���ܰ� �߻����� �ʵ��� �Ѵ�
//   4. �����ڴ� �Ϲ� �Լ��� �޸� �ּҸ� �� �� ����.
//		=> ���� �Լ� �����Ϳ� �����ڸ� �Ҵ��ϰų� ȣ���� �� ����.
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
//		printf("Complex(double %.2f) ȣ���\n", x);
//	}
//
//	Complex(double x, double y) : silsoo(x), heosoo(y) {
//		printf("Complex(double %.2f, double %.2f) ȣ���\n", x, y);
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
// * �����Ϸ��� ���� ���� �پ��� ������ ������Ű�鼭 ��ü�� ������ �� �ִ� �Ͻ��� ��ȯ�� ���
//	 => �Ͻ��� ��ȯ�� ��� & �̷��� ����� �����ϴ� �����ڸ� �Ͻ��� ��ȯ �����ڶ�� ��
// ** ����� ���� �����ڰ� �Ͻ��� ��ȯ �������� ������ ����
// �Ͻ��� ��ȯ �����ڴ� ��ĩ�ϸ� ������ �߻���ų ���� �ֱ� ������ ����� �����ڸ� �Ἥ
// ��Ȯ�ϰ� ���� ���� ����
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
//		printf("Complex(double %.2f) ȣ��\n", x);
//	}
//
//	explicit Complex(double x, double y) : real(x), imaginary(y) {
//		printf("Complex(double %.2f, double %.2f) ȣ��\n", x, y);
//	}
//};
//
//int main()
//{
//	// Complex b1= 1; => �ؼ��� �����Ǽ� ���ؼ���! ����
//	Complex b2(2);
//	Complex b3{ 4,5 };
//	// Complex b4 = { 4,5 }; => ������
//	Complex b5 = (Complex)1;		// �̰� �������� ȣ���� �ƴ� ������ Ÿ�� ��ȯ�̱� ������ ������ �ȳ�
//	Complex *b6 = new Complex(4, 5);
//
//	delete b6;
//
//	// ��κ� ���� �����ڸ� ����Ͽ� ��ü�� �����ϸ� ������ ��
//}

//===============================================================================================
//
// * ������ ���
//   Ŭ������ ��ӿ� �־ �⺻ Ŭ������ ����� ��Ģ������ ���� Ŭ������ �״�� ������
//	 ** �׷��� ��� ��� ������, �Ҹ���, ���� �����ڴ� �� ������
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
	// ������ ���� ���� Ŭ�������� �����ϴ� �����ڸ� ������ ����� �־���Ѵ�.
	WoodBox(int w, int h, int l) : Box(w,h,l) {}
};

int main()
{
	WoodBox *b = new WoodBox(5, 10, 3);
	cout << "���� ������ ũ��: " << b->Volume() << endl;
	delete b;
}

// ���� ���� Ŭ���� �� �����ڿ� ����� Ŭ������ �����ڰ� �� ���̰� ���ٸ� 
// using Box::Box�� ��ü�� �� �ִ�