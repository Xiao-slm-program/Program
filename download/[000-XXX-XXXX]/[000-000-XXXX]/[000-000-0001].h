#ifndef STRINGPLAS_H
#define STRINGPLAS_H
#include<windows.h>
#include<iostream>
#include<unistd.h>
#include<string>
#include<time.h>
/*Output_DebugDeta*/
#define data "data"
#define error "error"
#define null ""
using namespace std;

void toclipboard(const std::string& s){
    if (!s.empty()) {
        const char* str = s.c_str();
        HWND hWnd = NULL;    
        OpenClipboard(hWnd);
        EmptyClipboard();
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, (s.length() + 1) * sizeof(char));
        char* pData = (char*)GlobalLock(hHandle);
        strcpy(pData, str);
        SetClipboardData(CF_TEXT, hHandle);
        GlobalUnlock(hHandle); 
        CloseClipboard();
        GlobalFree(hHandle);
    } 
	else {    
        char emptyString[] = "";
        OpenClipboard(NULL);
        EmptyClipboard();  
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, sizeof(emptyString));
        char* pData = (char*)GlobalLock(hHandle);    
        strcpy(pData, emptyString);
        SetClipboardData(CF_TEXT, hHandle);
        GlobalUnlock(hHandle);
        CloseClipboard();
        GlobalFree(hHandle);
    }   
}

string nowtime(){
	time_t timep;
	time(&timep);
	return ctime(&timep);
}

void end(){
	system("pause");
}

/*Output_DebugDeta*/
#define data "data"
#define error "error"
#define null ""

void Output_DebugDeta(string type,bool autopm,string s_pm){
	const string a114514="error";
	
	
	if(type=="error"){
		if(autopm){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cerr<<"[ERROR]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cerr<<"Some content produced an error.\n";
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cerr<<"[ERROR]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cerr<<s_pm<<"\n";
		}
	}
	else if(type=="data"){
		if(autopm){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			cerr<<"[DATA]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cerr<<"This is a data message.\n";
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			cerr<<"[DATA]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cerr<<s_pm<<"\n";
		}
	}
	
	
}

#endif
