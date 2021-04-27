#include <stdio.h>
#include <stdlib.h>

void dfmenu(); //untuk Daftar menu
void belanja();// untuk Belanja
typedef struct h{
    int harga1;
}menu;
int main(){
    int mmenu;
    

    do{

        printf("\n==============================\n");
        printf("Welcome to VINTAGE STYLE CAFE \n");
        printf("==============================\n");
        printf("1. Daftar menu\n"); //1-3 adalah main menu
        printf("2. Belanja\n");
        printf("3. Keluar\n\n");
        printf("______________________________\n");
    do {
        printf("Pilihan Anda: ");
        scanf("%d", &mmenu);         //disini hanya harus memasuk nilai 1-3
        if (mmenu>3 || mmenu<1){
            printf("Maaf input Anda tidak sesui!\n"); //jika memasukkan nilai salah monitor akan mencetak pesan ini
        }
    } while (mmenu>3 || mmenu<1);


    switch (mmenu) {

            // untuk fungsi Daftar menu
            case 1:
                dfmenu();
                continue;

                // untuk fungsi belanja
            case 2:
                belanja();
                continue;

                //Untuk keluar app
            case 3:
                exit (1);

            default:
                printf("Maaf, input anda tidak sesuai!");
                break;
        }
    }while(mmenu>=1&&mmenu<=3);
}
void dfmenu(){
    int i;
    int harga2[6]={0,30,35,25,50,45};
    menu drink[6];
    for (i = 0; i <6 ; i++) {
     drink[i].harga1 = harga2[i];
    }
    printf("+----+--------------------+----------+\n");
    printf("| No |       Menu         |Price/Baht|\n");
    printf("+----+--------------------+----------+\n");
    printf("  1   Thai tea original        %d \n",drink[1].harga1);
    printf("  2   Green tea                %d \n",drink[2].harga1);
    printf("  3   Pink milk                %d \n",drink[3].harga1);
    printf("  4   Choco oreo smoothie      %d \n",drink[4].harga1);
    printf("  5   Blueberry smoothie       %d \n",drink[5].harga1);
    printf("+----+--------------------+----------+\n\n");
    printf("Tekan Enter untuk lanjut.....");
    getchar();
    getchar();
}
void belanja() {
    int array[6] = {0,30, 35, 25, 50, 45}; //Harga produk
    int b, c,harga,total=0,uang;  // b=nomor produk c= jumlah produk harga= harga produk total=harga semua uang=jumlah uang pelanggan
    char yn[]={'y','n'}; //untuk jawaban yes no

    do { //do while ini untuk pelanggan mau belanja yang lain
        do {
            printf("Input nomor menu: ");
            scanf("%d", &b);
            if (b > 5 || b < 1){
                printf("Maaf input anda tidak sesuai!\n");
            }
        }while (b >5 || b < 1);

        if (b <= 5 || b >= 1) {
                printf("Input banyak menu ini yang diinginkan: ");
                scanf("%x", &c);
                harga = c * array[b];
                total += harga;

        }
        do {
            printf("apakah Anda ingin belanja yang lain (y/n)?: ");
            scanf("%s",yn);
            getchar();

            if ((*yn != 'y' ) && (*yn !='n'))
                printf("Maaf input anda tidak sesuai!\n");

        } while ((*yn != 'y' ) && (*yn !='n'));
    } while (*yn=='y'); //jika  memasukkan y program akan loop diatas kembali

    printf("\nTotal belanjaan: %d Baht\n",total); //harga semua
    printf("Masukkan uang Anda ");
    scanf("%d",&uang);
    do { //jika memasuk nilai uang kurang total loo ini akan kerja
        if (uang < total) {
            total-=uang;
            printf("Uang tidak cukup! %d Baht \n",total);
            printf("Masukkan uang tambahan:");
            scanf("%d", &uang);
        }
    } while (uang<total);
    printf("Kembalian Anda: %d Baht\n",uang-total);
    printf("______________________________\n");
    printf("=Terimakasih telah berkunjung=\n");
    printf("______________________________\n\n");
    printf("Tekan Enter untuk lanjut.....");
    getchar();
    getchar();
}
