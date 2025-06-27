package com.wisoft.io.datastructure.recursion;

public class Factorial {
    public static long factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int num = 5;
        System.out.println(num + "! = " + factorial(num));
    }
}
