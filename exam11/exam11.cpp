#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

int main() {
    map<string, map<int, int>> students;
    string name;
    int mid_score;
    int final_score;
    int num;

    cout << "학생 수를 입력해 주세요:" << endl;
    cin >> num;
    cin.clear();

    
    for(int i = 0; i < num; i++){
        cout << "[" << i+1 <<"] 학생이름과 중간, 기말고사 점수를 입력해 주세요:" << endl;
        cin >> name >> mid_score >> final_score;
        // 입력이 제대로 되었는지 확인
        if (cin.fail()) {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if(students.find(name) != students.end()){
            cout << "중복된 이름이 있습니다. 다시 시도하세요." << endl;
            i--;
            continue;
        }
        map<int, int> temp;
        temp.emplace(mid_score, final_score);
        students.emplace(name, temp);
    }

    cout << "입력된 학생을 출력합니다:" << endl;
    for (const auto &student : students) {
        cout << student.first << " ";
        for (const auto &score : student.second){
            cout << score.first << " " << score.second << endl;
        } 
        
    }

    cout << "검색할 이름을 입력하세요:\n";
    string search_name;
    
    while (cin >> search_name) {
        auto m = students.find(search_name);

        if (m != students.end()) {
            cout << "검색 성공: " << m->first << endl;
            for (const auto &score : m->second) {
                cout << "중간시험: " << score.first << endl << "기말시험: " << score.second << " ";
            }
            cout << endl;
        } else {
            cout << "검색 결과가 없습니다: " << search_name << endl;
        }
    }

    return 0;
}
