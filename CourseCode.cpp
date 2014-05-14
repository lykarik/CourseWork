#include <iostream>
#include <string.h>
#include <stdio.h>

#define OPENTEXT    "/home/rideer/rideer/Study/CourseWork/opentext.txt"
#define CRYPTFILE   "/home/rideer/rideer/Study/CourseWork/cryptedtext.txt"
#define DECRYPTFILE "/home/rideer/rideer/Study/CourseWork/decryptedtext.txt"

//#define KEY "as28zw37q8397342ui238e2twqm2ewp1"
//#define KEY "as28zw37q8397342ui238e2twqm2ewp1"
#define KEY "98765432109876543210987654321098"


void GOST () {

    unsigned int Sbox[8][16] =                      //таблица замен
    {
        {5,9,2,4,8,7,3,10,15,1,13,11,6,14,0,12},
        {7,13,5,12,2,14,4,3,0,8,10,9,1,6,11,15},
        {12,9,11,4,15,5,10,1,14,3,7,13,8,6,0,2},
        {10,8,4,0,6,15,11,3,12,13,2,1,7,5,9,14},
        {8,10,15,6,9,11,4,12,7,1,15,3,5,0,2,13},
        {13,1,10,0,5,8,2,14,7,15,9,12,11,3,6,4},
        {15,7,6,10,12,4,1,11,14,9,8,0,2,5,13,3},
        {15,7,6,10,12,4,1,11,14,9,8,0,2,5,13,3}
    };

    char s[33] = KEY;
    unsigned int key[8];

    for(int i = 0; i<8; i++)
    {
        key[i] = (s[4*i]<<24) + (s[1+4*i]<<16) + (s[2+4*i]<<8) + s[3+4*i];
    }

    std::cout << key << std::endl;

    for(int j = 0; j<8; j++) {

        //Fragments[j] = Sbox[j][Fragments[j]];     // Пропуск фрагментов через Sbox'ы
    }

    FILE *fi;
    FILE *fo;

    fi = fopen (OPENTEXT, "rb");
    fo = fopen (CRYPTFILE, "ab");

    unsigned int L[4],R[4];

    L[4] = '\0';
    R[4] = '\0';

    fread(L, 4, 1, fi);
    fread(R, 4, 1, fi);

    std::cout << "This is the L block ->   " << L << std::endl
                << "This is the R block ->   " << R << std::endl;

    unsigned int T;

    for(int i = 0; i<32; i++)
    {
        if (i<24) T = (R[4]+key[i%8]);    // суммирование с ключом в зависимости от раунда
        else T = (R[4]+key[7-(i%8)]);
    }


    std::cout << T << std::endl;

    fclose(fi);
    fclose(fo);
}

int main (){

    GOST ();

return 0;
}
