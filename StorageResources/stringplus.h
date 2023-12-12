#ifndef STRINGPLAS_H//���ã���ֹͷ�ļ����ظ�����
#define STRINGPLAS_H
#include<windows.h>//���ñ�׼���ͷ�ļ�
#include<iostream>
#include<string>
using namespace std;

void toclipboard(const std::string& s){    
    if (!s.empty()) { // ����ַ����Ƿ�Ϊ��    
        const char* str = s.c_str(); // ��ȡconst char*�汾���ַ���    
        HWND hWnd = NULL;    
        OpenClipboard(hWnd); // �򿪼��а�    
        EmptyClipboard(); // ��ռ��а�    
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, (s.length() + 1) * sizeof(char)); // �����ڴ棬�����ַ������Ⱥͽ����ַ�'\0'    
        char* pData = (char*)GlobalLock(hHandle); // �����ڴ棬���������ڴ���׵�ַ    
        strcpy(pData, str); // ���ü��а�����    
        SetClipboardData(CF_TEXT, hHandle); // ���ü��а�����    
        GlobalUnlock(hHandle); // �������    
        CloseClipboard(); // �رռ��а�    
        GlobalFree(hHandle); // �ͷ��ڴ�    
    } else {    
        // ������ַ��������    
        char emptyString[] = ""; // ����һ�����ַ���  
        OpenClipboard(NULL); // �򿪼��а�    
        EmptyClipboard(); // ��ռ��а壨����Ѿ���һ���ַ�������Ḳ������  
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, sizeof(emptyString)); // Ϊ���ַ��������ڴ�  
        char* pData = (char*)GlobalLock(hHandle); // �����ڴ棬���������ڴ���׵�ַ    
        strcpy(pData, emptyString); // ���ü��а�����    
        SetClipboardData(CF_TEXT, hHandle); // ���ü��а�����    
        GlobalUnlock(hHandle); // �������    
        CloseClipboard(); // �رռ��а�    
        GlobalFree(hHandle); // �ͷ��ڴ�    
    }   
}

//
#endif
