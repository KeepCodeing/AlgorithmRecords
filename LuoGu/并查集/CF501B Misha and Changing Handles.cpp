#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ����⿴�������񲢲鼯����Ϊ����һ�������ڵĹ��̣���֪���ǲ��ǶԵ� 
// ������ͼȷʵ�Ǹ����鼯������Ҫע������ô�ж�һ���ж��ٸ�Ա����ͼ��
// ���Ļ�ͼ��Ͳ�����һ�������ڵ㣬Ҳ����˵���ĳ����Ա�ĳ�ʼ����ֻ���ֹ�
// һ�Σ���������־��Ǹ�Ա�ĳ�ʼ���� 

// ���￼����һ��mapӳ���Ա����id

// ͻȻ���ÿ�����map����ӳ��... 

// ���Ե�����������֪���ɲ����У�����д����Ӧ����û����ģ����ģ� 
// ׹�٣�ͼ�۷���Ҳ���ò���ˣ���������д����д�����Ƚ��鷳Ҳû�취�����ܣ� 
const int M = 1000;
struct Node {
	string str;
	int id;
	Node(string str, int id) : str(str), id(id) {};
	//Node () {};
	Node (int i = -1) {
		id = i;
	}
};
Node head[M], e[M], ex[M];
int idx = 0;
void head_add(int id, string str) {
	e[idx] = Node(str, id), ex[idx] = head[id], head[id] = Node("114514", idx), idx++;
}
vector<string > vec;
map<string, string > mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int n;
	string a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;	
		// �������ַ�����û���ӽڵ㣬��ô����ַ����Ϳ϶���ͷ��㣬���䱣������������� 
		// map���ƣ�key->val������������һֱѭ����ȥ��ֻҪ�����ֻ�֮��Ķ���������ֻ�ô�ͷ��㣬��key��val
		// ӳ���¾��ܸ㵽���ɸ�������֪������Ч����Σ�Ӧ���Ƿǳ��͵� 
		if (mp[a] == "") vec.push_back(a); 
		// ��b��ӵ��ڵ�β�� 
		mp[a] = b;
		// ��Ϊ���ǵ�map���ַ������ַ�����ӳ�䣬��������������βҲ�õ��ַ��� 
		mp[b] = "114514";
	}
	string res;
	int vLen = vec.size();
	cout << vLen << endl;
	for (int i = 0; i < vLen; i++) {
		cout << vec[i] << ' ';
		// ������ǰ�������β�����ַ������Ǹ�Ա���ڵ����� 
		while (mp[vec[i]] != "114514") res = mp[vec[i]], vec[i] = mp[vec[i]];
		cout << res << endl;
	}
	// ����֮ǰд��һ��ѭ����������key�������˲���β�ڵ�Ĳ�������ʱ��û���뵽����
	// ��˼·���ڷ��ֶ�ÿ���ڵ㶼���б�������֮���ֻ�����ͼ������Ƿ���ֻ�ܶ�ͷ������
	// �������Բ���������Ĵ��룬��ʵҲ�е��������ĸо�����Ϊ��д����ʱ����������˼· 
	return 0;
}
