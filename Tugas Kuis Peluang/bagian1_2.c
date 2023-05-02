#include <stdio.h>
#include <math.h>

int main(){
    // deklarasi variabel
    int jumlah_mobil = 1; // asumsikan melihat 1 mobil
    float prob_mobil;
    int waktu;
    double lambda, peluang, persentase;

    // input
    system("cls");
    printf("Masukkan nilai peluang melihat mobil dalam 30 menit: ");
    scanf("%f", &prob_mobil);
    printf("Masukkan waktu dalam satuan menit: ");
    scanf("%d", &waktu);

    // proses
    lambda = prob_mobil * waktu / 30;
    peluang = exp(-lambda) * pow(lambda, jumlah_mobil) / tgamma(jumlah_mobil+1); // menghitung peluang dengan distribusi poison
    persentase = peluang * 100; // menghitung persentase

    // output
    printf("\nPeluang melihat %d mobil dalam %d menit: %.4f", jumlah_mobil, waktu, peluang);
    printf("\nPersentase melihat %d mobil dalam %d menit: %.2f%%", jumlah_mobil, waktu, persentase);

    return 0;
}
