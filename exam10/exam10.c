#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    int mid_exam;
    int final_exam;
};

int compare(const void *cp1, const void *cp2) {
    return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

void print_node(const void *, VISIT, int);
struct node *root = NULL; // 전역 변수로 선언

struct node *search(const char *name) {
    struct node target;
    target.name = (char *)name;

    // tfind 함수를 사용하여 이름을 기반으로 학생을 검색합니다.
    struct node **result = (struct node **)tfind((void *)&target, (void **)&root, compare);

    if (result != NULL) {
        return *result;
    } else {
        return NULL;
    }
}

int main() {
    int num = 0;
    printf("학생수를 입력해 주세요: ");
    scanf("%d", &num);

    // 학생 이름을 저장할 동적 할당된 배열을 생성합니다.
    char *nametable = (char *)malloc(num * 20);
    if (nametable == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        return 1;
    }
    char *nameptr = nametable;

    // 학생 정보를 저장할 동적 할당된 배열을 생성합니다.
    struct node *nodetable = (struct node *)malloc(num * sizeof(struct node));
    if (nodetable == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        free(nametable); // 메모리 누수 방지를 위해 할당된 메모리를 해제합니다.
        return 1;
    }

    struct node *nodeptr = nodetable;
    struct node **ret;
    int i = 0;

    printf("학생 정보를 입력해 주세요:\n(이름) (중간시험점수) (기말시험점수)\n");
    while (i < num && scanf("%s %d %d", nameptr, &nodeptr->mid_exam, &nodeptr->final_exam) != EOF) {
        nodeptr->name = nameptr;
        // 트리에 넣기
        ret = (struct node **)tsearch((void *)nodeptr, (void **)&root, compare);
        printf("\"%s\" 님이 ", (*ret)->name);

        if (*ret == nodeptr)
            printf("트리에 추가되었습니다.\n");
        else
            printf("트리에 이미 존재합니다.\n");

        nameptr += strlen(nameptr) + 1;
        nodeptr++;
        i++;
    }

    twalk((void *)root, print_node);

    char search_name[20];
    
    printf("검색할 학생의 이름을 입력해 주세요 (끝내려면 Ctrl+D 또는 Ctrl+Z를 누르세요):\n");
    while (scanf("%s", search_name) != EOF) {
        printf("%s를 검색합니다.\n", search_name);
        struct node *found = search(search_name);
        if (found) {
            printf("이름 = %s, 중간시험 = %d, 기말시험 = %d\n", found->name, found->mid_exam, found->final_exam);
        } else {
            printf("%s를 찾을 수 없습니다.\n", search_name);
        }
    }

    // 할당된 메모리를 해제합니다.
    free(nametable);
    free(nodetable);

    return 0;
}

/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
    if (order == preorder || order == leaf)
        printf("이름 = %-8s, 중간시험 = %d, 기말시험 = %d\n",(*(struct node **)nodeptr)->name, (*(struct node **)nodeptr)->mid_exam, (*(struct node **)nodeptr)->final_exam);
}
