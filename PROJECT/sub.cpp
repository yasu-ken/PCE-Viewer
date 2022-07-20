
//char textworkbuf[MAX_PATH];
char textworkbuf[1024];

//**************************************
// ���̓��t�Ǝ��Ԃ̕�����𓾂�
//**************************************
char * GetStr_DayAndTime()
{
	time_t t = time(NULL);
	struct tm *local = localtime(&t);
	//char * const wdays[] = { "��", "��", "��", "��", "��", "��", "�y" };
	char * const wdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	sprintf(textworkbuf, ";[ %04d/%02d/%02d (%s)] %02d:%02d:%02d\n",
			local->tm_year + 1900,
			local->tm_mon + 1,
			local->tm_mday,
			wdays[local->tm_wday],
			local->tm_hour,
			local->tm_min,
			local->tm_sec);

	return textworkbuf;
}


//**************************************
// EXE�̂���p�X�𓾂�
//**************************************
char * GetInstallPath()
{

	char Path[MAX_PATH+1]; 
	char drive[MAX_PATH+1],dir[MAX_PATH+1],fname[MAX_PATH+1],ext[MAX_PATH+1];

	if(0 != GetModuleFileName( NULL, Path, MAX_PATH ))  // ���s�t�@�C���̊��S�p�X���擾
	{
		_splitpath(Path,drive,dir,fname,ext);   //�p�X���𕪉�

		//printf("���S�p�X               : %s\n",Path);
		//printf("�h���C�u               : %s\n",drive);
		//printf("�f�B���N�g�� �p�X      : %s\n",dir);
		//printf("�t�@�C����(�g���q�Ȃ�) : %s\n",fname);
		//printf("�g���q                 : %s\n",ext);

		sprintf(textworkbuf, "%s%s",drive,dir );

		return textworkbuf;
	}

	return NULL;  //�G���[
}


//**************************************
//�w��t�@�C�������C���X�g�[���f�B���N�g��(EXE�̂���t�H���_)����̃t���p�X�ɂ��܂�
//    ������ǂݍ��ނ��߂ɃJ�����g�f�B���N�g�����ړ������ꍇ
//    EXE�̂���t�H���_�ɂ���t�@�C��������������
//**************************************
char *GetFullPath_ThisFile( char *fname )
{
	char Path[1024];
	char *dir;

	dir = GetInstallPath();

	if( dir == NULL )return NULL;

	sprintf(Path, "%s%s",dir,fname );
	strcpy(textworkbuf,Path);

	return textworkbuf;
}



//---------------------------------------------------------------
// �l�p��`��
//---------------------------------------------------------------
// ���܂�ɂ��_�`�悪�x�����߁A����Ă��Ǒ�������w�͂����Ă݂܂����B
// 21/12/08

//void elDraw32_ColorFill(int X1,int Y1,int X2,int Y2,COLORREF Color)
void elDraw32_ColorFill(int X1,int Y1,int X2,int Y2, int rr,int gg, int bb )
{
	static DDBLTFX ddbltfx;
	static RECT rect;

	rect.left   = X1;
	rect.top    = Y1;
	rect.right  = X2;
	rect.bottom = Y2;

	ddbltfx.dwSize      = sizeof(ddbltfx);
	//ddbltfx.dwFillColor = GetRValue(Color)<<elDraw::ShiftR|
	//					GetGValue(Color)<<elDraw::ShiftG|
	//					GetBValue(Color)<<elDraw::ShiftB;
	ddbltfx.dwFillColor = rr<<elDraw::ShiftR|
						  gg<<elDraw::ShiftG|
						  bb<<elDraw::ShiftB;

	//DDBack->Blt(&rect,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&ddbltfx);
	DDBack->Blt(&rect,NULL,NULL,DDBLT_COLORFILL,&ddbltfx);
}



//��̊֐����}�N���ɂ��Ă݂܂���
	DDBLTFX cf_ddbltfx;
	RECT cf_rect;

#define ColFilMac(X1,Y1,X2,Y2,rr,gg,bb) \
	cf_rect.left   = X1; \
	cf_rect.top    = Y1; \
	cf_rect.right  = X2; \
	cf_rect.bottom = Y2; \
	cf_ddbltfx.dwSize      = sizeof(cf_ddbltfx);  \
	cf_ddbltfx.dwFillColor = rr<<elDraw::ShiftR|  \
						  gg<<elDraw::ShiftG|     \
						  bb<<elDraw::ShiftB;     \
	DDBack->Blt(&cf_rect,NULL,NULL,DDBLT_COLORFILL,&cf_ddbltfx);

