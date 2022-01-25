#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream source ;
    source.open(filename);
    string text ;

    int s1 ,s2 ,s3 ;
    char Name[100] ;
    char format[] = "%[^:]: %d %d %d" ;

    while(getline(source,text)) {
        char* chartext = const_cast<char*>(text.c_str());
        sscanf(chartext,format,Name,&s1,&s2,&s3);

        string N = Name ;
        int sums = s1+s2+s3 ;
        char G =  score2grade(sums) ;
        names.push_back(N);
        scores.push_back(sums);
        grades.push_back(G) ;

    }
    source.close();
}

void getCommand(string command, string &key){
    cout << "Please input your command : " ;
    cin >> command >> key ;
}

void searchName(vector<string>names, vector<int>scores, vector<char>grades,string key){
    for (int i = 0; i < names.size() ; ++i) {
        if( toUpperStr(names[i])  == key){
            cout << "---------------------------------\n";
            cout << names[i] << "'s score = " << scores[i] << "\n" ;
            cout << names[i] << "'s grade = " << grades[i] << "\n" ;
            cout << "---------------------------------\n";
            break ;
        }else if (toUpperStr(names[i])  != key ) {
           if ( i+1 == names.size() ) {
                cout << "---------------------------------\n";
                cout << "Cannot found.\n" ;
                cout << "---------------------------------\n";
            }
            
        }
    }
   
}




void searchGrade(vector<string>names, vector<int>scores, vector<char>grades,string key){
    for (int i = 0; i < names.size() ; ++i) {
        if( toUpperStr(names[i])  == key){
            cout << "---------------------------------\n";
            cout << names[i] << "'s score = " << scores[i] << "\n" ;
            cout << names[i] << "'s grade = " << grades[i] << "\n" ;
            cout << "---------------------------------\n";
            break ;
        }else if (toUpperStr(names[i])  != key ) {
           if ( i+1 == names.size() ) {
                cout << "---------------------------------\n";
                cout << "Cannot found.\n" ;
                cout << "---------------------------------\n";
            }
            
        }
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
