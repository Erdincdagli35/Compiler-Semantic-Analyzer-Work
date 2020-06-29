//
//  main.cpp
//  LL(1)parser
//
//  Created by Elessar Telcontar on 22/06/2019.
//  Copyright © 2019 Elessar Telcontar. All rights reserved.
//
#include <string>
#include <iostream>
#include <fstream>
#include "Token.h"
#include "Scanner.h"
using namespace std;
void funcTT(int ,int &a1 );
void funcF(int &a2);
void funcEE(int,int &a3);
void funcT(int&a4);
void funcE(int&a5);
string line;
ifstream myfile ("/Users/telcontar/Desktop/Maribor Compiling/LL(1)parser/LL(1)parser/Input.txt");
Scanner s(&myfile);
void funcE(int& Eval){
    int Tval;
    funcT(Tval);
    funcEE(Tval,Eval);
}
void funcEE(int EE0inval,int &EE0val){
    if(s.currentToken().getLexem()=="+"){
        s.nextTokenImp();
        int Tval=0;
        int EE1inval=0;
        int EE1val=0;
        funcT(Tval);
        funcEE(EE1inval,EE1val);
        EE0val=EE1val;
    }
    else
        EE0val=EE0inval;
}
void T(int& Tval){
    int Fval,TTinval,TTval;
    funcF(Fval);
    TTinval=Fval;
    funcTT(TTinval,TTval);
    Tval=TTval;
}
void TT(int TT0inval,int & TT0val){
    if(s.currentToken().getLexem()=="*"){
        s.nextTokenImp();
        int Fval,TT1inval,TT1val;
        funcF(Fval);
        TT1inval=TT0inval*Fval;
        funcTT(TT1inval,TT1val);
        TT0val=TT1val;
    }
    else
        TT0val=TT0inval;
}
void funcF(int &Fval){
    if(s.currentToken().getLexem()=="("){
        s.nextTokenImp();
        int Eval;
        funcE(Eval);
        Fval=Eval;
        if(s.currentToken().getLexem()==")"){
            s.nextTokenImp();
        }
        else{
            cout<<"Error";
        }
    }
    
    else if(s.currentToken().getToken()==1){
        s.nextTokenImp();
        Fval=stoi(s.currentToken().getLexem());
    }
    else
        cout<<"Error";
}


int main()
{
    
    if (myfile.is_open())
    {
        
        while ( getline (myfile,line) )
        {
            int result=0;
            s.nextToken().getLexem();
            //funcE(result);
            
            //cout<<s.currentToken().isEof();
            //s.currentToken().getLexem();
            //funcP();
            //cout << line << '\n';
            
            //s.initAutomata();
            /*
             for(int i=0;i<12;i++){
             cout<<s.currentToken()<<endl;
             }
             */
            
        }
        myfile.close();
    }
    
    // GET_TOKEN; //scanner oluşturup gelicek.
    // funcP();
    // if EOF
    return 0;
}
