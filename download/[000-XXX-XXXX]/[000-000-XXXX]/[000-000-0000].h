#ifndef STRINGPLAS_H
#define STRINGPLAS_H
#include<windows.h>
#include<iostream>
#include<string>
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
    } else {    
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

//
#endif
