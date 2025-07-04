package com.wisoft.io.datastructure.list.common;

public interface ListInterface<T> {
    void add(T element);

    void add(int index, T element);

    T remove(int index);

    T get(int index);

    T set(int index, T element);

    int indexOf(T element);

    int size();

    boolean isEmpty();

    void clear();

    Object[] toArray();
}
