#include <iostream>
#include <set>
#include <vector>
using namespace std;
// �����������о����п��ܣ�ͬʱ��һ��setȥ���ж�������ַ����Ĵ�С������¼һ�����ֵ 
// �����ı������ݳ�ʱ׹���ˣ������жϴ�Ҳд���������������ڹ��� 

// ��������ַ���ȥ����ֱ����set����Ч�ʼ��ͣ����������λѹ���㷨��ѧϰ�� 
class Solution {
public:
	int maxLen = 0;
	set<char > charSet;
	vector<string > temp;
	vector<string > strArr;
	// ����������λѹ���㷨�����ø��㷨ȥ������ʹ��set
	// ����㷨����Ҫ˼·�ǵ���Ҫȥ�ص��ַ����Ĳ�ͬ�ַ�������intλ32ʱ��ͨ��ĳ��
	// int������λ��¼�ַ��Ƿ���ֹ� 
	bool isUnique(string& s, int& t) {
		int sLen = s.size();
	    for (int i = 0; i < sLen; i++) {
	    	//��ȡ�ַ���Ӧλ
	        int n = s[i]-'a';	
	        //�жϸ�λ�Ƿ�Ϊ0
	        if (t & (1<<n)) {
	            return false;
	        }
	        t |= (1<<n);
	    }
    	return true;
	}

	bool isAnswer() {
		string tempStr;
		int tLen, sLen;
		set<char > tempSet;
		// �Ƚ���ǰ���ת��Ϊһ�������ַ��������ж������ַ��Ƿ��ظ� 
		tLen = temp.size();
		for (int i = 0; i < tLen; i++) {
			tempStr += temp[i];
		}
		sLen = tempStr.size();
		// cout << tempStr << endl;
		// �ж��ظ� 
		for (int i = 0; i < sLen; i++) {
			if (tempSet.count(tempStr[i])) return false;
			tempSet.insert(tempStr[i]); 
		}
		// �����ĸ��´𰸣��������ж��Ƿ��ظ��ͳ������ж��Ƿ��ظ����������ˣ����� 
		if (maxLen < tempSet.size()) maxLen = tempSet.size();
		return true;
	}
	void dfs(int level, int deepth) {
		// ����д�������⣬ò�ƴﵽ����������tempҲû�д�����п��ܽ⣬
		// �������ӡ�Ľ�Ҳ�͵ݹ�����һ����������Ѹ��½���ĺ����ĳ�
		// ��isAnswer����isAnswer�ڻ��ݹ����и��´𰸣��������ڹ��� 
		if (level == deepth) {
			// ��Ŀ�����Ŀ��н���ָû���ַ��ظ��Ĵ����ַ��������������ﻹҪ��֦
			// ȥ���Ƿ���
			//isAnswer();
			//if (!isAnswer()) return;
			// ��ֹ�������һ�ε��ַ����³��ȴ��� 
//			charSet.clear();
//			int tempLen = temp.size();
//			for (int i = 0; i < tempLen; i++) { 
//				cout << temp[i];
//			}
//			cout << endl;
			
			// �����еĿ��ܵ��ַ�����ϵ��ַ�ȥ�� 
//			for (int i = 0; i < tempLen; i++) {
//				int charLen = temp[i].size();
//				for (int j = 0; j < charLen; j++) {
//					charSet.insert(temp[i][j]); 
//				}
//			} 
//			// ������󳤶� 
//			int charSetLen = charSet.size();
//			if (charSetLen > maxLen) maxLen = charSetLen;
			return;
		}
		for (int i = level; i < deepth; i++) {
			temp.push_back(strArr[i]);
			// isAnswer();
			dfs(i + 1, deepth);
			// �ڻ��ݵĹ����и��´𰸣�����Ϊʲô����֪���������ڻ��ݵĹ�����
			// �𰸲�����ȫ�ģ������ǲ����ĵݹ�������ȫ�� 
			isAnswer();
			temp.pop_back();
		}
	}
    int maxLength(vector<string >& arr) {
        if (arr.size() <= 0) return 0;
        // ���ֻ��һ���ַ��������ز��ظ��ַ��ĸ������� 
        if (arr.size() == 1) {
        	int strLen = arr[0].size();
        	for (int i = 0; i < strLen; i++) {
        		charSet.insert(arr[0][i]); 
			}
			return charSet.size();
		}
        this->strArr = arr;
        dfs(0, arr.size());
        return maxLen;
    }
};
int main() {
	Solution s = Solution();
	vector<string > v;
//	v.push_back("un");
//	v.push_back("iq");
//	v.push_back("ue");
	v.push_back("jnfbyktlrqumowxd");
	v.push_back("mvhgcpxnjzrdei");
	cout << s.maxLength(v); 
	return 0;
}
