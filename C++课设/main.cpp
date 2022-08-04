#include <iostream>
#include <vector>
#include <windows.h>
#include "student_service.h"
using namespace std;

void printMenu() {
	for (int i = 0; i < 20; i++) cout << "*";
	cout << "欢迎使用学生成绩管理系统";
	for (int i = 0; i < 20; i++) cout << "*";
	cout << endl;
	cout << "请输入需要执行的操作：" << endl;
	cout << "1. 查看全部学生列表" << endl;
	cout << "2. 增加学生" << endl;
	cout << "3. 删除学生（学号）" << endl;
	cout << "4. 更新学生信息（学号）" << endl;
	cout << "5. 通过学生名查找学生信息" << endl;
	cout << "6. 通过ID查看学生信息" << endl;
	cout << "7. 指定课程以及成绩区间查找学生信息" << endl;
	cout << "8. 依据指定课程成绩排序" << endl;
	cout << "9. 高级排序（可指定升降序、依据总分、课程等方式）" << endl;
	cout << "10. 保存学生信息至文件" << endl;
	for (int i = 0; i < 64; i++) cout << "*";
	cout << endl << "请输入指令编号:" << endl;
}

template<typename T> void printStudentList(vector<Student<T> > stuList) {
	cout << "学生信息列表：" << endl;
	cout << "姓名" << '\t' << "学号" << '\t' << "语文" << '\t' << "数学" << '\t' << "英语" << endl;
	for (auto s : stuList) cout << s.name << '\t' << s.id << '\t' << s.score["语文"] << '\t' << s.score["数学"] << '\t' << s.score["英语"] << endl;
	cout << endl;
}

template<typename T> void printStudentInfo(Student<T> s) {
	cout << "学生信息列表：" << endl;
	cout << "姓名" << '\t' << "学号" << '\t' << "语文" << '\t' << "数学" << '\t' << "英语" << endl;
	cout << s.name << '\t' << s.id << '\t' << s.score["语文"] << '\t' << s.score["数学"] << '\t' << s.score["英语"] << endl;
	cout << endl;
}

template<typename T> void addStu(StudentService<T >& stu) {
	string name, id;
	T c, m, e;
	cout << "请输入学生姓名：";
	cin >> name;
	cout << "请输入学生学号：";
	cin >> id;
	cout << "请输入语文成绩：";
	cin >> c;
	cout << "请输入数学成绩：";
	cin >> m;
	cout << "请输入英语成绩：";
	cin >> e;
	stu.addStudent({ name, id, m, c, e });
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void delStu(StudentService<T >& stu) {
	string id;
	cout << "请输入要删除的学生id：";
	cin >> id;
	stu.delStudent(id);
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void updStu(StudentService<T >& stu) {
	string name, id;
	T c, m, e;
	cout << "请输入学生姓名：";
	cin >> name;
	cout << "请输入学生学号：";
	cin >> id;
	cout << "请输入语文成绩：";
	cin >> c;
	cout << "请输入数学成绩：";
	cin >> m;
	cout << "请输入英语成绩：";
	cin >> e;
	stu.updStudent({ name, id, m, c, e });
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void findStuByName(StudentService<T >& stu) {
	string name;
	cout << "请输入学生姓名: ";
	cin >> name;
	auto s = stu.findStudentByName(name);
	if (!s.name.length()) {
		cout << "学生 " << name << " 不存在！" << endl;
		return;
	}
	printStudentInfo(s);
}

template<typename T> void findStuById(StudentService<T >& stu) {
	string id;
	cout << "请输入学生学号: ";
	cin >> id;
	auto s = stu.findStudentById(id);
	if (!s.name.length()) {
		cout << "学生不存在！" << endl;
		return;
	}
	printStudentInfo(s);
}

template<typename T> void filStu(StudentService<T >& stu) {
	string course;
	T l, r;
	cout << "请输入课程名：";
	cin >> course;
	cout << "请输入最低分数：";
	cin >> l;
	cout << "请输入最高分数：";
	cin >> r;
	auto res = stu.filterStudentByScore(course, { l, r });
	if (!res.size()) {
		cout << "课程 " << course << " 没有满足分数区间条件的学生！" << endl;
		return;
	}
	printStudentList(res);
}

template<typename T> void sortStu(StudentService<T >& stu) {
	string course;
	cout << "请输入课程名：";
	cin >> course;
	stu.sortStudentQS(course);
	printStudentList(stu.getStudentList());
}

template<typename T> void advSortStu(StudentService<T >& stu) {
	bool rev = false, type = true;
	string course = "";
	cout << "请输入排序规则（升序1，降序0，默认降序）：";
	cin >> rev;
	cout << "请输入排序字段（总分1，课程0，默认总分）：";
	cin >> type;
	if (!type) {
		cout << "请输入课程名：";
		cin >> course;
	}
	
	stu.sortStudent(rev, type, course);
	printStudentList(stu.getStudentList());
}

int main() {
	system("color F0");
	StudentService<float > stu;
	int op;

	printMenu();
	while (cin >> op) {
		if (op < 1 || op > 10) {
			cout << "指令有误，请重新输入！" << endl;
			continue;
		}

		system("cls");

		switch (op) {
			case 1:
				printStudentList(stu.getStudentList());
				break;
			case 2:
				addStu(stu);
				break;
			case 3:
				delStu(stu);
				break;
			case 4:
				updStu(stu);
				break;
			case 5:
				findStuByName(stu);
				break;
			case 6:
				findStuById(stu);
				break;
			case 7:
				filStu(stu);
				break;
			case 8:
				sortStu(stu);
				break;
			case 9:
				advSortStu(stu);
				break;
			case 10:
				stu.reserveStudentList();
				cout << "学生信息保存至路径 " << OUT_PUT_FILE << " 成功！" << endl;
				break;
		}

		system("pause");
		system("cls");
		printMenu();
	}


	/*for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;

	stu.addStudent({ "胡文卓", "06", 100, 99, 98 });
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;

	stu.delStudent("02");
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;

	stu.updStudent({ "胡文卓", "06", 60, 70, 80 });
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;

	auto hwz = stu.findStudentByName("胡文卓");
	cout << endl;
	cout << hwz.name << ',' << hwz.id << ',' << hwz.score["语文"] << ',' << hwz.score["数学"] << ',' << hwz.score["英语"] << endl;


	hwz = stu.findStudentById("03");
	cout << endl;
	cout << hwz.name << ',' << hwz.id << ',' << hwz.score["语文"] << ',' << hwz.score["数学"] << ',' << hwz.score["英语"] << endl;

	cout << endl;
	for (auto s : stu.filterStudentByScore("数学", { 70, 80 })) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;

	// stu.reserveStudentList();

	cout << endl;
	// stu.sortStudent(true, false, "数学");
	stu.sortStudentQS("数学");
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["语文"] << ',' << s.score["数学"] << ',' << s.score["英语"] << endl;
	*/
	return 0;
}
