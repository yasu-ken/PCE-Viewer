


//*******************************************************************************
//* 
//*******************************************************************************

/*
256�Fbmp�摜�Ƃ��ĕۑ�
*/
void pce_rom_FG_DspBMP();
void pce_rom_BG_DispBMP();

/*
�A���C�������g�����邽�߁A���̂܂܃t�@�C���ɏo�͂��Ȃ��ł��������B
�w�b�_�T�C�Y��(14+40+1024)
*/
struct BMAPHEADER_2 {
	unsigned char	bfType0;		//1 �f�[�^�`��(B)
	unsigned char	bfType1;		//1 �f�[�^�`��(M)
	//<--�����Ƀf�[�^�M���b�v���B�ȍ~�Q������܂��B
	unsigned long	bfSize;			//4 �t�@�C���T�C�Y
	unsigned short	bfReserved1;	//2 �\��
	unsigned short	bfReserved2;	//2 �\��
	unsigned long	bfOffBits;		//4 �r�b�g�}�b�v�f�[�^�̊J�n�I�t�Z�b�g
	unsigned long	biSize;			//4 �w�b�_�[�̃T�C�Y�i�ȉ��̃f�[�^�j
	long			biWidth;		//4 �����h�b�g��
	long			biHeight;		//4 �����h�b�g��
	unsigned short	biPlanes;		//2 �v���[����
	unsigned short	biBitCount;		//2 �P�s�N�Z��������̃r�b�g��(8)
	unsigned long	biCompression;	//4 ���k�`���i�O�������j
	unsigned long	biSizeImage;	//4 �r�b�g�}�b�v�f�[�^�T�C�Y
	long			biXPixPerMeter;	//4 �����𑜓x
	long			biYPixPerMeter;	//4 �����𑜓x
	unsigned long	biClrUsed;		//4 �g�p�F��
	unsigned long	biClrImporant;	//4 �d�v�ȐF�H
	unsigned char	palet[256][4];	//1024 256�F�p���b�g
}bitmapstr;

//#define BMPW 600    //�ۑ�����摜�̕�
#define BMPW 640    //�ۑ�����摜�̕�
#define BMPH 1280   //���� 211209
//#define BMPH 1500   //����

char bmpbuf[BMPW*BMPH+100];

char fileNbuf[1024];

//*******************************************************************************
//* 
//*******************************************************************************

//�t���p�X����t�@�C�������������o���܂��B
char * GetFilemeiDake( char *fullpath )
{
	//�����Ȃ��悤�ɃX�^�e�B�b�N��
	static char szDrive[8], szPath[MAX_PATH], szFName[MAX_PATH], szExt[MAX_PATH];

	// _splitpath_s(fullpath,
	// 				szDrive, sizeof(szDrive),
	// 				szPath,  sizeof(szPath),
	// 				szFName, sizeof(szFName),
	// 				szExt,   sizeof(szExt));

	_splitpath(fullpath, szDrive, szPath, szFName, szExt);

	return szFName;
}

//*******************************************************************************
//* 
//*******************************************************************************

