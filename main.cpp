#include <iostream>
#include <stack>

using namespace std;

stack<int> findPrimesUnder(int limit){ //stack is used for O(k) complexity where k is constant
	stack<int> primes;
	
	for(int i = 2; i <= limit; i++){
		int numFactors = 0;
		for(int j = i-1; j > 1; j--){//anything divided by itself is 1 so can be excluded for efficiency by subtracting 1 from i
									 //also, anything divided by 1 is itself so is excluded for efficiency;
			if (float(i)/j == i/j){
				numFactors++;
			}
		}
		if(numFactors == 0)
			primes.push(i);
		
	}
	
	return primes;
}

int factorial(int n){
	if(n == 1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}

int main(){
	int limit;
	cout << "Enter limit: "; cin >> limit;
	
	stack<int> primes = findPrimesUnder(limit);
	stack<int> wilsonPrimes;
	
	bool descriptive = false;
	
	while(!primes.empty()){
		unsigned long long int firstWilsonCheck = (factorial(primes.top()-1)+1)/primes.top();//((p-1)! + 1)/p is always an int where p is prime
		double secondWilsonCheck = double(firstWilsonCheck)/primes.top();
		
		if(secondWilsonCheck == int(secondWilsonCheck))
			wilsonPrimes.push(primes.top());
		
		if(descriptive){
			cout << "Prime: " << primes.top() << endl;
			cout << "First Check: " << firstWilsonCheck << endl;
			cout << "Second Check: " << secondWilsonCheck << endl;
			
			cout << "------------------------" << endl;
		}
		
		
		primes.pop();
	}
	

	cout << "These are the Wilson Primes under " << limit << ":" << endl;
	while(!wilsonPrimes.empty()){
		cout << wilsonPrimes.top() << endl;
		wilsonPrimes.pop();
		
	}	
	
	return 0;
}