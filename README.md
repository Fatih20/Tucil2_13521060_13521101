# Mencari Pasangan Titik Terdekat Dimensi N dengan Algoritma Divide and Conquer
## Deskripsi Program
Program ini merupakan program yang dapat menyelesaikan permasalahan _closest points problem_ dengan sejumlah titik di ruang dimensi N. Program ini menggunakan algoritma _divide and conquer_ untuk menyelesaikan permasalahan tersebut. Program ini dibuat untuk memenuhi tugas kecil 2 mata kuliah IF2211 Strategi Algoritma. 

## _Requirements_ dan Cara Penggunaan Program
### _Requirements_
Program ini menggunakan bahasa pemrograman C++, [matplotlib](https://matplotlib.org/) untuk visualisasi dari bahasa Python, dan juga CMake untuk _compile_ dan linking ke header C dari python sehingga requirements untuk program ini adalah:
- Compiler c++ ([MinGW](https://www.mingw-w64.org/))
- [Python (versi 3)](https://www.python.org/) dan install matplotlib
- [CMake (minimal versi 3.23)](https://cmake.org/)
### Kompilasi
  Program dapat di-_compile_ dengan cara:
```bash
cmake -G "Unix Makefiles" -B build
cd build
make
```
atau
```bash
cmake -G "MinGW Makefiles" -B build
cd build
make
```
Setelah itu, program dapat dijalankan dengan cara:

```bash
# Untuk Windows
./output.exe

# Untuk Linux
./output
```

## Author
Program ini dibuat oleh:
- 13521060 - Fatih Nararya R.I.
- 13521101 - Arsa Izdihar Islam