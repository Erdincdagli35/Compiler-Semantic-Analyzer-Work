#include <string>
#include <iostream>
#include <fstream>
#include "Token.h"
#include "Scanner.h"
using namespace std;

int main() {
    
    string line;
    ifstream myfile ("/Users/telcontar/Desktop/Maribor Compiling/lexicalanalysis/lexicalanalysis/Input.txt");
    if (myfile.is_open())
    {
        Scanner s(&myfile);

        while ( getline (myfile,line) )
        {
            //cout << line << '\n';
            cout<<s.nextToken()<<endl;
            //s.initAutomata();
            /*
            for(int i=0;i<12;i++){
                cout<<s.currentToken()<<endl;
            }
             */
            
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
     //    Scanner temp1(is);
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
