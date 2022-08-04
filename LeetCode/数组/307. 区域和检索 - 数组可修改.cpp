typedef long long LL;
const int N = 1e6 + 10, M = 4 * N;
struct Node {
    int l, r;
    LL sum;
} root[M];
class NumArray {
public:
    vector<int > vec;
    NumArray(vector<int>& nums) {
        vec = nums;
        // ����ܿӣ����п����飬Ȼ��ͻ�׹��...��ָ������磩.. 
        if (!vec.empty()) build(1, 1, nums.size());
    }
    void pushup(int now) {
        root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
    }
    void build(int now, int left, int right) {
        root[now].l = left, root[now].r = right;
        if (left == right) {
            root[now].sum = vec[left - 1];
            return;
        }
        int mid = (left + right) >> 1;
        int ln = now << 1, rn = now << 1 | 1;
        build(ln, left, mid);
        build(rn, mid + 1, right);
        pushup(now);
    }
    void my_update(int now, int L, int R, int val) {
    	// ��ʵ�Լ�д��ʱ�������ط����󲻶��������������ȫ���Ը��ǵ����Ĺ��ܣ�
		// ֻ����˵�޸ĵ���Ҷ�ӽڵ�ĺͣ������������֮��Ķ���... 
        if (L <= root[now].l && root[now].r <= R) {
            root[now].sum = val;
            return;
        }
        int mid = (root[now].l + root[now].r) >> 1;
        int ln = now << 1, rn = now << 1 | 1;
        if (L <= mid) my_update(ln, L, R, val);
        if (R > mid) my_update(rn, L, R, val);
        pushup(now);
    }
    LL query(int now, int L, int R) {
        if (L <= root[now].l && root[now].r <= R) return root[now].sum;
        if (L > root[now].r || R < root[now].l) return 0;
        return query(now << 1, L, R) + query(now << 1 | 1, L, R);
    }
    void update(int i, int val) {
        my_update(1, i + 1 , i + 1, val);
    }
    int sumRange(int i, int j) {
        return query(1, i + 1, j + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
