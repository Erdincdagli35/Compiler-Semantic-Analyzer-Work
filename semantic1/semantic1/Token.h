/*
 * Token.h
 *
 *  Created on: 29 May 2019
 *      Author: Erdinc
 */

#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
#include <iostream>


class Token {
    friend std::ostream& operator <<(std::ostream &out ,const Token&aToken);
    
private:
    std::string lexem;
    int column,row,token;bool eof;
public:
    Token(const std::string& aLexem,int aColumn,int aRow,int aToken,bool aEof);
    Token();
    virtual ~Token();
    
    const std::string getLexem()const;
    const int getRow()const;
    const int getColumn()const;
    const int getToken()const;
    const bool isEof()const;
    
};

#endif /* TOKEN_H_ */
