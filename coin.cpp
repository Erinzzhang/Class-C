#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>

using namespace std;

int RollDice(float, float, float);

int main(){
	float p1, p2, p3;
	unsigned int blue = 0,check = 0;
	double prob;
	srand(time(NULL));
	cout << "輸入為出現三枚正面的理論機率(變數名 p1,p2,p3, 三者機率介於0.0~1.0)" << endl;
	cout << "Please enter p1, p2 , p3" << endl;
	cin >> p1 >> p2 >> p3;
	if (p1 > 1 || p1 < 0 || p2 >1 || p2 < 0 || p3 > 1|| p3 < 0){
		cout << "You idiot!" << endl;
		return 0;
	}
	for (int count = 0; count < 10000; count++) { 
		check = RollDice(p1, p2, p3);
		/*cout << check ;*/
		if (check == 1) blue++; 
	}
	prob = double(blue)/10000;
	cout << "藍色的機率是" << setprecision(4) << prob << " ,百分比為" << prob *100 << "%" << endl;
	system("pause");
	return 0;
}

int RollDice(float p1, float p2, float p3){
	int x = 0;

	float p[] = { p1, p2, p3 };
	for (int i = 0; i < 3; i++){
		if (rand() % 100 + 1 < 100 * p[i]) x++;
	}
	if (x >= 2) return 1;
	else return 2;	
}
