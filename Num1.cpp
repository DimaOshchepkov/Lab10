// Num1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "array.h"

int main()
{
    int n, m, z;
    bool flag = true, haveElement = false;
    std::cout << "Input n and m:\n";
    std::cin >> n >> m;
    int k = n;
    int** arr;
    int** strightArr;
    int** arr2;
    int* arr1d;
    arr = fillArr(createArr(n, m), n, m);
    printArr(arr, n, m);
    enum TASK {
        EXIT, FILLARR09, COUNT_ENTRY, CREATE_ARR_1D, MAX_MOD_COLUMN, CONVERT_ARR, SEARCH_ROW,
        MAX_IN_OBLAST, EQUAL_ELEMENTS, REVERSE_ROW, SUDOKU, SNAKE_A, SNAKE_B, DELETE_ROW,
        DELETE_ROWS_WHITH_ELEMENT, CREATE_STRIGHT_ARR, CLEAN_CONSOL
    };
    while (flag)
    {
        std::cout << "1)fillArr09\n2)countEntry\n3)crateArr1d\n4)maxModColumn\n5)convetArr\n6)searchRow\n7)maxInOblast\n";
        std::cout << "8)equalElements\n9)reverseRow\n10)sudoku\n11)snakeA\n12)snakeB\n13)deleteRow\n";
        std::cout << "14)deleteRowsWithElement\n15)createstrightArr\n0)exit\n";
        std::cin >> z;
        switch (z)
        {
        case TASK::FILLARR09:
            arr = fillArr09();
            printArr(arr, 10, 10);
            break;
        case TASK::COUNT_ENTRY:
            int num;
            std::cout << "Input number = ";
            std::cin >> num;
            (countEntry(arr, n, m, num) != 0) ? std::cout << countEntry(arr, n, m, num) << '\n' :
                std::cout << "No such elements in the array";
            break;
        case TASK::CREATE_ARR_1D:
            arr1d = crateArr1d(arr, n, m);
            printArr1d(arr1d, n);
            break;
        case TASK::MAX_MOD_COLUMN:
            printColumn(arr, n, m);
            break;
        case TASK::CONVERT_ARR:
            arr = convertArr(arr, n, m);
            printArr(arr, n, m);
            break;
        case TASK::EXIT:
            flag = false;
            deleteArr(arr, n);
            break;
        case TASK::MAX_IN_OBLAST:
            if (n != m)
            {
                std::cout << "Need square matrix, the program will take the mattress:\n";
                if (n < m)
                    k = n;
                else
                    k = m;
                std::cout << k << " X " << k;
            }
            std::cout << maxInOblast(arr, k);
            break;
        case TASK::SEARCH_ROW:
            (searchRow(arr, n, m) != -1) ? std::cout << "Growing row number " << searchRow(arr, n, m) << '\n' :
                std::cout << "Not growing row\n";
            break;
        case TASK::EQUAL_ELEMENTS:
            std::cout << "First ";
            printArr(arr, n, m);
            arr2 = fillArr(createArr(n, m), n, m);
            std::cout << "Second ";
            printArr(arr2, n, m);
            equalElements(arr, arr2, n, m);
            break;
        case TASK::REVERSE_ROW:
            reverseRow(arr, n);
            printArr(arr, n, m);
            break;
        case TASK::SUDOKU:
            if (n != m)
            {
                std::cout << "Need square matrix k = 2x + 1, the program will take the mattress:\n";
                if (n < m)
                    k = n;
                else
                    k = m;
                if (k % 2 != 1)
                    k -= 1;
                std::cout << k << " X " << k;
            }
            arr = sudoku(arr, k);
            std::cout << "Square ";
            printArr(arr, k, k);
            break;
        case TASK::SNAKE_A:
            arr = snakeA(arr, n, m);
            printArr(arr, n, m);
            break;
        case TASK::SNAKE_B:
            arr = snakeB(arr, n, m);
            printArr(arr, n, m);
            break;
        case TASK::DELETE_ROW:
            std::cin >> k;
            arr = deleteRow(arr, &n, k);
            printArr(arr, n, m);
            break;
        case TASK::DELETE_ROWS_WHITH_ELEMENT:
            std::cin >> k;
            std::tie(arr, haveElement) = deleteRowsWithElement(arr, &n, m, k);
            if (haveElement)
                printArr(arr, n, m);
            else
                std::cout << "No element equaval " << k << '\n';
            break;
        case TASK::CREATE_STRIGHT_ARR:
            std::cin >> k;
            strightArr = createStrightArr(k);
            printStrightArr(strightArr, k);
            deleteArr(strightArr, k);
            break;
        }
        std::cout << "Do you want to clean consol?(input 16)\n";
        std::cin >> z;
        if (TASK::CLEAN_CONSOL == z) 
        {
            system("cls");
            printArr(arr, n, m);
        }
    }
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
