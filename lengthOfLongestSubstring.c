#include"stdio.h"
#define MAX_STRING 256
int sub_len_has(char * s,int start,int end,char ch){
    char *p = s+start;
    while(p!='\0'){
        if(*p == ch){
            return p-s;
        }
        if(p - s == end){
            break;
        }
        p++;
    }    
    return -1;
}
#define CONTINUE  printf("%d %d %d \n",start[i],end[i],repeat[i]);i++;ch=*(s+i);continue
int lengthOfLongestSubstring(char* s) {
    int i=0;
    int end[MAX_STRING]={-1};
    int start[MAX_STRING]={-1};
    int repeat[MAX_STRING]={-1};
    if(s == NULL || *s=='\0') return 0;
    char ch = *s;
    while(ch!='\0'){
        if(i == 0){
            start[i]=0;
            end[i]=0;
            repeat[i]=0;
            CONTINUE;
        }
        
        int repeatpos = -1;
        if(end[i-1] == i-1){
            repeatpos = sub_len_has(s,start[i-1],end[i-1],ch);
            if(repeatpos == -1){
                start[i]=start[i-1];
                end[i]=i;
                repeat[i]=start[i]; 
                CONTINUE;
            }else{
                repeat[i] = repeatpos+1;
            }
        }

        if(repeat[i] != -1){
            repeatpos = sub_len_has(s,repeat[i-1],i-1,ch);
            if(repeatpos==-1){
                repeat[i] = repeat[i-1];
            }else{
                repeat[i] = repeatpos+1;
            }
        }

        if(i-repeat[i]+1>= end[i-1]-start[i-1]+1){
            start[i]=repeat[i];
            end[i]=i;
            CONTINUE;
        }

        start[i]=start[i-1];
        end[i]=end[i-1];
        CONTINUE;
    }
    return end[i-1]-start[i-1]+1;
}

int lengthOfLongestSubstring1(char* s) {
    char m[256]={-1};
    char ch = *s;
    int len = 0;
    int i=0;
    int start=0;
    while(ch!='\0'){
        if(m[ch] == -1){
            len = i-start;
        }
        if(m[ch]!=-1 && i-m[ch]>=len){
            s=i-len+1;
            len = i-start;
        }
        m[ch]=i;
        i++;
        ch = *(s+i);
    }
    return len;
}
int main()
{
    char *p = "abba";
    int result;
    result = lengthOfLongestSubstring1(p);
    printf("%s %d",p,result);
    p = "aab";
    result = lengthOfLongestSubstring1(p);
    printf("%s %d",p,result);
    return 0;

}
