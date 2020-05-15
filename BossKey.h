#pragma once
#include <Windows.h>
#include <String>
using namespace std;

struct window
{
	HWND hd;
	wstring caption;
};

bool Get_EndLine = 0, Get_BadInput = 0;
wstring HelpWord =
LR"(BossKey����

 - List �г������б�
     [-a] �г����д��ڣ��������صĴ��ڣ�����Ϊ�յĴ���)
     [-e] ���г����ⲻΪ�յĴ��ڣ�Ĭ�ϣ�
     [-t] ���г��������еĴ��� ��
     [-f] ˢ�´����б�
     [-o] ��ˢ�´����б�Ĭ�ϣ�
 - Reg �ȼ����� ��
     [-i] ע���ȼ���Ĭ�ϣ����� -u ������
     [-k] �ȼ������� -i ���룩
     [-h] ָ��hwnd
     [-n] �������
     [-u] ��ע���ȼ�
 - Hide ���ش���
     [-h] ָ��hwnd
     [-n] �������
 - Show ��ʾ����
     [-h] ָ��hwnd
     [-n] �������
 - Help ��ʾ����
 - Exit �˳�BossKey

)",
WelcomeWord =
LR"(BossKey v0.1.2
���ߣ�LTS
==================================

)",
WrongWord =
LR"(����
ʹ��Help����鿴����

)";

wstring GetWord();
inline void GetClear();
void ListWindow();
BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
bool HideWindow();
bool UnHideWindow();
bool GetHwnd(HWND& hWnd);