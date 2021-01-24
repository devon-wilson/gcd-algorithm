#include <iostream> 
#include <string>
#include <gmpxx.h>

using namespace std;

int main()
{
	mpz_class inputA, inputB, hardA, hardAA, tempA, tempB, remainder, quotient, quotientA, result, preResult; 
	string valA, valB, valR;
	cout << endl;						
	cout << "Enter an integer(A) that is 1 or greater and 2^50 or less: " << endl;
	cout << endl;
	getline(cin, valA); 
	cout << endl;										
        cout << "Enter a second integer(B) such that it is less than the first and is 1 or greater " << endl; 
	cout << "(1 <= A <= 2^50 and 1 <= B < A)" << endl;
	cout << endl;
        getline(cin, valB);
	cout << endl;
	cout << "First value " << valA;
        cout << " Second value " << valB << endl;
	cout << endl;
	inputA = valA.c_str();                             
        inputB = valB.c_str();
	hardAA = inputA;
	tempA = inputA;
	hardA = inputA;
	tempB = inputB;
	quotientA;
	quotient = 0;
	remainder = 0;	
	preResult = 0;
	do                             
        {                               
                inputA = inputA - inputB;
        	quotientA++;
        }while(inputA >= inputB);
	cout << "a(" << hardA << ") = d(" << inputB << ") * q(" << quotientA << ") + r(" << inputA << ") " << endl; 
	cout << endl;
	do
	{
		do				//this loop takes the larger value(n) and the smaller value(d) and it finds the quotient and remainder
		{				//this loop that finds the quotient and remainder is using the division algorithm
			tempA = tempA - tempB;
			quotient++;
		}while(tempA >= tempB);			
		if(tempA != 0)			//after we have found the quotient and remainder of our original quotient, we swap the larger(a) and the smaller(d) with its quotient and remainder
		{				//and we repeat the process(euclids algorithm) until we reach zero 
			preResult = tempA;	//here we store the remainder each through each iteration, until remainder is zero, than we stop because the remainder previous to zero is our GCD(euclid)
		}
		remainder = tempA;		//here we have to follow euclid and replace our a(tempA) with our d(tempB) and replace our d(tempB) with our remainder
		tempA = tempB;
		tempB = remainder;
		quotient = 0;			//quotient must be reset each iteration because we treat each iteration and value as a new quotient(euclid)
	}while(remainder != 0);
	cout << endl;
	cout << "GCD of " << hardAA << " and " << inputB << " is "  << preResult << endl;
	cout << endl;
	//
	//
	//
	//
	//
	/* 		My GCD algorithm, this is how I would have done it, and did do it for practice, however it uses the 'mod' function and simply stores all divisors of both values at once, and 
	//		loops through the array comparing each value each iteration and at the end what is the greatest value in the array(GCD)
	int valA, valB;
        int checker = 0;
	cout << "Enter an integer(A) that is 1 or greater and 2^50 or less: " << endl;
        getline(cin, valA);
        cout << endl;                                           
        cout << "Enter a second integer(B) such that it is less than the first " << endl;
        cout << "and is 1 or greater(1 <= A <= 2^50 and 1 <= B < A)" << endl;
        getline(cin, valB);
	for(int i = 1; i < inputA + 1; i++)	//loop through each number smaller than the second(smaller) number, because a GCD has to divise both values(must be smaller to do so)		
	{
		remainder = i;			//remainder represents each current value starting from one(denominator != 0)  
		if(inputA % remainder == 0 && inputB % remainder == 0 && remainder < inputB) //mod each remainder to our larger number(numerator) 
		{
			array[counter] = i; 	// if the current value(remainder) divides both values inputted and is still less than both we want to store that number
			cout << "current gcd " << array[counter]  << endl;
			counter++;		// we have to increment our counter once each time this happens, so we know the size or array(amount of common divisors) for our loop
		}
	}
	for(int h = 0; h < counter - 1; h++)	// this is our loop, we go through the array of common divisors, we compare each with the next and if the current one is the greater
	{					// of the two than we want to set our 'result'(GCD) to that value, and at the end we will have the greatest value(GCD)
		tempA = array[h];
		tempB = array[h + 1];
		if(tempA < tempB)
		{
			tempA = tempB;
		}
	}
	result = tempB;
	cout << "The GCD is, " << tempB << endl;
	*/	
	return 0;
}
