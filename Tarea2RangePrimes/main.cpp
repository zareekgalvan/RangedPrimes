//
//  main.cpp
//  Tarea2RangePrimes
//
//  Created by Zareek Galvan on 8/17/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

//=======================================================================================================================
bool isPrime(int intNumber)
{
    if (intNumber == 2 || intNumber == 3)
    {
        return true;
    }
    
    if (intNumber % 2 == 0 && intNumber != 2)
    {
        return false;
    }
    
    if (intNumber % 3 == 0 && intNumber != 3)
    {
        return false;
    }
    
    for (int i = 3; i*i <= intNumber; i += 2)
    {
        if (intNumber % i == 0)
        {
            return false;
        }
    }
    return true;
}

//=======================================================================================================================
int subPrevPrime(int intNumber)
{
    if (isPrime(intNumber))
    {
        return intNumber;
    }
    
    int intPrevPrime = intNumber - 1;
    
    while (!isPrime(intPrevPrime))
    {
        intPrevPrime -= 1;
    }
    
    return intPrevPrime;
}

//=======================================================================================================================
int subNextPrime(int intNumber)
{
    if (isPrime(intNumber))
    {
        return intNumber;
    }
    
    int intNextPrime = intNumber + 1;
    
    while (!isPrime(intNextPrime))
    {
        intNextPrime += 1;
    }
    
    return intNextPrime;
}

//=======================================================================================================================
int main()
{
    int intTimes;
    cin >> intTimes;
    
    for (int intI = 0; intI < intTimes; intI++)
    {
        int intNumber;
        cin >> intNumber;
        cout << subPrevPrime(intNumber) << " " << subNextPrime(intNumber) << endl;
    }
}
