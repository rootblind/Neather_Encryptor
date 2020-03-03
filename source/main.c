#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ascii_code.h"
#include "power_of_lentext.h"
#include "reverse_char.h"

char text[100000];
 reading_text()
{
    system("cls");
    printf("============================== READING ==============================\n\n");
    printf("The input (special characters are replaced with space): ");
    gets(text);

    int i;
    for(i = 0; i < strlen(text); i++)
        if(text[i] != ' ' && (text[i] < 'A' || text[i] > 'Z' ) && (text[i] < 'a' || text[i] > 'z' ) && (text[i] < '0' || text[i] > '9'))
            text[i] = ' ';
    FILE *input = fopen("input.txt","a");
    fprintf(input,text);
    fprintf(input,"\n");
    fclose(input);
}

void enc()//encryptors
{
    unsigned select;
    do{
        do{
                system("cls");
                printf("============================== ENCRYPTORS ==============================\n\n");
                printf("The crypting power of each method is rated from 1 to 10, where 1 is low\nsecurity, 10 is undecrytable.\n");
                printf("1.1- ASCII CODE(numeral base: 2-20)\n");
                printf("2.1- POWER OF LENTEXT\n");
                printf("3.2- REVERSE CHAR\n");
                printf("0- Exit\n");
                printf("Choose: ");scanf("%u",&select);
        }while(select != 1 && select != 0 && select != 2 && select != 3);
        switch(select)
        {
        case 1:
            getchar();
            reading_text();
            ascii_encryptor(text);
            _getch();
            break;
        case 2:
            getchar();
            reading_text();
            pol_encryptor(text);
            _getch();
            break;
        case 3:
            getchar();
            reading_text();
            reverse_char_enc(text,0);
            _getch();
            break;
        }
    }while(select);
}

void dec()//decryptors
{
    unsigned select;
    do{
        do{
            system("cls");
            printf("============================== DECRYPTORS ==============================\n\n");
            printf("1- ASCII CODE(numeral base: 2 and 10; content: words and spaces)\n");
            printf("2- POWER OF LENTEXT(unable to decrypt text that originally has digits\n");
            printf("3- REVERSE CHAR\n");
            printf("0- Exit\n");
            printf("Choose: ");scanf("%u",&select);
        }while(select != 1 && select != 0 && select != 2 && select != 3);
        switch(select)
        {
        case 1:
            getchar();
            reading_text();
            ascii_decryptor(text);
            _getch();
            break;
        case 2:
            getchar();
            reading_text();
            pol_decryptor(text);
            _getch();
        case 3:
            getchar();
            reading_text();
            reverse_char_enc(text,1);
            _getch();
            break;

        }
    }while(select);
}
void clr_file()
{
    system("cls");
    FILE *input = fopen("input.txt","w"),*output = fopen("output.txt","w");
    printf("The files were emptied!");
    fclose(input);
    fclose(output);
    _getch();
}

int main()
{
    unsigned select;
    do{
    do{
    system("cls");
    printf("============================== NEATHER ENCRYPTOR v0.1 ==============================\n\n");
    printf("Both the input and the output are going to be stored in text files.\nThe output will be stored in the clipboard as well.\nCheck the program's folder.\n\n");
    printf("1- Crypting text\n");
    printf("2- Decrypting text\n");
    printf("3- Clear files\n");
    printf("0- Exit\n");
    printf("Choose: ");scanf("%u",&select);
    }while(select != 1 && select != 2 && select != 0 && select != 3);
    switch(select)
    {
    case 1:
        enc();
        break;
    case 2:
        dec();
        break;
    case 3:
        clr_file();
        break;

    }
    }while(select);


    _getch();
    return 0;
}
