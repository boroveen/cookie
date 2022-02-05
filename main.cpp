#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "config.h"
using namespace std;
bool daycookie=true, cookie=true,status=true;
char ConfigC[150],ConfigC1[150],command[225];
int Month,Day,TimeI;
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
	sprintf(ConfigC1,"%s/.config/cookie/time.txt",HomeS.c_str());
}
/*void Time(){
	time_t now = time(0);
	
}*/
int main(int argc,char* argv[]){
	srand((int)time(0));
	if(argc==1) daycookie=false;
	if(argc==2){
		if(string(argv[1])=="cookie") cookie=false;
		else if(string(argv[1])=="status") status=false;
		else cout << "i not know " << argv[1] << ":(" << endl;
	}
	if(!daycookie){
		HomeV();
		time_t now = time(0);
		fstream timeF;
		int timeI;
		timeF.open(ConfigC1);
		timeF >> timeI;
		timeF.close();
		if(timeI<now) cout << DAYCOOKIE << endl;
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

		time_t now = time(0);
		int timeI=60+rand() % TIME;
		now=now+timeI;
		sprintf(command,"rm %s",ConfigC1);
		system(command);
		sprintf(command,"touch %s",ConfigC1);
		system(command);
		fstream timeF;
		timeF.open(ConfigC1);
		timeF << now;
		timeF.close();

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
