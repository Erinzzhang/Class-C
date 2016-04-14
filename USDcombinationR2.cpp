// Revised - USCombinationR2.cpp  -Date: May-17-2011 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define B 5
#define C 10
#define D 25

void printcomb(double, int *, int ); // pass-by-address

void part1(void);
void part1_NOPRINT( double *); 

void part2(void);

void main(){
    double amount; 
    part1();  //  ONE-Dollar used as BASE case.
    // 
    amount = 0.5;
    do {
        part1_NOPRINT( &amount );  // pass-by-Address 
        //amount += 0.25 ;  // NOTE-- who change it ? 
        }
    while ( amount < 2.5);
    
    part2();
}

void part1(){
    int n = 1;  // should be DOUBLE value 1.0 
    int us1d_ans; 
    printf("\nPart I. n = (US$)%.2f �榡:[25c, 10c , 5c, 1c] ", (double)n);
    printcomb(n,&us1d_ans, 1 );
}

void part1_NOPRINT(double *anyDouble ){
    int any_ans; 
    if ( *anyDouble < 0 | *anyDouble > 5.0 ) {
        printf ("Error -- INVALID AMOUNT %.4f \n", *anyDouble);
        return;
        };
    
    
    printf("\nPart I.NoPrint_�K�n (US$) %.2f ",*anyDouble );
    printcomb(*anyDouble,&any_ans, 0 );
    // change it -- so, it will be returned to calling part. 
    *anyDouble += 0.25 ;   //
    printf("Bonus -- Add One Quarter, �s��=%0.2f\n ", *anyDouble );
    return ;
}

void part2(){
    double n;
    int  myans;
    printf("\nPart II . -�U�زզX\n");
    for ( n = .5; n < 2.0; n += .25){
        myans = 0;   // always need to reset it...
        printf("\t Current n = %.2f ", n);
        printcomb(n, &myans, 0);   // pass by address 
        printf("\t After.. n = %.2f, (���� %d ) \n\n", n, myans);
    }
    return;
}

void printcomb( double val, int* ans_tms, int printflag){
    double t25, t10, t5, orgn_val = 100.0*val, temp5, temp10, tms = 0;
    
    for ( t25 = 0; t25 <= orgn_val/D; t25++){
        orgn_val -= t25 * 25;   
        for ( t10 = 0; t10 <= orgn_val/C; t10++){
            temp10 = orgn_val;
            orgn_val -= t10 * 10;
            for ( t5 = 0; t5 <= orgn_val/B; t5++){
                if (int(tms) % 5 == 0 & printflag==1 )
                    {   printf("\n\t");
                    }
                // Do the job....     
                temp5 = orgn_val;
                orgn_val -= t5 * 5;
                if (printflag == 1) {
                   printf("(%.0f, %.0f, %.0f, %.0f)\t", t25, t10, t5, orgn_val);
                }
                tms++;
                orgn_val = temp5;
            } // End of Loop_t5 
            orgn_val = temp10; 
        } // End of Loop_t10
        orgn_val = 100*val;
    } //End of Loop_t25
    *ans_tms = tms;  //  the VALUE of (  ) is  "tms"
    printf("........There are %.0f combinations.(�Ǧ^ %d )\n", tms, *ans_tms);
}