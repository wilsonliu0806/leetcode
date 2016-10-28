#define NUM_MIN 0xFFFF

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int lend= nums1Size-1;
    int lstart = 0;
    int rend= nums2Size-1;
    int rstart = 0;
    int totaldel = nums1Size + nums2Size;
    totaldel = (totalcnt-2+(totalcnt%2))/2;
    int totalcnt = -1*((nums1Size + nums2Size)%2)+2;
    int nummax;
    int lNumMax;
    int rNumMax;
    double dbResult[2];
    while(1){
        if(lend<0){
            lNumMax = NUM_MIN;
        }else{
            lNumMax = nums1[lend];
        }
        if(rmaxpos<0){
            rNumMax = NUM_MIN;
        }else{
            rNumMax = nums2[rmaxpos];
        }
        if(lNumMax<rNumMax){
            if(lNumMax < nums2[(rend+rstart)/2]){
                if(totalcnt>(rend-rstart+1)/2){
                    totalcnt -=rmaxpos;
                }else{
                    int pos = (rend+rstart)/2+ totalcnt - 1; 
                    dbResult[1]=nums2[pos];
                    if(totalcnt == 1){
                        break;
                    }else if(lNumMax < nums2[pos-1]){
                        dbResult[0]=nums2[pos-1];
                    }else{
                        dbResult[0]=lNumMax;
                    }
                }
            }
        }else{
            //...
        }

    }
    }
}