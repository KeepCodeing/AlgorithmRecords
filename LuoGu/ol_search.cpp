#include <iostream>
using namespace std;
bool visited[100] = {false};
int primes[100], prime_count = 0;
void ol(int num) {
	for (int i = 2; i <= num; i++) {
		if (visited[i] == false) {
			primes[prime_count++] = i;
		}
		for (int j = 0; j < prime_count; j++) {
			if (i * primes[j] > num) break;
			visited[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
int main() {
	ol(21);
	for (int i = 0; i < prime_count; i++) {
		cout << primes[i] << ' ';
	}
	return 0;
}
