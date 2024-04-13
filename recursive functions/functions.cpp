#include <iostream>
#include <time.h>
#include <iomanip>
#include <limits.h>

using namespace std;

int searchMin(int* massiv, int massivSize, int startIndex, int& min);
void initAndPrintMassiv(int* massiv, int massivSize);
void searchMax(int* massiv, int massivSize);
void searchMax(int massiv[][3], int massivSize, int secondSize);
void searchMax(int massiv[][2][2], int massivSize, int secondSize, int thirdSize);
void searchMax(int number1, int number2);
void searchMax(int number1, int number2, int number3);




int main()
{
    
    setlocale(LC_ALL, "RU");
    srand((int)time(NULL));
    int const massivSize = 100;
    int massiv[massivSize];
    int min = INT_MAX;
    initAndPrintMassiv(massiv, massivSize);
    searchMin(massiv, massivSize, 0, min);
    std::cout << "минимальное число = " << min << endl;
    return 0;
}

int searchMin(int* massiv, int massivSize, int startIndex, int& min)
{
    int localMin = 0;
    if (startIndex + 9 == massivSize)
    {
        return 0;
    }
    for (int i = startIndex; i < startIndex + 10; i++)
    {
        localMin += massiv[i];
    }
    if (localMin < min)
    {
        min = localMin;
    }
   
    return searchMin(massiv, massivSize, startIndex + 1, min);
}


void initAndPrintMassiv(int* massiv, int massivSize)
{
    for (int i = 0; i < massivSize; i++)
    {
        *(massiv + i) = rand() % 101;
        std::cout << fixed << setw(4) << *(massiv + i) << " ";
        if (i % 10 == 9)
        {
            std::cout << endl;
        }
    }
}
//задача 2
int const massivSize = 10;
int const massivSize2 = 3;
int const massivSize3 = 2;
int massiv1[massivSize] = {1,2,3,4,5,6,7,8,9,10 };
int massiv2[massivSize2][massivSize2] = { {8,7,6},{5,4,3},{2,1,9} };
int massiv3[massivSize3][massivSize3][massivSize3] = { {{2,2},{3,3}},{{4,8},{8,7}} };
int number1 = 2;
int number2 = 4;
int number3 = 6;
void searchMax(int* massiv, int massivSize)
{
    std::cout << "нахождение значения в одномерном массиве" << endl <<
        "    ";
    int max = massiv[0];
    int index = 0;
    for (int i = 0; i < massivSize; i++)
    {
        cout << massiv[i] << " ";
        if (massiv[i] > max)
        {
            max = massiv[i];
            index = i;
        }
    }
    std::cout << endl << "  максимальный элемент в масссиве[" << index << "] = " << max << endl << endl;
}

void searchMax(int massiv[][3], int massivSize, int secondSize)
{
    std::cout << "нахождение максимального значения в двухмерном массиве" <<
        endl << "   Array:" << endl << "   ";
    int max = massiv[0][0];
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < massivSize; i++)
    {
        for (int j = 0; j < secondSize; j++)
        {
            std::cout << massiv[i][j] << " ";
            if (massiv[i][j] > max)
            {
                max = massiv[i][j];
                index1 = i;
                index2 = j;
            }
        }
        std::cout << endl << "   ";
    }
    std::cout << "максимальный элемент массива равен[" << index1 << "][" << index2 << "] = " << max << endl << endl;
}

void searchMax(int massiv[][2][2], int massivSize, int secondSize, int thirdSize)
{
    std::cout << "нахождение максимального значения в массиве" << endl;
    int max = massiv[0][0][0];
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    for (int i = 0; i < massivSize; i++)
    {
        for (int j = 0; j < secondSize; j++)
        {
            for (int k = 0; k < thirdSize; k++)
            {
                if (massiv[i][j][k] > max)
                {
                    max = massiv[i][j][k];
                    index1 = i;
                    index2 = j;
                    index3 = k;
                }
            }
        }
    }
    std::cout << "   максимальный элемент массива равен[" << index1 << "][" << index2 << "][" <<
        index3 << "] = " << max << endl << endl;
}

void searchMax(int number1, int number2)
{
    cout << "нахождение макимального значения между двух переменных" << endl << "   " << number1;
    if (number1 > number2)
    {
        cout << " > ";
    }
    else if (number1 < number2)
    {
        cout << " < ";
    }
    else
    {
        cout << " = ";
    }
    cout << number2 << endl << endl;
}

void searchMax(int number1, int number2, int number3)
{
    cout << "нахождение максимального значения между переменными" << endl;

    int max = number1;
    if (number1 > number2)
    {
        if (number1 >= number3)
        {
            max = number1;
        }
        else
        {
            max = number3;
        }
    }
    else if (number1 < number2)
    {
        if (number2 >= number3)
        {
            max = number2;
        }
        else
        {
            max = number3;
        }
    }
    else
    {
        if (number2 >= number3)
        {
            max = number2;
        }
        else
        {
            max = number3;
        }
    }

    std::cout << "   максимальное между : " << number1 << " " << number2 << " " <<
        number3 << " = " << max << endl << endl;
}

