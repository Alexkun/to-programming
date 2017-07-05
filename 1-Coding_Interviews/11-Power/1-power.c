/*************************************************************************
	> File Name: 1-power.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 一  7/ 3 14:50:37 2017
 ************************************************************************/


#include <stdio.h>
#include "../commons/common.h"
#include <stdbool.h>

bool equal(double num1, double num2){
	if (num1 - num2 > -DOUBLE_PRECISE
		&& num1 - num2 < DOUBLE_PRECISE)
		return true;
	else
		return false;
}

double power(double base, int exp){
	if (equal(base, 1.0)){
		return 1.0;
	} 
	if (equal(base, 0.0)){ // 0的任何次方为0
		if (exp > 0)
			return 0;
		else{
			fprintf(stderr, "ERR: exp <= 0 when base = 0\n");
			return 0.0;
		}
	}
	if (1 == exp){
		return base;
	}

	unsigned int abs_exp = (unsigned int)exp;
	if (exp < 0)
		abs_exp = (unsigned int)(-exp);

	bool single = (abs_exp % 2 == 0) ? false : true;
	double result = base;
	abs_exp = abs_exp >> 1;
	while (abs_exp != 0){
		result*= result;
		abs_exp = abs_exp >> 1;
	}
	if(single) result*= base;
	if(exp < 0)
		result = 1.0 / result;

	return result;

}


int main()
{
	double base = 1.0;
	int exp = 1;
	printf("power(%f, %d)=%f\n", base, exp, power(base, exp));

	base = -2.3;
	exp = 4;
	printf("power(%f, %d)=%f\n", base, exp, power(base, exp));

	base = -3;
	exp = 3;
	printf("power(%f, %d)=%f\n", base, exp, power(base, exp));

	base = 0.0;
	exp = 3;
	printf("power(%f, %d)=%f\n", base, exp, power(base, exp));

	return 0;
}
