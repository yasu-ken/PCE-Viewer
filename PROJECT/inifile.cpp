/*
MFCは2000系でレジストリに書き込むので使用できません。
API系関数はGetPrivateProfileIntなどです。

フルパスを作成するのが面倒ですが、動作確認しました。
スペースがあるマイドキュメントでも動作します。

*/


#include <windows.h>
#include <stdio.h>

/**************************************************
	フルパスの作成
**************************************************/
char szPath[_MAX_PATH];       //￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥test.exe
char szDrive[_MAX_DRIVE];     //c:
char szDir[_MAX_DIR];         //￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥
char szFileName[_MAX_FNAME];  //test
char szExt[_MAX_EXT];         //.exe
char szDrvPath[_MAX_PATH];    //c:￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥test.exe
char szOutput[_MAX_PATH * 5 + 1024];//(^^;

void makefullpath()
{
	DWORD dwRet;
	//実行中のプロセスのフルパス名を取得する
	dwRet = GetModuleFileName(NULL, szPath, sizeof(szPath));
	if(dwRet == 0) {
		//エラー処理など(省略)
	}
	//フルパス名を分割する
	_splitpath(szPath, szDrive, szDir, szFileName, szExt); 

	//出力文字列を作成
	//wsprintf(szOutput,
	//	"実行しているプログラムのフルパス名 %s\r\nドライブ %s\r\n"
	//	"ディレクトリ %s\r\nファイル名 %s\r\n拡張子 %s\n",
	//	szPath,
	//	szDrive,
	//	szDir,
	//	szFileName,
	//	szExt);

	//c:.....のメイク
	sprintf(szDrvPath,"%s%s%s\0",szDrive,szDir,"test.ini");
}


/**************************************************
// Iniファイルの情報を読み取る
// fileName Iniファイルの名前(フルパス)
// section セクション名
// entry Entry名
**************************************************/
//bufは最大256文字分のバッファ
void ini_GetStr(char *section,char *koumoku, char *szAppName,char *buf)
{
	int i;
	GetPrivateProfileString(section,koumoku, NULL, buf, 255, szAppName);
}

/**************************************************
// Iniファイルの情報を読み取る
// fileName Iniファイルの名前(フルパス)
// section セクション名
// entry Entry名
**************************************************/
int ini_GetInt(char *section,char *koumoku,char *szAppName)
{
	int i;
	printf("path = %s\n",szAppName);

	return GetPrivateProfileInt(section,koumoku,-1, szAppName);
}

/**************************************************
// Iniファイルへ情報保存
**************************************************/
void ini_SetInt(char *section,char *koumoku,char *szAppName,int val)
{
	//WritePrivateProfileSection(section,koumoku,szAppName);
	char buf[256];
	sprintf( buf,"%d\0",val);

	WritePrivateProfileString(
		section,   // セクション名へのポインタ
		koumoku,   // キー名へのポインタ
		buf,       // 追加するべき値
		szAppName  // .ini ファイルへのポインタ
	);
}
/**************************************************
// Iniファイルへ情報保存
**************************************************/
void ini_SetStr(char *section,char *koumoku,char *szAppName,char *str)
{
	//WritePrivateProfileSection(szAppName,"JOUHOU",szAppName);
	WritePrivateProfileString(
		section,   // セクション名へのポインタ
		koumoku,   // キー名へのポインタ
		str,       // 追加するべき値
		szAppName  // .ini ファイルへのポインタ
	);
}
/**************************************************
**************************************************/
//extern int main()
//{
//	int val;
//	char buf[256];
//	makefullpath();
//
//	ini_SetInt("JOUHOU", "SPEED",szDrvPath,5678910);
//	ini_SetInt("MOJIRETU", "FILE",szDrvPath,"abcdefg.txt");
//	val = ini_GetInt("JOUHOU", "SPEED",szDrvPath);
//	printf("int %d\n",val);
//
//	ini_GetStr("MOJIRETU", "FILE",szDrvPath,buf);
//	printf("str %s\n",buf);
//
//	//メッセージボックスで出力
//	MessageBox(NULL, szOutput, "結果", MB_OK);
//
//   return 0;
//}
