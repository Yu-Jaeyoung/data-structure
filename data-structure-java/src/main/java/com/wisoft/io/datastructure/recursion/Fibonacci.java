package com.wisoft.io.datastructure.recursion;

public class Fibonacci {
    public static int fibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    public static int fibonacciIterative(int n) {
        if (n <= 1) {
            return n;
        }

        int prev1 = 0;
        int prev2 = 1;
        int current = 0;

        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }


    public static void main(String[] args) {
        int n = 10;
        System.out.println("f(" + n + ") = " + fibonacciRecursive(n));
        System.out.println("f(" + n + ") = " + fibonacciIterative(n));
    }
}