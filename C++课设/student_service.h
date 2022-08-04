#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include "student.h"
#define endl '\n'
using namespace std;

const string FILE_NAME = "./student.csv";
// const string OUT_PUT_FILE = "./student_output.csv";
const string OUT_PUT_FILE = "./student.csv";
const int MAX_LEN = 100;

template<typename T> class StudentService {
		typedef pair<T, T> boundary;
	private:
		// 读取文件以及转换学生信息为对象
		void readFile();
		void convertData(char *res[]);
		void quicksort(int left, int right, string course);
	public:
		StudentService();

		vector<Student<T> > stus;
		// map<string, vector<T > > info;

		// 学生信息的增，删，改
		bool addStudent(Student<T> stu);
		bool delStudent(string id);
		bool updStudent(Student<T> stu);

		// 按某一课程的成绩排序
		bool sortStudentQS(string course = "数学");
		// 按总分或课程排序，type为true按总分排序
		// rev:升序降序，默认降序；type:排序字段，默认总分；course: 课程，默认数学 
		bool sortStudent(bool rev = false, bool type = true, string course = "数学");

		// 文件保存学生信息
		bool reserveStudentList();

		// 学生信息的查
		Student<T> findStudentByName(string name);
		Student<T> findStudentById(string id);
		vector<Student<T> > filterStudentByScore(string course, boundary bd);

		// 获取全部学生信息
		vector<Student<T> >  getStudentList();
};

// 数据格式转换 
template<typename T> void StudentService<T>::convertData(char *res[]) {
	for (int i = 0; i <= 4; i++) {
		if (!res[i]) return;
	}
	T math, chinese, english;
	stringstream ss;
	ss << res[3];
	ss >> chinese;
	ss.clear();
	ss << res[2];
	ss >> math;
	ss.clear();
	ss << res[4];
	ss >> english;
	ss.clear();
	stus.push_back({ res[0], res[1], chinese, math, english });
}

// 读取数据，格式转换 
template<typename T> void StudentService<T>::readFile() {
	fstream fs = fstream(FILE_NAME, ios::in);
	if (!fs.is_open()) {
		ofstream fout(FILE_NAME);
		fout.close();
	}
	char temp[MAX_LEN], *res[MAX_LEN];
	int cnt = 0;
	bool isTitle = true;
	while (!fs.eof()) {

		cnt = 0;
		fs.getline(temp, MAX_LEN);
		if (isTitle) {
			isTitle = false;
			continue;
		}

		res[cnt] = strtok(temp, ",");
		while (res[cnt]) res[++cnt] = strtok(NULL, ",");

		// 输出文件会多一个空格，此时进行转换会出现空指针的问题
		if (res) convertData(res);

		cnt = 0;
	}
	fs.close();
}

template<typename T> StudentService<T>::StudentService() {
	readFile();
};

// 增加学生
template<typename T> bool StudentService<T>::addStudent(Student<T> stu) {
	stus.push_back(stu);
	return true;
}

// 删除学生（根据id）
template<typename T> bool StudentService<T>::delStudent(string id) {
	for (unsigned int i = 0; i < stus.size(); i++) {
		if (stus[i].id == id) {
			stus.erase(stus.begin() + i);
			return true;
		}
	}
	return false;
}

// 更新学生（根据id）
template<typename T> bool StudentService<T>::updStudent(Student<T> stu)  {
	for (unsigned int i = 0; i < stus.size(); i++) {
		if (stus[i].id == stu.id) {
			stus[i] = stu;
			return true;
		}
	}
	return false;
}

// 获取全部学生信息
template<typename T> vector<Student<T > > StudentService<T>::getStudentList() {
	return stus;
}

// 通过学生名查找学生
template<typename T> Student<T > StudentService<T>::findStudentByName(string name) {
	for (Student<T> s : stus) {
		if (s.name == name) return s;
	}
	return Student<T>();
}

// 通过ID查找学生
template<typename T> Student<T> StudentService<T>::findStudentById(string id) {
	for (Student<T> s : stus) {
		if (s.id == id) return s;
	}
	return Student<T>();
}

// 区间查询学生信息
template<typename T> vector<Student<T> > StudentService<T>::filterStudentByScore(string course, boundary bd) {
	vector<Student<T> > res;
	if (course != "数学" && course != "语文" && course != "英语") return res;
	if (bd.first > bd.second) swap<T>(bd.first, bd.second);
	for (Student<T> s : stus) {
		if (s.score[course] >= bd.first && s.score[course] <= bd.second) res.push_back(s);
	}
	return res;
}

// 文件保存学生信息
template<typename T> bool StudentService<T>::reserveStudentList() {
	ofstream fout(OUT_PUT_FILE);
	fout << "姓名,学号,语文,数学,英语" << endl;
	for (Student<T> s : stus) fout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;
	fout.close();
	return true;
}

// 提供升序降序、总分课程排序 
template<typename T> bool StudentService<T>::sortStudent(bool rev, bool type, string course) {
	sort(stus.begin(), stus.end(), [&rev, &type, &course](Student<T> &a, Student<T> &b) {
		if (type)
			return rev ? a.totalScore < b.totalScore : a.totalScore > b.totalScore;
		else 
			return rev ? a.score[course] < b.score[course] : a.score[course] > b.score[course];
	});
	return true;
}

// 快排
template<typename T> void StudentService<T>::quicksort(int left, int right, string course) {
	if (left > right) return;
	int mid = stus[left].score[course];
	int l = left, r = right;
	while (l != r) {
		while (stus[r].score[course] >= mid && l < r) r--;
		while (stus[l].score[course] <= mid && l < r) l++;
		
		if (l < r) swap(stus[l], stus[r]);
	}
	
	swap(stus[left], stus[l]);
	
	quicksort(left, l - 1, course);
	quicksort(l + 1, right, course);
}

// 提供课程排序
template<typename T> bool StudentService<T>::sortStudentQS(string course) {
	quicksort(0, stus.size() - 1, course);
	return true;
} 
