#pragma once
#include <Windows.h>
#include <String>
using namespace std;

#define WM_MY_HKREG WM_USER + 1
#define WM_MY_HKUNREG WM_USER + 2

struct window
{
	HWND hd;
	wstring caption;
};
struct hkWindow
{
	HWND hwnd;
	hkWindow* nextwin;
};
struct hotkey
{
	int id;
	bool keyon;
	UINT mod;
	UINT vkcode;
	hkWindow* win;
	hotkey* nextkey;
};

HINSTANCE mhInstance = NULL;
TCHAR wcname[] = TEXT("HotKeyWindow");
bool Get_EndLine = 0, Get_BadInput = 0;
const wstring HelpWord =
LR"(BossKey����

 - Exit �˳�BossKey
 - Help ��ʾ����
 - Hide ���ش���
     [-h] ָ��hwnd
     [-n] �������
 - List �г������б�
     [-f] ˢ�´����б�
         [-a] �г����д��ڣ��������صĴ��ڣ�����Ϊ�յĴ���)
         [-e] ���г����ⲻΪ�յĴ���
         [-t] ���г��������еĴ��ڣ�Ĭ�ϣ�
     [-o] ��ˢ�´����б�Ĭ�ϣ�
 - Reg �ȼ�����
     [-i] ע���ȼ���Ĭ�ϣ����� -u ������
         [-h] ָ��hwnd
         [-n] �������
         [-k] �ȼ�
     [-u] ��ע���ȼ�
         [-h] ָ��hwnd
         [-n] �������
         [-k] �ȼ�
 - Show ��ʾ����
     [-h] ָ��hwnd
     [-n] �������

)",
WelcomeWord =
LR"(BossKey v0.2.1
���ߣ�LTS
==================================

)",

WrongWord =
LR"(����
ʹ��Help����鿴����

)";

wstring GetWord();
inline void GetClear();
bool GetHwnd(HWND& hWnd);
void UpperToLower(wstring& upstr);
bool EndLineTry();
bool GetHotKey(UINT& mod, UINT& vkcode);

void ListWindow();
BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
bool HideWindow();
bool UnHideWindow();

bool SetHotKey();
void HotKeyThreadFunc();
LRESULT CALLBACK HotKeyWindowProc(_In_ HWND hWnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

BOOL WINAPI HandlerRoutine(_In_ DWORD dwCtrlType);