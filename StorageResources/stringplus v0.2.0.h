/*
	
	csdn���Ӹ�
*/


#ifndef STRINGPLAS_H//���ã���ֹͷ�ļ����ظ�����
#define STRINGPLAS_H
#include<windows.h>//���ñ�׼���ͷ�ļ�
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
    } 
	else {    
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

string nowtime(){
	time_t timep;
	time(&timep); //��ȡ��1970������˶����룬����time_t���͵�timep
	return ctime(&timep);//��ctime������ת�����ַ�����ʽ
}

void end(){
	system("pause");//�����������������
}

/*Output_DebugDeta*/
#define data "data"
#define error "error"
#define null ""

void Output_DebugDeta(string type,bool autopm,string s_pm){
	const string a114514="error";
	
	
	if(type=="error"){
		if(autopm){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����̨��ɫ�ĺ�ɫ
			cerr<<"[ERROR]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����̨��ɫ�İ�ɫ
			cerr<<"Some content produced an error.\n";
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����̨��ɫ�ĺ�ɫ
			cerr<<"[ERROR]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����̨��ɫ�İ�ɫ
			cerr<<s_pm<<"\n";
		}
	}
	else if(type=="data"){
		if(autopm){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//����̨��ɫ����ɫ
			cerr<<"[DATA]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����̨��ɫ�İ�ɫ
			cerr<<"This is a data message.\n";
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//����̨��ɫ����ɫ
			cerr<<"[DATA]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//����̨��ɫ�İ�ɫ
			cerr<<s_pm<<"\n";
		}
	}
	
	
}

#endif
