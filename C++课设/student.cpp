#include "student.h"

template<typename T> Student<T>::Student(string sname, string sid, T m, T c, T e):
	name(sname), id(sid) {
		this->totalScore = m + c + e;
		this->score["语文"] = c;
		this->score["数学"] = m;
		this->score["英语"] = e;
	};
	
template<typename T> T Student<T>::ScoreSum() {
	return totalScore = score["数学"] + score["语文"] + score["英语"];
}
