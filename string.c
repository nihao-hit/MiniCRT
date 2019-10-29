// string.c
#include "minicrt.h"

char* itoa(int n, char* str, int radix)
{
    char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* p = str;
    char* head = str;
    if(!p || radix <2 || radix > 36){
        return p;
    }
    if(radix != 10 && n < 0)
        return p;
    if(n == 0){
        *p++ = '0';
        *p = 0;
        return p;
    }
    if(radix == 10 && n < 0){
        *p++ = '-';
        head++;
        n = -n;
    }
    while(n){
        *p++ = digit[n % radix];
        n /= radix;
    }
    *p = 0;
    for(--p; head < p; ++head, --p){
        char temp = *head;
        *head = *p;
        *p = temp;
    }
    return str;
}

int strcmp(const char* src, const char* dst)
{
    if(src == dst)
        return 0;
    while(*src && *dst && !(*src - *dst))
        ++src, ++dst;
    return *src - *dst;
}

char* strcpy(char* dest, const char* src)
{
    char* ret = dest;
    while(*src)
        *dest++ = *src++;
    *dest = '\0';
    return ret;
}

unsigned strlen(const char* str)
{
    int cnt = 0;
    if(!str)
        return 0;
    for( ; *str != '\0'; str++)
        ++cnt;
    return cnt;
}