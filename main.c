#include <stdio.h>
#include <stdlib.h>

int getAnsAt(int list,int pos);
int cmp1(const void * a,const void * b){
    return (*(int*)a-*(int*)b);//a>b ·µ»ØÕıÖµ
}
int main(){

    int from =0;
    int to=0xfffff;
    int ans[10]={0,};


    int i,j;
    for(i=from;i<=to;i++){
            int sta[4]={0,};
        for(j=0;j<10;j++){
            ans[j]=getAnsAt(i,j);
            sta[ans[j]]++;
        }

        //q0 pass
        //q1 4th ans is 2301
        if( (ans[1]+2)%4 != ans[4] ){
            continue;
        }
        //q2 2513
        switch (ans[2]){
        case 0:
            if(ans[2]== ans[5] || ans[2]== ans[1] || ans[2]== ans[3])
                continue;
            break;
        case 1:
            if(ans[5]== ans[2] || ans[5]== ans[1] || ans[5]== ans[3])
                continue;
            break;
        case 2:
            if(ans[1]== ans[2] || ans[1]== ans[5] || ans[1]== ans[3])
                continue;
            break;
        case 3:
            if(ans[3]== ans[2] || ans[3]== ans[5] || ans[3]== ans[1])
                continue;
            break;
        }

        //q3
        switch(ans[3]){
        case 0:
            if(ans[0]!=ans[4]) continue;break;
        case 1:
            if(ans[1]!=ans[6]) continue;break;
        case 2:
            if(ans[0]!=ans[8]) continue;break;
        case 3:
            if(ans[5]!=ans[9]) continue;break;
        }

        //q4:
        switch(ans[4]){
        case 0:
            if(0!=ans[7]) continue;break;
        case 1:
            if(1!=ans[3]) continue;break;
        case 2:
            if(2!=ans[8]) continue;break;
        case 3:
            if(3!=ans[6]) continue;break;
        }

        //q5:
        switch(ans[5]){
        case 0:
            if(ans[7]!= ans[1] || ans[7]!=ans[3]) continue;break;
        case 1:
            if(ans[7]!= ans[0] || ans[7]!=ans[5]) continue;break;
        case 2:
            if(ans[7]!= ans[2] || ans[7]!=ans[9]) continue;break;
        case 3:
            if(ans[7]!= ans[4] || ans[7]!=ans[8]) continue;break;
        }

        //q6
        switch(ans[6]){
        case 0:
            if(sta[2]>sta[0]||sta[2]>sta[1]||sta[2]>sta[3]) continue;break;
        case 1:
            if(sta[1]>sta[0]||sta[1]>sta[2]||sta[1]>sta[3]) continue;break;
        case 2:
            if(sta[0]>sta[1]||sta[0]>sta[2]||sta[0]>sta[3]) continue;break;
        case 3:
            if(sta[3]>sta[0]||sta[3]>sta[1]||sta[3]>sta[2]) continue;break;
        }


        //q7
        switch(ans[7]){
        case 0:
            if(ans[6]-ans[0]==1 || ans[6]-ans[0]==-1) continue;break;
        case 1:
            if(ans[4]-ans[0]==1 || ans[4]-ans[0]==-1) continue;break;
        case 2:
            if(ans[1]-ans[0]==1 || ans[1]-ans[0]==-1) continue;break;
        case 3:
            if(ans[9]-ans[0]==1 || ans[9]-ans[0]==-1) continue;break;
        }

        //q9
        switch(ans[8]){
        case 0:
            if(   !((ans[0]==ans[5] && ans[5]!=ans[4]) ||  (ans[0]!=ans[5] && ans[5]==ans[4]))   )
                continue;
            break;
        case 1:
            if(   !((ans[0]==ans[5] && ans[9]!=ans[4]) ||  (ans[0]!=ans[5] && ans[9]==ans[4]))   )
                continue;
            break;
        case 2:
            if(   !((ans[0]==ans[5] && ans[1]!=ans[4]) ||  (ans[0]!=ans[5] && ans[1]==ans[4]))   )
                continue;
            break;
        case 3:
            if(   !((ans[0]==ans[5] && ans[8]!=ans[4]) ||  (ans[0]!=ans[5] && ans[8]==ans[4]))   )
                continue;
            break;

        }

        //q10
        qsort(sta,4,sizeof(int),&cmp1);
        int distan=abs(sta[0]=sta[2]);
        switch(ans[9]){
            case 0: if(distan!=3)continue;break;
            case 1: if(distan!=2)continue;break;
            case 2: if(distan!=4)continue;break;
            case 3: if(distan!=1)continue;break;
        }


        for(j=0;j<10;j++){
            printf("%c",ans[j]+'A');
        }
        printf("\n");

    }



    return 0;
}


int getAnsAt(int list,int pos){
    if(pos>=0 && pos<10){
        return (list>>(pos*2)) % 4;
    }
    else{
        return -1;
    }
}
