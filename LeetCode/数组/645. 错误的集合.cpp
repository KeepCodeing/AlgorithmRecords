// Ϊ�˽����ˢ������֣�ˮ��һ��ԭ�⣬���������... 
// [1,2,3,4, 4, 4, 5]�Լ��Ĳ�������... 
class Solution {
public:
    vector<int > vec;
    set<int > st;
    vector<int> findErrorNums(vector<int>& nums) {
        bool flag = true;
        // ֱ�ӿ���set�����������ַŽ�ȥ��Ȼ���ж����Ƿ��ظ����֣�����ǵ�һ���ظ����֣���Ϊ��.. 
        for (auto& i : nums) {
            if (st.count(i) && flag) vec.push_back(i), flag = !flag;
            st.insert(i);
        }
        // ����ط�����ʡȥ������Ϊ�������Ǹ����ֲ��ڼ�������ǰ��ռ��ϵ������������������Ժ����Եķ���
		// �������i - 1���ڼ������ôi - 1����ȱʧ������....�������ƺ�������w... 
        for (int i = 1; i <= nums.size(); i++) {
            if (!st.count(i)) {
                vec.push_back(i);
                break;
            }
        }
        return vec;
    }
};
