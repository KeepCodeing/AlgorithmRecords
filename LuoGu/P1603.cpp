#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<string, int > m_data;
vector<int > v;
// ������⺯�����û�з���ֵ�������;�ֻ��д�� 
void creatVector(int num) {
	num = (num * num) % 100;
	// ȥ��Ԫ�ص���0�����������Ϊ�˲���0��Ҫ�ж�Ԫ���Ƿ�С��10 
	if (num == 0) return;
	v.push_back(num);
}
void initMap() {
	string temp[] = {"zero", "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
	"fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	// ��ʼ��map 
	for (int i = 0; i <= 20; i++) m_data[temp[i]] = i;
	// 1,4,1,1,4,9
	m_data["a"] = 1;
	m_data["both"] = 4;
	m_data["another"] = 1;
	m_data["first"] = 1;
	m_data["second"] = 4;
	m_data["third"] = 9;
}
void soultion() {
	initMap();
	string str;
	cin >> str;
	while (str != ".") {
		if (m_data.count(str)) {
			creatVector(m_data[str]);
		}
		cin >> str;
	}
}

int main() {
	// Black Obama is two five zero one .
	soultion();
	if (v.size() == 0) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	bool flag = true;
	cout << v[0];
	for (int i = 1; i < v.size(); i++) {
		if (flag && v[i] == 0) {
			continue;
		} else {
			flag = false;
		}
		if (v[i] < 10) cout << 0;
		cout << v[i];
	}
	return 0;
}
