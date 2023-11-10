#include "CppUTest/TestHarness.h"
#include "CppUTest/MergeSort.hpp"
#include <iostream>
#include <cstdlib>

TEST_GROUP(mergeSort)
{
};

TEST(mergeSort, notChangingArrayWhenItsSorted)
{
    int tab[5]{1, 2, 3, 4, 5};
    int tab2[5]{1, 2, 3, 4, 5};

    MergeSort m1;
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);

    for (int i = 0; i < 5; i++) {
        LONGS_EQUAL(tab2[i], tab[i]);
    }
}

TEST(mergeSort, sortsWhenArraySortedInReverse)
{
    int tab[5]{5,4,3,2,1};
    int tab2[5]{1,2,3,4,5};

    MergeSort m1;
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);

    for (int i = 0; i < 5; i++) {
        LONGS_EQUAL(tab2[i], tab[i]);
    }
}

TEST(mergeSort, sortsRandomNumbers)
{  
    int tab[5];
    srand((unsigned)time(NULL));

    for (int i = 0; i < 5; i++) {
        tab[i] = 1 + (rand() % 9);
        //std::cout << tab[i];
    }

    MergeSort m1;
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);

    //tab[0] = 9;

    for (int i = 1; i < 5; i++) {
        CHECK(tab[i-1] <= tab[i]);
    }
}

TEST(mergeSort, sortsOnlyNegativeNumbers)
{
    int tab[5]{-3, -2, -9, -1, -7};
    int tab2[]{-9,-7,-3,-2,-1};

    MergeSort m1;
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);

    for (int i = 0; i < 5; i++) {
        //std::cout << tab[i];
        LONGS_EQUAL(tab[i], tab2[i]);
    }
}

TEST(mergeSort, sortsNegativeAndPositiveNumbers)
{
    int tab[5]{-2, -3, 2,2,3};
    int tab2[]{-3,-2,2,2,3};

    MergeSort m1;
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);

    for (int i = 0; i < 5; i++) {
        std::cout << tab[i] << ",";
        LONGS_EQUAL(tab[i], tab2[i]);
    }
}

TEST(mergeSort, wontThrowExceptionWhenArrayIsEmpty)
{
int* tab = new int[0];
MergeSort m1;
try {
    m1.sortowanie_przez_scalanie(tab, 5, 0, 4);
}
catch (...) {
    FAIL("wyj¹tek");
}
delete[] tab;
}



#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}