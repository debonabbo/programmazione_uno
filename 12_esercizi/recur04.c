#include <stdio.h>
#include <stdbool.h>

// restituisce true se un elemento val esiste in un dato array
bool esiste_elemento(const size_t aLen, const int a[], const int val) {
    if(aLen<=0){
        return false;
    } else {
        if(a[aLen-1]==val)
            return true;
        return esiste_elemento(aLen-1, a, val);
    }
}

void e2R(const size_t aLen, int a[], const size_t bLen, const int b[],
            size_t i, size_t *c)
{
    if(i>=aLen){
        return; //Fine
    } else {
        //Copio l'elemento che compare in b e che non esiste ancora in a
        if(esiste_elemento(bLen, b, a[i])){
            if(!esiste_elemento(i, a, a[i])){
                a[(*c)++] = a[i];
            }
        } else {    //Copio l'elemento perche' non compare in b
            a[(*c)++] = a[i];
        }

        return e2R(aLen, a, bLen, b, i+1, c);
    }
}

void e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    size_t copiati = 0;
    e2R((*p_aLen), a, bLen, b, 0, &copiati);
    *p_aLen = copiati;
}







//TEST

void int_array_print(const size_t len, const int a[]){
    for (size_t i = 0; i < len; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int main(){
    size_t aLen = 4; const size_t bLen = 1;
    int a[4] = {2, 3, 2, 4};
    const int b[1] = {2};
    e2(&aLen, a, bLen, b);
    int_array_print(aLen, a);

    return 0;
}