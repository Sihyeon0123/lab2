#include <iostream>
#include <vector>
using namespace std;

int main(){
	int x, y;
	cout << "행렬의 x, y 길이를 입력해주세요: ";
	cin >> x >> y;

	vector<vector<int>> matrix1(y, vector<int>(x));
	vector<vector<int>> matrix2(y, vector<int>(x));

	cout << "첫번째 행렬의 값을 입력해 주세요:" << endl;
	for (int i = 0; i <y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> matrix1[j][i];
		}
	}
	cout << endl;

	cout << "두번째 행렬의 값을 입력해 주세요:" << endl;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> matrix2[j][i];
		}
	}
	cout << endl;

	cout << "첫번째 행렬의 값:" << endl;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << matrix1[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "두번째 행렬의 값:" << endl;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << matrix2[j][i] << ' ';
			matrix1[j][i] += matrix2[j][i];
		}
		cout << endl;
	}
	cout << endl;

	cout << "결과 출력:" << endl;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << matrix1[j][i]<< ' ';
		}
		cout << endl;
	}
	cout << endl;
}