package com.wisoft.io.datastructure.recursion;

import java.util.Arrays;

public class SumArray {
    public static int sumArray(int[] arr) {
        if (arr.length == 1) {
            return arr[0];
        }

        // 마지막 원소를 제외한 새 배열을 생성
        int[] subArray = Arrays.copyOfRange(arr, 0, arr.length - 1);

        return sumArray(subArray) + arr[arr.length - 1];
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int sum = sumArray(arr);
        System.out.println("배열의 합: " + sum);
    }
}