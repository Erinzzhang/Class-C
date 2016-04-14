# USCombination #
----------	

## 程式說明	 ##
>	美金轉換：大鈔換小抄的排列組合種類、數目	<br>
>	$1.0 dollar to 25,10,5,1 cents	<br>
   ----


## main() 和函式呼叫階層

    main()
	|---part1(void) --- printcomb(n, &us1d_ans, 1)
	|			|-------printcomb(double val, int* ans_tms, int printflag)
	|
	|---part1_NOPRINT(&amount)
	|			|---part1_NOPRINT(double *anyDouble) --- printcomb(n, &myans, 0) 
	|								|--------------------printcomb(double val, int* ans_tms, int printflag)
	|
	|---part2(void) --- printcomb(n, &myans, 0)
				|-------printcomb(double val, int* ans_tms, int printflag)		

>#### -- 說明 --
>
    main()
	|---part1 :"由小而大"印出可能之組合，及總組合數 
	|			|-------printcomb(n dollars, 總組合數,印出排列組合)
	|
	|---part1_NOPRINT:印出範圍內不同的美金值之組合總數，並印出增加後的新值
	|			|---part1_NOPRINT(double *anyDouble) 
	|								|--------------------printcomb(n dollars, 總組合數,不印出排列組合)
	|
	|---part2 : 印出範圍內不同的美金值可能之組合總數，並印出Current和After的值，做傳接值的驗證。 
				|-------printcomb(n dollars, 總組合數,不印出排列組合)		



##程式碼---For 迴圈之關聯性
> #### -- 公式 --
> ### n*100 = t25 *25 + t10 *10 + t5 *5 + orgn_val *1 <br>
>
>		ex.100 =  t25  , t10 ,  t5 , orgn_val 	
>			    (  0   ,  0  ,	 0 ,  100   )		tms = 1
>			    (  0   ,  0  ,	 1 ,   95   )		tms = 2
>			    (  0   ,  0  ,	 2 ,   90   )		tms = 3



##輸出之樣本 : 

 
>1 . Part I.n : 以 n= [25c, 10c , 5c, 1c]格式"由小而大"印出可能之組合，並傳回總組合數。 <br>   
 
    	Part I. n = (US$)0.00 格式:[25c, 10c , 5c, 1c] 
    	(0, 0, 0, 100)	(0, 0, 1, 95)	(0, 0, 2, 90)	(0, 0, 3, 85)	(0, 0, 4, 80)	
    	(0, 0, 5, 75)	(0, 0, 6, 70)	(0, 0, 7, 65)	(0, 0, 8, 60)	(0, 0, 9, 55)	
    	(0, 0, 10, 50)	(0, 0, 11, 45)	(0, 0, 12, 40)	(0, 0, 13, 35)	(0, 0, 14, 30)	
    	(0, 0, 15, 25)	(0, 0, 16, 20)	(0, 0, 17, 15)	(0, 0, 18, 10)	(0, 0, 19, 5)
		...
		...........There are 242 combinations.(傳回 242 )




> 2 . Part I.NoPrint_摘要 : 直接印出固定範圍內不同的美金值可能之組合總數，並印出增加後的新值。 <br> 
>

    Part I.NoPrint_摘要 (US$) 0.50 ........There are 49 combinations.(傳回 49 )
    Bonus -- Add One Quarter, 新值=0.75
     
    Part I.NoPrint_摘要 (US$) 0.75 ........There are 121 combinations.(傳回 121 )
    Bonus -- Add One Quarter, 新值=1.00
     
    Part I.NoPrint_摘要 (US$) 1.00 ........There are 242 combinations.(傳回 242 )
    Bonus -- Add One Quarter, 新值=1.25
     
    Part I.NoPrint_摘要 (US$) 1.25 ........There are 424 combinations.(傳回 424 )
    Bonus -- Add One Quarter, 新值=1.50
     
    Part I.NoPrint_摘要 (US$) 1.50 ........There are 680 combinations.(傳回 680 )
    Bonus -- Add One Quarter, 新值=1.75
     
    Part I.NoPrint_摘要 (US$) 1.75 ........There are 1022 combinations.(傳回 1022 )
    Bonus -- Add One Quarter, 新值=2.00
     
    Part I.NoPrint_摘要 (US$) 2.00 ........There are 1463 combinations.(傳回 1463 )
    Bonus -- Add One Quarter, 新值=2.25
     
    Part I.NoPrint_摘要 (US$) 2.25 ........There are 2015 combinations.(傳回 2015 )
    Bonus -- Add One Quarter, 新值=2.50


>3 . Part II . -各種組合 :印出固定範圍內不同的n值可能之組合總數，並印出Current和After的值，做傳接值的驗證。


	Part II . -各種組合
	 Current n = 0.50 ........There are 49 combinations.(傳回 49 )
	 After.. n = 0.50, (接到 49 ) 

	 Current n = 0.75 ........There are 121 combinations.(傳回 121 )
	 After.. n = 0.75, (接到 121 ) 

	 Current n = 1.00 ........There are 242 combinations.(傳回 242 )
	 After.. n = 1.00, (接到 242 ) 

	 Current n = 1.25 ........There are 424 combinations.(傳回 424 )
	 After.. n = 1.25, (接到 424 ) 

	 Current n = 1.50 ........There are 680 combinations.(傳回 680 )
	 After.. n = 1.50, (接到 680 ) 

	 Current n = 1.75 ........There are 1022 combinations.(傳回 1022 )
	 After.. n = 1.75, (接到 1022 ) 

