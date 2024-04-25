#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Insertion Sort
template<typename T>
static int insertionSort(vector<T>& arr) {
    int n = arr.size() , count = 0 ;
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            count++;
        }
        arr[j + 1] = key;
    }
    return count ;
}

// Selection Sort
template<typename T>
static int selectionSort(vector<T>& arr) {
    int n = arr.size() , count = 0 ;
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            count++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return count ;
}

// Bubble Sort
template<typename T>
static int bubbleSort(vector<T>& arr) {
    int n = arr.size() , count = 0 ;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return count ;
}

// Shell Sort
template<typename T>
static int shellSort(vector<T>& arr) {
    int n = arr.size() , count = 0 ;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp ; j -= gap) {
                count++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return count ;
}

// Merge Sort
template<typename T>
static void merge(vector<T>& arr, int l, int m, int r , int& count) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        count++;
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

template<typename T>
static void mergeSortHelper(vector<T>& arr, int l, int r , int& count) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortHelper(arr, l, m , count);
        mergeSortHelper(arr, m + 1, r , count);

        merge(arr, l, m, r , count);
    }
}

template<typename T>
static int mergeSort(vector<T>& arr) {
    int count = 0 ;
    mergeSortHelper(arr, 0, arr.size() - 1 , count);
    return count ;
}


// Quick Sort
template<typename T>
static int partition(vector<T>& arr, int low, int high , int& count) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
            count++;
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
static void quickSortHelper(vector<T>& arr, int low, int high , int& count) {
    if (low < high) {
        int pi = partition(arr, low, high , count);
        quickSortHelper(arr, low, pi - 1, count);
        quickSortHelper(arr, pi + 1, high, count);
    }
}

template<typename T>
static int quickSort(vector<T>& arr) {
    int count = 0 ;
    quickSortHelper(arr, 0, arr.size() - 1 , count);
    return count ;
}

// Count Sort
static void CountSort(vector<int>& arr){
    int n = arr.size() ;
    int mx = *max_element(arr.begin() , arr.end());
    if (mx >= 5000006) return void (cout << "This algorithm is not obtimal for this list , try other algorithm") ;
    vector<int> count(mx+1) , sort_arr(n);
    for(int vl : arr){
        count[vl]++;
    }
    for(int i = 1 ; i <= mx ;i++){
        count[i] += count[i-1];
    }
    for(int i = n-1 ; i >= 0 ; i--){
        sort_arr[--count[arr[i]]] = arr[i];
    }
    for(int i = n-1 ; i >= 0 ; i--){
        arr[i] = sort_arr[i];
    }
}