void bmpsave()
{
	int lp,i;
	FILE *fp;
	//char fileNbuf[100];

	bitmapstr.bfType0		= 'B';
	bitmapstr.bfType1		= 'M';
	//bitmapstr.bfSize	=BMPW*BMPH+(sizeof BMAPHEADER); //�t�@�C���T�C�Y
	bitmapstr.bfSize		=BMPW*BMPH+(14+40+1024); //�t�@�C���T�C�Y
	bitmapstr.bfReserved1	=0;		 //�\��
	bitmapstr.bfReserved2	=0;		 //�\��
	bitmapstr.bfOffBits	=(14+40+1024);  //�r�b�g�}�b�v�f�[�^�̊J�n�I�t�Z�b�g
	bitmapstr.biSize		=0x28;  // 40;//�w�b�_�[�̃T�C�Y�i�ȉ��̃f�[�^�j
	bitmapstr.biWidth		=BMPW;	//�����h�b�g��
	bitmapstr.biHeight	=BMPH;	//�����h�b�g��
	bitmapstr.biPlanes	=1;		//�v���[����
	bitmapstr.biBitCount	=8;		//�P�s�N�Z��������̃r�b�g��(8)
	bitmapstr.biCompression=0;	//���k�`���i�O�������j
	bitmapstr.biSizeImage	=0;	//�r�b�g�}�b�v�f�[�^�T�C�Y
	bitmapstr.biXPixPerMeter=0;	//�����𑜓x
	bitmapstr.biYPixPerMeter=0;	//�����𑜓x
	bitmapstr.biClrUsed	=256;	//�g�p�F��
	bitmapstr.biClrImporant=0;	//�d�v�ȐF�H
	// bitmapstr.palet[256][4]=;	//256�F�p���b�g
	//01234567���R�Q�{����0,32,64, 96,128,160,192,224
	//0�ȊO�̂Ƃ��A+31��  0,63,95,127,159,191,223,255
	bitmapstr.palet[0][0]=0;
	bitmapstr.palet[0][1]=0;
	bitmapstr.palet[0][2]=0;
	bitmapstr.palet[0][3]=0;		//reserved;
	for(lp=1;lp<16;lp++){
		bitmapstr.palet[lp][0]=lp*16-1;
		bitmapstr.palet[lp][1]=lp*16-1;
		bitmapstr.palet[lp][2]=lp*16-1;
		bitmapstr.palet[lp][3]=0;		//reserved;
	}

	//255�Ԃ̐F�ɔ����Z�b�g
	bitmapstr.palet[255][0]=255; //B
	bitmapstr.palet[255][1]=255; //G
	bitmapstr.palet[255][2]=255; //R
	bitmapstr.palet[255][3]=0;   //reserved;

	//254�Ԃ̐F�ɗ΂��Z�b�g
	bitmapstr.palet[254][0]=0;   //B
	bitmapstr.palet[254][1]=255; //G
	bitmapstr.palet[254][2]=0;   //R
	bitmapstr.palet[254][3]=0;   //reserved;

	//253�Ԃ̐F�ɐԂ��Z�b�g
	bitmapstr.palet[253][0]=0;   //B
	bitmapstr.palet[253][1]=100; //G
	bitmapstr.palet[253][2]=255; //R
	bitmapstr.palet[253][3]=0;   //reserved;

	//252�Ԃ̐F�ɉ��F���Z�b�g
	bitmapstr.palet[252][0]=0;   //B
	bitmapstr.palet[252][1]=240; //G
	bitmapstr.palet[252][2]=255; //R
	bitmapstr.palet[252][3]=0;   //reserved;

	//------------------------------------------------------

	for(lp=0;lp<BMPW*BMPH;lp++){
		bmpbuf[lp]= 0;
	}

	//sprintf(fileNbuf,"SPR%06X.bmp",rom_datacnt);


	//.pce�Ȃ�xxxxx.pce��xxxxx���t�@�C������
	for( i=0; i<500; i++ ){
		if( RomName[i] == '\0' ){
			//.pce�ł�.bin�ł��Ȃ��Ƃ�
			sprintf(fileNbuf,"SPR%06X.bmp",rom_datacnt);
			break;
		}

		//.pce�̂Ƃ�
		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'P') || (RomName[i+1] == 'p') )
				if(     (RomName[i+2] == 'C') || (RomName[i+2] == 'c') )
					if( (RomName[i+3] == 'E') || (RomName[i+3] == 'e') )
					{
						sprintf(fileNbuf,"%s_SPR%06X.bmp",GetFilemeiDake( RomName ), rom_datacnt);
						break;
					}

		//.bin�̂Ƃ�
		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'B') || (RomName[i+1] == 'b') )
				if(     (RomName[i+2] == 'I') || (RomName[i+2] == 'i') )
					if( (RomName[i+3] == 'N') || (RomName[i+3] == 'n') )
					{
						sprintf(fileNbuf,"%s_SPR%06X.bmp",GetFilemeiDake( RomName ), rom_datacnt);
						break;
					}
	}



	//if (( fp = fopen( "savebmp01.bmp", "wb" )) == NULL )
	if (( fp = fopen( fileNbuf, "wb" )) == NULL )
	{
		elDraw::Error("bmpwrite()","BMP file not write error");
		return;
	}
	pce_rom_FG_DspBMP();

	//fwrite(&bmpbuf[0], 1,filesize,fp);
	//�����߁B�A���C�������g�̖�蔭���B�f�[�^���S�o�C�g��؂�ŏo���̂ł���Ă��܂��܂��B
	//�X�g���N�`�������łɂ��̑傫���Ǝv���B�f�[�^�T�C�Y���v�Z���Ă���Ƃ���
	//siseof BMAPHEADER�ł͂��߁B
	fwrite(&bitmapstr.bfType0        , 1,1,fp);
	fwrite(&bitmapstr.bfType1        , 1,1,fp);
	fwrite(&bitmapstr.bfSize         , 1,4,fp);
	fwrite(&bitmapstr.bfReserved1    , 1,2,fp);
	fwrite(&bitmapstr.bfReserved2    , 1,2,fp);
	fwrite(&bitmapstr.bfOffBits      , 1,4,fp);
	fwrite(&bitmapstr.biSize         , 1,4,fp);
	fwrite(&bitmapstr.biWidth        , 1,4,fp);
	fwrite(&bitmapstr.biHeight       , 1,4,fp);
	fwrite(&bitmapstr.biPlanes       , 1,2,fp);
	fwrite(&bitmapstr.biBitCount     , 1,2,fp);
	fwrite(&bitmapstr.biCompression  , 1,4,fp);
	fwrite(&bitmapstr.biSizeImage    , 1,4,fp);
	fwrite(&bitmapstr.biXPixPerMeter , 1,4,fp);
	fwrite(&bitmapstr.biYPixPerMeter , 1,4,fp);
	fwrite(&bitmapstr.biClrUsed      , 1,4,fp);
	fwrite(&bitmapstr.biClrImporant  , 1,4,fp);
	fwrite(&bitmapstr.palet          , 1,1024,fp);
	fwrite(&bmpbuf,1,BMPW*BMPH,fp);
	fclose(fp);


	//-----------------------------------------------

	for(lp=0;lp<BMPW*BMPH;lp++){
		bmpbuf[lp]= 0;
	}

	//sprintf(fileNbuf,"BG%06X.bmp",rom_datacnt);

	//.pce�Ȃ�xxxxx.pce��xxxxx���t�@�C������
	for( i=0; i<500; i++ ){
		if( RomName[i] == '\0' ){
			//.pce�ł�.bin�ł��Ȃ��Ƃ�
			sprintf(fileNbuf,"BG%06X.bmp",rom_datacnt);
			break;
		}

		//.pce�̂Ƃ�
		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'P') || (RomName[i+1] == 'p') )
				if(     (RomName[i+2] == 'C') || (RomName[i+2] == 'c') )
					if( (RomName[i+3] == 'E') || (RomName[i+3] == 'e') )
					{
						sprintf(fileNbuf,"%s_BG%06X.bmp",GetFilemeiDake( RomName ), rom_datacnt);
						break;
					}

		//.bin�̂Ƃ�
		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'B') || (RomName[i+1] == 'b') )
				if(     (RomName[i+2] == 'I') || (RomName[i+2] == 'i') )
					if( (RomName[i+3] == 'N') || (RomName[i+3] == 'n') )
					{
						sprintf(fileNbuf,"%s_BG%06X.bmp",GetFilemeiDake( RomName ), rom_datacnt);
						break;
					}
	}

	//if (( fp = fopen( "saveBG.bmp", "wb" )) == NULL )
	if (( fp = fopen( fileNbuf, "wb" )) == NULL )
	{
		elDraw::Error("bmpwrite()","BMP file not write error");
		return;
	}
	pce_rom_BG_DispBMP();

	fwrite(&bitmapstr.bfType0        , 1,1,fp);
	fwrite(&bitmapstr.bfType1        , 1,1,fp);
	fwrite(&bitmapstr.bfSize         , 1,4,fp);
	fwrite(&bitmapstr.bfReserved1    , 1,2,fp);
	fwrite(&bitmapstr.bfReserved2    , 1,2,fp);
	fwrite(&bitmapstr.bfOffBits      , 1,4,fp);
	fwrite(&bitmapstr.biSize         , 1,4,fp);
	fwrite(&bitmapstr.biWidth        , 1,4,fp);
	fwrite(&bitmapstr.biHeight       , 1,4,fp);
	fwrite(&bitmapstr.biPlanes       , 1,2,fp);
	fwrite(&bitmapstr.biBitCount     , 1,2,fp);
	fwrite(&bitmapstr.biCompression  , 1,4,fp);
	fwrite(&bitmapstr.biSizeImage    , 1,4,fp);
	fwrite(&bitmapstr.biXPixPerMeter , 1,4,fp);
	fwrite(&bitmapstr.biYPixPerMeter , 1,4,fp);
	fwrite(&bitmapstr.biClrUsed      , 1,4,fp);
	fwrite(&bitmapstr.biClrImporant  , 1,4,fp);
	fwrite(&bitmapstr.palet          , 1,1024,fp);
	fwrite(&bmpbuf,1,BMPW*BMPH,fp);
	fclose(fp);
}


