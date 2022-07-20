/*
MFC��2000�n�Ń��W�X�g���ɏ������ނ̂Ŏg�p�ł��܂���B
API�n�֐���GetPrivateProfileInt�Ȃǂł��B

�t���p�X���쐬����̂��ʓ|�ł����A����m�F���܂����B
�X�y�[�X������}�C�h�L�������g�ł����삵�܂��B

*/


#include <windows.h>
#include <stdio.h>

/**************************************************
	�t���p�X�̍쐬
**************************************************/
char szPath[_MAX_PATH];       //��mydocuments���V����̫���(7)��test��test.exe
char szDrive[_MAX_DRIVE];     //c:
char szDir[_MAX_DIR];         //��mydocuments���V����̫���(7)��test��
char szFileName[_MAX_FNAME];  //test
char szExt[_MAX_EXT];         //.exe
char szDrvPath[_MAX_PATH];    //c:��mydocuments���V����̫���(7)��test��test.exe
char szOutput[_MAX_PATH * 5 + 1024];//(^^;

void makefullpath()
{
	DWORD dwRet;
	//���s���̃v���Z�X�̃t���p�X�����擾����
	dwRet = GetModuleFileName(NULL, szPath, sizeof(szPath));
	if(dwRet == 0) {
		//�G���[�����Ȃ�(�ȗ�)
	}
	//�t���p�X���𕪊�����
	_splitpath(szPath, szDrive, szDir, szFileName, szExt); 

	//�o�͕�������쐬
	//wsprintf(szOutput,
	//	"���s���Ă���v���O�����̃t���p�X�� %s\r\n�h���C�u %s\r\n"
	//	"�f�B���N�g�� %s\r\n�t�@�C���� %s\r\n�g���q %s\n",
	//	szPath,
	//	szDrive,
	//	szDir,
	//	szFileName,
	//	szExt);

	//c:.....�̃��C�N
	sprintf(szDrvPath,"%s%s%s\0",szDrive,szDir,"test.ini");
}


/**************************************************
// Ini�t�@�C���̏���ǂݎ��
// fileName Ini�t�@�C���̖��O(�t���p�X)
// section �Z�N�V������
// entry Entry��
**************************************************/
//buf�͍ő�256�������̃o�b�t�@
void ini_GetStr(char *section,char *koumoku, char *szAppName,char *buf)
{
	int i;
	GetPrivateProfileString(section,koumoku, NULL, buf, 255, szAppName);
}

/**************************************************
// Ini�t�@�C���̏���ǂݎ��
// fileName Ini�t�@�C���̖��O(�t���p�X)
// section �Z�N�V������
// entry Entry��
**************************************************/
int ini_GetInt(char *section,char *koumoku,char *szAppName)
{
	int i;
	printf("path = %s\n",szAppName);

	return GetPrivateProfileInt(section,koumoku,-1, szAppName);
}

/**************************************************
// Ini�t�@�C���֏��ۑ�
**************************************************/
void ini_SetInt(char *section,char *koumoku,char *szAppName,int val)
{
	//WritePrivateProfileSection(section,koumoku,szAppName);
	char buf[256];
	sprintf( buf,"%d\0",val);

	WritePrivateProfileString(
		section,   // �Z�N�V�������ւ̃|�C���^
		koumoku,   // �L�[���ւ̃|�C���^
		buf,       // �ǉ�����ׂ��l
		szAppName  // .ini �t�@�C���ւ̃|�C���^
	);
}
/**************************************************
// Ini�t�@�C���֏��ۑ�
**************************************************/
void ini_SetStr(char *section,char *koumoku,char *szAppName,char *str)
{
	//WritePrivateProfileSection(szAppName,"JOUHOU",szAppName);
	WritePrivateProfileString(
		section,   // �Z�N�V�������ւ̃|�C���^
		koumoku,   // �L�[���ւ̃|�C���^
		str,       // �ǉ�����ׂ��l
		szAppName  // .ini �t�@�C���ւ̃|�C���^
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
//	//���b�Z�[�W�{�b�N�X�ŏo��
//	MessageBox(NULL, szOutput, "����", MB_OK);
//
//   return 0;
//}
