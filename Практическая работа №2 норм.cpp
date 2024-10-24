#include <iostream>
#include <chrono>
using namespace std;

void InputCheck(int &number)
{
    while (cin.fail())
    {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Введите ЧИСЛО" << endl;
        cin >> number;
    }
}

void BubbleSort(int Array[], int N)
{
    bool swapped = true;
    int j = 0;

    while (swapped)
    {
        swapped = false;
        for (int i = 0; i != N - j - 1; ++i)
        {
            if (Array[i] > Array[i + 1])
            {
                swap(Array[i], Array[i + 1]);
                swapped = true;
            }
        }
        j++;
    }
}

void ShakerSort(int Array[], int N)
{
    int start = 0, end = N - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i != end; ++i)
        {
            if (Array[i] > Array[i + 1])
            {
                swap(Array[i], Array[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end; i != start; --i)
        {
            if (Array[i] < Array[i - 1])
            {
                std::swap(Array[i], Array[i - 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void CombSort(int Array[], int N)
{
    bool swapped = true;
    int j = 0;
    float S = N - 1, k = 1.247;

    while (S >= 1)
    {
        for (int i = 0; i + S < N; ++i)
        {
            if (Array[i] > Array[int(i + S)])
                swap(Array[i], Array[int(i + S)]);
        }
        S /= k;
    }

    while (swapped)
    {
        swapped = false;
        for (int i = 0; i != N - j - 1; ++i)
        {
            if (Array[i] > Array[i + 1])
            {
                swap(Array[i], Array[i + 1]);
                swapped = true;
            }
        }
        j++;
    }
}

void InsertSort(int Array[], int N)
{
    int key, j;

    for (int i = 1; i != N; ++i)
    {
        key = Array[i];
        j = i - 1;

        while (j >= 0 && key < Array[j])
        {
            Array[j + 1] = Array[j];
            j -= 1;
        }
        Array[j + 1] = key;
    }
}

void QuickSort(int Array[], int start, int end)
{
    int mid, l = start, r = end;
    mid = Array[(l + r) / 2];

    while (l < r)
    {
        while (Array[l] < mid)
            l++;
        while (Array[r] > mid)
            r--;
        if (l <= r)
        {
            swap(Array[l], Array[r]);
            l++;
            r--;
        }
    }
    if (start < r)
        QuickSort(Array, start, r);
    if (end > l)
        QuickSort(Array, l, end);
}

int BinarySearch(int Array[], int value, int start, int end)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (Array[mid] == value)
            return mid;
        if (Array[mid] > value)
            return BinarySearch(Array, value, start, mid - 1);
        return BinarySearch(Array, value, mid + 1, end);
    }
    return -1;
}

int BinarySearchFirstOccurrence(int Array[], int value, int start, int end)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (Array[mid] == value)
        {
            while (Array[mid - 1] == value && mid - 1 >= 0)
                mid -= 1;
            return mid;
        }
        if (Array[mid] > value)
            return BinarySearchFirstOccurrence(Array, value, start, mid - 1);
        return BinarySearchFirstOccurrence(Array, value, mid + 1, end);
    }
    return start;
}

int BinarySearchLastOccurrence(int Array[], int value, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (end >= start)
    {
        if (Array[mid] == value)
        {
            while (Array[mid + 1] == value && mid + 1 <= end)
                mid += 1;
            return mid;
        }
        if (Array[mid] > value)
            return BinarySearchLastOccurrence(Array, value, start, mid - 1);
        return BinarySearchLastOccurrence(Array, value, mid + 1, end);
    }
    return start - 1;
}

int ElemSearch(int Array[], int value, int N)
{
    int X = -1;
    for (int i = 0; i < N; ++i)
    {
        if (Array[i] == value)
        {
            X = value;
            break;
        }
    }
    return X;
}

int MinSearch(int Array[], int N)
{
    int min = 101;
    for (int i = 0; i < N; ++i)
        min = Array[i] < min ? Array[i] : min;
    return min;
}

int MaxSearch(int Array[], int N)
{
    int max = 0;
    for (int i = 0; i < N; ++i)
        max = Array[i] > max ? Array[i] : max;
    return max;
}

int main()
{
    srand(time(0));
    setlocale(0, "");

    const int N = 100;
    int Array[N], sortedArray[N], select = 0;
    bool isSorted = false;
    chrono::nanoseconds duration;
    chrono::steady_clock::time_point start, end;
      
    cout << "Неотсортированный массив:" << endl;
    for (int i = 0; i < N; ++i)
    {
       Array[i] = -99.5 + rand() % 200;
       cout << Array[i] << " ";
    }
    cout << endl;

    cout << "1 - создать новый неотсортированный массив\n" << 
        "2 - отсортировать массив\n" << 
        "3 - найти максимальный и минимальный элементы массива\n" <<
        "4 - найти среднее значение максимального и минимального элементов, а также вывести индексы элементов, равных этому и значению и их количество\n" <<
        "5 - найти количество элементов в отсортированном массиве, которые меньше числа A\n" <<
        "6 - найти количество элементов в отсортированном массиве, которые больше числа B\n" <<
        "7 - вывести информацию о том, есть ли число X в массиве\n" << 
        "8 - поменять местами два элемента\n" <<
        "9 - показать текущее состояние массивов" << endl;

    while (true)
    {
        cin >> select;
        InputCheck(select);
        switch (select)
        {
        case 1:
            cout << "Неотсортированный массив:" << endl;
            for (int i = 0; i < N; ++i)
            {
                Array[i] = -99.5 + rand() % 200;
                cout << Array[i] << " ";
            }
            cout << endl;
            isSorted = false;
            break;
        case 2:
        {
            isSorted = false;
            cout << "1 - Bubble sort\n2 - Shaker sort\n3 - Comb sort\n4 - Insert sort\n5 - Quick sort" << endl;
            for (int i = 0; i < N; ++i)
                sortedArray[i] = Array[i];

            cout << "Введите номер алгоритма" << endl;
            int numberOfAlgorithm;
            cin >> numberOfAlgorithm;
            InputCheck(numberOfAlgorithm);
            while (!isSorted)
            {
                switch (numberOfAlgorithm)
                {
                case 1:
                    isSorted = true;
                    start = chrono::steady_clock::now();
                    BubbleSort(sortedArray, N);
                    end = chrono::steady_clock::now();
                    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    break;

                case 2:
                    isSorted = true;
                    start = chrono::steady_clock::now();
                    ShakerSort(sortedArray, N);
                    end = chrono::steady_clock::now();
                    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    break;

                case 3:
                    isSorted = true;
                    start = chrono::steady_clock::now();
                    CombSort(sortedArray, N);
                    end = chrono::steady_clock::now();
                    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    break;

                case 4:
                    isSorted = true;
                    start = chrono::steady_clock::now();
                    InsertSort(sortedArray, N);
                    end = chrono::steady_clock::now();
                    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    break;

                case 5:
                    isSorted = true;
                    start = chrono::steady_clock::now();
                    QuickSort(sortedArray, 0, N - 1);
                    end = chrono::steady_clock::now();
                    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    break;

                default:
                    cout << "Алгоритма с такими номером нет. Введите другое число." << endl;
                }
            }
            if (isSorted)
            {
                cout << "Отсортированный массив:" << endl;
                for (int i = 0; i != N; ++i)
                    cout << sortedArray[i] << " ";
                cout << endl << "Алгоритм занял " << duration.count() << " нс" << endl;
            }
            break;
        }
        case 3:
        {
            if (isSorted)
            {
                start = chrono::steady_clock::now();
                int min = MinSearch(Array, N);
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Поиск минимального элемента в неотсортированном массиве занял " << duration.count() << " нс" << endl;

                start = chrono::steady_clock::now();
                int max = MaxSearch(Array, N);
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Поиск максимального элемента в неотсортированном массиве занял " << duration.count() << " нс" << endl;

                start = chrono::steady_clock::now();
                min = sortedArray[0];
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Поиск минимального элемента в отсортированном массиве занял " << duration.count() << " нс" << endl;

                start = chrono::steady_clock::now();
                max = sortedArray[N - 1];
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Поиск максимального элемента в отсортированном массиве занял " << duration.count() << " нс" << endl;

                cout << "Максимальный элемент: " << max << "\nМинимальный элемент: " << min << endl;
            }
            else
                cout << "Сначала надо отсортировать массив" << endl;
            break;
        }
        case 4:
        {   
            if (isSorted)
            {
                int number = 0, mid;
                double dMid = static_cast<double>((sortedArray[N - 1] + sortedArray[0])) / 2;
                cout << "Точное среднее значение: " << dMid << endl;
                if (dMid > 0)
                    mid = dMid + 0.5;
                else
                    mid = dMid - 0.5;
                cout << "Округленное среднее значение: " << mid << endl;
                cout << "Индексы элементов, равных этому значению в неотсортированном массиве: ";
                start = chrono::steady_clock::now();
                for (int i = 0; i < N; ++i)
                {
                    if (Array[i] == mid)
                    {
                        cout << i << " ";
                        number++;
                    }
                }
                end = chrono::steady_clock::now();
                if (!number)
                    cout << "-" << endl;
                else cout << endl;
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Время поиска: " << duration.count() << " нс" << endl;

                number = 0;
                cout << "Индексы элементов, равных этому значению в отсортированном массиве: ";
                int j = 0;
                start = chrono::steady_clock::now();
                while (sortedArray[j] <= mid)
                {
                    if (sortedArray[j] == mid)
                    {
                        cout << j << " ";
                        number++;
                    }
                    j++;
                }
                end = chrono::steady_clock::now();
                if (!number)
                    cout << "-" << endl;
                else cout << endl;
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Время поиска: " << duration.count() << " нс" << endl;
                cout << "Количество таких элементов: " << number << endl;
            }
            else
                cout << "Сначала надо отсортировать массив" << endl;
            break;
        }
        case 5:
        {
            if (isSorted)
            {
                int A;
                cout << "Введите число a" << endl;
                cin >> A;
                InputCheck(A);
                int indexA = BinarySearchFirstOccurrence(sortedArray, A, 0, N - 1);
                cout << "Количество элементов, которые меньше a: " << indexA << endl;
            }
            else
                cout << "Сначала надо отсортировать массив" << endl;
            break;
        }
        case 6:
        {
            if (isSorted)
            {
                int B;
                cout << "Введите число B" << endl;
                cin >> B;
                InputCheck(B);
                int indexB = BinarySearchLastOccurrence(sortedArray, B, 0, N - 1);
                cout << "Количество элементов, которые больше b: " << N - indexB - 1 << endl;
            }
            else
                cout << "Сначала надо отсортировать массив" << endl;
            break;
        }
        case 7:
        {
            if (isSorted)
            {
                int X;
                cout << "Введите число X" << endl;
                cin >> X;
                InputCheck(X);
                start = chrono::steady_clock::now();
                int xInArray = BinarySearch(sortedArray, X, 0, N - 1);
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                if (xInArray == -1)
                    cout << "Числа X нет в массиве" << endl;
                else
                    cout << "Число X есть в массиве" << endl;
                cout << "Алгоритм бинарного поиска занял " << duration.count() << " нс" << endl;
                start = chrono::steady_clock::now();
                xInArray = ElemSearch(Array, X, N);
                end = chrono::steady_clock::now();
                duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "Алгоритм перебора занял " << duration.count() << " нс" << endl;
            }
            else
                cout << "Сначала надо отсортировать массив" << endl;
            break;
        }
        case 8:
        {
            int p, q;
            cout << "Введите индекс первого элемента" << endl;
            cin >> p;
            InputCheck(p);

            cout << "Введите индекс второго элемента" << endl;
            cin >> q;
            InputCheck(q);

            start = chrono::steady_clock::now();
            swap(sortedArray[p], sortedArray[q]);
            end = chrono::steady_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            for (int i = 0; i < N; ++i)
                cout << sortedArray[i] << " ";
            cout << endl << "Обмен занял " << duration.count() << " нс" << endl;
            if (p != q)
                isSorted = false;
            break;
        }     
        case 9:
            cout << "Неотсортированный массив:" << endl;
            for (int i = 0; i < N; ++i)
                cout << Array[i] << " ";
            cout << endl;
            cout << "Отсортированный массив:" << endl;
            for (int i = 0; i < N; ++i)
                cout << sortedArray[i] << " ";
            cout << endl;
            break;

        case 666:
            return 0;

        default:
            cout << "Нет команды с таким номером" << endl;
        }
    }
}