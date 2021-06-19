/* Program Tic Tac Toe
Andrew Poda Jeremy - 1906384163
Muhammad Rizqi Naufal Saragih - 1906305266
Nanda Ilham Harahap - 1906384195*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//pembuatan prototypes
int init(char arr1[3][3]);
int papan(char arr2[3][3]);
int giliran(int *giliranpemain);
int trackpindah(char arr3[3][3], int giliranpemain2, int *pindah, char pemain1[], char pemain2[]);
int validasipindah(int pindah);
int validasimenang(char arr[3][3], int banyakgiliran);
int papanbaru(char arr[3][3], const int * pindah, int giliran);
int menu();

typedef struct{
  char pemain1[20];
  char pemain2[20];
} pemain;

int main(void) {
    system("color 8a");//Mengubah warna menjadi abu-abu dengan font hijau
    int ulangpermainan = 1; //membuat loop
    if(menu() == 1){ //memilih menu 
        while(ulangpermainan == 1) { //ketika para pemain ingin bermain lagi, loop
            int giliranpemain = 1;
            int pindah = 0;
            int banyakgiliran = 1;
            pemain parapemain; //membuat data baru dari initial structure
            char arr[3][3]; //memmbuat array
            init(arr); //membuat papan permainan
            printf("Nama Pemain 1 : ");
            scanf(" %s", parapemain.pemain1);
            printf("%s, kamu adalah 'X'\n", parapemain.pemain1);
            printf("Nama Pemain 2 : ");
            scanf(" %s", parapemain.pemain2);
            printf("%s, kamu adalah 'O'\n", parapemain.pemain2);
            while (validasimenang(arr, banyakgiliran) == 0) {
                trackpindah(arr, giliranpemain, &pindah, parapemain.pemain1, parapemain.pemain2); //menerima pergerakan pemain 
                validasipindah(pindah); //call the function untuk validasi pemindahan
                papanbaru(arr, &pindah, giliranpemain); //call the function yang merubah papan permainan sesuai pergerakan pemain
                papan(arr); //menampilkan ulang papam permainan
                giliran(&giliranpemain); //memanggil fungsi untuk merubah giliran
                banyakgiliran++; //banyakgiliran bertambah sesuai incriment
            }
            printf("Apakah anda ingin bermain lagi?(ketik 1 untuk YA atau angka selain 1 untuk TIDAK) ");
            scanf(" %d", &ulangpermainan);
        }
    }
    return 0;
}

//Mengatur papan permainan
int init(char arr1[3][3]){
    arr1[0][0] = '1';
    arr1[0][1] = '2';
    arr1[0][2] = '3';
    arr1[1][0] = '4';
    arr1[1][1] = '5';
    arr1[1][2] = '6';
    arr1[2][0] = '7';
    arr1[2][1] = '8';
    arr1[2][2] = '9';
    return 0;
}

//Menampilkan papan pada layar
int papan(char arr2[3][3]){
    printf("\n%c | %c | %c\n", arr2[0][0], arr2[0][1], arr2[0][2]); //menampilkan baris atas
    printf("----------\n");
    printf("%c | %c | %c\n", arr2[1][0], arr2[1][1], arr2[1][2]); //menampilkan baris tengah
    printf("----------\n");
    printf("%c | %c | %c\n\n\n", arr2[2][0], arr2[2][1], arr2[2][2]); //menampilkan baris bawah
    return 0;
}

//Pergantian giliran pemain
int giliran(int *giliranpemain1){
    if(*giliranpemain1 == 1){ //ketika giliran pemain pertama
        *giliranpemain1 = 2; //ganti ke giliran pemain kedua
    }
    else if(*giliranpemain1 == 2){ //ketika giliran pemain kedua
        *giliranpemain1 = 1; // ganti ke giliran  pemain pertama 
    }
    return 0;
}

//Pergerakan pemain tergantung giliran dari setiap pemain 
int trackpindah(char arr3[3][3], int giliranpemain2, int *pindah, char pemain1_1[], char pemain2_1[]){
    if(giliranpemain2 == 1){ //ketika giliran pemain pertama
        papan(arr3); //menampilkan papan permainan
        printf("%s, ketik angka yang anda mau pilih : ", pemain1_1); //meminta pergerakan 
        scanf(" %d", pindah);//pergerakan pemain
    }
    else if(giliranpemain2 == 2){ //ketika giliran pemain pertama
        papan(arr3); //menampilkan papam permainan
        printf("%s, ketik angka yang anda mau pilih : ", pemain2_1); //meminta pergerakan
        scanf(" %d", pindah); //pergerakan pemain
    }
    return *pindah;
}

int validasipindah(int pindah){
    if (pindah < 1 || pindah > 9) { //ketika pergerakan diluar angka yang ada di papan permainan
        return 0;
    }
    else //ketika pergerakan diluar dari yang ada  di papan permainan
        return 1;
}

//Fungsi ketika pemain melakukan pergerakan
int papanbaru(char arr[3][3], const int *pindah, int giliran){
    if(*pindah == 1 && giliran == 1) //kiri atas telah dipilih pemain pertama
        arr[0][0] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 1 && giliran == 2) //kiri atas telah dipilih pemain kedua
        arr[0][0] = 'O'; //merubah yang ada  di papan menjadi O
    else if(*pindah == 2 && giliran == 1) //tengah atas telah dipilih pemain pertama
        arr[0][1] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 2 && giliran == 2) //tengah atas telah dipilih  pemain pertama
        arr[0][1] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 3 && giliran == 1) //kanan atas telah dipilih pemain pertama
        arr[0][2] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 3 && giliran == 2) //kanan atas telah dipilih pemain kedua
        arr[0][2] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 4 && giliran == 1) //kiri tengah telah dipilih oleh pemain pertama 
        arr[1][0] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 4 && giliran == 2) //kiri tengah telah dipilih oleh pemain kedua
        arr[1][0] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 5 && giliran == 1) //tengah telah dipilih oleh pemain pertama
        arr[1][1] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 5 && giliran == 2) //tengah telah dipilih oleh pemain kedua
        arr[1][1] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 6 && giliran == 1) //tenggah kanan telah dipilih pemain pertama 
        arr[1][2] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 6 && giliran == 2) //tengah kanan telah dipilih pemain kedua 
        arr[1][2] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 7 && giliran == 1) //kanan bawah telah dipilih pemain pertama
        arr[2][0] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 7 && giliran == 2) //kanan bawah telah dipilih pemain kedua
        arr[2][0] = 'O'; //merubah yang ada di papan menjadi O
    else if(*pindah == 8 && giliran == 1) //tenggah  bawah telah  dipilih pemain pertama
        arr[2][1] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 8 && giliran == 2) //tengah bawah telah  dipilih pemain kedua
        arr[2][1] = 'O';//merubah yang ada di papan menjadi O
    else if(*pindah == 9 && giliran == 1) //bawah kanan telah dipilih pemain pertama
        arr[2][2] = 'X'; //merubah yang ada di papan menjadi X
    else if(*pindah == 9 && giliran == 2) //bawah kanan telah dipilih pemain kedua
        arr[2][2] = 'O'; //merubah yang ada di papan menjadi O
    else  {
    	printf("PERHATIAN!!!\nInput tidak sesuai, anda kehilangan giliran.\n");
    }
    return 0;
}

//Melihat papan permainan jika salah satu pemain telah menang
int validasimenang(char arr[3][3], int banyakgiliran){
    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) { //mengecek garis horizontal atas
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) { //mengecek garis horizonal tengah
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) { //mengecek garis horizontal bawah
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) { //mengecek garis vertikal kiri
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) { //mengecek garis vertikal tengah
        printf("Selamat, Anda menang!\n");
        return 1;
    }
    else if(arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]) { //mengecek garis vertikal kanan
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) { //mengecek garis diagonal dari atas kiri ke bawah kanan
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2]) { //mengecek garis diagonal dari atas kanan ke bawah kiri
        printf("~~~!!!SELAMAT, ANDA MEMENANGKAN GAME INI!!!~~~\n");
        return 1;
    }
    else if(banyakgiliran >= 10) //mengecek apakah game berakhir seri
        printf("Game berakhir seri, tidak ada yang menang.\n");
    else
        return 0;
}

//mengatur menu
int menu(){
    int opsi = 0; //menentukan opsi	
    printf("-----------------------------------------------------\n");
    printf("           Selamat datang di Tic Tac Toe !           \n");
    printf("-----------------------------------------------------\n");
    printf("Tic Tac Toe adalah sebuah permainan dimana pemain dapat\nmemasukan X/O dengan memilih nomor secara bergantian \npada papan. Dapatkan sampai satu axis (vertikal, \nhorizontal atau diagonal) sempurna untuk menang! \nJika tidak, permainan akan berakhir dengan seri. \n\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!PERHATIAN!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("-----GAMEPLAY HANYA MENERIMA INPUT BERUPA ANGKA-----\n\n");
    printf("Apakah anda sudah siap bermain ?\n");
    printf("1. Mulai \n");
    printf("2. Keluar ");
    printf("\nTentukan Pilihanmu : ");
    scanf(" %d", &opsi); //mendapat pilihan dari user
    switch(opsi){
        case 1: //jika user memilih opsi 1
        	printf("\nGood Luck and Have fun!\n\n");
            return 1;
        case 2: //jika user memilih opsi 2
            printf("Terima kasih!");
			return 2;
        default: //jika user memilih pilihan yang lain
            printf("Error. Silahkan jalankan program lagi.");
    }
}

