# USCombination #
----------	

## 程式說明	 ##
>	美金轉換：大鈔換小抄的排列組合種類、數目	<br>
>	$1.0 dollar to 25,10,5,1 cents	<br>
    
-				
## main code			

###1 . #include,#define
>定義函式庫、宣告function、參數，定義function參數資料型態	<br>	
>>	a.	int * : pass-by-address  
>>	---	其中: * 的意思是『指標Pointer』指標是用來儲存記憶體位址的	<br>
>>	---	相對應: &的意思就是要領出該變數的『位址』	<br>
>>	b.	long
		
>	
    // Revised - USCombinationR2.cpp  -Date: May-17-2011 
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #define B 5
    #define C 10
    #define D 25
>    
    void printcomb(double, int *, int); // pass-by-address
>   
    void part1(void);
    void part1_NOPRINT(double *);
>    
    void part2(void);
>    
 
###2.main function
>呼叫part1、part1_NOPRINT、part2 function 執行
>>	a.	&amount : pass-by-address  
>>	---	相對應: &的意思就是要領出該變數的『位址』，&amount的話是把記憶體位址給對方 <br>
>>	---	其中: * 的意思是『指標Pointer』指標是用來儲存記憶體位址的	<br>
>>	b.	do{ }while() : 先執行do{} 中之程式碼，在由while()中之判斷是進行執行與否之判斷	<br>
>>	---	amount 由 0.5 開始，每次加 0.25 直到 amount >= 0.5 為止， <br>
>>	--- 故此程式僅從 amount=0.5 執行至 amount = 2.25 ，<br>
>>	---	每次amount值經由part1_NOPRINT function 增加0.25後回傳。	
> 
>    
    void main(){
    	double amount;
    	part1();  //  ONE-Dollar used as BASE case.
    	// 
    	amount = 0.5;
    	do {
    		part1_NOPRINT(&amount);  // pass-by-Address 
    		//amount += 0.25 ;  // NOTE-- who change it ? 
    	} while (amount < 2.5);
>    
    	part2();
    	system("pause");
    }


##Function code

###1 . part1()
>part1 function: 以 one-dollar 為Base case 進行排列組合。
>>a.	int n : n為有多少dollar ，此處設n=1,以one-dollar為例	<Br>
>>b.	printf : 印出part1()執行之說明 "Part I. n = (US$)1.00 格式:[25c, 10c , 5c, 1c] "	<br>
>>c.printcomb(n, &us1d_ans, 1)	<br>
  --- printcomb(n dollars ,接收 n dollars 排列組合總值，印出結果)
>   
    void part1(){
    	int n = 1;  // should be DOUBLE value 1.0 
    	int us1d_ans;
    	printf("\nPart I. n = (US$)%.2f 格式:[25c, 10c , 5c, 1c] ", (double)n);
    	printcomb(n, &us1d_ans, 1);
    }



###2 . part1_NOPRINT(double *anyDouble)
>part1_NOPRINT function : 印出 <5.0 & >0  之 dollar 數會有幾種排列組合 
>>	a. double *anyDouble : 任何double型態的數值， *anyDouble 代表多少dollars <br>
>>	--- *anyDouble 指向 main func. 中的 &amount 
>>	b. printf("Error -- ...") : 當 *anyDouble 值 >5.0 | <0 時print error <br>
>>	c. printcomb(*anyDouble, &any_ans, 0) <br>
>>	d. *anyDouble += 0.25 : 每次值增加0.25


>>--- printcomb(input n dollars to *"anyDouble"*, output 有幾種排列組合 to *"any_ans"*, 不印出排列組合之結果);


>    
    void part1_NOPRINT(double *anyDouble){
    	int any_ans;
    	if (*anyDouble < 0 | *anyDouble > 5.0) {
    		printf("Error -- INVALID AMOUNT %.4f \n", *anyDouble);
    		return;
    	};
    
>    
    	printf("\nPart I.NoPrint_摘要 (US$) %.2f ", *anyDouble);
    	printcomb(*anyDouble, &any_ans, 0);
    	// change it -- so, it will be returned to calling part. 
    	*anyDouble += 0.25;   //
    	printf("Bonus -- Add One Quarter, 新值=%0.2f\n ", *anyDouble);
    	return;
    }

###3 . part2() 
>印出 0.5 ~ 1.75 dollars 有幾種排列組合，dollars 數每次增加0.25 dollars
>> a. myans : 作為 &myans 傳回值是否正確之確認，故每次迴圈都需reset <br>
>> b. n : 為目前的 dollars 數，以%.2f 形式印出 <br>
>> c. printcomb(n, &myans, 0) <br>
>>	--- printcomb(n dollars, 傳出值到myans,不印出排列組合)
>
>    
    void part2(){
    	double n;
    	int  myans;
    	printf("\nPart II . -各種組合\n");
    	for (n = .5; n < 2.0; n += .25){
    		myans = 0;   // always need to reset it...
    		printf("\t Current n = %.2f ", n);
    		printcomb(n, &myans, 0);   // pass by address 
    		printf("\t After.. n = %.2f, (接到 %d ) \n\n", n, myans);
    	}
    	return;
    }


