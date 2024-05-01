#include <stdio.h>
#include <stdbool.h>

#define MAX_STR  100

bool isprefix(const char* sub, const char* str){
    if(*sub != *str){
        return false; //Fine
    } else {
        if(*(++sub) != '\0')
            return isprefix(sub, str+1);
        return true;
    }
}

size_t lunghezzadi(char* str){
    if(*str == '\0'){
        return 0;//Fine
    } else {
        return 1 + lunghezzadi(str+1);
    }
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