//*******************************************************************************
//* 
//*******************************************************************************
/*
�o�b�t�@�ɕ�����`��
*/
char mojidata[]={ 
" OOOOO  "\
"OO    O "\
"O O   O "\
"O  O  O "\
"O   O O "\
"O    OO "\
" OOOOO  "\
"        "\
\
"   O    "\
"  OO    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"  OOO   "\
"        "\
\
" OOOOO  "\
"O     O "\
"O     O "\
"     O  "\
"   OO   "\
" OO     "\
"OOOOOOO "\
"        "\
\
" OOOOO  "\
"O     O "\
"      O "\
"   OOO  "\
"      O "\
"O     O "\
" OOOOO  "\
"        "\
\
"    O   "\
"O   O   "\
"O   O   "\
"O   O   "\
"OOOOOOO "\
"    O   "\
"    O   "\
"        "\
\
"OOOOOOO "\
"O       "\
"O       "\
"OOOOOO  "\
"      O "\
"      O "\
"OOOOOO  "\
"        "\
\
" OOOOO  "\
"O     O "\
"O       "\
"OOOOOO  "\
"O     O "\
"O     O "\
" OOOOO  "\
"        "\
\
"OOOOOOO "\
"      O "\
"      O "\
"     O  "\
"    O   "\
"   O    "\
"   O    "\
"        "\
\
" OOOOO  "\
"O     O "\
"O     O "\
" OOOOO  "\
"O     O "\
"O     O "\
" OOOOO  "\
"        "\
\
" OOOOO  "\
"O     O "\
"O     O "\
" OOOOOO "\
"      O "\
"O     O "\
" OOOOO  "\
"        "\
\
"  OOO   "\
" O   O  "\
"O     O "\
"O     O "\
"OOOOOOO "\
"O     O "\
"O     O "\
"        "\
\
"OOOOO   "\
"O    O  "\
"O    O  "\
"OOOOOO  "\
"O     O "\
"O     O "\
"OOOOOO  "\
"        "\
\
" OOOOO  "\
"O     O "\
"O       "\
"O       "\
"O       "\
"O     O "\
" OOOOO  "\
"        "\
\
"OOOOO   "\
"O    O  "\
"O     O "\
"O     O "\
"O     O "\
"O    O  "\
"OOOOO   "\
"        "\
\
"OOOOOO  "\
"O       "\
"O       "\
"OOOOO   "\
"O       "\
"O       "\
"OOOOOOO "\
"        "\
\
"OOOOOOO "\
"O       "\
"O       "\
"OOOOOO  "\
"O       "\
"O       "\
"O       "\
"        "\
\
" OOOOO  "\
"O     O "\
"O       "\
"O       "\
"O  OOOO "\
"O     O "\
" OOOOOO "\
"        "\
\
"O     O "\
"O     O "\
"O     O "\
"OOOOOOO "\
"O     O "\
"O     O "\
"O     O "\
"        "\
\
"  OOO   "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"  OOO   "\
"        "\
\
"    OOO "\
"     O  "\
"     O  "\
"     O  "\
"     O  "\
"O    O  "\
" OOOO   "\
"        "\
\
"O    O  "\
"O   O   "\
"O  O    "\
"O OO    "\
"OO  O   "\
"O    O  "\
"O     O "\
"        "\
\
"O       "\
"O       "\
"O       "\
"O       "\
"O       "\
"O       "\
"OOOOOOO "\
"        "\
\
"O     O "\
"OO   OO "\
"O O O O "\
"O  O  O "\
"O     O "\
"O     O "\
"O     O "\
"        "\
\
"O     O "\
"OO    O "\
"O O   O "\
"O  O  O "\
"O   O O "\
"O    OO "\
"O     O "\
"        "\
\
" OOOOO  "\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
" OOOOO  "\
"        "\
\
"OOOOOO  "\
"O     O "\
"O     O "\
"O     O "\
"OOOOOO  "\
"O       "\
"O       "\
"        "\
\
" OOOOO  "\
"O     O "\
"O     O "\
"O     O "\
"O  OOOO "\
"O O   O "\
" OOOOOO "\
"        "\
\
"OOOOOO  "\
"O     O "\
"O     O "\
"OOOOOO  "\
"O   O   "\
"O    O  "\
"O     O "\
"        "\
\
" OOOOO  "\
"O     O "\
"O       "\
" OOOOO  "\
"      O "\
"O     O "\
" OOOOO  "\
"        "\
\
"OOOOOOO "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"        "\
\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
" OOOOO  "\
"        "\
\
"O     O "\
"O     O "\
"O     O "\
"O     O "\
" O   O  "\
"  O O   "\
"   O    "\
"        "\
\
"O     O "\
"O     O "\
"O     O "\
"O  O  O "\
"O O O O "\
"OO   OO "\
"O     O "\
"        "\
\
"O     O "\
" O   O  "\
"  O O   "\
"   O    "\
"  O O   "\
" O   O  "\
"O     O "\
"        "\
\
"O     O "\
" O   O  "\
"  O O   "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"        "\
\
"OOOOOOO "\
"     O  "\
"    O   "\
"   O    "\
"  O     "\
" O      "\
"OOOOOOO "\
"        "\
\
"        "\
"        "\
" OOOOO  "\
"O     O "\
"O     O "\
"O     O "\
"O    OO "\
" OOOO O "\
\
"        "\
" O      "\
" O      "\
" OOOOO  "\
" O    O "\
" O    O "\
" O    O "\
" OOOOO  "\
\
"        "\
"        "\
" OOOOO  "\
"O     O "\
"O       "\
"O       "\
"O     O "\
" OOOOO  "\
\
"        "\
"      O "\
"      O "\
"  OOOOO "\
" O    O "\
" O    O "\
" O    O "\
"  OOOOO "\
\
"        "\
"        "\
" OOOOO  "\
"O     O "\
"O00OOOO "\
"O       "\
"O       "\
" OOOOO  "\
\
"        "\
"   OOO  "\
"   O    "\
"   O    "\
"OOOOOOO "\
"   O    "\
"   O    "\
"   O    "\
\
"        "\
"        "\
" OOOO O "\
"O    OO "\
"O     O "\
" OOOOOO "\
"      O "\
" OOOOO  "\
\
"        "\
" O      "\
" O      "\
" O      "\
" OOOOO  "\
" O    O "\
" O    O "\
" O    O "\
\
"        "\
"   O    "\
"        "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
\
"        "\
"     O  "\
"        "\
"     O  "\
"     O  "\
"     O  "\
"     O  "\
" OOOO   "\
\
"        "\
" O      "\
" O      "\
" O   OO "\
" O OO   "\
" OOO    "\
" O  OO  "\
" O    O "\
\
"        "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
"   OOO  "\
\
"        "\
"        "\
"OOOOOO  "\
"O  O  O "\
"O  O  O "\
"O  O  O "\
"O  O  O "\
"O  O  O "\
\
"        "\
"        "\
" OOOOO  "\
" O    O "\
" O    O "\
" O    O "\
" O    O "\
" O    O "\
\
"        "\
"        "\
"  OOOO  "\
" O    O "\
" O    O "\
" O    O "\
" O    O "\
"  OOOO  "\
\
"        "\
" OOOOO  "\
" O    O "\
" O    O "\
" O    O "\
" OOOOO  "\
" O      "\
" O      "\
\
"        "\
"  OOOO  "\
" O    O "\
" O    O "\
" O   O  "\
"  OOOO  "\
"     O  "\
"     OO "\
\
"        "\
"        "\
"   O O  "\
"   OO   "\
"   O    "\
"   O    "\
"   O    "\
"   O    "\
\
"        "\
"        "\
"  OOOO  "\
" O    O "\
" OOO    "\
"   OOOO "\
" O    O "\
"  OOOO  "\
\
"        "\
"   O    "\
"   O    "\
" OOOOOO "\
"   O    "\
"   O    "\
"   O    "\
"   OO   "\
\
"        "\
"        "\
" O    O "\
" O    O "\
" O    O "\
" O    O "\
" O    O "\
"  OOOOO "\
\
"        "\
"        "\
" O    O "\
" O    O "\
" O   O  "\
"  O  O  "\
"  O O   "\
"   O    "\
\
"        "\
"        "\
"O     O "\
"O     O "\
"O  O  O "\
"O  O  O "\
"O O O O "\
" O   O  "\
\
"        "\
"        "\
"O     O "\
" O   O  "\
"  O O   "\
"  OOO   "\
" O   O  "\
"O     O "\
\
"        "\
"        "\
" O    O "\
" O    O "\
" O    O "\
"  OOOOO "\
"      O "\
"  OOOO  "\
\
"        "\
"        "\
"OOOOOOO "\
"     O  "\
"    O   "\
"  OO    "\
" O      "\
"OOOOOOO "\
\
"        "\
"        "\
"        "\
"        "\
"        "\
"        "\
"        "\
"        "\
\
"    OO  "\
"   O    "\
"  O     "\
"  O     "\
"  O     "\
"  O     "\
"   O    "\
"    OO  "\
\
"  OO    "\
"    O   "\
"     O  "\
"     O  "\
"     O  "\
"     O  "\
"    O   "\
"  OO    "

};


