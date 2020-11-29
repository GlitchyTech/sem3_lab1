//
// Created by Vasiliy Evdokimov on 29.11.2020.
//

#include "Test.hpp"
#include "ISequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
#include "Utils.hpp"


void TestQuickSort(){
    ArraySequence<int> arr1 = {-454, 4, 45, 87, 934, 0, -4, 3849};
    ArraySequence<int> sArr1 = {-454, -4, 0, 4, 45, 87, 934, 3849};
    ListSequence<int> list1;
    ListSequence<int> sList1;
    list1.Append(9);
    list1.Append(5);
    list1.Append(-5);
    list1.Append(3);

    sList1.Append(-5);
    sList1.Append(3);
    sList1.Append(5);
    sList1.Append(9);

    if ((*(ArraySequence<int>*)quickSort(&arr1, cmpB) != sArr1)){
        std::cout << "TEST QUICK SORT ARRAY : FAILED\n";
    }
    else
        std::cout << "TEST QUICK SORT ARRAY : SUCCEEDED\n";

    if ((*(ListSequence<int>*)quickSort(&list1, cmpB) != sList1)){
        std::cout << "TEST QUICK SORT LIST : FAILED\n";
    }
    else
        std::cout << "TEST QUICK SORT LIST : SUCCEEDED\n";
}

void TestBubbleSort(){
    ArraySequence<int> arr2 = {-454, 4, 45, 87, 934, 0, -4, 3849};
    ArraySequence<int> sArr2 = {-454, -4, 0, 4, 45, 87, 934, 3849};
    ListSequence<int> list2;
    ListSequence<int> sList2;
    list2.Append(9);
    list2.Append(5);
    list2.Append(-5);
    list2.Append(3);

    sList2.Append(-5);
    sList2.Append(3);
    sList2.Append(5);
    sList2.Append(9);

    if ((*(ArraySequence<int>*)bubbleSort(&arr2, cmpB) != sArr2))
        std::cout << "TEST BUBBLE SORT ARRAY : FAILED\n";
    else
        std::cout << "TEST BUBBLE SORT ARRAY : SUCCEEDED\n";


    if ((*(ListSequence<int>*)bubbleSort(&list2, cmpB) != sList2)){
        std::cout << "TEST BUBBLE SORT LIST : FAILED\n";
    }
    else
        std::cout << "TEST BUBBLE SORT LIST : SUCCEEDED\n";
}

void TestShakerSort(){
    ArraySequence<int> arr3 = {-454, 4, 45, 87, 934, 0, -4, 3849};
    ArraySequence<int> sArr3 = {-454, -4, 0, 4, 45, 87, 934, 3849};
    ListSequence<int> list3;
    ListSequence<int> sList3;
    list3.Append(9);
    list3.Append(5);
    list3.Append(-5);
    list3.Append(3);

    sList3.Append(-5);
    sList3.Append(3);
    sList3.Append(5);
    sList3.Append(9);

    if ((*(ArraySequence<int>*)shakerSort(&arr3, cmpB) != sArr3)){
        std::cout << "TEST SHAKER SORT ARRAY : FAILED\n";
    }
    else
        std::cout << "TEST SHAKER SORT ARRAY : SUCCEEDED\n";

    if ((*(ListSequence<int>*)shakerSort(&list3, cmpB) != sList3)){
        std::cout << "TEST SHAKER SORT LIST : FAILED\n";
    }
    else
        std::cout << "TEST SHAKER SORT LIST : SUCCEEDED\n";
}

void Test(){
    std::cout << "\n\n**** RUNNING TESTS **** \n\n";
    TestQuickSort();
    TestBubbleSort();
    TestShakerSort();

    std::cout << "\n\n**** TESTS COMPLETED **** \n\n";
}