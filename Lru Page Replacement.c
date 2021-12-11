#include<stdio.h>
#include<conio.h>

int main(){
    int pages,f,string[50],frames[50];
    printf("Enter pages: ");
    scanf("%d",&pages);

    printf("Enter frames: ");
    scanf("%d",&f);

    for(int i=0;i<pages;i++){
        scanf("%d",&string[i]);
    }

    for(int i=0;i<f;i++){
        frames[i] = -1;
    }

    int index=-1;
    int page_faults=0;
    int page_hits=0;

    for(int i=0;i<pages;i++){
        int symbol=string[i];
        int full=0;
        int flag=0;
        for(int j=0;j<f;j++){
            if(symbol==frames[j]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            page_hits++;
        }
        else{
            if(full==0){
                index=(index+1)%pages;
                frames[index]=symbol;
                page_faults++;
            }
            else{
                int pos=999;
                int index=-1;
                for(int j=0;j<f;j++){
                    for(int k=0;k<pages;k++){
                        if(frames[j]==string[k]){
                            if(pos>k){
                                pos=k;
                                index=j;
                                break;
                            }
                        }
                    }
                }
                frames[index] = symbol;
            }
        }
    }

    printf("Pages Faults: %d",page_faults);
    printf("\nPage Hits: %d",page_hits);
    printf("\nPage Fault Ratio: %.2f",(float)page_faults/pages);
    printf("\nPage Hit Ratio: %.2f",(float)page_hits/pages);
}
