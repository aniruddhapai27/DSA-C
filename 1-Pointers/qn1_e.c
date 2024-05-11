/*
Create two pointer called PS1 and PS2 to two strings, Read the contents using pointers and also write a function StrCat (PS1, PS2) which concatenates second string to the end of first string using pointers PS1 and PS2
*/

#include<stdio.h>

void Strcat(char* s1, char* s2){
    int i=0;
    while(*(s1+i)!='\0'){
        *(s1+i) = *(s1+i);
        i++; 
    }
    int j=0;
    while(*(s2+j) != '\0'){
        *(s1+i) = *(s2+j);
        i++;
        j++;
    }
    *(s1+i) = '\0';
}


int main(){
    char s1[50] ,s2[50];
    char *ps1, *ps2;
    ps1 = s1;
    ps2 = s2;

    printf("Enter first string: ");
    scanf("%s",ps1);

    printf("Enter second string: ");
    scanf("%s",ps2);
    
    Strcat(ps1,ps2);
    printf("Concateneated string: %s", ps1);

    return 0;

}
