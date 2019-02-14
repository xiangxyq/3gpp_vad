#include "vad1.h"
#include "copy.h"
#include "cnst.h"
#include <stdio.h>

//#define L_FRAME (160)
int main()
{
    vadState1 *vadSt;
    vad1_init(&vadSt);
    Word16 vad_flag;
    int count = 0;
    FILE *fp = fopen("../vad.pcm","r");

    FILE *fw = fopen("../processed.pcm","w");

    Word16 new_speech[L_FRAME];
    while(fread(new_speech,sizeof(Word16),L_FRAME,fp) == L_FRAME){
        /* code */
        vad_flag = vad1(vadSt, new_speech);
        printf("vad flag %d \n", vad_flag);
        count++;

        if (vad_flag)
        {
            fwrite(new_speech,sizeof(Word16),L_FRAME,fw);
        }
    }
    
    printf("count %d ", count);
     
    //Copy(new_speech, st->new_speech, L_FRAME);  
    return 0;
}