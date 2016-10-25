#include"stdio.h"
#define MAX_STRING 256
int is_valid_substr(char *s,int start,int end){

}
int sub_len_has(char * s,int start,int end,char ch){
    
}
int lengthOfLongestSubstring(char* s) {
    int i=1;
    int startpos,endpos;
    int end[MAX_STRING];
    int start[MAX_STRING];
    int repeat[MAX_STRING];
    while(true){
        if(i == 1){
            start[i]=1;
            end[i]=1;
            repeat[i]=0;
            continue;
        }
        
        if(end[i-1] == i-1){
            startpos=start[i-1];
            endpos = end[i-1];
        }else{
            startpos=repeat[i-1]+1;
            endpos=i-1;
        }
        if(repeat[i]=sub_len_has(s,start[i-1],end[i-1],s+i)){
            start[i]=start[i-1];
            end[i]=end[i-1];
        }else{
            start[i]=start[i-1];
            end[i]=i;
        }
            if(repeat[i]=sub_len_has(s,repeat[i-1]+1,i-1,s+i)){
                start[i]=start[i-1];
                end[i]=end[i-1];
            }else{
                start[i]=repeat[i-1]+1;
                end[i]=i;
            }
        }
        i++;
    }
}
void main()
{
    printf("Hello!\n");
}
