#include <iostream>
#include <stack>
#include "Verbose.h"

using namespace std;



int main(){

	stack<int> p;
	
	cout << "Introduce los caracteres(CTRL*D para parar): ";

	int n;

	while(cin>>n){
		p.push(n);
	}

	while (! p.empty() )
	{
	    cout << p.top() << " " ;
	    p.pop();
	}

	cout << endl;

	return 0;
}