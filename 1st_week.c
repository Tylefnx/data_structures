/*
Data Structures Week 1

Recursive Functions: It's a function who repeats itself until some conditions are satisfied.
(A problem solving technique that reduces large problems to tmaller problems of the *same form*).

*/
#include <stdio.h>


/*Factorial example*/

/*int fac(int x){
	if(x > 0){
		return x * fac(x-1);
	}
	else {
		return 1;
	}
}

int main()
{
	int x = 5;
	printf("%d! = %d", x, fac(x));
}
*/



/*Another example*/
/*
int calculate(int x){
	printf("%d", x);
	if(x < 9)
		calculate(x+1);
	printf("%d",x);
}

int main(){
	calculate(1);
}
*/



/*Structures in C: A structure is a collection of variables under a single name*/

/*Defining a structure in c*/

/*
   struct complex{
	int real;
	int img;
};
*/

/*Alternative ways of declaring structures*/
/*

int main() {
	typedef struct{
		int id;
		char *name;
		float grade;
	} Student;

	Student tylefnx;
}
*/
