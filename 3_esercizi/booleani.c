#include <stdio.h>
#include <stdbool.h>

int main(){
    int a, b;

    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);

    if(a%b == 0)
        printf("1");
    else
        printf("0");
    printf("\n");
        
    int voto;

    printf("Inserisci il voto: ");
    scanf("%d", &voto);

    if(voto <= 30 && voto >= 1)
        printf("true");
    else
        printf("false");
    printf("\n");

    char c1, c2;
    printf("Inserisci i valori ('v' o 'f') di b1 e b2: ");
    scanf(" %c %c", &c1, &c2);
    bool b1 = (c1 == 'v');
    bool b2 = (c2 == 'v');

    if(b1 && b2)
        printf("false");
    else
        printf("true");
    printf("\n");

    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    int max = 0;

    if(a==b)
        printf("I valori di A e B sono uguali");
    else{
        if(a>b)
            max = a;
        else
            max=b;
        printf("Il valore massimo e': %d", max);
    }
    printf("\n");

    int c;
    
    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    printf("Inserisci c: ");
    scanf("%d", &c);
    max = a;

    if(b>max)
        max = b;
    if(c>max)
        max = c;

    printf("Il valore massimo e': %d\n", max);

    if(a<b && b<c)
        printf("Ordinati.");

    return 0;
}