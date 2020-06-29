/*
 * Scanner.cpp
 *
 *  Created on: 29 May 2019
 *      Author: Erdinc
 */

#include "Scanner.h"
#include "Token.h"
#include <string>
#include <iostream>
using namespace std;

void Scanner::initAutomata() {
	for (int i = 0; i<=maxState; i++) {
		for (int j = 0; j<256; j++){
		automata[i][j] = noEdge;
	}
	for (int i = '0'; i<='9'; i++)
		{
		automata[0][i] = automata[1][i] = 1;
		automata[0]['+'] = automata[0]['*'] = 2;
		automata[0]['('] = automata[0][')'] = 3;
		automata[0]['\n']=automata[0][' ']=automata[0]['\t']=4;
		automata[4]['\n']=automata[4][' ']=automata[4]['\t']=4;
		finite[0] = tLexError;
		finite[1] = tInteger;
		finite[2] = tOperator;
		finite[3] = tSeparator;
		finite[4] = tIgnore;
		}

	}
//	cout<<automata[1][1];

}

int Scanner::getnextState(int aState, int aChar) const {
	if(aChar==-1)
		return noEdge;
	return automata[aState][aChar];
}

bool Scanner::isFiniteState(int aState) {
	return finite[aState]!=tLexError;
}

int Scanner::getFiniteState(int aState) {
	return finite[aState];
}

int Scanner::peek() {
	return input->peek();
}

int Scanner::read() {
	int temp= input->get();
	column++;
	if(temp=='\n'){
		row++;
		column=1;
	}
	return temp;

}

bool Scanner::eof() {
	return peek()==-1;
}



Token Scanner::nextTokenImp() {
	int currentState=startState;
		std::string lexem;
		int startColumn=column;
		int startRow=row;
		int tempState;

		do{
			tempState=Scanner::getnextState(currentState,peek());
//			tempState=getNextState(currentState,peek());
			if(tempState!=noEdge)
			{
				currentState=tempState;
				lexem+=(char)read();

			}
			else{
				if(isFiniteState(currentState)){
					Token token(lexem,startColumn,startRow,getFiniteState(currentState),eof());
					if(token.getToken()==tIgnore)
						return nextToken();
					else
						return token;
				}
				else
					return Token("",startColumn,startRow,tLexError,eof());

			}

		}
		while(true);
}
//Scanner::Scanner(istream* aInput) {

//}
Scanner::Scanner(istream *aInput) {
	row=1;
	column=1;
	initAutomata();
	input=aInput;
}
Token Scanner::nextToken() {
	return lastToken=nextTokenImp();
}

Token Scanner::currentToken() {
	return lastToken;
}


//Scanner::~Scanner() {
//	// TODO Auto-generated destructor stub
//}

