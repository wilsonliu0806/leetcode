#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* longestPalindrome(char* s) {
    char *presult = (char*)malloc(1001*sizeof(char));
    memset(presult,0x00,sizeof(char)*1001);
    int i;
    int maxLength = 1;
    int maxpos = 0;
    int lastrepeatpos = -1;
    int lastPos = 0;
    int last2pos = 0;
    if(*s == '\0'||*(s+1)=='\0'){
        return s;
    }
    for(i=1;i<1000;i++){
        char ch = *(s+i);
        if(ch == '\0'){
            break;
        }
        if(lastPos -1 >= 0){
            if(ch == *(s+lastPos-1)){
                lastPos=lastPos -1;
            }
        }
        if(ch == *(s+i-1)){
            if(lastrepeatpos == i -1){
                //m[i] = lastPos;
            }else{
                lastPos = i-1;
            } 
            lastrepeatpos = i;
        }
        if(i-2 >=0){
            if(ch == *(s+i-2)){
                lastPos= i-2;
            }
        }
        /*
        if(last2pos -1 >=0){
            if(ch == *(s+last2pos-1)){
                m[i] = last2pos -1;
                last2pos = m[i];
            }
        }
        */
        if(i-lastPos+1> maxLength){
            maxLength = i-lastPos+1;
            maxpos = lastPos;
        }
    }
    memcpy(presult,s+maxpos,maxLength);
    return presult;
}
int main(){
    char *s[] = {"abababa","banana","abcda","xyzzyxabc","a","bb","aba"};
    int i;
    for(i=0;i<sizeof(s)/sizeof(char*);i++){
        char *p = longestPalindrome(s[i]);
        printf("%s\n%s\n\n",s[i],p);
    }
    return 1;
}