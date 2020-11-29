//
// Created by Vasiliy Evdokimov on 27.11.2020.
//

#pragma once

#include <stack>
#include <utility>
#include <iostream>
#include <string>


template <typename T>
ISequence<T>* bubbleSort(ISequence<T> *seq, CompareFun<T> *cmp){

    auto swap = [seq](int i, int j) {
        T temp = seq->GetElementData(i);
        seq->Set(i, seq->GetElementData(j));
        seq->Set(j, temp);
    };

    if(seq->GetSize() == 0) return seq;
    if(seq->GetSize() == 1) return seq;

    for(int i = 0; i < seq->GetSize() - 1; i++)
        for(int j = 0; j < seq->GetSize() - 1; j++){
            if(cmp(seq->GetElementData(j), seq->GetElementData(j + 1)) > 0){
                swap(j, j + 1);
            }
        }

    return seq;
}


template <typename T>
ISequence<T>* quickSort(ISequence<T> *seq, CompareFun<T> *cmp){

    auto swap = [seq](int i, int j) {
        T temp = seq->GetElementData(i);
        seq->Set(i, seq->GetElementData(j));
        seq->Set(j, temp);
    };

    if(seq->GetSize() == 0) return seq;
    if(seq->GetSize() == 1) return seq;

    std::stack<std::pair<int,int>> edges;
    edges.push({0, seq->GetSize() - 1});

    while(!edges.empty()){
        int start = edges.top().first;
        int end = edges.top().second;
        edges.pop();

        int p = start;
        int i = p + 1;
        int j = end;

        while(i <= j && i <= end && j > p){
            if(cmp(seq->GetElementData(i), seq->GetElementData(p)) <= 0) i++;
            else if(cmp(seq->GetElementData(j), seq->GetElementData(p)) > 0) j--;
            else swap(i, j);
        }
        swap(p, j);
        if(j > start + 1)
            edges.push({p, j - 1});
        if(j < end - 1)
            edges.push({j + 1, end});
    }
    return seq;
}


template <typename T>
ISequence<T>* shakerSort(ISequence<T> *seq, CompareFun<T> *cmp){

    if(seq->GetSize() == 0) return seq;
    if(seq->GetSize() == 1) return seq;

    auto swap = [seq](int i, int j) {
        T temp = seq->GetElementData(i);
        seq->Set(i, seq->GetElementData(j));
        seq->Set(j, temp);
    };

    int i = seq->GetSize();
    int cur = -1;

    while(true){
        --i;
        if(i == 0) break;
        for(int j = 0; j < i; j++){
            ++cur;

            if(cmp(seq->GetElementData(cur), seq->GetElementData(cur + 1)) > 0){
                swap(cur, cur + 1);
            }
        }

        --i;
        if(i == 0) break;
        for(int j = 0; j < i; ++j){
            --cur;

            if(cmp(seq->GetElementData(cur), seq->GetElementData(cur + 1)) > 0){
                swap(cur, cur + 1);
            }
        }
    }

    return seq;
}