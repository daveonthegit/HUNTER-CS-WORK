//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/16/23
//Assignment: Lab 5
//This is a lab on functions and numbers

#include <iostream>
using namespace std;


bool isDivisibleBy(int n, int d){
    if(n%d==0)
        return true;
    else
        return false;
}
bool isPrime(int n){
    for (int i =2;i<n;i++){
        if(isDivisibleBy(n,i))
            return false;
    }
    return true;
}

int nextPrime(int n){
    int prime = n+1;
    while(!isPrime(prime))
        prime++;
    return prime;
}

int countPrimes(int a,int b){
    int num_primes = 0;
    for(int i = a; i<=b;i++){
        if(isPrime(i))
            num_primes++;
    }
    return num_primes;
}

bool isTwinPrime(int n){
    if(isPrime(n)&&(isPrime(n-2)||isPrime(n+2)))
        return true;
    return false;
}

int nextTwinPrime(int n){
    int twin_prime = n+1;
    while(!isTwinPrime(twin_prime))
        twin_prime++;
    return twin_prime;
}

int largestTwinPrime(int a, int b){
    for(int i = b; i>=a;i--){
        if(isTwinPrime(i))
            return i;
    }
    return -1;
}

int main() {
    /*
    int x; int y;//test isDivisibleBy
    cout<<"Input a numerator and denominator seperated by a white space: ";
    cin>>x; cin>>y;
    cout<<"Divisible: ";
    if(isDivisibleBy(x,y))
        cout<<"Yes";
    else
        cout<<"No";
    */
    /*
    int x; //test isPrime
    cout<<"Input an integer greater than or equal to 2: ";
    cin>>x;
    cout<<"Prime: ";
    if(isPrime(x))
        cout<<"Yes";
    else
        cout<<"No";
    */
    /*
    // test nextPrime
    int x; 
    cout<<"Input an integer greater than or equal to 2: ";
    cin>>x;
    cout<<"Next Prime: ";
    cout<<nextPrime(x);
    */
    /*
    //test countPrimes
    int x; int y;
    cout<<"Input a range of integers with white space inbetween: ";
    cin>>x; cin>>y;
    cout<<"# Prime: ";
    cout<<countPrimes(x,y);
    */
    /*
    //test isTwinPrime
    int x; 
    cout<<"Input an integer greater than or equal to 2: ";
    cin>>x;
    cout<<"TwinPrime: ";
    if(isTwinPrime(x))
        cout<<"Yes";
    else
        cout<<"No";
    */
    /*
    //test nextTwinPrime
    int x; 
    cout<<"Input an integer greater than or equal to 2: ";
    cin>>x;
    cout<<"Next Twin Prime: ";
    cout<<nextTwinPrime(x);
    */
    /*
    //test largestTwinPrime
    int x; int y;
    cout<<"Input a range of integers with white space inbetween: ";
    cin>>x; cin>>y;
    cout<<"Largest Twin Prime: ";
    cout<<largestTwinPrime(x,y);
    */
    return 0;
}
