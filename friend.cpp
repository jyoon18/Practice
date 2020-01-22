//===============================================================================================
//
// * public �����ڷ� ������� ���� ����� ���� ������ ��Ģ������ ����
//	 => Ŭ���� ���ο� friend �����ڸ� ����Ͽ� �Լ��� Ŭ������ ģ���� �����Ѵٸ� ��Ӱ��谡 ���� 
//		ģ�� Ŭ������ ģ�� �Լ��� Ŭ���� ����ΰ�ó�� Ŭ���� ���� ��� ����� ���� ������ �����
// 
//
//===============================================================================================

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
//
//// �Լ� friend ���� 
//
//class Ours;		// ���� ����
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
//	friend int Friends::Func1(Ours &);	// Freinds::Func1 �Լ��� class Ours�� ģ��
//	// =>  Friends::Func1 �Լ��� ���α׷��� ������ �� class Ours�� ��� ��� ������ �����ϴ�
//};
//
//int Friends::Func1(Ours &b) { return b._b; }		// class Ours�� private ����� ���ٰ��ɶ�
//int Friends::Func2(Ours &b) { return b._b; }		// ģ���� �ƴϱ� ������ ���� �� ������ �߻�


// calss friend ����

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

// MyClass�� OtherClass�� ģ����� �����ؼ� MyClass�� private����� ���ٱ����� ������
// OtherClass�� MyClass�� ģ����� �������ؼ� OtherClass�� private or protected ����� ���� ���ϰ� �Ѵ