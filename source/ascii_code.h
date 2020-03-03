#ifndef ASCII_CODE_H_INCLUDED
#define ASCII_CODE_H_INCLUDED
#include <string.h>
#include <windows.h>

void ascii_decryptor(char text[])
{
    char c[10] = "",text_dec[100000] = "";
    int i,base,j = 0,x,zecimal[100000] = {0},k = 0;
    do{
        printf("\nInsert the numeral base(2 or 10): ");
        scanf("%u",&base);
    }while(base != 10 && base != 2);
    if(base == 10)
        for(i = 0; i < strlen(text); i += 2)
        {
            c[0] = text[i];
            x = atoi(c) * 10;
            c[0] = text[i + 1];
            x += atoi(c);
            if(x >= 48 && x <= 57)
                {
                    text_dec[j++] = x;
                    continue;
                }
            else if(x < 'A' && x != 32)
            {
                c[0] = text[i + 2];
                x = x * 10 + atoi(c);
                i++;
            }
            else if(x % 10 == 0 && x / 10 < 'A')
                x /= 10;


            text_dec[j++] = x;
        }
        else
        {
        int lun = strlen(text) - 1;
        for(k = 0; k < strlen(text) / 8; k++)
        {
            int p = 1;
            for(i = lun; i >= lun - 8; i--)
            {
                c[0] = text[i];
                zecimal[k] += atoi(c) * p;
                p *= 2;
            }
            lun -= 8;
        }

        for(i = 0; i < k; i++)
        {
            text_dec[j++] = zecimal[k - i - 1];
        }
    }
    text_dec[j + 1] = NULL;
    FILE *output = fopen("output.txt","a");
    fprintf(output,text_dec);
    fprintf(output,"\n");
    fclose(output);
    printf("\nThe decrypted text: %s",text_dec);
    printf("\nPress any key to continue.");

    const size_t len = strlen(text_dec) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), text_dec, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    _getch();
    for(i = 0; i < 100000; i++)
        text[i] = ' ';

}

void ascii_encryptor(char text[])
{
    char text_enc[100000] = "",buffer[100000],adaos[100000] = "";
    unsigned i,base,k;
    do{
        printf("\nInsert the numeral base: ");
        scanf("%u",&base);
    }while(base <= 1 || base > 20);
    for(i = 0; i < strlen(text); i++)
    {
        int character_int = text[i];
        itoa(character_int,buffer,base);
        if(base == 2)
        {for(k = 0; k < 8 - strlen(buffer); k++)
            adaos[k] = '0';
        adaos[k] = NULL;
        strcat(adaos,buffer);
        strcat(text_enc,adaos);
        }
        else
            strcat(text_enc,buffer);

    }
    FILE *output = fopen("output.txt","a");
    fprintf(output,text_enc);
    fprintf(output,"\n");
    fclose(output);
    printf("\nThe encrypted text: %s",text_enc);
    printf("\nPress any key to continue.");

    const size_t len = strlen(text_enc) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), text_enc, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    _getch();
    fflush(stdin);
}

#endif // ASCII_CODE_H_INCLUDED
