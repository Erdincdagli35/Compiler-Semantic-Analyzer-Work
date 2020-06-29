//============================================================================
// Name        : 1.cpp
// Author      : Erdinc Dagli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
#include <fstream>
#include "Token.h"
#include "Scanner.h"
using namespace std;

int main() {

	string line;
	  ifstream myfile ("Input.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      cout << line << '\n';
	      Scanner s(&myfile);
	      for(int i=0;i<12;i++){
	      	  s.initAutomata();
	      	  cout<<s.currentToken()<<endl;
	      }

	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";



	/*
	string s;
	cin>>s;

	cout<<s;
	Scanner temp1(s);
  // istream is(&a);
//	Scanner temp1(is);
 */
	/*
	filebuf fb;
	  if (fb.open ("C:/Users/Erdinc/Desktop/deneme.txt",std::ios::in))
	  {
		  istream is(&fb);
		  while (is)


		  fb.close();

	  }
	  */

	  return 0;
	}
