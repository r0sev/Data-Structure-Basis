#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <malloc/malloc.h>


int getLength(const char *str){              
    int i = 0;
    while(1){
        if(str[i] != '\0') i++;
        else break;
    }
    return i;
}

void myMethod(const char *str , int bit){
    int length = getLength(str);
    int offset = length/bit;
    char *old = NULL;
    int mod = length % bit;
    int n=0,m=0,i=0,j=0;
    if(mod == 0) {
        length = length;
        char *oldStr = (char *)malloc(sizeof(char) * (length + 1));
        strcpy(oldStr, str);
        old = oldStr;
    }
    else{
        n = bit - mod;
        length = length + bit - mod;
        offset += 1;
        char *oldStr = (char *)malloc(sizeof(char) * (length + 1));
        strcpy(oldStr, str);
        i = 1;
        while (n) {
            oldStr[length-i]='*';  
            n--;
            i++;
        }
        oldStr[length] = '\0';
        old = oldStr;
        
    }
    char *newStr = (char *)malloc(sizeof(char) * (length + 1));
    for(i=0;i<bit;i++){
        m = i;
        n = offset;
        do{
            newStr[j] = old[m];
            m+=bit;
            j++;
            n--;
        }while(n > 0);
    }

    printf("Result :%s\n",newStr);
    free(old);
    free(newStr);

}


int main(int argc, char *argv[]) {
	myMethod(argv[2],atoi(argv[3]));
    return 0;
}
