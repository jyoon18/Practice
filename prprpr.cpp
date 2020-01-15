#include <iostream>
#include <Windows.h>

using namespace std;

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

int main() 
{

}
