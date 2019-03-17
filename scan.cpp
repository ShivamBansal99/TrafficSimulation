#include <bits/stdc++.h>
#include <regex>
using namespace std ;
#define loop(a,b) for(int a=0;a<b;a++)

int scan(vector< vector<int> > &spec ,vector<string> &types ,vector<vector<string> > &seconds ){
	ifstream config("config.ini");		//file opening
	//vector< vector<int>> spec ;			//containing specifications 
	//vector<string> types; 	
	//vector<vector<string>> seconds ;	
		//containing paragraph headings
	if(config.is_open()){
		string input;					//input line
		int state=-1;					//state wise
		while(getline(config,input)){	
			string inp="" ;int charcount=0 ;
			loop(charcount,input.length()){
				//cout<<input[charcount]<<"*" ;
				if(inp!="" && isspace(input[charcount])) break ;	//it breaks the loop when we have got something as input in inp string and the current character is now whitespace. 
				inp.push_back(input[charcount]) ;
			}
			//cout<<inp<<"in comments"<<endl ;
			if(inp[0]=='#' || inp=="")continue ;
			//cout<<inp<<endl ;
			if(inp=="START") {seconds.push_back(vector<string>(0));seconds[0].push_back(inp); ;break ;}
                        regex reg("[a-z_A-Z]+");
			if(regex_match(inp,reg)) {
				spec.push_back(vector<int>(0)) ;
				types.push_back(inp) ;
				state++ ; 
				}
			else {spec[state].push_back(stoi(inp)) ;}
		}
	}
	else{
		cout<<"Configuration file not found" ;
		return 0; 
	}
	string input ;
	int i=1;
	while(getline(config,input)){
		//cout<<input<<endl ;
		if (!input.compare("")) continue ;
		seconds.push_back(vector<string>(0)) ;
		stringstream iss(input) ;
		string word;
		while(iss>>word){
			if(word[0]=='#') break;
			seconds[i].push_back(word) ;
		}
		if(seconds[i].size()==0) seconds.pop_back() ; 
		else i++ ;
	}
	config.close() ;
	/*loop(i,seconds.size()) {
		loop(j,seconds[i].size()){
			cout<<seconds[i][j]<<" " ;
		}
	cout<<endl ;
	}*/
	return 0;
}