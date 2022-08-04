#include <iostream>
#include <map>
using namespace std;

// ��֪��Ϊʲô��������ɢ��������ӳ���±��˼��̫���ˣ��ƺ����У�
// ��Ϊѯ�ʲ�ֹ���±꣬�����ַ��������֣����Ǹɴ���һ��map����
// ����ӳ�䣬һ��vector�����֣������Ϳ���Ӧ���ַ������±�����ѯ���� 

// �ݣ���������ķ����е��鷳���뵽���ò��鼯�㣬����ͳһ����Ϊ��һ��
// ������Ů��ͳһ����Ϊ��һ��Ů����Ȼ������ֺ�idӳ���£�������������
// ȥmap����id���������idȥ���������ȣ����һ��ѯ��������ͬ��˵��
// �����У�������У�ѧ��������ַ����Ļ�������10λ����֮�࣬���Ե�
// ������˳��ӳ�䣬ӳ���ϵʽ����->˳���±��Լ�ѧ��->˳���±꣬����
// ���������ֲ�ͬ��ѯ�������ȥ������ 

// ���鼯ģ�� 
struct unionFind {
	int bin[1010];
	unionFind () {
		for (int i = 1; i <= 1010; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
map<string, int > m, im;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n;
	cin >> n;
	bool mFlag = false, wFlag = false;
	// fM��¼��һ���������±꣬ fW��¼��һ��Ů���� 
	int fM, fW;
	for (int i = 1; i <= n; i++) {
		string name, id, gender;
		cin >> name >> id >> gender;
		// ���ֺ��±��ӳ�� 
		m[name] = i;
		// id���±��ӳ��
		im[id] = i; 
		// һ������Ϊ��¼��һ������/Ů�����±꣬�Լ���֮���ѧ��������ӳ�䵽������ 
		if (!mFlag && gender == "M") fM = i, mFlag = !mFlag;
		else if (gender == "M") u.uni(fM, i);
		if (!wFlag && gender == "F") fW = i, wFlag = !wFlag;
		else if (gender == "F") u.uni(fW, i);
	}
	int k;
	cin >> k;
	while (k--) {
		string a, b;
		cin >> a >> b;
		int fId, sId;
		// ��ȡ��Ӧ��ϵ 
		if (m.count(a)) fId = m[a];
		else fId = im[a];
		if (m.count(b)) sId = m[b];
		else sId = im[b];
		// ��ѯ�Ƿ�Ϊͬһ�Ա� 
		if (u.ask(fId, sId)) cout << "N";
		else cout << "Y";
		cout << endl;
	}
	return 0;
}
