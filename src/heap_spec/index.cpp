#include <gtest/gtest.h>
#include <ctime>
#include "../algorithms/algorithms.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(algorithms, binarySearch) {
    int arr[] = { -11, 1, 3, 5, 7, 8 };

    EXPECT_TRUE(Algorithms::binarySearch(arr, 0, 6, 7));
    EXPECT_TRUE(Algorithms::binarySearch(arr, 0, 6, 1));
    EXPECT_FALSE(Algorithms::binarySearch(arr, 0, 6, -3));
}

TEST(algorithms, quickSort) {
    int arr[] = { 5, 7, -11, 3, 8, 1 };
    int expectedArr[] = { -11, 1, 3, 5, 7, 8 };

    Algorithms::quickSort(arr, 0, 6);
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST(algorithms, bubbleSort) {
    int arr[] = { 5, 7, -11, 3, 8, 1 };
    int expectedArr[] = { -11, 1, 3, 5, 7, 8 };

    Algorithms::bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST(algorithms, heapSort) {
    int arr[] = { 5, 7, -11, 3, 8, 1 };
    int expectedArr[] = { -11, 1, 3, 5, 7, 8 };

    Algorithms::heapSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST(algorithms, bogoSort) {
    int arr[] = { 5, 7, -11 };
    int expectedArr[] = { -11, 5, 7 };

    Algorithms::bogoSort(arr, 3);
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST(algorithms, countingSort) {
    char arr[] = { 5, 7, 3, 8, 1 };
    char expectedArr[] = { 1, 3, 5, 7, 8 };

    Algorithms::countSort(arr, 5);
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

TEST(algorithms, quickSortSpeedTest) {
    std::cout.precision(17);
    int arr1[10];
    for (int & i : arr1) {
        i = rand() % 50;
    }
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        double startTime = clock();
        Algorithms::quickSort(arr1, 0, 10);
        double endTime = clock();
        sum += (endTime - startTime) / 1000;
    }
    std::cout << "\nQUICK SORT 10 ITEMS " << sum / 10 << " s\n";

    int arr2[100];
    for (int & i : arr2) {
        i = rand() % 50;
    }
    sum = 0;
    for (int i = 0; i < 10; i++) {
        double startTime = clock();
        Algorithms::quickSort(arr2, 0, 100);
        double endTime = clock();
        sum += (endTime - startTime) / 1000;
    }
    std::cout << "QUICK SORT 100 ITEMS " << sum / 10 << " s\n";

    int arr3[1000];
    for (int & i : arr3) {
        i = rand() % 50;
    }
    sum = 0;
    for (int i = 0; i < 10; i++) {
        double startTime = clock();
        Algorithms::quickSort(arr3, 0, 1000);
        double endTime = clock();
        sum += (endTime - startTime) / 1000;
    }
    std::cout << "QUICK SORT 1000 ITEMS " << sum / 10 << " s\n";

    int arr4[10000];
    for (int & i : arr4) {
        i = rand() % 50;
    }
    sum = 0;
    for (int i = 0; i < 10; i++) {
        double startTime = clock();
        Algorithms::quickSort(arr4, 0, 10000);
        double endTime = clock();
        sum += (endTime - startTime) / 1000;
    }
    std::cout << "QUICK SORT 10000 ITEMS " << sum / 10 << " s\n";
}


//TEST(heap, insert) {
//    auto *heap = new Heap();
//    for (int i = 0; i < 10; i++) {
//        heap->insert(i);
//        EXPECT_TRUE(heap->contains(i));
//    }
//    EXPECT_FALSE(heap->contains(10));
//}
//
//TEST(heap, contains) {
//    auto *heap = new Heap();
//    EXPECT_FALSE(heap->contains(0));
//    heap->insert(0);
//    EXPECT_TRUE(heap->contains(0));
//}
//
//TEST(heap, remove) {
//    auto *heap = new Heap();
//    heap->remove(0);
//    for (int i = 0; i < 10; i++) {
//        heap->insert(i);
//        EXPECT_TRUE(heap->contains(i));
//    }
//
//    heap->remove(6);
//    EXPECT_FALSE(heap->contains(6));
//    heap->remove(3);
//    EXPECT_FALSE(heap->contains(3));
//}
//
//TEST(heap, dft_iterator) {
//    auto *heap = new Heap();
//    for (int i = 0; i < 10; i++) {
//        heap->insert(i);
//    }
//
//    int dftArray[] = {9, 8, 6, 0, 3, 7, 2, 5, 1, 4};
//    Iterator *iterator = heap->create_dft_iterator();
//
//    for (int i = 0; i < 10; i++) {
//        EXPECT_TRUE(iterator->has_next());
//        EXPECT_EQ(iterator->next()->get_data(),dftArray[i]);
//    }
//
//    EXPECT_FALSE(iterator->has_next());
//    try {
//        iterator->next();
//    } catch (std::exception &err) {
//        EXPECT_STREQ(err.what(), "Hasn't next element");
//    }
//}
//
//TEST(heap, bft_iterator) {
//    auto *heap = new Heap();
//    for (int i = 0; i < 10; i++) {
//        heap->insert(i);
//    }
//
//    int bftArray[] = {9, 8, 5, 6, 7, 1, 4, 0, 3, 2};
//    Iterator *iterator = heap->create_bft_iterator();
//
//    for (int i = 0; i < 10; i++) {
//        EXPECT_TRUE(iterator->has_next());
//        EXPECT_EQ(iterator->next()->get_data(),bftArray[i]);
//    }
//
//    EXPECT_FALSE(iterator->has_next());
//    try {
//        iterator->next();
//    } catch (std::exception &err) {
//        EXPECT_STREQ(err.what(), "Hasn't next element");
//    }
//}
