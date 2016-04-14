#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>

using namespace std;

int RollDice(int, float);

int main(){
	int pn;
	float prob, out_d2, out_d12;
	int pn_d2 = 1;
	float prob_d2 = 1.000 / 6.000;
	unsigned int d1 = 0, d2 = 0, dSum = 0;
	int count2 = 0, count12 = 0;

	srand(time(NULL));

	/*輸入pn,prob */
	cout << "pn 為 1~6 之骰子數 " << endl << "prob為pn之機率 0 < prob < 1 " << endl;
	cout << "Please enter pn, prob" << endl;
	cin >> pn >> prob;
	if (pn < 0 || pn > 7 || prob < 0 || prob > 1){
		cout << "error!!" << endl;
		cout << "pn 為 1~6 之骰子數，prob為pn之機率 0 < prob < 1 " << endl;
		system("pause");
		return 0;
	}

	//(1)
	//pn = 1; prob = 0.25;
	//(2)
	//pn = 6; prob = 0.12;

	/* RollDice 10000 */
	for (int i = 0; i < 10000; i++){
		d1 = RollDice(pn, prob);
		//d2為正常骰子
		d2 = RollDice(pn_d2, prob_d2);
		dSum = d1 + d2;
		//cout << "dSum = " << d1 << " + " << d2 << " = " << dSum << endl;
		if (dSum == 2) count2++;
		if (dSum == 12) count12++;
	}

	/*print ans*/
	cout << "pn = " << pn << "," << "prob = " << prob << endl;
	out_d2 = count2 / 10000.0;
	cout << "count2 = " << count2 << endl;
	cout << "out_d2 = " << out_d2 << " ,realprob = " << 0.02778 << endl;
	out_d12 = count12 / 10000.0;
	cout << "count12 = " << count12 << endl;
	cout << "out_d12 = " << out_d12 << " ,realprob = " << 0.02778 << endl;

	system("pause");
	return 0;
}

int RollDice(int pn, float prob){

	int newNum[5];
	for (int i = 0; i < 5; i++){
		newNum[i] = (pn + 1 + i) % 6;
		if (newNum[i] == 0){
			newNum[i] = 6;
		}
		/*check*/
		//cout << newNum[i] << " ";
	}

	int randNum = rand() % 100 + 1;
	//cout << "randNum = " << randNum << endl;
	if (randNum < 100 * prob){
		return pn;
	}
	else {
		int j;
		j = rand() % 5;
		return newNum[j];
	}

}

