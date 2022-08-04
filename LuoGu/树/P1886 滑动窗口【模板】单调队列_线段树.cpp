#include <iostream>
#include <vector>
using namespace std;

// �߶������嵯.. 
// ����˯����ʱ��ͻȻ�뵽�������Ҳ����������ֵ�����Ծ�����һ�£������������ֻ��һ����ֵ�����������Ҫ�����ֵ
// ����Сֵ�����������д������ѯ���������߶�������logn^2�ˣ��ٿ����ݷ�Χ��ʱ���ɱ�w����������������ôһ�η���
// ����ֵ����Ȼ�뵽python��Ԫ����ȥ��...Ȼ��������֪�����Է��ؽ����... 

// O2�����ɹ�...�߶������������ڹ�Ȼ����̫����... 

typedef pair<int, int > PII;
// ��������ṹ����д�˸�val����������¼Ҷ�ӽڵ��ֵ�����������������ˣ���Ϊ����Ҫ�Աȵ�����ֵ
// ����ֵʱֻ��Ҷ�ӽڵ�ĸ��ڵ��¼������ֵ��������������val������ֻ�Ǹ�û�г�ʼ���Ŀձ�����
// �������Աȵľ���val... 
struct Node {
	int mx, mn;
	Node (int mx, int mn) : mx(mx), mn(mn) {};
	Node () {};
};
const int N = 1e6 + 10, M = N * 4;
int arr[N];
Node root[M];
void build(int now ,int left, int right) {
	if (left == right) {
		root[now].mx = root[now].mn = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	// ��ǰ�ڵ�����ֵ�����������������ֵ��ע������root��ʵ����������ֵ 
	// ֮ǰ�Աȵ�val�����������Ļ�ֻ��Ҷ�ӽڵ�ĸ��׶Աȵ�����ֵ���������������val��ʲô��valֻ��Ҷ�ӽڵ��ʱ�����
	// �˸�ֵ������������ĶԱȶ���δ�����...��������ɴ಻��val��ֱ�Ӱ���ֵ�����Ա�... 
	root[now].mx = max(root[l_node].mx, root[r_node].mx);
	root[now].mn = min(root[l_node].mn, root[r_node].mn);
}
Node query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return Node(-1e9, 1e9);
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	Node lres = query(l_node, left, mid, L, R), rres = query(r_node, mid + 1, right, L, R);
	return Node(max(lres.mx, rres.mx), min(lres.mn, rres.mn));
}
vector<Node > vec;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n, m;
	cin >> n >> m;
	// ����ģ���ѯ������ֵ��ע������������Ǳ����� 
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(0, 0, n - 1);
	for (int i = 0; i < n - m + 1; i++) vec.push_back(query(0, 0, n - 1, i, i + m - 1));
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) cout << vec[i].mn << ' ';
	cout << endl;
	for (int i = 0; i < vLen; i++) cout << vec[i].mx << ' ';
	return 0;
}
