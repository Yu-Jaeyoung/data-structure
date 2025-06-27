package com.wisoft.io.datastructure.recursion;

public class TowerOfHanoi {
    public static void hanoi(int count, char from, char to, char temp) {
        if (count <= 0) return;

        hanoi(count - 1, from, temp, to);
        System.out.println("원반 " + count + "를 " + from + "에서 " + to + "으로 이동");
        hanoi(count - 1, temp, to, from);
    }

    public static void main(String[] args) {
        int count = 3;
        char from = 'A';
        char temp = 'B';
        char to = 'C';

        hanoi(count, from, to, temp);
    }
}
