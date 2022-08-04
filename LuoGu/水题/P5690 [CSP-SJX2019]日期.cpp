#include <iostream>
using namespace std;
int main() {
    int n, m;
	char c;
    cin >> n >> c >> m;
    cout<<(n>12||n==0)+(m>31||m==0||n==2&&m>28);
    return 0;
}
