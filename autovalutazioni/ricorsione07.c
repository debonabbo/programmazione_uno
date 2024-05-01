#include <stdio.h>
#include <stdbool.h>

void e2R(size_t *p_aVal, int a[], const int min, const int max, const int i,
        size_t im) 
{
   if(i>= *p_aVal){
        *p_aVal = im;
   } else {
        if(a[i]>=min && a[i]<=max)
            a[im++] = a[i];
        
        return e2R(p_aVal, a, min, max, i+1, im);
   }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) 
{
    return e2R(p_aVal, a, min, max, 0, 0);
}

int main(){

}