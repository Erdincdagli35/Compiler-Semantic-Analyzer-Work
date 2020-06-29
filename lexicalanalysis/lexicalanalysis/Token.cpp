#include "Token.h"
#include <string>
#include <iostream>

//Token::Token():lexem("");

Token::Token(const std::string& aLexem, int aColumn, int aRow, int aToken,bool aEof)
:lexem(aLexem),column(aColumn),row(aRow),token(aToken),eof(aEof)
{
    
}
Token::Token():lexem(""){
    
}
const std::string Token::getLexem() const {
    return lexem;
}

const int Token::getRow() const {
    return row;
}

const int Token::getColumn() const {
    return column;
}

const int Token::getToken() const {
    return token;
}

const bool Token::isEof() const {
    return eof;
}
std::ostream& operator <<(std::ostream &out ,const Token&aToken){
    out<<"'"<<aToken.getLexem()<<"' "<<aToken.getToken()<<
    " ("<<aToken.getRow()<<", "<<aToken.getColumn()<<") ";
    return out;
}

Token::~Token()
{
    
}