/*
0...9 A...Z
8x8=64�o�C�g�̃h�b�g�f�[�^�B

col==0 ��
col==0�ȊO �ΐF
*/
void ascii_BMP(int code,int ofsx,int ofsy, int col=0)
{
	int lpx,lpy;
	unsigned char wok;

	//if(code==' ')return;
	if(code=='\0')return;
	if(code=='\n')return;

	if((code >='0')&&( code <='9'))
		code = code-'0';
	else if((code >='A')&&( code <='Z'))
		code = code-'A'+10;
	else if((code >='a')&&( code <='z'))
		code = code-'a'+10+26;
	else if(code ==' ')
		code = code-'a'+10+26+26;
	else if(code =='(')
		code = code-'a'+10+26+26+1;
	else if(code ==')')
		code = code-'a'+10+26+26+2;
	else{}

	code *= 64;

	int PalNo;
	if( col == 0 ) PalNo=255;
	else PalNo = col;           //255 254 253

	//16x16dot
	for(lpy=0;lpy<8;lpy++){
		for(lpx=0;lpx<8;lpx++){
			wok = mojidata[code + lpx+lpy*8];
			if( wok == 'O' ){
				bmpbuf[(BMPW*BMPH) +(ofsx+lpx)
								   -(ofsy+lpy+1)*(BMPW)] = PalNo;
								   //-(ofsy+lpy+1)*(BMPW)] = 15;
			}
		}
	}
}



