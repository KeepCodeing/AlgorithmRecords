#include <iostream>
using namespace std;
class Solution {
	public:
		string rotateString(string A, int offset) {
			if (A.empty() || A.size() == 0) return A;
			int len = A.size();
			offset %= len;
			reverse(A, 0, len - offset - 1);
			reverse(A, len - offset, len - 1);
			reverse(A, 0, len - 1);
			return A;
		}
		private:
			void reverse(string &str, int start, int end) {
				while (start < end) {
					char temp = str[start];
					str[start] = str[end];
					str[end] = temp;
					start++;
					end--;
				}
			}
};
int main() {
	Solution s = Solution();
	cout << s.rotateString("Hello", 6); 
	return 0;
}
