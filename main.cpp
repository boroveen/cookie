#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "config.h"
using namespace std;
bool daycookie=true, cookie=true,status=true;
char ConfigC[225],command[225];
void HomeV(){
	system("echo $HOME > home.txt");
	fstream HomeF;
	string HomeS;
	//char ConfigC[225];
	HomeF.open("home.txt");
	HomeF >> HomeS;
	HomeF.close();
	system("rm home.txt");
	sprintf(ConfigC,"%s/.config/cookie/cookie.txt",HomeS.c_str());
}
int main(int argc,char* argv[]){
	srand((int)time(0));
	if(argc==1) daycookie=false;
	if(argc==2){
		if(string(argv[1])=="cookie") cookie=false;
		else if(string(argv[1])=="status") status=false;
		else cout << "i not know " << argv[1] << ":(" << endl;
	}
	if(!daycookie){
		if(rand() % 10==5) cout << DAYCOOKIE << endl;
	}
	if(!cookie){
		HomeV();
		int cookieI;
		fstream CookieF;
		CookieF.open(ConfigC);
		CookieF >> cookieI;
		CookieF.close();
		cookieI++;
		sprintf(command,"rm %s",ConfigC);
		system(command);
		sprintf(command,"touch %s",ConfigC);
		system(command);
		CookieF.open(ConfigC);
		CookieF << cookieI;
		CookieF.close();
		cout << COOKIE << endl;
	}
	if(!status){
		HomeV();
		fstream CookieF;
		int cookieI;
		CookieF.open(ConfigC);
		CookieF >> cookieI;
		CookieF.close();
		cout << STATUS << cookieI << endl;
	}
	return 0;
}
/*
./cookie cookie
*/