char moji_4x8_data[]={ 
" OO "\
"O  O"\
"O  O"\
"O  O"\
"O  O"\
"O  O"\
" OO "\
"    "\
\
"  O "\
" OO "\
"  O "\
"  O "\
"  O "\
"  O "\
"  O "\
"    "\
\
" OO "\
"O  O"\
"   O"\
"   O"\
"  O "\
" O  "\
"OOOO"\
"    "\
\
" OO "\
"O  O"\
"   O"\
"  O "\
"   O"\
"O  O"\
" OO "\
"    "\
\
"  O "\
"O O "\
"O O "\
"O O "\
"OOOO"\
"  O "\
"  O "\
"    "\
\
"OOOO"\
"O   "\
"O   "\
"OOO "\
"   O"\
"   O"\
"OOO "\
"    "\
\
" OO "\
"O  O"\
"O   "\
"OOO "\
"O  O"\
"O  O"\
" OO "\
"    "\
\
"OOOO"\
"   O"\
"   O"\
"  O "\
"  O "\
" O  "\
" O  "\
"    "\
\
" OO "\
"O  O"\
"O  O"\
" OO "\
"O  O"\
"O  O"\
" OO "\
"    "\
\
" OO "\
"O  O"\
"O  O"\
" OOO"\
"   O"\
"   O"\
" OO "\
"    "\
\
" OO "\
"O  O"\
"O  O"\
"O  O"\
"OOOO"\
"O  O"\
"O  O"\
"    "\
\
"OO  "\
"O O "\
"O O "\
"OOO "\
"O  O"\
"O  O"\
"OOO "\
"    "\
\
" OO "\
"O  O"\
"O   "\
"O   "\
"O   "\
"O  O"\
" OO "\
"    "\
\
"OO  "\
"O O "\
"O  O"\
"O  O"\
"O  O"\
"O O "\
"OO  "\
"    "\
\
"OOO0"\
"O   "\
"O   "\
"OOO "\
"O   "\
"O   "\
"OOOO"\
"    "\
\
"OOOO"\
"O   "\
"O   "\
"OOO0"\
"O   "\
"O   "\
"O   "\
"    "
};


/*
	0...9 A...F
	8x8=64�o�C�g�̃h�b�g�f�[�^�B
	col==0 ��
	col==0�ȊO �ΐF
*/
void ascii_BMP4X8(int code,int ofsx,int ofsy, int col=0)
{
	int lpx,lpy;
	unsigned char wok;

	//if(code==' ')return;
	if(code=='\0')return;
	if(code=='\n')return;

	if((code >='0')&&( code <='9'))
		code = code-'0';
	else if((code >='A')&&( code <='Z'))
		code = code-'A'+10;
	else{ return; }

	code *= 32;  //1����32byte

	int PalNo;
	if( col == 0 ) PalNo=255;
	else PalNo = col;           //255 254 253

	//16x16dot
	for(lpy=0;lpy<8;lpy++){
		for(lpx=0;lpx<4;lpx++){
			wok = moji_4x8_data[code + lpx+lpy*4];
			if( wok == 'O' ){
				bmpbuf[(BMPW*BMPH) +(ofsx+lpx)
								   -(ofsy+lpy+1)*(BMPW)] = PalNo;
								   //-(ofsy+lpy+1)*(BMPW)] = 15;
			}
		}
	}
}



//*******************************************************************************
//* 
//*******************************************************************************

void FG_BoxBMP( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy , int bkno)
{
	int lp,linecnt,dotcnt,lpx,lpy,pln_cnt,wok;
	unsigned short linedata;	//�P���C��16�h�b�g�̃f�[�^
	unsigned short setbit;		//1 2 4 8�i�v���[���ɐݒ肷��r�b�g�j

	char msgbuf[100];
	//elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=SPR",rom_datacnt+dispadr_add);

	for(lp=0;lp<100;lp++)
		msgbuf[100]='\0';
	sprintf(msgbuf,"%06X SPR",rom_datacnt+dispadr_add);
	for(lp=0;lp<16;lp++){
		if(msgbuf[lp]=='\0')break;
		ascii_BMP(msgbuf[lp], ofsx+lp*8,ofsy-8);
	}

	sprintf(msgbuf,"%03X",bkno);
	for(lp=0;lp<3;lp++){
		ascii_BMP(msgbuf[lp], ofsx+96+lp*8,ofsy-8,254);
	}

	sprintf(msgbuf,"%03X %03X %03X %03X",bkno*4,bkno*4+1,bkno*4+2,bkno*4+3 );
	for(lp=0;lp<16;lp++){
		ascii_BMP(msgbuf[lp], ofsx+lp*8,ofsy-16,253);  //253 �ԐF
	}

	//�U�S�̃X�v���C�g��\��
	for(lp=0;lp<64;lp++){

		for(wok=0;wok<256;wok++){
			dot_wok[wok]=0;				//���ŃN���A
		}

		//0�̃v���[��=1 1�̃v���[��=2 2�̃v���[��=4 3�̃v���[��=8
		setbit = 0x01;

		for(pln_cnt=0;pln_cnt<4;pln_cnt++){		//�v���[���S��

			for(linecnt = 0;linecnt<16;linecnt++){	//16���C��
				linedata = *romptr;		//�P���C�����f�[�^����肾��
				romptr++;

				for(dotcnt = 0;dotcnt<16;dotcnt++){		//16�r�b�g
					//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
					if(linedata & 0x8000){
						dot_wok[linecnt*16+dotcnt] |= setbit;
					}
					//�E���[�h����<<1
					linedata = linedata<<1;
				}
			}
			setbit = setbit <<1 ;		//1 2 4 8
		}

		//16x16dot
		for(lpy=0;lpy<16;lpy++){
			for(lpx=0;lpx<16;lpx++){
				wok = dot_wok[lpy*16+lpx];		//0...15 palet no.

				//wok = wok+viewer_Pal * 16;		//�Z���N�g����Ă���16�F�p���b�g
				//elDraw::ColorFill(
				//				ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx,
				//				ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy,
				//				ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx+1,
				//				ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy+1,
				//				  RGB16(
				//					windows_paltbl[ palet[wok].red ],
				//					windows_paltbl[ palet[wok].green ],
				//					windows_paltbl[ palet[wok].blue ])
				//					);
				bmpbuf[(BMPW*BMPH) +(ofsx+lpx+sprt_disploctbl[lp][0])
								   -(ofsy+lpy+1+sprt_disploctbl[lp][1])*(BMPW)] = wok;
			}
		}
	}
}




