// Revised - USCombinationR2.cpp  -Date: May-17-2011 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define B 10
#define C 50
#define D 25

void printcomb(double, int *, int); // pass-by-address

void part1(void);
void part1_NOPRINT(double *);

void part2(void);

void main(){
	double amount;
	part1();  //  ONE-Dollar used as BASE case.
	// 
	amount = 10;
	do {
		part1_NOPRINT(&amount);  // pass-by-Address
		//amount += 10 ;  // NOTE-- who change it ?
	} while (amount < 60);

	part2();
	system("pause");
}

void part1(){
	int n = 99;  // should be DOUBLE value 1-99
	int us1d_ans;
	printf("\nPart I. n = (TWD)%.0f 格式:[ 50c , 10c, 1c] ", (double)n);
	printcomb(n, &us1d_ans, 1);
}

void part1_NOPRINT(double *anyDouble){
	int any_ans;
	if (*anyDouble < 0 | *anyDouble > 100) {
		printf("Error -- INVALID AMOUNT %.4f \n", *anyDouble);
		return;
	};


	printf("\nPart I.NoPrint_摘要 (NT) %.2f ", *anyDouble);
	printcomb(*anyDouble, &any_ans, 0);
	// change it -- so, it will be returned to calling part. 
	*anyDouble += 10;   //
	printf("Bonus -- Add One Quarter, 新值=%0.2f\n ", *anyDouble);
	return;
}

void part2(){
	double n;
	int  myans;
	printf("\nPart II . -各種組合\n");
	for (n = 15; n < 50; n += 5){
		myans = 0;   // always need to reset it...
		printf("\t Current n = %.2f ", n);
		printcomb(n, &myans, 0);   // pass by address 
		printf("\t After.. n = %.2f, (接到 %d ) \n\n", n, myans);
	}
	return;
}

void printcomb(double val, int* ans_tms, int printflag){
	double t25, t50, t10, orgn_val = 1.0*val, temp10, temp50, tms = 0;

 
	for (t50 = 0; t50 <= orgn_val / C; t50++){	
		temp50 = orgn_val;	
		orgn_val -= t50 * 50;
		for (t10 = 0; t10 <= orgn_val / B; t10++){	
			if (int(tms) % 10 == 0 & printflag == 1)
			{
				printf("\n\t");
			}
			// Do the job....     
			temp10 = orgn_val;
			orgn_val -= t10 * 10;
			if (printflag == 1) {
				printf("(%.0f, %.0f, %.0f)\t", t50, t10, orgn_val);
			}
			tms++;
			orgn_val = temp10;
		} // End of Loop_t10
		orgn_val = temp50;
	} // End of Loop_t50

	*ans_tms = tms;  //  the VALUE of (  ) is  "tms"
	printf("........There are %.0f combinations.(傳回 %d )\n", tms, *ans_tms);
}