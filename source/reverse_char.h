#ifndef REVERSE_CHAR_H_INCLUDED
#define REVERSE_CHAR_H_INCLUDED
void reverse_char_enc(char text[],unsigned sel)
{
    char text_dec[100000] = "";
    int i = 0;
    for(i = 0; i < strlen(text); i++)
        if(text[i] >= 'A' && text[i] <= 'Z')
            text_dec[i] = 'Z' - text[i] + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text_dec[i] = 'z' - text[i] + 'a';
            else if(text[i] >= '0' && text[i] <= '9')
                    text_dec[i] = '9' - text[i] + '0';
            else if(text[i] == ' ')
                text_dec[i] = '.';
                else if(text[i] == '.')
                    text_dec[i] = ' ';
            else
                text_dec[i] = text[i];
    text_dec[i] = NULL;
    if(sel == 0)
    {
        FILE *output = fopen("output.txt","a");
        fprintf(output,text_dec);
        fprintf(output,"\n");
        fclose(output);

    }
    else
    {
        FILE *input = fopen("input.txt","a");
        fprintf(input,text_dec);
        fprintf(input,"\n");
        fclose(input);
    }
    printf("\nThe encrypted text: %s",text_dec);
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
}

#endif // REVERSE_CHAR_H_INCLUDED
