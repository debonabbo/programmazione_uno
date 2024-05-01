#include <stdio.h>
#include <stdbool.h>

#define MAX_STR  100

bool isprefix(const char* sub, const char* str){
    bool ret = true;

    if(*sub != *str){
        ret = false; //Fine
    } else {
        if(*(++sub) != '\0'){
            ret = isprefix(sub, str+1);
        }
    }

    return ret;
}

size_t lunghezzadi(char* str){
    size_t lunghezza = 0;

    if(*str == '\0'){
        //Fine
    } else {
        lunghezza = 1 + lunghezzadi(str+1);
    }

    return lunghezza;
}

void stampa_delezione(char* str, const char* del_seq, const size_t len_del_seq){
    if(*str == '\0'){
        //Fine
    } else {
        size_t offset = 1;

        if(isprefix(del_seq, str)){
            printf("-");
            offset = len_del_seq;
        } else {
            printf("%c", *str);
        }

        stampa_delezione(str+offset, del_seq, len_del_seq);
    }
}

int main(void) {
	char seq[MAX_STR] = {0};
    char del_seq[MAX_STR] = {0};

    scanf("%s", seq);
    scanf("%s", del_seq);
    size_t len_del_seq = lunghezzadi(del_seq);

    stampa_delezione(seq, del_seq, len_del_seq);
}