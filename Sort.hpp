//
// Created by Vasiliy Evdokimov on 27.11.2020.
//

#ifndef SEM3_LAB1_SORT_HPP
#define SEM3_LAB1_SORT_HPP

#include "ISequence.hpp"

template<typename T>
using CompareFun = int (T, T);

//int (*const defaultCompareFun)(int, int) = [](int a,int b){return a - b;};

template<typename T>
ISequence<T>* bubbleSort(const ISequence<T> *, CompareFun<T> *);

template <typename T>
ISequence<T>* quickSort(const ISequence<T> *, CompareFun<T> *);

template<typename T>
ISequence<T>* shakerSort(const ISequence<T> *, CompareFun<T> *);

#include "SortImplementation.hpp"

#endif //SEM3_LAB1_SORT_HPP
