#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* to_hex(int64_t val)
{
    char* HEX_DIGITS = "0123456789abcdef";
    char* s = malloc(sizeof(char)*10);
    if(val<0)
    {
        int64_t a =1;
        val+=(a<<32);
    }
    int limit =0;
    while (1)
    {`
        char d[2] = {HEX_DIGITS[val & 0xf],NULL};
        
        char* tmp= strdup(s);
        strcpy(s,d);
        strcat(s,tmp);
        free(tmp);

        val >>=4;
        limit++;
        if (val==0 || limit==8)break;
    }
    char f[] = "0x";
    char* tmp2= strdup(s);
    strcpy(s,f);
    strcat(s,tmp2);
    free(tmp2);
    return(s);
}


int main(){
    char* ans = to_hex(33);
    int i =0;
    while (ans[i] != NULL)
    {
        printf("%c",ans[i]);
        i = i + 1;
    }
    free(ans);
    return 0;
}