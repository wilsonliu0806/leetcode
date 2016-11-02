#include <stdio.h>
#define NUM_MIN 0xFFFFFFFF
int del_max_num(int *targetnums,int startpos,int endpos,int num){
    while(endpos>=startpos){
        if(num <= targetnums[(startpos+endpos)/2]){
            return (endpos-startpos)/2+1;
        }
        startpos = (startpos+endpos)/2+1;
    }
    return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int numMin = NUM_MIN;
    int lend= nums1Size-1;
    int lstart = 0;
    int rend= nums2Size-1;
    int rstart = 0;
    int totalcnt = -1*((nums1Size + nums2Size)%2)+2;
    int totaldel = nums1Size + nums2Size;
    totaldel = (totaldel-2+(totaldel%2))/2;
    printf("totalcnt = %d totaldel = %d \n",totalcnt,totaldel);
    int nummax;
    int delcnt;
    int *pnumflag;
    int *pend;
    int *pstart;
    int *pnums;
    double dbResult[2];
    while(1){
        if(lend<0 && rend <0){
            printf("error! both end <0\n");
            return 0;
        }

        if(lend<0){
            pend = &rend;
            pstart = &rstart;
            pnums = nums2;
            pnumflag = &numMin;
        }else if(rend<0){
            pend = &lend;
            pstart = &lstart;
            pnums = nums1;
            pnumflag = &numMin;
        }else if(nums1[lend]>nums2[rend]){
            pend = &lend;
            pstart = &lstart;
            pnums = nums1;
            pnumflag = &nums2[rend];
        }else{
            pend = &rend;
            pstart = &rstart;
            pnums = nums2;
            pnumflag = &nums1[lend];
        }
        printf("[%d %d] -> %d\n",*(pnums+*pstart),*(pnums+*pend),*pnumflag);
        delcnt = del_max_num(pnums,*pstart,*pend,*pnumflag);
        printf("delcnt = %d\n",delcnt);
        if(totaldel < delcnt || totaldel == 0){
            int pos = *pend-totaldel;
            if(totalcnt == 2){
                if((delcnt - totaldel == 1)&&(pos==*pstart||(pos>*pstart&&(*(pnums+pos-1)<*pnumflag)))){
                    return (*(pnums + pos) + *pnumflag)/2.0;
                }else{
                    return (*(pnums+pos-1) + *(pnums+pos))/2.0;
                }
            }else{
                return *(pnums+pos)/1.0;
            }
        }else{
            totaldel -=delcnt;
            *pend -=delcnt;
        }
    }
}

int main(){
    int nums1[] = {1,2};
    int nums2[] = {3,4};
    double result = findMedianSortedArrays(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int));
    printf("findMedianSortedArrays %.2f\n",result);
    int nums3[] = {1,3};
    int nums4[] = {2,4};
    result = findMedianSortedArrays(nums3,sizeof(nums3)/sizeof(int),nums4,sizeof(nums4)/sizeof(int));
    printf("findMedianSortedArrays %.2f\n",result);
    int nums5[] = {};
    int nums6[] = {2,3,4};
    result = findMedianSortedArrays(nums5,sizeof(nums5)/sizeof(int),nums6,sizeof(nums6)/sizeof(int));
    printf("findMedianSortedArrays %.2f\n",result);
    int nums7[] = {};
    int nums8[] = {2,3};
    result = findMedianSortedArrays(nums7,sizeof(nums7)/sizeof(int),nums8,sizeof(nums8)/sizeof(int));
    printf("findMedianSortedArrays %.2f\n",result);
    int nums9[] = {2,2,2,2};
    int nums10[] = {2,2,2};
    result = findMedianSortedArrays(nums9,sizeof(nums9)/sizeof(int),nums10,sizeof(nums10)/sizeof(int));
    printf("findMedianSortedArrays %.2f\n",result);
}