#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int > PII;
vector<PII > vec;

// �о�����Ĵ�����ںܴ��ȱ�ݣ��������޷������ַ���ĩβ�������ַ���˼�����·��ֿ��Լ�¼WUB������
// ��Ȼ��������ַ����ַ���������WUB��β��ʱ��ᱻ��������ô��˵���������û�����ǣ�������Ǳ�������.. 
  
int main() {
	string str, temp;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen - 2; i++) {
		if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') vec.push_back(PII(i, i + 2)), i += 2;  
	}
	for (int i = 0; i < vec.size(); i++) {
		int l = vec[i].first, m = vec[i].first + 1, r = vec[i].second;
		str[l] = str[m] = str[r] = ' ';
	}
	string res;
	bool flag = false;
	for (int i = 0; i < sLen; i++) {
		if (str[i] == ' ') {
			if (flag) {
				res += ' ';
				flag = !flag;
			}
		} else {
			res += str[i];
			flag = true;
		}
	}
	int rLen = res.size();
	if (res[rLen - 1] == ' ') res = res.substr(0, rLen - 1); 
	cout << res << endl;
	return 0;
}
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<string > vec;
//int main() {
//	string str, temp;
//	cin >> str;
//	str += '*';
//	int sLen = str.size();
//	for (int i = 0; i < sLen - 2; i++) {
//		// �����ǰ�ַ���Ϊ��׼���Ϻ�����ַ�ΪWUB���������������´εĻ�׼�ַ�һ����WUB���߲���WUB
//		// �������WUB�������뵽����ķ�֧����������� 
//		if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') {
//			i += 2;
//			if (temp.size()) {
//				vec.push_back(temp); 
//				temp = "";
//			}
//			continue;
//		} else {
//			// ������ǣ��ͽ��������... 
//			temp += str[i];
//		}
//	}
//	for (int i = 0; i < vec.size(); i++) {
//		if (i != 0) cout << ' ';
//		cout << vec[i];
//	} 
//	return 0;
//}
