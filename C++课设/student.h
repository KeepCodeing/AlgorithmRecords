#include <iostream>
#include <map>
using namespace std;

template<typename T> class Student {
	public:
		string name, id;
		map<string, T> score;
		T totalScore;
		Student(string sname, string sid, T m, T c, T e);
		Student();

		T ScoreSum();
		
		// 考虑到这里运算符重载只能对总分进行判断，所以改用自定义排序规则 
//		bool operator<(Student<T> &s) const {
//			return s.totalScore < totalScore;
//		}
};

template<typename T> Student<T>::Student(string sname, string sid, T m, T c, T e):
	name(sname), id(sid) {
	this->totalScore = m + c + e;
	this->score["语文"] = c;
	this->score["数学"] = m;
	this->score["英语"] = e;
};

template<typename T> Student<T>::Student() {};

template<typename T> T Student<T>::ScoreSum() {
	return totalScore = score["数学"] + score["语文"] + score["英语"];
}
