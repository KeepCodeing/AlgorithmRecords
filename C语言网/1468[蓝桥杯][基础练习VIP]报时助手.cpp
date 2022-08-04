#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ����ģ�⣬�ø�map��¼�¶�Ӧ��ϵ���� 
// �ƺ�Ҳ�������������������鷳�� 

map<int, string > mp;
// �ø�ʸ��������� 
vector<string > vec;
void initMap() {
	mp[0] = "zero", mp[1] = "one", mp[2] = "two", mp[3] = "three";
	mp[4] = "four", mp[5] = "five", mp[6] = "six", mp[7] = "seven";
	mp[8] = "eight", mp[9] = "nine", mp[10] = "ten", mp[11] = "eleven";
	mp[12] = "twelve", mp[13] = "thirteen", mp[14] = "fourteen", mp[15] = "fifteen";
	mp[16] = "sixteen", mp[17] = "seventeen", mp[18] = "eighteen", mp[19] = "nineteen";
	// ���̣�30~50���Ǻ�������������ŵģ���������20~50֮����x0�������������Щ������ӳ���ˣ�����
	// ���ĳ���x0 - 0����� 
	mp[20] = "twenty", mp[30] = "thirty", mp[40] = "forty", mp[50] = "fifty";
}
int main() {
	initMap();
	int h, m;
	cin >> h >> m;
	if (mp.count(h)) {
		vec.push_back(mp[h]);
	} else {
		// �ֽ���ַ�����ע������insert��pos�Ǹ������� 
		// �ڿ�ʼλ�ò��룬�Ȳ����λ��Ȼ���ȥ��λ������
		// ���ܱ�֤���˳��Ȼ������Ҳ�����㷴�����У�����push_back����
		// ��֪����ʱ����ô��ģ���֮��˳�������� 
		vec.push_back(mp[(h - h % 10)]);
		vec.push_back(mp[h % 10]);
		
//		vec.insert(vec.begin(), mp[h % 10]);
//		vec.insert(vec.begin(), mp[(h - h % 10)]);
	}
	if (mp.count(m)) {
		// �����Ϊ0�����
		if (m == 0) vec.push_back("o'clock");
		else vec.push_back(mp[m]);
	} else {
		vec.push_back(mp[(m - m % 10)]);
		vec.push_back(mp[m % 10]);
		
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen) cout << ' ';
	}
	return 0;
}
