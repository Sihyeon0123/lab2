#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[128];
    int mid_exam;
    int final_exam;
    struct Student* left;
    struct Student* right;
} Student;

Student* insertStudent(Student* root, const char* name, int mid_exam, int final_exam) {
    if (root == NULL) {
        Student* newStudent = (Student*)malloc(sizeof(Student));
        strcpy(newStudent->name, name);
        newStudent->mid_exam = mid_exam;
        newStudent->final_exam = final_exam;
        newStudent->left = newStudent->right = NULL;
        return newStudent;
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = insertStudent(root->left, name, mid_exam, final_exam);
    } else if (cmp > 0) {
        root->right = insertStudent(root->right, name, mid_exam, final_exam);
    }

    return root;
}

Student* searchStudent(Student* root, const char* name) {
    if (root == NULL) {
        return NULL;  // 학생을 찾을 수 없음
    }

    int cmp = strcmp(name, root->name);
    if (cmp == 0) {
        return root;  // 학생을 찾음
    } else if (cmp < 0) {
        return searchStudent(root->left, name);  // 왼쪽 서브트리에서 탐색
    } else {
        return searchStudent(root->right, name);  // 오른쪽 서브트리에서 탐색
    }
}

void freeTree(Student* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int num;
    printf("학생수를 입력해 주세요: ");
    scanf("%d", &num);

    Student* root = NULL;

    for (int i = 0; i < num; i++) {
        char name[128];
        int mid_exam, final_exam;
        printf("학생 이름: ");
        scanf("%s", name);
        printf("중간 시험 점수: ");
        scanf("%d", &mid_exam);
        printf("기말 시험 점수: ");
        scanf("%d", &final_exam);
        printf("\n");
        root = insertStudent(root, name, mid_exam, final_exam);
    }

    printf("찾을 학생의 이름을 입력해 주세요: ");
    char name[128];
    scanf("%s", name);

    Student* foundStudent = searchStudent(root, name);

    if (foundStudent) {
        printf("학생을 찾았습니다:\n");
        printf("이름: %s\n", foundStudent->name);
        printf("중간 시험 점수: %d\n", foundStudent->mid_exam);
        printf("기말 시험 점수: %d\n", foundStudent->final_exam);
    } else {
        printf("학생을 찾을 수 없습니다.\n");
    }

    // 트리 메모리 해제
    freeTree(root);

    return 0;
}
