#pragma once
#include < iostream>
#include <tuple>
int** createArr(int n, int m);
int** fillArr(int** arr, int n, int m);
void printArr(int** arr, int n, int m);
int** fillArr09();
int countEntry(int** arr, int n, int m, int num);
void deleteArr(int** arr, int n);
void printColumn(int** arr, int n, int m);
int** convertArr(int** arr, int n, int m);
int* crateArr1d(int** arr, int n, int m);
void printArr1d(int* arr1d, int n);
int searchRow(int** arr, int n, int m);
int maxInOblast(int** arr, int k);
void equalElements(int** arr, int** arr2, int n, int m);
void reverseRow(int** arr, int n);
int** sudoku(int** arr, int k);
int** snakeA(int** arr, int n, int m);
int** snakeB(int** arr, int n, int m);
int** deleteRow(int** arr, int* n, int k);
std::tuple<int**, int> deleteRowsWithElement(int** arr, int* n, int m, int k);
int** createStrightArr(int k);
void printStrightArr(int** strightArr, int k);