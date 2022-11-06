#ifndef _Y_TAB_H
#define _Y_TAB_H

/* Tokens: identifier, integer constant, floating-point constant, 
           && || ~ == < <= > >= != + - * / ( ) {  } , ; = int float
           for do else  if print scan while

 */
#define IDENTIFIER 300
#define INT_CONST 301
#define FLO_CONST 302

#define PLUS      312
#define MINUS     313
#define MULT      314
#define DIV       315
#define PERCENT   303
#define PLUS_PLUS 304
#define MINUS_MINUS 305

#define EQ        311
#define PLUS_EQ   316
#define MINUS_EQ  317
#define MULT_EQ   318
#define DIV_EQ    319

#define EQ_EQ     306
#define LESSER    307
#define LESS_EQ   308
#define GREATER   309
#define GREAT_EQ  310

#define L_SQUARE  414
#define R_SQUARE  415
#define L_PARAEN  416
#define R_PARAEN  417
#define L_CBRACE  418
#define R_CBRACE  419
#define COMMA     420
#define SEMICOL   421

#define SHORT     422
#define INT       423
#define FLOAT     424
#define DOUBLE    425
#define BOOL      426
#define CHAR      427
#define SIGNED    428
#define UNSIGNED  429
#define FOR       430
#define WHILE     431
#define DO        432
#define RETURN    433
#define STRUCT    434
#define CONST     435
#define VOID      436
#define SWITCH    437
#define BREAK     438
#define CASE      439
#define CONTINUE  440
#define GOTO      441
#define LONG      442
#define STATIC    443
#define UNION     444
#define DEFAULT   445
#define IF        475
#define ELSE      476

#define NOTOK     -1


typedef union {
       char *string;
       int integer;
       float real;
} attrType;

#endif

// Language: cpp
// Path: FSM.cpp

#include<bits/stdc++.h>
using namespace std;

bool isDelimeter(char ch){
    if( ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}'
    )   return true;
    else return false;
}

bool isOperator(char ch){
    if( ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=' || ch == '%'
    )   return true;
    else return false;
}

bool multipleOperator(string s){
    if(s=="+=" || s=="-=" || s=="*=" || s=="/=" || s=="==" || s=="!=" || s=="<=" || s==">=" || s=="++" || s=="--") return true;
    else return false;
}


bool validIdentifier(string str){
    if( (str[0] >= 'a' && str[0] <= 'z') ||
        (str[0] >= 'A' && str[0] <= 'Z') ||
        str[0] == '_'
    ){  
        if(str.size() == 1) return true;
        if(str.size() > 1 & str[1] == '_') return false;
        for(int i=1; i<str.size(); i++){
            if( (str[i] >= 'a' && str[i] <= 'z') ||
                (str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= '0' && str[i] <= '9') ||
                str[i] == '_'
            )   continue;
            else return false;
        }
        return true;
    }
    else return false;
}

bool validInteger(string str){
    if(str.size()==0) return false;
    for(int i=0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9') continue;
        else return false;
    }
    return true;
}



bool validFloat(string str){
    int dot=0;
    if(str.size()==1 and str[0] == '.') return false;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '.') dot++;
        else if(str[i] >= '0' && str[i] <= '9') continue;
        else return false;
    }
    if(dot == 1) return true;
    else return false;
}

bool isSignedNumber(string line, int right){
    right++;
    //go till we find delimeter
    while(right < line.size() && !isDelimeter(line[right])) right++;

    //check if it valid integer or float or variable name
    string str = line.substr(right-1, 1);
    if(validInteger(str) || validFloat(str) || validIdentifier(str)) return true;
    else return false;
    // string temp="";
    // temp+=s[1];
    // if(validInteger(temp) || validFloat(temp)) return true;
    // else return false;
}

bool isKeyword(string str){
    if(str == "auto" || str == "break" || str == "case" || str == "char" ||
        str == "const" || str == "continue" || str == "default" || str == "do" ||
        str == "double" || str == "else" || str == "enum" || str == "extern" ||
        str == "float" || str == "for" || str == "goto" || str == "if" ||
        str == "int" || str == "long" || str == "register" || str == "return" ||
        str == "short" || str == "signed" || str == "sizeof" || str == "static" ||
        str == "struct" || str == "switch" || str == "typedef" || str == "union" ||
        str == "unsigned" || str == "void" || str == "volatile" || str == "while"
    )   return true;
    else return false;
}

bool isSpecialSymbols(char ch){
    if(ch=='(' || ch==')' || ch=='{' || ch=='}' || ch=='[' || ch==']' || ch=='.' || ch==',' || ch==';' || ch=='?' || ch==',') return true;
    else return false;
}

