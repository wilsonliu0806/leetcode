#include"stdio.h"
#define MAX_STRING 256
int sub_len_has(char * s,int start,int end,char ch){
    char *p = s+start-1;
    while(p!='\0'){
        if(*p == ch){
            return p-s+1;
        }
        if(p - s == end-1){
            break;
        }
        p++;
    }    
    return 0;
}
int lengthOfLongestSubstring(char* s) {
    int i=1;
    int startpos,endpos;
    int end[MAX_STRING]={0};
    int start[MAX_STRING]={0};
    int repeat[MAX_STRING]={0};
    while(*(s+i-1)!='\0'){
	printf("%d ",i);
        if(i == 1){
            start[i]=1;
            end[i]=1;
            repeat[i]=0;
            i++;
	printf("\n");
            continue;
        }
        
        if(end[i-1] == i-1){
            startpos=start[i-1];
            endpos = end[i-1];
        }else if(i-repeat[i-1]>=end[i-1]-start[i-1]+1){
            startpos=i-(end[i-1]-start[i-1]+1);
            endpos=i-1;
        }else{
            start[i]=start[i-1];
            end[i]=end[i-1];
            i++;
            continue;
        }
        if((repeat[i]=sub_len_has(s,startpos,endpos,*(s+i-1)))== 0){
            start[i]=startpos;
            end[i]=i;
        }else{
            start[i]=start[i-1];
            end[i]=end[i-1];
        }
        printf("%d %d %d ",start[i],end[i],repeat[i]);
        i++;
        printf("\n");
    }
    return end[i]-start[i]+1;
}
int main()
{
    char *p = "abcabc";
    int i = lengthOfLongestSubstring(p);
    return 0;

}
