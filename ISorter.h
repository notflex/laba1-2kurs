#include "Sequences.h"

template<typename T>
class ISorter {
public:
    virtual void Sort(bool(*first)(const T &, const T &), Sequence<T> *seq, bool(*second)(const T &, const T &),int max_elem) = 0;
};

template<typename T>
class ISelectionSort : public ISorter<T> { //сортировка выбором
public:
    void
    Sort(bool(*first)(const T &, const T &), Sequence<T> *seq, bool(*second)(const T &, const T &) = nullptr,int max_elem = 10000) override {
        for (int num = 0; num < seq->GetLength(); ++num) {
            int min_value = num;     // ищем номер минимального значения в массиве
            for (int item = num; item < seq->GetLength(); ++item) {
                if (first(seq->Get(min_value), seq->Get(item))) // обмен этого значения с значением первой неотсортированной позиции
                    min_value = item;
            }
            T tmp = seq->Get(num);
            seq->Get(num) = seq->Get(min_value);
            seq->Get(min_value) = tmp; // отсортировано -> идем к хвосту сортировать его
        }
    }
};

template<typename T>
class IShakerSort : public ISorter<T> { // разновидность сортировки пузырьком - шейкерная
public:
    void
    Sort(bool(*first)(const T &, const T &), Sequence<T> *seq, bool(*second)(const T &, const T &) = nullptr,int max_elem = 10000) override {
        int left = 0;
        int right = seq->GetLength() - 1;
        int last_swap;

        while (left < right) {
            last_swap = 0;

            for (int i = left; i < right; ++i) {
                if (first(seq->Get(i), seq->Get(i + 1))) { // сравниваем правый с левым, если правый больше левого - меняем
                    T tmp = seq->Get(i);
                    seq->Get(i) = seq->Get(i + 1);
                    seq->Get(i + 1) = tmp;

                    last_swap = i;   // запоминаем номер на котором был сделан обмен
                }
            }
            right = last_swap;
            for (int j = right; j > left; --j) {
                if (second(seq->Get(j), seq->Get(j - 1))){ // сравниваем правый с левым, если левый меньше правого то
                    T tmp = seq->Get(j);
                    seq->Get(j) = seq->Get(j - 1); // все оставляем и в переменную ласт свап вводим значение житого элемента
                    seq->Get(j - 1) = tmp;

                    last_swap = j;
                }
            }

            left = last_swap;
        }
    }
};

template<typename T>
class ICountSort : public ISorter<T> { //подсчетом
public:
    void
    Sort(bool(*first)(const T &, const T &), Sequence<T> *seq, bool(*second)(const T &, const T &) = nullptr,int max_elem = 10000) override {
        int max = max_elem;
        T* every_possible_elements = new T[max]; // создаем новый массив
        for (int i = 0; i < max; ++i) {
            every_possible_elements[i] = 0; // заполняем его нулями
        }
        for (int i = 0; i < seq->GetLength(); ++i) {
            T tmp = seq->Get(i); // проходим по элементам массива
            every_possible_elements[tmp] = every_possible_elements[tmp] + 1; // для каждого T[A[i]] прибавляем его значение на 1
        }

        int index = 0;
        for (int i = 0; i < max; ++i) {
            while (every_possible_elements[i] != 0){
                seq->Get(index) = i;
                every_possible_elements[i]--; // проходим по второму массиву и получаем отсортированный наш
                index++;
            }
        }
    }
};