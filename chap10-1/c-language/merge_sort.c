/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE];
int n;

*/
/*
   i는 정렬된 왼쪽 리스트에 대한 인덱스
   j는 정렬된 오른쪽 리스트에 대한 인덱스
   k는 정렬된 리스트에 대한 인덱스
*//*


void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    */
/* 분할 정렬된 list의 합병 *//*

    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            sorted[k++] = list[i++];
        } else {
            sorted[k++] = list[j++];
        }
    }

    if (i > mid) { // 남아 있는 레코드의 일괄 복사
        for (l = j; l <= right; l++) {
            sorted[k++] = list[l];
        }
    } else {
        for (l = i; l <= mid; l++) { // 남아 있는 레코드의 일괄 복사
            sorted[k++] = list[l];
        }
    }

    // 배열 sorted[]의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;              // 리스트의 균등 분할
        merge_sort(list, left, mid);      // 부분 리스트 정렬
        merge_sort(list, mid + 1, right);  // 부분 리스트 정렬
        merge(list, left, mid, right);         // 합병
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
    }

    merge_sort(list, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}*/
