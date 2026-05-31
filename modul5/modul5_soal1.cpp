#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertionSort(string& arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(string& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = arr.substr(l, n1);
    string R = arr.substr(m + 1, n2);
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void shellSort(string& arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(string& arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(string& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(string& arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(string& arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int pilihan;
    string inputData;

    do {
        cout << "-------------------------------\n";
        cout << "            SORTING            \n";
        cout << "-------------------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "-------------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                getline(cin, inputData);
                insertionSort(inputData);
                cout << "[Insertion Sort] Hasil: " << inputData << "\n\n";
                break;
            case 2:
                cout << "Masukkan Nama: ";
                getline(cin, inputData);
                mergeSort(inputData, 0, inputData.length() - 1);
                cout << "[Merge Sort] Hasil: " << inputData << "\n\n";
                break;
            case 3:
                cout << "Masukkan Nama: ";
                getline(cin, inputData);
                shellSort(inputData);
                cout << "[Shell Sort] Hasil: " << inputData << "\n\n";
                break;
            case 4:
                cout << "Masukkan NIM: ";
                getline(cin, inputData);
                quickSort(inputData, 0, inputData.length() - 1);
                cout << "[Quick Sort] Hasil: " << inputData << "\n\n";
                break;
            case 5:
                cout << "Masukkan NIM: ";
                getline(cin, inputData);
                bubbleSort(inputData);
                cout << "[Bubble Sort] Hasil: " << inputData << "\n\n";
                break;
            case 6:
                cout << "Masukkan NIM: ";
                getline(cin, inputData);
                selectionSort(inputData);
                cout << "[Selection Sort] Hasil: " << inputData << "\n\n";
                break;
            case 7:
                break;
            default:
                cout << "Pilihan tidak valid.\n\n";
        }
    } while (pilihan != 7);

    return 0;
}