###4 . printcomb(double val, int* ans_tms, int printflag)
>利用迴圈將各項排列組合的可能列出
>>
>> - function <br>
>>	 -- founction 參數 -- <br>
>> a. double val : 有多少dollars <br>
>> b. int* ans_tms : 將排列組合的可能總數傳回 <br>
>> c. int printflag : 若printflag 值= 1 ,則將各個排列組合印出 <br> 		
>		
>>		-- founction 說明 -- <br>
>>   	將 n dollars 乘以100 換成 n *100 cents ，再以for迴圈的方式找出(25,10,5,1)cents的各種排列組合 <br>
>>	
>>	- for 迴圈 <br>
>> 	function 共三層for 迴圈,由每層迴圈分別計算25,10,5cents & 1cent 的可能數目。 <br>
>>	for 迴圈由內而外執行，故排列組合之結果由小而大印出。 <br><br>	
>>		-- 參數說明 -- <br>
>>		a. t25,t10,t5 : 25,10,5 cents 個數 <br>
>>		b. temp5 : 作為 t5迴圈中儲存原有orgn _ val(cents數)的暫存，temp5=val * 100 - t25 * 25 - t10 * 10 cents <br>
>>		c. temp10 : 作為 t10迴圈中儲存原有orgn _ val(cents數)的暫存，temp10=val * 100 - t25 * 25 cents <br>
>>		d. tms : 計算有幾種組合數 <br>
>>		e. orgn _ val : orgn _ val = 100 * val ，為dollar轉換為 cents 之數值 ，同時也被當作 1 cent 數目之計算值 <br>
>>		
>>		-- 數學公式 (t25,t10,t5之關聯性) -- <br>
>>		n*100 = t25 *25 + t10 *10 + t5 *5 + orgn_val *1 <br>
>>
>>			ex.100 =  t25  , t10 ,  t5 , orgn_val 	
>>				    (  0   ,  0  ,	 0 ,  100   )		tms = 1
>>				    (  0   ,  0  ,	 1 ,   95   )		tms = 2
>>				    (  0   ,  0  ,	 2 ,   90   )		tms = 3
>> 
>>##
>>### /* --- printcomb function code各行之解說 --- */
	// 參數型態定義 printcomb(n dollars, 傳出排列組合數目總值 ,判定是否印出排列組合)
	// 宣告之後會用到的參數型態		
    /* ---for迴圈進行排列組合計算--- */
	// 最外層 : 計算t25之可能數 ，t25 最大值 < 原有cents數 / 25 ，D = 25 
	// 每次增加一次 t25 ,orgn_val 扣除 t25 *25cents 
	// 第二層 : 計算t10之可能數 ，t10 最大值 < 原有cents數 / 10 ，C = 10
	// 以temp10 先暫存原有cents數，以保持每次for迴圈開始時都是由原有的值(val*100-t25*25cents)開始 
	// 每次增加一次 t10 ,orgn_val 扣除 t10 *10cents 
	// 最內層 ： 計算t5之可能數 ，t5 最大值 < 原有cents數 / 5 ，B = 5
	// 當每五個組合列產生且需要印出組合列(printflag == 1)時，進行"跳行空格(\n\t)"的動作
	// 以temp5 先暫存原有cents數，以保持每次for迴圈開始時都是由原有的值(val*100-t25*25-t10*10 cents)開始 
	// 每次增加一次 t5 ,orgn_val 扣除 t5 *5cents
	// 若 printflag == 1，印出(t25,t10,t5,t1)之值
	// 排列組合可能總數加一
	// 將被改變之orgn_val回復到原有的值(val*100-t25*25-t10*10 cents)
	// 將被改變之orgn_val回復到原有的值(val*100-t25*25 cents)
	// 將被改變之orgn_val回復到原有的值(val*100 cents)
    // *ans_tms = tms ，將排列組合可能總數(tms)由 *ans_tms 傳出到指定"&空間"
	// 印出"排列組合可能總數"及"傳回的值"
>>##
>
    void printcomb(double val, int* ans_tms, int printflag){
    	double t25, t10, t5, orgn_val = 100.0*val, temp5, temp10, tms = 0;
    	for (t25 = 0; t25 <= orgn_val / D; t25++){
    		orgn_val -= t25 * 25;
    		for (t10 = 0; t10 <= orgn_val / C; t10++){
    			temp10 = orgn_val;
    			orgn_val -= t10 * 10;
    			for (t5 = 0; t5 <= orgn_val / B; t5++){
    				if (int(tms) % 5 == 0 & printflag == 1)
    				{
    					printf("\n\t");
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
    		orgn_val = 100 * val;
    	} //End of Loop_t25
    	*ans_tms = tms;  //  the VALUE of (  ) is  "tms"
    	printf("........There are %.0f combinations.(傳回 %d )\n", tms, *ans_tms);
    }

