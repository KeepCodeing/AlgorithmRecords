#include <iostream>
#include <thread>
using namespace std;

void callback(int &started, const int& b) {
	cout << "hello world" << endl;
	started = true;
}

int main() {
//	int started = false;
//	thread cl(callback, ref(started), 1);
//	cl.detach();
//	for (int i = 0; i < 1e7; i++);
//	cout << started << endl;
	int x=3,y=2;double a=2.5,b=3.5;
	cout << ((x+y)%2+a/b) << endl;
	return 0;
}
