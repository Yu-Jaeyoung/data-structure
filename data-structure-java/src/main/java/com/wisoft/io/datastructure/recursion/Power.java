package com.wisoft.io.datastructure.recursion;

public class Power {
    public static long power(int x, int n) {
        if (n == 0) return 1;
        return x * power(x, n - 1);
    }

    public static void main(String[] args) {
        System.out.println(power(2, 5));
    }
}