map<string,int> tokenMapping(){
    //perform the mapping according to #define in FSM.h
    
    map<string,int> mp;

    mp["+"] = PLUS;
    mp["-"] = MINUS;
    mp["*"] = MULT;
    mp["/"] = DIV;
    mp["%"] = PERCENT;
    mp["++"] = PLUS_PLUS;
    mp["--"] = MINUS_MINUS;

    mp["="] = EQ;
    mp["+="] = PLUS_EQ;
    mp["-="] = MINUS_EQ;
    mp["*="] = MULT_EQ;
    mp["/="] = DIV_EQ;

    mp["=="] = EQ_EQ;
    mp["<"] = LESSER;
    mp["<="] = LESS_EQ;
    mp[">"] = GREATER;
    mp[">="] = GREAT_EQ;

    mp["["]=L_SQUARE;
    mp["]"]=R_SQUARE;
    mp["("]=L_PARAEN;
    mp[")"]=R_PARAEN;
    mp["{"]=L_CBRACE;
    mp["}"]=R_CBRACE;
    mp[","]=COMMA;
    mp[";"]=SEMICOL;

    
    mp["short"]= SHORT    ; 
    mp["int"]= INT      ; 
    mp["float"]= FLOAT    ; 
    mp["double"]= DOUBLE   ; 
    mp["bool"]= BOOL     ; 
    mp["char"]= CHAR     ; 
    mp["signed"]= SIGNED   ; 
    mp["unsigned"]= UNSIGNED ; 
    mp["for"]= FOR      ; 
    mp["while"]= WHILE    ; 
    mp["do"]= DO       ; 
    mp["return"]= RETURN   ; 
    mp["struct"]= STRUCT   ; 
    mp["const"]= CONST    ; 
    mp["void"]= VOID     ; 
    mp["switch"]= SWITCH   ; 
    mp["break"]= BREAK    ; 
    mp["case"]= CASE     ; 
    mp["continue"]= CONTINUE ; 
    mp["goto"]= GOTO     ; 
    mp["long"]= LONG     ; 
    mp["static"]= STATIC   ; 
    mp["union"]= UNION    ; 
    mp["default"]= DEFAULT  ; 
    mp["if"]= IF       ; 
    mp["else"]= ELSE     ; 

    return mp;
}


void parser(string file){
    map<string,int> mp = tokenMapping();
    ofstream fout("pa_1.out");

    ofstream fout2("symbol_table_1.out");
    
    ifstream fin(file);
    if(!fin){
        fout << "File not found" << endl;
        return;
    }

    //read line by line from file

    string line;
    while(getline(fin, line)){
        int left=0, right=0;
        int len=line.size();

        while(right<=len and left<=right){
            // fout<<line.substr(left, right-left)<<endl;
            if(isDelimeter(line[right]) == false) right++;
            if(isDelimeter(line[right])==true and left==right) {
                if(isOperator(line[right])==true) {
                    if(multipleOperator(line.substr(right, 2))==true){
                        // fout << "Operator: " << line.substr(right, 2) << endl;
                        // fout << "Operator: " << line.substr(right, 2) << endl;
                        fout<<mp[line.substr(right, 2)]<<" "<<line.substr(right,2)<<endl;
                        right+=2;
                        left=right;
                    }
                    else if(isSignedNumber(line, right)==true){
                        //go on till you find a delimeter
                        right++;
                        while(!isDelimeter(line[right])) right++;
                        // fout << "Signed Number: " << line.substr(left, right-left) << endl;
                        fout<<FLO_CONST<<" "<<line.substr(left, right-left)<<endl;
                        right++;
                        left=right;
                    }
                    else{
                        // fout << "Operator: " << line[right] << endl;
                        fout<<mp[line.substr(right, 1)]<<" "<<line.substr(right,1)<<endl;
                        right++;
                        left=right;
                    }
                }
                else if(isSpecialSymbols(line[right])){
                    if(line[right]=='('){
                        if(right<line.length() && line[right+1]==')'){
                            // fout<<"Special Symbol: "<<line.substr(right, 2)<<endl;
                            fout<<mp[line.substr(right, 2)]<<" "<<line.substr(right,2)<<endl;
                            right+=2;
                            left=right;
                        }
                        else{
                            // fout<<"Special Symbol: "<<line[right]<<endl;
                            fout<<mp[line.substr(right, 1)]<<" "<<line.substr(right,1)<<endl;
                            right++;
                            left=right;
                        }
                    }
                    else{
                        // fout << "Special Symbol: " << line[right] << endl;
                        fout<<mp[line.substr(right, 1)]<<" "<<line.substr(right,1)<<endl;
                        right++;
                        left=right;
                    }
                }
                else{
                    right++;
                    left=right;
                }
            }
            else if(isDelimeter(line[right])==true and left!=right || (right==len and left!=right)){
                string str=line.substr(left, right-left);
                if(str==" ") continue;
                // fout<<str<<endl;
                if(isKeyword(str)==true) fout<<mp[str]<<" "<<str<<endl,fout2<<str<<"\t0"<<endl;
                else if(validIdentifier(str)==true) {
                    // fout << "Identifier: " << str << endl;
                    fout<<IDENTIFIER<<" "<<str<<endl;
                    fout2<<str<<"\t1"<<endl;
                }
                else if(validInteger(str)==true) fout<<INT_CONST<<" "<<str<<endl;
                else if(validFloat(str)==true) fout<<FLO_CONST<<" "<<str<<endl;
                else if(isSpecialSymbols(str[0])==true) fout<<mp[str]<<" "<<str<<endl;

                left=right;
            }

        }
    }
    fin.close();
    return;
}

int main(int argc, char *argv[]){
    //take input from command line file
    if(argc != 2){
        cout << "Invalid input" << endl;
        return 0;
    }
    //call the lexical parser and read line by line

    parser(argv[1]);

    return 0;
}