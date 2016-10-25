#include"stdio.h"
#define MAX_STRING 256
int sub_len_has(char * s,int start,int end,char ch){
    char *p = s+start;
    while(p!='\0'){
        if(*p == ch){
            return p-s+1;
        }
        if(p - s == end){
            break;
        }
        p++;
    }    
    return 0;
}
int lengthOfLongestSubstring(char* s) {
    int i=1;
    int startpos,endpos;
    int end[MAX_STRING];
    int start[MAX_STRING];
    int repeat[MAX_STRING];
    while(1){
        if(i == 1){
            start[i]=1;
            end[i]=1;
            repeat[i]=0;
            continue;
        }
        
        if(end[i-1] == i-1){
            startpos=start[i-1];
            endpos = end[i-1];
        }else if(i-repeat[i-1]>=end[i-1]-start[i-1]+1){
            startpos=repeat[i-1]+1;
            endpos=i-1;
        }else{
            start[i]=start[i-1];
            end[i]=end[i-1];
            continue;
        }
        if(repeat[i]=sub_len_has(s,startpos,endpos,*(s+i)) == 0){
            start[i]=startpos;
            end[i]=i;
        }else{
            start[i]=start[i-1];
            end[i]=end[i-1];
        }
        i++;
    }
}
int main()
{
    printf("Hello!\n");
    return 0;

}
