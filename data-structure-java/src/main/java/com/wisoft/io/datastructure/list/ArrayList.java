package com.wisoft.io.datastructure.list;

import com.wisoft.io.datastructure.list.common.ListInterface;

import java.util.Arrays;

public class ArrayList<T> implements ListInterface<T> {
    private final Object[] array;

    private int size;

    public ArrayList() {
        int DEFAULT_CAPACITY = 10;
        this.array = new Object[DEFAULT_CAPACITY];
    }

    public ArrayList(int capacity) {
        this.array = new Object[capacity];
    }

    @Override
    public void add(T e) {
        array[size++] = e;
    }

    @Override
    public void add(int index, T element) {
        if (size == 0) {
            array[0] = element;
            size++;
            return;
        }
        shiftRight(index);
        array[index] = element;
        size++;
    }

    private void shiftRight(int index) {
        for (int i = size - 1; i > index; i--) {
            array[i] = array[i - 1];
        }
    }

    @Override
    public T remove(int index) {
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        return null;
    }

    @Override
    public T get(int index) {
        return null;
    }

    @Override
    public T set(int index, T element) {
        return null;
    }

    @Override
    public int indexOf(T o) {
        return 0;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public void clear() {

    }

    @Override
    public Object[] toArray() {
        return new Object[0];
    }

    public void printAll() {
        for (Object object : array) {
            System.out.print("object = " + object + " ,");
        }
    }

    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(array, size));
    }
}
