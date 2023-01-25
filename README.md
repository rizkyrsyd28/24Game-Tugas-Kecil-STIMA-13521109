# 24 SOLVER - "24 SOLVER, BUKAN POKER"
> Program dibuat untuk memenuhi tugas Kecil 1 IF2211 Strategi Algoritma

## Deskripsi Program
Program digunakan untuk menyelesaikan **permainan kartu 24**. Tujuan dari permainan kartu 24 adalah menghasilkan nilai 24 dari 4 karty yang diberikan menggunakan operasi matematika penjumahan (+), pengurangan (-), perkalian (*), pembagian (/), dan kurung (()). Program ini menggunakan ***Algoritma Brute-Force*** dengan bahasa pemrograman C++. Program akan menghasilkan semua kemungkinan solusi dari 4 masukan kartu dari user maupun masukan random, masukan user berupa nilai pada kartu remi (A/1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J/11, Q/12, K/13). Setelah ditemukan solusi program dapat disimpal dalam file .txt. 


## Struktur Program
    .
    ├── bin
    |   └── main                     
    ├── docs
    |   └── Laporan_Tucil1_IF2211_13521109.pdf
    ├── input                   
    │   ├── input1.txt         
    │   ├── input2.txt         
    │   └── input3.txt            
    ├── src                
    │   ├── 24game.cpp       
    │   ├── iosystem.cpp       
    │   └── main.cpp          
    ├── test                   
    │   ├── output1.txt         
    │   ├── output2.txt         
    │   └── output3.txt     
    └── README.md

## Requirement
- GNU g++ compiler
- STL (standard template library)

## Langkah Penggunaan Program
### Linux
1. `cd bin`
2. `g++ ../src/main.cpp -o <nama executable>`. contoh :  `g++ main.cpp -o main`
3. `./main`

### Windows
1. `cd bin`
2. `g++ ../src/main.cpp -o <nama executable>`. contoh :  `g++ main.cpp -o main`
3. `main.exe`

## Author
Rizky Abdillah Rasyid / 13521109