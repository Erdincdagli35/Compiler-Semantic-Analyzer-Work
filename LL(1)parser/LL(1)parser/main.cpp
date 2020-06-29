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
void funcTT();
bool funcF();
void funcEE();
void funcT();
void funcE();
string line;
ifstream myfile ("/Users/telcontar/Desktop/Maribor Compiling/LL(1)parser/LL(1)parser/Input.txt");
Scanner s(&myfile);


//İlk ödevi gösterecez. İlk ödevin maini yapamadım, onu göstersin.
/*
 void funcA(){
 if (s.nextTokenImp().getLexem()=="a"){
 s.nextTokenImp();
 funcA();
 }
 }
 void funcB(){
 if((s.nextTokenImp().getLexem())=="b"){
 s.getToken();
 funcB();
 }
 }
 void funcP(){
 if (s.nextTokenImp().getLexem()=="a" || s.nextTokenImp().getLexem()=="c"){ //buna eşitse içeri girecek, ancak ilk ödev tam olmadığı için ne döndüğünü bilmiyorum.
 funcA();
 if(s.getLexem()=="c")
 s.getToken();//GET_TOKEN ilk ödevden geliyor, scanner oluşturup alacağımızı tahmın ediyorum.
 else
 exit(0);
 }
 else if(s.nextTokenImp().getLexem()=="b" || s.nextTokenImp().getLexem()=="d"){ //b,d nin kontrolü böyle olmayabilir. İlk ödevden geri dönüşü bilmediğim için
 //böyle yazdım.
 funcB();
 if(s.nextTokenImp().getLexem()=="d")
 s.getToken(); //ilk ödevden. Scanner oluşturup çağrılcak
 //token yüksek ihtimal şöyle bir şey olacak. Scanner s("...");
 //s.Get_Token()
 else
 exit(0);
 }
 else
 exit(0);
 }
 */
void funcT(){
    if(funcF()==false){
        cout<<"False";
        exit(0);
    }
    else
        funcTT();
}
void funcE(){
    funcT();
    funcEE();
    if(funcF()==true){
        cout<<"true";
    }
    else
        cout<<"false";
}
bool funcF(){
    if(s.currentToken().getLexem()=="("){
        funcE();
        if(s.currentToken().getLexem()==")"){
            s.nextTokenImp();
            return true;
        }
        else
            return false;
    }
    else if(s.currentToken().getToken()==1){
        s.nextTokenImp();
        
        return true;
    }
    else
        return false;
}
void funcTT(){
    if(s.currentToken().getLexem()=="*"||s.currentToken().getLexem()=="/"){
        s.nextTokenImp();
        if(funcF()==false){
            cout<<"False";
            exit(0);
        }
        else
            funcTT();
    }
}

void funcEE(){
    if(s.currentToken().getLexem()=="+"||s.currentToken().getLexem()=="-"){
        s.nextTokenImp();
        funcT();
        funcEE();
    }
}





int main()
{
    
    
    if (myfile.is_open())
    {
        
        while ( getline (myfile,line) )
        {
            s.nextToken().getLexem();
            //cout<<s.currentToken().isEof();
            //s.currentToken().getLexem();
            funcE();
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
    exit(0);
    // return 0;
}
