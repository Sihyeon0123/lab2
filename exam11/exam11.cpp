#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Student {
    int mid_exam;
    int final_exam;
    Student() : mid_exam(0), final_exam(0) {}

    Student(int mid, int final) : mid_exam(mid), final_exam(final) {}
};

int main() {
    int num;
    cout << "학생수를 입력해 주세요: ";
    cin >> num;
    cin.ignore();  // Enter 키 제거

    map<string, Student> studentMap;

    for (int i = 0; i < num; i++) {
        string name;
        int mid_exam, final_exam;

        cout << "학생 이름: ";
        cin >> name;
        cout << "중간 시험 점수: ";
        cin >> mid_exam;
        cout << "기말 시험 점수: ";
        cin >> final_exam;
        cin.ignore();  // Enter 키 제거
        cout << endl;

        studentMap[name] = Student(mid_exam, final_exam);
    }

    string name;
    cout << "찾을 학생의 이름을 입력해주세요: ";
    cin >> name;

    auto it = studentMap.find(name);

    if (it != studentMap.end()) {
        // 학생을 찾았을 경우
        Student student = it->second;
        cout << "학생을 찾았습니다:" << endl;
        cout << "이름: " << name << endl;
        cout << "중간 시험 점수: " << student.mid_exam << endl;
        cout << "기말 시험 점수: " << student.final_exam << endl;
    } else {
        // 학생을 찾지 못한 경우
        cout << "학생을 찾을 수 없습니다." << endl;
    }

    return 0;
}
