//
// Created by Vasiliy Evdokimov on 30.11.2020.
//

#include <iostream>

#include "Interface.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
#include "Test.hpp"

typedef enum {ARRAY, LIST} Type;
typedef enum {QUICK, BUBBLE, SHAKER} Sorting;

void Interface(){
    std::cout << "Hello, Dear User! Currently you're using my C++ program with different sorting algorithms"
                 "\nI hope you'll enjoy! Let's start then!\n\n";

    bool restart = true;
    while(restart){
        bool flag = false;
        Type choice = ARRAY;
        long long int len = 0;

        while (!flag){
            std::cout << "Now I will give you the choice to pick type\n"
                         "Write \"1\" for Array\n"
                         "Write \"2\" for List\n";

            size_t tmp = 0;
            std::cin >> tmp;

            if (tmp != 1 && tmp != 2) std::cout << "\nWrong input! Try again!\n";
            else {
                flag = true;
                choice = (tmp == 1 ? ARRAY : LIST);
            }
        }

        if (choice == ARRAY) std::cout << "\nYou picked array.\n";
        else if (choice == LIST) std::cout << "\nYou picked list.\n";

        flag = false;
        while (!flag) {
            std::cout << "\nNice one! So now tell me the size of the container : ";
            std::cin >> len;
            if (len < 0){
                std::cout << "\nSize can't be negative! Try again!\n";
            }
            else flag = true;
        }

        if (choice == ARRAY){
            ArraySequence<int> arr(len);
            std::cout << "\nWrite down " << len << " integer elements of your array : ";
            for (size_t i = 0; i < len; ++i) std::cin >> arr[i];

            std::cout << arr;

            flag = false;
            Sorting sort = QUICK;

            while(!flag) {
                int sort_choice = 0;
                std::cout << "\nChoose sorting algorithm which you want to test :\n"
                             "Write \"1\" for quick sort\n"
                             "Write \"2\" for bubble sort\n"
                             "Write \"3\" for shaker sort\n";
                std::cin >> sort_choice;

                if (sort_choice != 1 && sort_choice != 2 && sort_choice != 3) std::cout << "\nWrong input! Try again!\n";
                else {
                    flag = true;
                    if (sort_choice == 1) {
                        sort = QUICK;
                        std::cout << "\nYou picked quick sort!\n";
                    }
                    else if (sort_choice == 2) {
                        sort = BUBBLE;
                        std::cout << "\nYou picked bubble sort!\n";
                    }
                    else if (sort_choice == 3) {
                        sort = SHAKER;
                        std::cout << "\nYou picked shaker sort!\n";
                    }
                }
            }

            flag = false;
            int choice_order = 0;
            while (!flag){
                std::cout << "\nAnd the last one... I promise, choose do you want sort in increasing or decreasing order :\n"
                             "Write \"1\" for increasing\n"
                             "Write \"2\" for decreasing\n";

                std::cin >> choice_order;
                if (choice_order != 1 && choice_order != 2) std::cout << "\nWrong input! Try again!\n";
                else flag = true;
            }

            if (choice_order == 1) std::cout << "\nYou picked increasing order!\n";
            else if (choice_order == 2) std::cout << "\nYou picked decreasing order!\n";

            if (sort == QUICK){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) arr = *(ArraySequence<int>*)quickSort(&arr, cmpB);
                else if (choice_order == 2) arr = *(ArraySequence<int>*)quickSort(&arr, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << arr;
                std::cout << "Time taken to quick sort : "
                          << duration.count() << " microseconds \n";
            }
            else if (sort == BUBBLE){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) arr = *(ArraySequence<int>*)bubbleSort(&arr, cmpB);
                else if (choice_order == 2) arr = *(ArraySequence<int>*)bubbleSort(&arr, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << arr;
                std::cout << "Time taken to bubble sort : "
                          << duration.count() << " microseconds \n";
            }
            else if (sort == SHAKER){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) arr = *(ArraySequence<int>*)shakerSort(&arr, cmpB);
                else if (choice_order == 2) arr = *(ArraySequence<int>*)shakerSort(&arr, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << arr;
                std::cout << "Time taken to shaker sort : "
                          << duration.count() << " microseconds \n";
            }
        }
        else if (choice == LIST){
            ListSequence<int> list;
            std::cout << "\nWrite down " << len << " integer elements of your list : ";
            for (size_t i = 0; i < len; ++i) {
                int elem = 0;
                std::cin >> elem;
                list.Append(elem);
            }

            std::cout << list;


            flag = false;
            Sorting sort = QUICK;

            while(!flag) {
                int sort_choice = 0;
                std::cout << "\nChoose sorting algorithm which you want to test :\n"
                             "Write \"1\" for quick sort\n"
                             "Write \"2\" for bubble sort\n"
                             "Write \"3\" for shaker sort\n";
                std::cin >> sort_choice;

                if (sort_choice != 1 && sort_choice != 2 && sort_choice != 3) std::cout << "\nWrong input! Try again!\n";
                else {
                    flag = true;
                    if (sort_choice == 1) {
                        sort = QUICK;
                        std::cout << "\nYou picked quick sort!\n";
                    }
                    else if (sort_choice == 2) {
                        sort = BUBBLE;
                        std::cout << "\nYou picked bubble sort!\n";
                    }
                    else if (sort_choice == 3) {
                        sort = SHAKER;
                        std::cout << "\nYou picked shaker sort!\n";
                    }
                }
            }

            flag = false;
            int choice_order = 0;
            while (!flag){
                std::cout << "\nAnd the last one... I promise, choose do you want sort in increasing or decreasing order :\n"
                             "Write \"1\" for increasing\n"
                             "Write \"2\" for decreasing\n";

                std::cin >> choice_order;
                if (choice_order != 1 && choice_order != 2) std::cout << "\nWrong input! Try again!\n";
                else flag = true;
            }

            if (choice_order == 1) std::cout << "\nYou picked increasing order!\n";
            else if (choice_order == 2) std::cout << "\nYou picked decreasing order!\n";

            if (sort == QUICK){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) list = *(ListSequence<int>*)quickSort(&list, cmpB);
                else if (choice_order == 2) list = *(ListSequence<int>*)quickSort(&list, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << list;
                std::cout << "Time taken to quick sort : "
                          << duration.count() << " microseconds \n";
            }
            else if (sort == BUBBLE){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) list = *(ListSequence<int>*)bubbleSort(&list, cmpB);
                else if (choice_order == 2) list = *(ListSequence<int>*)bubbleSort(&list, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << list;
                std::cout << "Time taken to bubble sort : "
                          << duration.count() << " microseconds \n";
            }
            else if (sort == SHAKER){
                auto start = std::chrono::high_resolution_clock::now();
                if (choice_order == 1) list = *(ListSequence<int>*)shakerSort(&list, cmpB);
                else if (choice_order == 2) list = *(ListSequence<int>*)shakerSort(&list, cmpL);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "\nLook at your sorted array :\n" << list;
                std::cout << "Time taken to shaker sort : "
                          << duration.count() << " microseconds \n";
            }
        }

        flag = false;
        while(!flag) {
            std::cout << "\nDo you want to test on different input data?\n"
                         "Write \"1\" if answer is yes\n"
                         "Write \"2\" if answer is no\n";
            int answer = 0;
            std::cin >> answer;
            if (answer != 1 && answer != 2) std::cout << "\nWrong input! Try again!\n";
            else if (answer == 1){
                flag = true;
                restart = true;
            }
            else if (answer == 2){
                flag = true;
                restart = false;
            }
        }
    }
}