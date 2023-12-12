#ifndef STRINGPLAS_H//作用：防止头文件被重复引用
#define STRINGPLAS_H
#include<windows.h>//引用标准库的头文件
#include<iostream>
#include<string>
using namespace std;

void toclipboard(const std::string& s){    
    if (!s.empty()) { // 检查字符串是否为空    
        const char* str = s.c_str(); // 获取const char*版本的字符串    
        HWND hWnd = NULL;    
        OpenClipboard(hWnd); // 打开剪切板    
        EmptyClipboard(); // 清空剪切板    
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, (s.length() + 1) * sizeof(char)); // 分配内存，考虑字符串长度和结束字符'\0'    
        char* pData = (char*)GlobalLock(hHandle); // 锁定内存，返回申请内存的首地址    
        strcpy(pData, str); // 设置剪切板数据    
        SetClipboardData(CF_TEXT, hHandle); // 设置剪切板数据    
        GlobalUnlock(hHandle); // 解除锁定    
        CloseClipboard(); // 关闭剪切板    
        GlobalFree(hHandle); // 释放内存    
    } else {    
        // 处理空字符串的情况    
        char emptyString[] = ""; // 定义一个空字符串  
        OpenClipboard(NULL); // 打开剪切板    
        EmptyClipboard(); // 清空剪切板（如果已经有一个字符串，这会覆盖它）  
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, sizeof(emptyString)); // 为空字符串分配内存  
        char* pData = (char*)GlobalLock(hHandle); // 锁定内存，返回申请内存的首地址    
        strcpy(pData, emptyString); // 设置剪切板数据    
        SetClipboardData(CF_TEXT, hHandle); // 设置剪切板数据    
        GlobalUnlock(hHandle); // 解除锁定    
        CloseClipboard(); // 关闭剪切板    
        GlobalFree(hHandle); // 释放内存    
    }   
}

//
#endif
