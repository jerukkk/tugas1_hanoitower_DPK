#include <stdio.h>

// Fungsi rekursif untuk memindahkan cakram
void hanoi(int n, char asal, char tujuan, char bantu) {
    if (n == 1) {
        // Pindahkan cakram terakhir dari tiang asal ke tiang tujuan
        printf("Pindahkan cakram 1 dari %c ke %c\n", asal, tujuan);
        return;
    }

    // Langkah 1: Pindahkan n-1 cakram dari tiang asal ke tiang bantu
    hanoi(n - 1, asal, bantu, tujuan);

    // Langkah 2: Pindahkan cakram terakhir dari tiang asal ke tiang tujuan
    printf("Pindahkan cakram %d dari %c ke %c\n", n, asal, tujuan);

    // Langkah 3: Pindahkan n-1 cakram dari tiang bantu ke tiang tujuan
    hanoi(n - 1, bantu, tujuan, asal);
}

int main() {
    int n;

    printf("Masukkan jumlah cakram: ");
    scanf("%d", &n);

    printf("Langkah-langkah untuk menyelesaikan Tower of Hanoi:\n");
    hanoi(n, 'A', 'C', 'B');  // Asumsi: A = tiang asal, C = tiang tujuan, B = tiang bantu

    return 0;
}