//*******************************************************************************
//* 
//*******************************************************************************

void pce_rom_FG_DspBMP()
{

	int i;
	unsigned short *romptr;

	//elDraw::ShowFormat( DISP_RU_X,DISP_RU_Y-16,"ADDRESS:%-8Xh   TYPE=SPRITE",rom_datacnt);

	romptr = rom_ptr;		//�I���W�i���̒l���󂳂Ȃ�����

	//�o���N�ԍ����v�Z
	int bkNo;
	bkNo = rom_datacnt / 0x2000;  //�[���͂Ƃ�܂��B���̌����Ă��鑋���ǂ̃o���N�ɑ����邩

	int indent=24;
	int romofs=0x000;
	for( i=0 ; i<8; i++ )
	{
		FG_BoxBMP( romptr + romofs        , romofs*2        , 24+0,     32+(128*i)+(indent*i) ,bkNo+i*4   );
		FG_BoxBMP( romptr +(romofs+0x1000),(romofs+0x1000)*2, 24+128+32,32+(128*i)+(indent*i) ,bkNo+i*4+1 );
		FG_BoxBMP( romptr +(romofs+0x2000),(romofs+0x2000)*2, 24+256+64,32+(128*i)+(indent*i) ,bkNo+i*4+2 );
		FG_BoxBMP( romptr +(romofs+0x3000),(romofs+0x3000)*2, 24+384+96,32+(128*i)+(indent*i) ,bkNo+i*4+3 );

		romofs += 0x4000;
	}


//	FG_BoxBMP( romptr         ,0x0000, 16+0,     32 ,bkNo   );
//	FG_BoxBMP( romptr + 0x1000,0x2000, 16+128+16,32 ,bkNo+1 );  //short*0x1000 = 0x2000byte
//	FG_BoxBMP( romptr + 0x2000,0x4000, 16+256+32,32 ,bkNo+2 );
//	FG_BoxBMP( romptr + 0x3000,0x6000, 16+384+48,32 ,bkNo+3 );
//
//	FG_BoxBMP( romptr + 0x4000,0x8000, 16+0,     32+128+16 ,bkNo+4 );
//	FG_BoxBMP( romptr + 0x5000,0xa000, 16+128+16,32+128+16 ,bkNo+5 );
//	FG_BoxBMP( romptr + 0x6000,0xc000, 16+256+32,32+128+16 ,bkNo+6 );
//	FG_BoxBMP( romptr + 0x7000,0xe000, 16+384+48,32+128+16 ,bkNo+7 );
//
//	FG_BoxBMP( romptr + 0x8000,0x10000, 16+0,     32+256+32 ,bkNo+8 );
//	FG_BoxBMP( romptr + 0x9000,0x12000, 16+128+16,32+256+32 ,bkNo+9 );
//	FG_BoxBMP( romptr + 0xa000,0x14000, 16+256+32,32+256+32 ,bkNo+10 );
//	FG_BoxBMP( romptr + 0xb000,0x16000, 16+384+48,32+256+32 ,bkNo+11 );
//
//	FG_BoxBMP( romptr + 0xc000,0x18000, 16+0,     32+384+48 ,bkNo+12 );
//	FG_BoxBMP( romptr + 0xd000,0x1a000, 16+128+16,32+384+48 ,bkNo+13 );
//	FG_BoxBMP( romptr + 0xe000,0x1c000, 16+256+32,32+384+48 ,bkNo+14 );
//	FG_BoxBMP( romptr + 0xf000,0x1e000, 16+384+48,32+384+48 ,bkNo+15 );
//
//	FG_BoxBMP( romptr + 0x10000,0x10000*2, 16+0,     32+128*4+16*4 ,bkNo+16 );
//	FG_BoxBMP( romptr + 0x11000,0x11000*2, 16+128+16,32+128*4+16*4 ,bkNo+17 );
//	FG_BoxBMP( romptr + 0x12000,0x12000*2, 16+256+32,32+128*4+16*4 ,bkNo+18 );
//	FG_BoxBMP( romptr + 0x13000,0x13000*2, 16+384+48,32+128*4+16*4 ,bkNo+19 );
//
//	FG_BoxBMP( romptr + 0x14000,0x14000*2, 16+0,     32+128*5+16*5 ,bkNo+20 );
//	FG_BoxBMP( romptr + 0x15000,0x15000*2, 16+128+16,32+128*5+16*5 ,bkNo+21 );
//	FG_BoxBMP( romptr + 0x16000,0x16000*2, 16+256+32,32+128*5+16*5 ,bkNo+22 );
//	FG_BoxBMP( romptr + 0x17000,0x17000*2, 16+384+48,32+128*5+16*5 ,bkNo+23 );
//
//	FG_BoxBMP( romptr + 0x18000,0x18000*2, 16+0,     32+128*6+16*6 ,bkNo+24 );
//	FG_BoxBMP( romptr + 0x19000,0x19000*2, 16+128+16,32+128*6+16*6 ,bkNo+25 );
//	FG_BoxBMP( romptr + 0x1a000,0x1a000*2, 16+256+32,32+128*6+16*6 ,bkNo+26 );
//	FG_BoxBMP( romptr + 0x1b000,0x1b000*2, 16+384+48,32+128*6+16*6 ,bkNo+27 );
//
//	FG_BoxBMP( romptr + 0x1c000,0x1c000*2, 16+0,     32+128*7+16*7 ,bkNo+28 );
//	FG_BoxBMP( romptr + 0x1d000,0x1d000*2, 16+128+16,32+128*7+16*7 ,bkNo+29 );
//	FG_BoxBMP( romptr + 0x1e000,0x1e000*2, 16+256+32,32+128*7+16*7 ,bkNo+30 );
//	FG_BoxBMP( romptr + 0x1f000,0x1f000*2, 16+384+48,32+128*7+16*7 ,bkNo+31 );
}



