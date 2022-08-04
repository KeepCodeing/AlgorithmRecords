#include <iostream>
#include <map>
using namespace std;

// 不知道为什么又想用离散化做，其映射下标的思想太触了，似乎不行，
// 因为询问不止有下标，还有字符串（名字），那干脆用一个map，用
// 名字映射，一个vector存名字，这样就可以应对字符串和下标两种询问了 

// 草，觉得上面的方法有点麻烦，想到了用并查集搞，男生统一祖先为第一个
// 男生，女生统一祖先为第一个女生，然后把名字和id映射下，如果输入的名字
// 去map里找id，再用这个id去找它的祖先，如果一次询问祖先相同，说明
// 不可行，否则可行，学号如果用字符串的话可能有10位数字之多，所以得
// 用输入顺序映射，映射关系式姓名->顺序下标以及学号->顺序下标，这样
// 就能在两种不同的询问情况下去查找了 

// 并查集模板 
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
	// fM记录第一个男生的下标， fW记录第一个女生的 
	int fM, fW;
	for (int i = 1; i <= n; i++) {
		string name, id, gender;
		cin >> name >> id >> gender;
		// 名字和下标的映射 
		m[name] = i;
		// id和下标的映射
		im[id] = i; 
		// 一下四行为记录第一个男生/女生的下标，以及将之后的学生的祖宗映射到他们上 
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
		// 获取对应关系 
		if (m.count(a)) fId = m[a];
		else fId = im[a];
		if (m.count(b)) sId = m[b];
		else sId = im[b];
		// 查询是否为同一性别 
		if (u.ask(fId, sId)) cout << "N";
		else cout << "Y";
		cout << endl;
	}
	return 0;
}
