/*
 * Scanner.h
 *
 *  Created on: 29 May 2019
 *      Author: Erdinc
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "Token.h"
#include <iostream>
#include <string>

using namespace std;
class Scanner :public Token{
private:
	istream* input;
	int row,column;
	const static int maxState=4,startState=0,noEdge=-1;
	int automata[maxState+1][256];
	int finite[maxState+1];
public:
	void initAutomata();
    Token lastToken;
protected:
	int getnextState(int aState,int aChar)const;
	bool isFiniteState(int aState);
	int getFiniteState(int aState);
private:
	int peek();
	int read();
	bool eof();
public:
	const static int tLexError=-1;
	const static int tIgnore=0;
	const static int tInteger=1;
	const static int tOperator=2;
	const static int tSeparator=3;

	Scanner(istream *aInput);
	Token nextToken();
	Token currentToken();
	Token nextTokenImp();
};

#endif /* SCANNER_H_ */
