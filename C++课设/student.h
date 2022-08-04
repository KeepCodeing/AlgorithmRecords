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
		
		// ���ǵ��������������ֻ�ܶ��ֽܷ����жϣ����Ը����Զ���������� 
//		bool operator<(Student<T> &s) const {
//			return s.totalScore < totalScore;
//		}
};

template<typename T> Student<T>::Student(string sname, string sid, T m, T c, T e):
	name(sname), id(sid) {
	this->totalScore = m + c + e;
	this->score["����"] = c;
	this->score["��ѧ"] = m;
	this->score["Ӣ��"] = e;
};

template<typename T> Student<T>::Student() {};

template<typename T> T Student<T>::ScoreSum() {
	return totalScore = score["��ѧ"] + score["����"] + score["Ӣ��"];
}
