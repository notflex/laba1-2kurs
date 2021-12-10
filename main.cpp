#include <iostream>
#include <ctime>
#include <fstream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Materials.h"

template<typename T>
void Sort(bool(*cmp)(const T &, const T &),Sequence<T>* seq){
    for (int num = 0; num < seq->GetLength(); ++num) {
        int min_value = num;
        for (int item = num; item < seq->GetLength(); ++item) {
            if(cmp(seq->Get(min_value),seq->Get(item)))
                min_value = item;
        }
        T tmp = seq->Get(num);
        seq->Get(num) = seq->Get(min_value);
        seq->Get(min_value) = tmp;
    }
}

void menu() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "1.Array\n" << "2.Linkedlist\n" << "3.Exit\n" << "Choose on of options: ";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice < 1 || choice > 3) {
            std::cout << "incorrect option. Choose another one.\n";
            continue;
        }
        int type;
        int n;

        switch (choice) {
            case 1: {
                std::cout << "1.Selectionsort\n2.Shakersort\n3.Countsort\nInput type of sort:";
                std::cin >> type;
                if (type != 1 && type != 2 && type != 3) {
                    std::cout << "Wrong choice of type! Try again.\n";
                    continue;
                }
                switch (type) {
                    case 1: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "Array SelectionSort : ";
                        unsigned int start_time =  clock();
                        ArraySequence<int> a(data, N);
                        a.SelectionSort(third);
                        a.Print();
                        unsigned int end_time = clock();
                        std::ofstream outf("arrayselectionsort.txt");
                        outf <<clock();
                    }
                    break;
                    case 2: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "Array ShakerSort : ";
                        unsigned int start_time =  clock();
                        ArraySequence<int> a(data, N);
                        a.ShakerSort(third, second);
                        a.Print();
                        unsigned int end_time = clock();
                        std::ofstream outf("arraysshakersort.txt");
                        outf <<clock();
                    }
                    break;
                    case 3: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "Array CountSort : ";
                        unsigned int start_time = clock();
                        ArraySequence<int> a(data, N);
                        a.CountSort(max);//функция сравнения не играет никакой роли в сортировке подсчетом
                        a.Print();
                        unsigned int end_time = clock();
                        std::ofstream outf("arraycountsort.txt");
                        outf <<clock();
                    }
                        break;
                }
            }
                break;
            case 2:{
                std::cout << "1.Selectionsort\n2.Shakersort\n3.Countsort\nInput type of sort:";
                std::cin >> type;
                if (type != 1 && type != 2 && type != 3) {
                    std::cout << "Wrong choice of type! Try again.\n";
                    continue;
                }
                switch (type) {
                    case 1: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "List SelectionSort : ";
                        unsigned int start_time = clock();
                        LinkedListSequence<int> a(data, N);
                        a.SelectionSort(third);
                        unsigned int end_time = clock();
                        a.Print();
                        std::ofstream outf("linkedselectionsort.txt");
                        outf <<clock();
                    }
                        break;
                    case 2: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "List ShakerSort : ";
                        unsigned int start_time = clock();
                        LinkedListSequence<int> a(data, N);
                        a.ShakerSort(third, second);
                        a.Print();
                        unsigned int end_time = clock();
                        std::ofstream outf("listshakersort.txt");
                        outf <<clock();
                    }
                        break;
                    case 3: {
                        int N;
                        int max;
                        std::cout << "input number of elements:";
                        std::cin >> N;
                        std::cout << "input max number:";
                        std::cin >> max;
                        int data[N];

                        for (int i = 0; i < N; ++i) {
                            data[i] = rand() % max;
                        }
                        std::cout << "List CountSort : ";
                        unsigned int start_time = clock();
                        LinkedListSequence<int> a(data, N);
                        a.CountSort(max);
                        a.Print();
                        unsigned int end_time = clock();
                        std::ofstream outf("listcountsort.txt");
                        outf <<clock();
                    }
                        break;
                }
            }
               break;
            case 3: {
                std::cout << "Exit the program...\n";
                return;
            }
                break;
            default: {
                std::cout << "Wrong choice! Try again.\n";
            }
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
