#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; // 부모 노드

void set_init(int n) { // 초기화
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

// curr가 속하는 집합을 반환
int set_find(int curr) {
    if (parent[curr] == -1) {
        return curr; // 루트
    }
    while (parent[curr] != -1) {
        curr = parent[curr];
    }
    return curr;
}

// 두 개의 원소가 속한 집합을 합친다.
void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2) {
        parent[root1] = root2;
    }
}