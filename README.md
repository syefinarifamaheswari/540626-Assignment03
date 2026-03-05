Syefina Rifa' Maheswari
24/540626/TK/60030

Brief Description for each Solution

(Problem 1 : Algorithm Analysis)
Solusi ini menganalisis tiga potongan kode menggunakan standard cost model, di mana setiap assignment, perbandingan, operasi aritmatika, dan akses array bernilai 1 unit biaya.
Untuk setiap snippet dilakukan:
1. Perhitungan exact operation count T(n) dengan anotasi baris dan jumlah eksekusi.
2. Penyederhanaan asimtotik untuk memperoleh Big-O.
3. Analisis perbedaan best case dan worst case.
### Ringkasan Hasil :
- **Snippet A**  
  Loop bersarang dengan pola segitiga, total iterasi inner loop = n(n−1)/2. 
  Kompleksitas: O(n²).  
  Best case = Worst case (jumlah iterasi selalu sama).
- **Snippet B**  
  Pola binary search, ruang pencarian dibagi dua setiap iterasi (⌊log₂ n⌋ + 1 iterasi).  
  Kompleksitas: O(log n).  
  Best case O(1), worst case O(log n).
- **Snippet C**  
  Tiga loop bersarang, dengan loop terdalam berjalan ⌈n/2⌉ kali.  
  Kompleksitas: O(n³).  
  Best case = Worst case (tidak ada early termination).
Analisis menunjukkan bahwa struktur loop dan pola pengulangan menentukan kelas kompleksitas algoritma.

(Problem 2 : DynArray i Procedural Implementation)
Program ini mengimplementasikan resizable array menggunakan `struct` dan free functions (tanpa class, template, atau `std::vector`).
### Konsep Utama
Struktur `DynArray` memiliki:
- `int* data` → pointer ke memori heap
- `int size` → jumlah elemen aktif
- `int capacity` → kapasitas maksimum saat ini
Array dimulai dengan kapasitas 2.  
Jika `size == capacity`, kapasitas akan digandakan (doubling strategy):
1. Alokasi array baru (2× capacity)
2. Salin semua elemen lama
3. Hapus array lama (`delete[]`)
4. Update pointer dan capacity
Strategi ini membuat `pushBack()` memiliki kompleksitas O(1) amortized.
### Fungsi yang Diimplementasikan
- `initArray()` → inisialisasi array
- `freeArray()` → membebaskan memori (tidak ada memory leak)
- `pushBack()` → tambah elemen (O(1) amortized, O(n) saat resize)
- `insertAt()` → sisipkan elemen (O(n))
- `removeAt()` → hapus elemen (O(n))
- `getAt()` → akses elemen (O(1))
- `setAt()` → ubah elemen (O(1))
- `printDynArr()` → tampilkan isi array (O(n))
### Demonstrasi
Di `main()` seluruh fungsi diuji:
- Trigger resize melalui `pushBack`
- Penyisipan (`insertAt`) 
- Penghapusan (`removeAt`)
- Akses dan modifikasi elemen (`getAt`, `setAt`)
- Pembebasan memori dengan `freeArray`
### Compile & Run
bash g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
./problem2

(Problem 3 : Linear Search vs Binary Search)

### Part A - Implement
Program ini mengimplementasikan dan membandingkan dua algoritma pencarian:
1. **Linear Search**
   - Mencari elemen secara berurutan dari indeks 0 hingga n−1.
   - Mengembalikan indeks pertama jika ditemukan, atau −1 jika tidak ada.
   - Kompleksitas: O(n).
2. **Binary Search (Iterative)**
   - Bekerja pada array terurut.
   - Setiap iterasi membagi ruang pencarian menjadi setengah.
   - Menggunakan rumus midpoint aman:  
     `mid = lo + (hi - lo) / 2`
   - Kompleksitas: O(log n).
3. **generateSortedArray(n)**
   - Mengalokasikan array terurut berisi bilangan genap:  
     `{0, 2, 4, ..., 2(n-1)}`
   - Memori dialokasikan di heap dan dibebaskan dengan `delete[]`.
### Demonstrasi
Program diuji pada ukuran array:
- n = 10
- n = 100
- n = 1000
Untuk setiap ukuran:
- Mencari nilai yang ada (elemen di tengah array)
- Mencari nilai yang tidak ada
- Membandingkan hasil indeks dari Linear dan Binary Search
- Memastikan kedua algoritma menghasilkan output yang sama
### Tujuan
Menunjukkan perbedaan pendekatan:
- Linear Search → pertumbuhan waktu linear
- Binary Search → pertumbuhan waktu logaritmik (lebih efisien untuk n besar)
### Compile & Run 
bash g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
./problem3

### Part B - Complexity Comparison Table
Solusi pada Part B ini melakukan analisis kompleksitas waktu untuk Linear Search dan Binary Search dalam kasus terbaik, terburuk, dan rata-rata. Linear Search memiliki kompleksitas O(n) pada rata-rata dan kasus terburuk, sedangkan Binary Search memiliki kompleksitas O(log n) karena setiap langkah mengurangi ruang pencarian menjadi setengah. Dari analisis pertumbuhan fungsi diperoleh bahwa pada kasus terburuk, Binary Search lebih efisien dibanding Linear Search untuk n ≥ 2, karena pertumbuhan logaritmik jauh lebih lambat dibanding pertumbuhan linear.

(Problem 4 : Amortized Analysis of pushBack
