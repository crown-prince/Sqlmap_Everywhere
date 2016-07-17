#include<stdio.h>
#include<string.h>
#include<time.h>
#include<iostream>
#include<cstdio>
#include<afx.h>
using namespace std;
#define _AFXDLL 

int main()
{
	const int MAXNUM = 300;
	char cmd[MAXNUM], line[MAXNUM];
	while(1)
	{
		memset(cmd,0, sizeof(cmd));
		memset(line,0,sizeof(line));
		TCHAR _szPath[MAX_PATH + 1]= {0};
		GetModuleFileName(NULL, _szPath, MAX_PATH);
		(_tcsrchr(_szPath, _T('\\')))[1] = 0;//删除文件名，只获得路径
		CString strPath;
		for (int n=0;_szPath[n];n++)
		{
			if (_szPath[n]!=_T('\\'))
			{
			strPath +=_szPath[n] ;
			}
			else
			{
			strPath += _T("\\\\");
			}
		}
		//printf("%s", strPath);
		for(int i = 0;i<strPath.GetLength();i++)
		{
				cmd[i]=strPath.GetAt(i);
		}
		strcat(cmd,"Bin\\sqlmap.exe ");
		cout << "sqlmap_everywhere:";
		//printf("%s", cmd);
		strcat(cmd, gets(line));
		//printf("%s", cmd);
		system(cmd);
	}
	system("pause");
	return 0;
}