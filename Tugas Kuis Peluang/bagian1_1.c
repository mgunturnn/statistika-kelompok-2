#include <stdio.h>

double jawabSoalA(double p_terlambat_lainnya){
    double p_tidakHujan_padat = 1 - p_terlambat_lainnya;
    return p_tidakHujan_padat;
}

double jawabSoalB(double p_hujan, double p_lalin_padat_hujan, double p_terlambat_hujan_padat, double p_tidakHujan, double p_lalin_tidakPadat_tidakHujan, double p_terlambat_tidakHujan_tidakPadat, double p_lalin_tidakPadat_hujan, double p_terlambat_lainnya, double p_lalin_padat_tidakHujan){
    double p_terlambat = (p_hujan * p_lalin_padat_hujan * p_terlambat_hujan_padat) + (p_tidakHujan * p_lalin_tidakPadat_tidakHujan * p_terlambat_tidakHujan_tidakPadat) + (p_hujan * p_lalin_tidakPadat_hujan * p_terlambat_lainnya) + (p_tidakHujan * p_lalin_padat_tidakHujan * p_terlambat_lainnya);
    return p_terlambat;
}

double jawabSoalC(double p_hujan, double p_lalin_padat_hujan, double p_terlambat_hujan_padat, double p_terlambat){
    double p_terlambat_hujan = (p_hujan * p_lalin_padat_hujan * p_terlambat_hujan_padat) / p_terlambat;
    return p_terlambat_hujan;
}

int main(){
    // deklarasi variabel
    double p_hujan, p_lalin_padat_hujan, p_lalin_padat_tidakHujan, p_terlambat_hujan_padat, p_terlambat_tidakHujan_tidakPadat, p_terlambat_lainnya;
    double p_tidakHujan, p_lalin_tidakPadat_hujan, p_lalin_tidakPadat_tidakHujan, p_tidakTerlambat_hujan_lalin_tidakPadat, p_tidakTerlambat_tidakHujan_lalin_padat, p_tidakTerlambat_lainnya;
    double p_tidakHujan_padat, p_terlambat, p_terlambat_hujan;

    // input
    system("cls");
    printf("Masukkan nilai probabilitas hujan turun pada suatu hari: ");
    scanf("%lf", &p_hujan);
    printf("Masukkan nilai probabilitas lalin padat jika hujan turun: ");
    scanf("%lf", &p_lalin_padat_hujan);
    printf("Masukkan nilai probabilitas lalin padat jika hujan tidak turun: ");
    scanf("%lf", &p_lalin_padat_tidakHujan);
    printf("Masukkan nilai probabilitas Andi terlambat jika hujan dan lalin padat: ");
    scanf("%lf", &p_terlambat_hujan_padat);
    printf("Masukkan nilai probabilitas Andi terlambat jika tidak hujan dan lalin tidak padat: ");
    scanf("%lf", &p_terlambat_tidakHujan_tidakPadat);
    printf("Masukkan nilai probabilitas Andi terlambat pada situasi lain (hujan dan lalin tidak padat / tidak hujan dan lalin padat): ");
    scanf("%lf", &p_terlambat_lainnya);

    // data tambahan
    // probabilitas hari tidak hujan
    p_tidakHujan = 1 - p_hujan;
    // probabilitas lalin tidak padat jika hujan
    p_lalin_tidakPadat_hujan = 1 - p_lalin_padat_hujan;
    // probabilitas lalin tidak padat jika tidak hujan
    p_lalin_tidakPadat_tidakHujan = 1 - p_lalin_padat_tidakHujan;
    // probabilitas Andi tidak terlambat jika hujan dan lalin tidak padat
    p_tidakTerlambat_hujan_lalin_tidakPadat = 1 - p_terlambat_hujan_padat;
    // probabilitas Andi tidak terlambat jika tidak hujan dan lalin padat
    p_tidakTerlambat_tidakHujan_lalin_padat = 1 - p_terlambat_tidakHujan_tidakPadat;
    // probabilitas Andi tidak terlambat jika hujan dan lalu lintas tidak padat, atau tidak hujan dan lalu lintas padat
    p_tidakTerlambat_lainnya = 1 - p_terlambat_lainnya;

    // proses
    p_tidakHujan_padat = jawabSoalA(p_terlambat_lainnya);
    p_terlambat = jawabSoalB(p_hujan, p_lalin_padat_hujan, p_tidakHujan_padat, p_tidakHujan, p_lalin_tidakPadat_tidakHujan, p_terlambat_tidakHujan_tidakPadat, p_lalin_tidakPadat_hujan, p_terlambat_lainnya, p_lalin_padat_tidakHujan);
    p_terlambat_hujan = jawabSoalC(p_hujan, p_lalin_padat_hujan, p_terlambat_hujan_padat, p_terlambat);

    // output
    printf("\n[A] Probabilitas Andi tidak terlambat pada kondisi hari tidak hujan dan lalin padat: %f", p_tidakHujan_padat);
    printf("\n[B] Probabilitas Andi terlambat: %f", p_terlambat);
    printf("\n[C] Probabilitas hari hujan jika diketahui andi datang terlambat adalah: %f", p_terlambat_hujan);

    return 0;
}
