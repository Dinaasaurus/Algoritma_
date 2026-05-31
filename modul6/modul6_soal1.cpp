#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

int main()
{
    int pilihan;

    do {
        clrscr();
        cout << "===============================\n";
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;
        cout << "===============================\n\n";

        switch (pilihan) {
            case 1: {
                int data[100];
                int cari = 20;
                int counter = 0;
                int flag = 0;
                int save;
                
                randomize();
                printf("generating 100 number ...\n");
                for (int i = 0; i < 100; i++)
                {
                    data[i] = random(100);
                    printf("%d ", data[i]);
                }
                printf("\ndone.\n");

                for (int i = 0; i < 100; i++)
                {
                    if (data[i] == cari)
                    {
                        counter++;
                        flag = 1;
                        save = i;
                    }
                }
                
                if (flag == 1)
                {
                    printf("data ada, sebanyak %d!\n", counter);
                    printf("pada index ke %d\n", save);
                }
                else
                {
                    printf("data tidak ada!\n");
                }
                break;
            }
            case 2: {
                int n, kiri, kanan, tengah, temp, key;
                bool ketemu = false;

                cout << "Masukan jumlah data? ";
                cin >> n;
                int angka[n];
                
                for (int i = 0; i < n; i++)
                {
                    cout << "Angka ke - [" << i << "] : ";
                    cin >> angka[i];
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n - 1; j++)
                    {
                        if (angka[j] > angka[j + 1])
                        {
                            temp = angka[j];
                            angka[j] = angka[j + 1];
                            angka[j + 1] = temp;
                        }
                    }
                }
                
                cout << "---------------------------------------\n";
                cout << "Data yang telah diurutkan adalah:\n";
                for (int i = 0; i < n; i++)
                {
                    cout << angka[i] << " ";
                }
                cout << "\n---------------------------------------\n";
                
                cout << "Masukan angka yang dicari: ";
                cin >> key;

                kiri = 0;
                kanan = n - 1;
                while (kiri <= kanan)
                {
                    tengah = (kiri + kanan) / 2;
                    if (key == angka[tengah])
                    {
                        ketemu = true;
                        break;
                    }
                    else if (key < angka[tengah])
                    {
                        kanan = tengah - 1;
                    }
                    else
                    {
                        kiri = tengah + 1;
                    }
                }
                
                if (ketemu == true)
                {
                    cout << "Angka ditemukan!\n";
                }
                else
                {
                    cout << "Angka tidak ditemukan!\n";
                }
                break;
            }
            case 3:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
        if (pilihan != 3) {
            cout << "\n";
            system("pause");
        }
        
    } while (pilihan != 3);

    return 0;
}