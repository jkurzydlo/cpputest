#include "CppUTest/TestHarness.h"
#include "CppUTest/MergeSort.hpp"
#include <iostream>

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

#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}