#include <iostream>
#include <vector>
#include <windows.h>
#include "student_service.h"
using namespace std;

void printMenu() {
	for (int i = 0; i < 20; i++) cout << "*";
	cout << "��ӭʹ��ѧ���ɼ�����ϵͳ";
	for (int i = 0; i < 20; i++) cout << "*";
	cout << endl;
	cout << "��������Ҫִ�еĲ�����" << endl;
	cout << "1. �鿴ȫ��ѧ���б�" << endl;
	cout << "2. ����ѧ��" << endl;
	cout << "3. ɾ��ѧ����ѧ�ţ�" << endl;
	cout << "4. ����ѧ����Ϣ��ѧ�ţ�" << endl;
	cout << "5. ͨ��ѧ��������ѧ����Ϣ" << endl;
	cout << "6. ͨ��ID�鿴ѧ����Ϣ" << endl;
	cout << "7. ָ���γ��Լ��ɼ��������ѧ����Ϣ" << endl;
	cout << "8. ����ָ���γ̳ɼ�����" << endl;
	cout << "9. �߼����򣨿�ָ�������������ܷ֡��γ̵ȷ�ʽ��" << endl;
	cout << "10. ����ѧ����Ϣ���ļ�" << endl;
	for (int i = 0; i < 64; i++) cout << "*";
	cout << endl << "������ָ����:" << endl;
}

template<typename T> void printStudentList(vector<Student<T> > stuList) {
	cout << "ѧ����Ϣ�б�" << endl;
	cout << "����" << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << endl;
	for (auto s : stuList) cout << s.name << '\t' << s.id << '\t' << s.score["����"] << '\t' << s.score["��ѧ"] << '\t' << s.score["Ӣ��"] << endl;
	cout << endl;
}

template<typename T> void printStudentInfo(Student<T> s) {
	cout << "ѧ����Ϣ�б�" << endl;
	cout << "����" << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << endl;
	cout << s.name << '\t' << s.id << '\t' << s.score["����"] << '\t' << s.score["��ѧ"] << '\t' << s.score["Ӣ��"] << endl;
	cout << endl;
}

template<typename T> void addStu(StudentService<T >& stu) {
	string name, id;
	T c, m, e;
	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѧ��ѧ�ţ�";
	cin >> id;
	cout << "���������ĳɼ���";
	cin >> c;
	cout << "��������ѧ�ɼ���";
	cin >> m;
	cout << "������Ӣ��ɼ���";
	cin >> e;
	stu.addStudent({ name, id, m, c, e });
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void delStu(StudentService<T >& stu) {
	string id;
	cout << "������Ҫɾ����ѧ��id��";
	cin >> id;
	stu.delStudent(id);
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void updStu(StudentService<T >& stu) {
	string name, id;
	T c, m, e;
	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѧ��ѧ�ţ�";
	cin >> id;
	cout << "���������ĳɼ���";
	cin >> c;
	cout << "��������ѧ�ɼ���";
	cin >> m;
	cout << "������Ӣ��ɼ���";
	cin >> e;
	stu.updStudent({ name, id, m, c, e });
	system("cls");
	printStudentList(stu.getStudentList());
}

template<typename T> void findStuByName(StudentService<T >& stu) {
	string name;
	cout << "������ѧ������: ";
	cin >> name;
	auto s = stu.findStudentByName(name);
	if (!s.name.length()) {
		cout << "ѧ�� " << name << " �����ڣ�" << endl;
		return;
	}
	printStudentInfo(s);
}

template<typename T> void findStuById(StudentService<T >& stu) {
	string id;
	cout << "������ѧ��ѧ��: ";
	cin >> id;
	auto s = stu.findStudentById(id);
	if (!s.name.length()) {
		cout << "ѧ�������ڣ�" << endl;
		return;
	}
	printStudentInfo(s);
}

template<typename T> void filStu(StudentService<T >& stu) {
	string course;
	T l, r;
	cout << "������γ�����";
	cin >> course;
	cout << "��������ͷ�����";
	cin >> l;
	cout << "��������߷�����";
	cin >> r;
	auto res = stu.filterStudentByScore(course, { l, r });
	if (!res.size()) {
		cout << "�γ� " << course << " û�������������������ѧ����" << endl;
		return;
	}
	printStudentList(res);
}

template<typename T> void sortStu(StudentService<T >& stu) {
	string course;
	cout << "������γ�����";
	cin >> course;
	stu.sortStudentQS(course);
	printStudentList(stu.getStudentList());
}

template<typename T> void advSortStu(StudentService<T >& stu) {
	bool rev = false, type = true;
	string course = "";
	cout << "�����������������1������0��Ĭ�Ͻ��򣩣�";
	cin >> rev;
	cout << "�����������ֶΣ��ܷ�1���γ�0��Ĭ���ܷ֣���";
	cin >> type;
	if (!type) {
		cout << "������γ�����";
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
			cout << "ָ���������������룡" << endl;
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
				cout << "ѧ����Ϣ������·�� " << OUT_PUT_FILE << " �ɹ���" << endl;
				break;
		}

		system("pause");
		system("cls");
		printMenu();
	}


	/*for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;

	stu.addStudent({ "����׿", "06", 100, 99, 98 });
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;

	stu.delStudent("02");
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;

	stu.updStudent({ "����׿", "06", 60, 70, 80 });
	cout << endl;
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;

	auto hwz = stu.findStudentByName("����׿");
	cout << endl;
	cout << hwz.name << ',' << hwz.id << ',' << hwz.score["����"] << ',' << hwz.score["��ѧ"] << ',' << hwz.score["Ӣ��"] << endl;


	hwz = stu.findStudentById("03");
	cout << endl;
	cout << hwz.name << ',' << hwz.id << ',' << hwz.score["����"] << ',' << hwz.score["��ѧ"] << ',' << hwz.score["Ӣ��"] << endl;

	cout << endl;
	for (auto s : stu.filterStudentByScore("��ѧ", { 70, 80 })) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;

	// stu.reserveStudentList();

	cout << endl;
	// stu.sortStudent(true, false, "��ѧ");
	stu.sortStudentQS("��ѧ");
	for (auto s : stu.getStudentList()) cout << s.name << ',' << s.id << ',' << s.score["����"] << ',' << s.score["��ѧ"] << ',' << s.score["Ӣ��"] << endl;
	*/
	return 0;
}
