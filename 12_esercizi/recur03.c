#include <stdio.h>
#include <stdbool.h>

bool esiste_carattere(const char* pStr, const char ch) {
    if(*(pStr) == '\0'){
        return false;
    } else {
        if((*pStr) == ch)
            return true;
        return esiste_carattere(pStr+1, ch);
    }
}

void e2R(char* pStr, const size_t i, char* pModifica) {
    char* pStrAttuale = pStr+i;
    if((*(pStrAttuale)) == '\0'){
        (*pModifica) = '\0';
    } else {
        if(!esiste_carattere(pStrAttuale+1, *(pStrAttuale)))
            (*(pModifica++)) = *(pStrAttuale);
        return e2R(pStr, i+1, pModifica);
    }
}

void e2(char* pStr) {
    char* pModifica = pStr;
    return e2R(pStr, 0, pModifica);
}

int main(){
    char str[] = "amaca";
    e2(str); 
    puts(str);

    return 0;
}