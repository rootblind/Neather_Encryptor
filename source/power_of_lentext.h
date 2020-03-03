#ifndef POWER_OF_LENTEXT_H_INCLUDED
#define POWER_OF_LENTEXT_H_INCLUDED

pol_decryptor(char text[])
{
    char text_dec[100000] = "";
    int i,k = 0;
    for(i = 0; i < strlen(text); i++)
        if(text[i] < 48 || text[i] > 57)
            text_dec[k++] = text[i];
    text_dec[k + 1] = NULL;
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

pol_encryptor(char text[])
{
    char buffer[100],text_enc[100000] = "";
    int i,p = 0;

    for(i = 0; i < strlen(text); i++)
    {
        buffer[0] = text[i];
        buffer[1] = NULL;
        strcat(text_enc,buffer);
        strcpy(buffer,"");
        if(i < strlen(text) - 1)
        {
            itoa(p,buffer,10);
            strcat(text_enc,buffer);
            strcpy(buffer,"");
            p += strlen(text);
        }
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
}

#endif // POWER_OF_LENTEXT_H_INCLUDED
