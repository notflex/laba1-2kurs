#pragma once

#include "Sequences.h"
#include "ISorter.h"

template<typename T>
class ArraySequence : public Sequence<T> {
public:


    ArraySequence() : data() {}

    ArraySequence(int count) : data(count) {}

    ArraySequence(T *item, int count) : data(item, count) {}

    ArraySequence(ArraySequence<T> &array) : data(array.data) {}

    ArraySequence(LinkedList<T> &list) {//копиконструктор для параметра LinkedList
        T *items;
        items = (T *) malloc(sizeof(T) * (list.GetLength()));
        for (int i = 0; i < list.GetLength(); ++i) {
            items[i] = list.Get(i);
        }
        data = DynamicArray<T>(items, list.GetLength());
    }

    int GetLength() {
        return data.GetSize();
    }

    T &Get(int index) {
        return data.Get(index);
    }

    T &GetFirst() {
        return data.Get(0);
    }

    T &GetLast() {
        return data.Get(data.GetSize() - 1);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {//void Set(int index,T value)
        if (index >= data.GetSize() || index < 0)
            throw "\nInsertAt Message : Index Out Of Range";
        data.Resize(data.GetSize() + 1);
        for (int i = data.GetSize() - 2; i >= index; --i) {
            data.Set(i + 1, data.Get(i));
        }
        data.Set(index, item);
    }

    void Print() {
        data.Print();
    }


    void SelectionSort(bool(*cmp)(const T &, const T &)) override {
        ISelectionSort<T> obj;
        obj.Sort(cmp, this);
    }

    void ShakerSort(bool(*first)(const T &, const T &), bool(*second)(const T &, const T &)) override {
        IShakerSort<T> obj;
        obj.Sort(first, this, second);
    }

    void CountSort(int max = 10000) override {
        ICountSort<T> obj;
        obj.Sort(nullptr, this);
    }

private:
    DynamicArray<T> data;

};