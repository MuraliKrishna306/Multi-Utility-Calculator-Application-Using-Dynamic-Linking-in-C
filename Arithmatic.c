#include<stdio.h>
//arithmatic operations

float add(float a, float b) {   return a+b;    }

float sub(float a, float b) {   return a-b;    }

float mul(float a, float b) {   return a*b;    }

float divi(float a, float b) {   return a/b;    }

float mod(float a, float b) {   int a1=a,b1=b;  a=a1%b1;    return a;    }

float power(float a, float b)   {    int i=b;    float n=1;    while(i--)  {    n*=a;    }   return n;     }

float factorial(float a, float b)   {    for(int n=a-1;n;n--)    {    a*=n;    }    return a;  }