//*******************************************************************************
//* 
//*******************************************************************************

void BG_BoxBMP( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy, int bkno)
{
	int lp,linecnt,dotcnt,lpx,lpy,wok;
	unsigned long linedata;	//�P���C��16�h�b�g�̃f�[�^(32�r�b�g��)
	unsigned short setbit;		//1 2 4 8�i�v���[���ɐݒ肷��r�b�g�j

	char msgbuf[100];
	//elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=BG ",rom_datacnt+dispadr_add);
	for(lp=0;lp<100;lp++)
		msgbuf[100]='\0';
	sprintf(msgbuf,"%06X BG",rom_datacnt+dispadr_add);
	for(lp=0;lp<16;lp++){
		if(msgbuf[lp]=='\0')break;
		ascii_BMP(msgbuf[lp], ofsx+lp*8,ofsy-8);
	}

	//sprintf(msgbuf,"%02X",bkno);
	sprintf(msgbuf,"%03X",bkno);
	for(lp=0;lp<3;lp++){
		ascii_BMP(msgbuf[lp], ofsx+96+lp*8,ofsy-8,254);
	}

	for(int i=0; i<4; i++ )
	{
		sprintf(msgbuf,"%03X",bkno*4+i);
		ascii_BMP4X8(msgbuf[0], ofsx    -12-2 ,ofsy+32*i,253);  //253 �ԐF
		ascii_BMP4X8(msgbuf[1], ofsx+1*4-12-1 ,ofsy+32*i,252);  //252 �Ԃ��ۂ��F
		ascii_BMP4X8(msgbuf[2], ofsx+2*4-12   ,ofsy+32*i,253);  //253 �ԐF
	}

	//256��BG��\��
	//for(lp=0;lp<256;lp++){

	//���w�蕝�A�����̉摜�̕\��
	for(lp=0;lp< rom_BG_High*rom_BG_Width;lp++){

		for(wok=0;wok<256;wok++){
			dot_wok[wok]=0;				//���ŃN���A
		}

		//0�̃v���[��=1 1�̃v���[��=2 2�̃v���[��=4 3�̃v���[��=8
		for(linecnt = 0;linecnt<8;linecnt++){	//8word(2�v���[����)
			setbit = 0x01;
			linedata = *romptr;		//16bit�f�[�^����肾��
			romptr++;

			//��ʂW�r�b�g��������ׂāA�r�b�g��ON�Ȃ牡�W�h�b�g�ɓW�J���܂�
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
				if(linedata & 0x80){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//�Ebyte����<<1
				linedata = linedata<<1;
			}

			//�v���[��++
			setbit = setbit <<1 ;		//1 2 4 8
			//���ʂW�r�b�g������ׂāA�r�b�g��ON�Ȃ牡�W�h�b�g�ɓW�J���܂�
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
				if(linedata & 0x800000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//�Ebyte����<<1
				linedata = linedata<<1;
			}
		}

		for(linecnt = 0;linecnt<8;linecnt++){	//8word(2�v���[����)
			setbit = 0x04;
			linedata = *romptr;		//16bit�f�[�^����肾��
			romptr++;

			//��ʂW�r�b�g��������ׂāA�r�b�g��ON�Ȃ牡�W�h�b�g�ɓW�J���܂�
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
				if(linedata & 0x080){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//�Ebyte����<<1
				linedata = linedata<<1;
			}

			//�v���[��++
			setbit = setbit <<1 ;		//1 2 4 8
			//���ʂW�r�b�g������ׂāA�r�b�g��ON�Ȃ牡�W�h�b�g�ɓW�J���܂�
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
				if(linedata & 0x800000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//�Ebyte����<<1
				linedata = linedata<<1;
			}
		}

		//8x8dot
		for(lpy=0;lpy<8;lpy++){
			for(lpx=0;lpx<8;lpx++){
				wok = dot_wok[lpy*8+lpx];		//0...15 palet no.
				bmpbuf[(BMPW*BMPH) +(ofsx+lpx+(lp%rom_BG_Width)*8)
								   -(ofsy+lpy+1+(lp/rom_BG_High)*8)*(BMPW)] = wok;

				//elDraw::ColorFill(
				//				//DISP_RU_X+(lp%16)*8 +lpx,
				//				//DISP_RU_Y+(lp/16)*8 +lpy,
				//				//DISP_RU_X+(lp%16)*8 +lpx+1,
				//				//DISP_RU_Y+(lp/16)*8 +lpy+1,
				//				DISP_RU_X+ofsx+(lp%rom_BG_Width)*8 +lpx,//���w�蕝�A�����̉摜�̕\��
				//				DISP_RU_Y+ofsy+(lp/rom_BG_High)*8 +lpy,
				//				DISP_RU_X+ofsx+(lp%rom_BG_Width)*8 +lpx+1,
				//				DISP_RU_Y+ofsy+(lp/rom_BG_High)*8 +lpy+1,
				//			    RGB16(
				//					windows_paltbl[ palet[wok].red ],
				//					windows_paltbl[ palet[wok].green ],
				//					windows_paltbl[ palet[wok].blue ])
				//					);
			}
		}
	}
}



