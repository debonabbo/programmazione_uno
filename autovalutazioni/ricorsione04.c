#include <stdio.h>
#include <stdbool.h>

bool esiste_carattereR(const char *pStr, const char c){
    if(*pStr == '\0'){
        return false;
    } else {
        if(*pStr == c)
            return true;
        return esiste_carattereR(pStr+1, c);
    }
}

bool esiste_carattere(const char *pStr, const char c) {
    return esiste_carattereR(pStr, c);
}

void e2R(char *pStr, char *pStrMod) {
    if(*pStr == '\0'){
        *pStrMod = '\0';
        return;
    } else {
        if(!esiste_carattereR(pStr+1, *pStr)){
            *(pStrMod++) = *pStr;
        }

        return e2R(pStr+1, pStrMod);
    }
}

void e2(char* pStr) {
    return e2R(pStr, pStr);
}

int main(){
    char str[] = "amaca";
    e2(str); puts(str);
    return 0;
}