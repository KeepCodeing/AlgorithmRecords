#include "student.h"

template<typename T> Student<T>::Student(string sname, string sid, T m, T c, T e):
	name(sname), id(sid) {
		this->totalScore = m + c + e;
		this->score["����"] = c;
		this->score["��ѧ"] = m;
		this->score["Ӣ��"] = e;
	};
	
template<typename T> T Student<T>::ScoreSum() {
	return totalScore = score["��ѧ"] + score["����"] + score["Ӣ��"];
}