//*******************************************************************************
//* 
//*******************************************************************************

void pce_rom_BG_DispBMP(){

	int i;
	unsigned short *romptr;
	romptr = rom_ptr;	//�I���W�i���̒l���󂳂Ȃ�����

	//�o���N�ԍ����v�Z
	int bkNo;
	bkNo = rom_datacnt / 0x2000;  //�[���͂Ƃ�܂��B���̌����Ă��鑋���ǂ̃o���N�ɑ����邩

	int indent=24;
	int romofs=0x000;
	for( i=0 ; i<8; i++ )
	{

		BG_BoxBMP( romptr + romofs        , romofs*2        , 24+0,     32+(128*i)+(indent*i) ,bkNo+i*4   );
		BG_BoxBMP( romptr +(romofs+0x1000),(romofs+0x1000)*2, 24+128+32,32+(128*i)+(indent*i) ,bkNo+i*4+1 );
		BG_BoxBMP( romptr +(romofs+0x2000),(romofs+0x2000)*2, 24+256+64,32+(128*i)+(indent*i) ,bkNo+i*4+2 );
		BG_BoxBMP( romptr +(romofs+0x3000),(romofs+0x3000)*2, 24+384+96,32+(128*i)+(indent*i) ,bkNo+i*4+3 );

		romofs += 0x4000;
	}


//	BG_BoxBMP( romptr         ,0x0000, 16+0,      32 ,bkNo   );
//	BG_BoxBMP( romptr + 0x1000,0x2000, 16+128+16, 32 ,bkNo+1 );  //short*0x1000 = 0x2000byte
//	BG_BoxBMP( romptr + 0x2000,0x4000, 16+256+32, 32 ,bkNo+2 );
//	BG_BoxBMP( romptr + 0x3000,0x6000, 16+384+48, 32 ,bkNo+3 );
//
//	BG_BoxBMP( romptr + 0x4000,0x8000, 16+0,      32+128+16 ,bkNo+4 );
//	BG_BoxBMP( romptr + 0x5000,0xa000, 16+128+16, 32+128+16 ,bkNo+5 );
//	BG_BoxBMP( romptr + 0x6000,0xc000, 16+256+32, 32+128+16 ,bkNo+6 );
//	BG_BoxBMP( romptr + 0x7000,0xe000, 16+384+48, 32+128+16 ,bkNo+7 );
//
//	BG_BoxBMP( romptr + 0x8000,0x10000, 16+0,     32+256+32 ,bkNo+8 );
//	BG_BoxBMP( romptr + 0x9000,0x12000, 16+128+16,32+256+32 ,bkNo+9 );
//	BG_BoxBMP( romptr + 0xa000,0x14000, 16+256+32,32+256+32 ,bkNo+10 );
//	BG_BoxBMP( romptr + 0xb000,0x16000, 16+384+48,32+256+32 ,bkNo+11 );
//
//	BG_BoxBMP( romptr + 0xc000,0x18000, 16+0,     32+384+48 ,bkNo+12 );
//	BG_BoxBMP( romptr + 0xd000,0x1a000, 16+128+16,32+384+48 ,bkNo+13 );
//	BG_BoxBMP( romptr + 0xe000,0x1c000, 16+256+32,32+384+48 ,bkNo+14 );
//	BG_BoxBMP( romptr + 0xf000,0x1e000, 16+384+48,32+384+48 ,bkNo+15 );
//
//	//21/12/09
//	BG_BoxBMP( romptr + 0x10000,0x10000*2, 16+0,     32+128*4+16*4 ,bkNo+16 );
//	BG_BoxBMP( romptr + 0x11000,0x11000*2, 16+128+16,32+128*4+16*4 ,bkNo+17 );
//	BG_BoxBMP( romptr + 0x12000,0x12000*2, 16+256+32,32+128*4+16*4 ,bkNo+18 );
//	BG_BoxBMP( romptr + 0x13000,0x13000*2, 16+384+48,32+128*4+16*4 ,bkNo+19 );
//
//	BG_BoxBMP( romptr + 0x14000,0x14000*2, 16+0,     32+128*5+16*5 ,bkNo+20 );
//	BG_BoxBMP( romptr + 0x15000,0x15000*2, 16+128+16,32+128*5+16*5 ,bkNo+21 );
//	BG_BoxBMP( romptr + 0x16000,0x16000*2, 16+256+32,32+128*5+16*5 ,bkNo+22 );
//	BG_BoxBMP( romptr + 0x17000,0x17000*2, 16+384+48,32+128*5+16*5 ,bkNo+23 );
//
//	BG_BoxBMP( romptr + 0x18000,0x18000*2, 16+0,     32+128*6+16*6 ,bkNo+24 );
//	BG_BoxBMP( romptr + 0x19000,0x19000*2, 16+128+16,32+128*6+16*6 ,bkNo+25 );
//	BG_BoxBMP( romptr + 0x1a000,0x1a000*2, 16+256+32,32+128*6+16*6 ,bkNo+26 );
//	BG_BoxBMP( romptr + 0x1b000,0x1b000*2, 16+384+48,32+128*6+16*6 ,bkNo+27 );
//
//	BG_BoxBMP( romptr + 0x1c000,0x1c000*2, 16+0,     32+128*7+16*7 ,bkNo+28 );
//	BG_BoxBMP( romptr + 0x1d000,0x1d000*2, 16+128+16,32+128*7+16*7 ,bkNo+29 );
//	BG_BoxBMP( romptr + 0x1e000,0x1e000*2, 16+256+32,32+128*7+16*7 ,bkNo+30 );
//	BG_BoxBMP( romptr + 0x1f000,0x1f000*2, 16+384+48,32+128*7+16*7 ,bkNo+31 );
}
