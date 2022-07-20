//ROM�ǂݍ��݃G���A �ő�̃X�g�Q�ɍ��킹�A�S���K�o�C�g�܂�
// 1024 x 1024 = 1048576(100000h)    1mega byte

//#define ROMDT_ST2 0x100000*4
//#define ROMDT_ST2 0x100000*16    //220420 cdromrom���ǂ݂�������16���K�o�C�g��
#define ROMDT_ST2 0x100000*0x20    //220505 �X�[�p�[���d 26MB �T�t�@�C��17MB �_�E�����[�h2(19MB)
                                   // �E�C���Y�I�u 7.4MB   �T�C�L�b�N�X�g�[��12MB �l�N�X�U�[���X�y�V����6.5MB
                                   // �X�^�[�p���W���[ 4.2MB �t�H�S�b�g�� 9.1MB
                                   // ������Ƃ���2-4MB�ł��B


unsigned char romdata[ROMDT_ST2];
int rom_datacnt;

//pce�̉摜�̓f�[�^�����[�h�A�N�Z�X�̂���
unsigned short *rom_ptr;
//����������������������������������������������������������������
//����������������������������������������������������������������
int romFileSize = 0;



//����������������������������������������������������������������
//rom�ǂݍ��݊֐�
//����������������������������������������������������������������
//(21/12/08) .pce�̂Ƃ��w�b�_200h����鏈����ǉ��B���Ȃ��Ƃ���.bin�̂���

int pce_Read()
{
	int Rtype = 0;   // 0=.pce 1=.bin
	int i,lp;
	FILE *fp;
	char buf[_MAX_PATH];

	for(lp=0;lp<ROMDT_ST2;lp++){
		romdata[lp]=0;
	}

	//ini�t�@�C�����O��A�N�Z�X�����f�B���N�g������肾���Đݒ�
	makefullpath();
	ini_GetStr("DIR", "CURENT",szDrvPath,buf);
	//�J�����g�f�B���N�g���Ƃ��Đݒ�
	SetCurrentDirectory(buf);

	strcpy( RomName, "*.pce;*.bin" );
	if(NULL == OpenDlg( "rom�t�@�C���i.pce�j", RomName )){
		strcpy( RomName, "KungFu.pce" );
	}

	//�ړ������̂��̃J�����g�f�B���N�g����ini�ɕۑ��B
	//�J�����g�f�B���N�g���̎擾
	GetCurrentDirectory(_MAX_PATH, buf);
	//�ۑ�
	ini_SetStr("DIR", "CURENT",szDrvPath,buf);

	if (( fp = fopen(RomName, "rb" )) == NULL )
	{
		elDraw::Error("pce_Read()","Rom file not found");
		exitflg = 1;
		return( -1 );
	}
/*
	romFileSize = fread(&romdata[0],1,ROMDT_ST2,fp);
	fclose(fp);

	if(( romFileSize % 0x2000 )==0x200){  //�t�@�C���T�C�Y��+200h�̔��[������΃w�b�_�t���B
		//0x200�̓w�b�_��ǂݔ�΂�����
		rom_datacnt =0x200;   //���[�h�J�E���^
		rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//���[�h�|�C���^
	}
	else{
		rom_datacnt =0x000;
		rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//���[�h�|�C���^
	}
*/

	//.pce�Ȃ�w�b�_���̂Ă�
	for( i=0; i<500; i++ ){
		if( RomName[i] == '\0' )break;

		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'P') || (RomName[i+1] == 'p') )
				if(     (RomName[i+2] == 'C') || (RomName[i+2] == 'c') )
					if( (RomName[i+3] == 'E') || (RomName[i+3] == 'e') )
					{
						//fp����0x200�ǂݔ�΂�
						romFileSize = fread(&romdata[0],1,0x200,fp);
						break;
					}
	}
	//pce��rom�̍ő�T�C�Y�ł���X�g�c�[�̃T�C�Y�œǂݍ���
	romFileSize = fread(&romdata[0],1,ROMDT_ST2,fp);
	fclose(fp);

	rom_datacnt =0x000;
	rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//���[�h�|�C���^

	return(0);
}

//����������������������������������������������������������������
// �X�v���C�g�̕\��
//rom�\���A�h���X����0x2000�o�C�g�i8x8�X�v���C�g���j�\��
//����������������������������������������������������������������
//�\���J�n������W
#define DISP_RU_X 365
#define DISP_RU_Y 40

//�\���ʒu�e�[�u��
//�U�S�̃X�v���C�g�̕\���ʒu�w�A�x
int sprt_disploctbl[64][2]={
{  0,  0},		{ 16,  0},	{  0, 16},		{ 16, 16},
{  0, 32},		{ 16, 32},	{  0, 48},		{ 16, 48},
{  0, 64},		{ 16, 64},	{  0, 80},		{ 16, 80},
{  0, 96},		{ 16, 96},	{  0,112},		{ 16,112},
{ 32,  0},		{ 48,  0},	{ 32, 16},		{ 48, 16},
{ 32, 32},		{ 48, 32},	{ 32, 48},		{ 48, 48},
{ 32, 64},		{ 48, 64},	{ 32, 80},		{ 48, 80},
{ 32, 96},		{ 48, 96},	{ 32,112},		{ 48,112},
{ 64,  0},		{ 80,  0},	{ 64, 16},		{ 80, 16},
{ 64, 32},		{ 80, 32},	{ 64, 48},		{ 80, 48},
{ 64, 64},		{ 80, 64},	{ 64, 80},		{ 80, 80},
{ 64, 96},		{ 80, 96},	{ 64,112},		{ 80,112},
{ 96,  0},		{112,  0},	{ 96, 16},		{112, 16},
{ 96, 32},		{112, 32},	{ 96, 48},		{112, 48},
{ 96, 64},		{112, 64},	{ 96, 80},		{112, 80},
{ 96, 96},		{112, 96},	{ 96,112},		{112,112}};
//�X�v���C�g�����̏��ԂɂȂ�悤�ɕ\��
// 00 01  10 11  20 21  30 31
// 02 03  12 13  22 23  32 33
// 04 05  14 15  24 25  34 35
// 06 07  16 17  26 27  36 37
// 08 09  18 19  28 29  38 39
// 0A 0B  1A 1B  2A 2B  3A 3B
// 0C 0D  1C 1D  2C 2D  3C 3D
// 0E 0F  1E 1F  2E 2F  3E 3F

//16x16�h�b�g�̍�Ɨ̈�
short dot_wok[256];


//$2000�Ԃ�8x8�Z���̉摜���X�v���C�g�Ƃ��ĕ`��B
//���̊֐��A�����[���x���̂Œ��ӁB

void FG_Box( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy)
{
	int lp,linecnt,dotcnt,lpx,lpy,pln_cnt,wok;
	unsigned short linedata;	//�P���C��16�h�b�g�̃f�[�^
	unsigned short setbit;		//1 2 4 8�i�v���[���ɐݒ肷��r�b�g�j

	elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=SPR",rom_datacnt+dispadr_add);

	//�U�S�̃X�v���C�g��\��
	for(lp=0;lp<64;lp++){

		for(wok=0;wok<256;wok++){
			dot_wok[wok]=0;				//���ŃN���A
		}

/*
		//0�̃v���[��=1 1�̃v���[��=2 2�̃v���[��=4 3�̃v���[��=8
		setbit = 0x01;
		for(pln_cnt=0;pln_cnt<4;pln_cnt++)		//�v���[���S��
		{
			for(linecnt = 0;linecnt<16;linecnt++)	//16���C��
			{
				linedata = *romptr;		//�P���C�����f�[�^����肾��
				romptr++;

				for(dotcnt = 0;dotcnt<16;dotcnt++)		//16�r�b�g
				{
					//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
					if(linedata & 0x8000)
					{
						dot_wok[linecnt*16+dotcnt] |= setbit;
					}
					//�E���[�h����<<1
					linedata = linedata<<1;
				}
			}
			setbit = setbit <<1 ;		//1 2 4 8
		}
*/

		//��̏��������[�v�W�J���܂��B

		short *dotptr;

		setbit = 0x01;		//0�̃v���[��=1 1�̃v���[��=2 2�̃v���[��=4 3�̃v���[��=8
		for(pln_cnt=0;pln_cnt<4;pln_cnt++)		//�v���[���S��
		{
			for(linecnt = 0;linecnt<256;linecnt+=16) //16���C��
			{
				linedata = *romptr;		//�P���C�����f�[�^����肾��
				romptr++;

				dotptr = &dot_wok[linecnt];   //16����

				//�EHIGH�̃r�b�g�𒲂ׂ܂� ON�Ȃ�f�[�^���J���[��ݒ�
				if(linedata & 0x8000) *dotptr |= setbit; dotptr++;
				if(linedata & 0x4000) *dotptr |= setbit; dotptr++;
				if(linedata & 0x2000) *dotptr |= setbit; dotptr++;
				if(linedata & 0x1000) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0800) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0400) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0200) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0100) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0080) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0040) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0020) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0010) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0008) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0004) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0002) *dotptr |= setbit; dotptr++;
				if(linedata & 0x0001) *dotptr |= setbit; dotptr++;
			}
			setbit = setbit <<1 ;		//1 2 4 8
		}



		//16x16dot
		for(lpy=0;lpy<16;lpy++){
			for(lpx=0;lpx<16;lpx++){
				wok = dot_wok[lpy*16+lpx];		//0...15 palet no.

				wok = wok+viewer_Pal * 16;		//�Z���N�g����Ă���16�F�p���b�g

				ColFilMac(		ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx,
								ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy,
								ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx+1,
								ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy+1,
								windows_paltbl[ palet[wok].red ],
								windows_paltbl[ palet[wok].green ],
								windows_paltbl[ palet[wok].blue ]);
/*
				elDraw32::ColorFill(
								ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx,
								ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy,
								ofsx+DISP_RU_X+sprt_disploctbl[lp][0]+lpx+1,
								ofsy+DISP_RU_Y+sprt_disploctbl[lp][1]+lpy+1,
								  RGB(
									windows_paltbl[ palet[wok].red ],
									windows_paltbl[ palet[wok].green ],
									windows_paltbl[ palet[wok].blue ])
									);
*/
			}
		}
	}

}

void pce_rom_FG_Disp(){

	unsigned short *romptr;

	//elDraw::ShowFormat( DISP_RU_X,DISP_RU_Y-16,"ADDRESS:%-8Xh   TYPE=SPRITE",rom_datacnt);

	romptr = rom_ptr;		//�I���W�i���̒l���󂳂Ȃ�����

	FG_Box( romptr         ,0x0000, 0,0 );
	FG_Box( romptr + 0x1000,0x2000, 128+8,0 );  //short*0x1000 = 0x2000byte
	FG_Box( romptr + 0x2000,0x4000, 256+16,0 );
	FG_Box( romptr + 0x3000,0x6000, 384+24,0 );

	//�Ƃ̃}�V���ł͒x���Ȃ肷���܂��B(2008�N)
	//FG_Box( romptr + 0x4000,0x8000, 0,     128+16 );
	//FG_Box( romptr + 0x5000,0xa000, 128+8, 128+16 );  //short*0x1000 = 0x2000byte
	//FG_Box( romptr + 0x6000,0xc000, 256+16,128+16 );
	//FG_Box( romptr + 0x7000,0xe000, 384+24,128+16 );
}
//����������������������������������������������������������������
// BG�̕\��
// rom�\���A�h���X����0x2000�o�C�g�i8x8�X�v���C�g���j�\��
//����������������������������������������������������������������

void BG_Box( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy)
{
	int lp,linecnt,dotcnt,lpx,lpy,wok;
	unsigned short linedata;	//�P���C��16�h�b�g�̃f�[�^
	unsigned short setbit;		//1 2 4 8�i�v���[���ɐݒ肷��r�b�g�j

	elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=BG ",rom_datacnt+dispadr_add);

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
				if(linedata & 0x8000){
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
				if(linedata & 0x8000){
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
				if(linedata & 0x8000){
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
				if(linedata & 0x8000){
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

				wok = wok+viewer_Pal * 16;		//�Z���N�g����Ă���16�F�p���b�g

				elDraw32::ColorFill(
								//DISP_RU_X+(lp%16)*8 +lpx,
								//DISP_RU_Y+(lp/16)*8 +lpy,
								//DISP_RU_X+(lp%16)*8 +lpx+1,
								//DISP_RU_Y+(lp/16)*8 +lpy+1,
								DISP_RU_X+ofsx+(lp%rom_BG_Width)*8 +lpx,//���w�蕝�A�����̉摜�̕\��
								DISP_RU_Y+ofsy+(lp/rom_BG_High)*8 +lpy,
								DISP_RU_X+ofsx+(lp%rom_BG_Width)*8 +lpx+1,
								DISP_RU_Y+ofsy+(lp/rom_BG_High)*8 +lpy+1,
							    RGB(
									windows_paltbl[ palet[wok].red ],
									windows_paltbl[ palet[wok].green ],
									windows_paltbl[ palet[wok].blue ])
									);
			}
		}
	}

}

void pce_rom_BG_Disp(){

	unsigned short *romptr;
	romptr = rom_ptr;	//�I���W�i���̒l���󂳂Ȃ�����

	BG_Box( romptr         ,0x0000, 0,0 );
	BG_Box( romptr + 0x1000,0x2000, 128+8,0 );  //short*0x1000 = 0x2000byte
	BG_Box( romptr + 0x2000,0x4000, 256+16,0 );
	BG_Box( romptr + 0x3000,0x6000, 384+24,0 );

	//�Ƃ̃}�V���ł͒x���Ȃ肷���܂��B
	//BG_Box( romptr + 0x4000,0x8000, 0,     128+16 );
	//BG_Box( romptr + 0x5000,0xa000, 128+8, 128+16 );  //short*0x1000 = 0x2000byte
	//BG_Box( romptr + 0x6000,0xc000, 256+16,128+16 );
	//BG_Box( romptr + 0x7000,0xe000, 384+24,128+16 );
}

void pce_rom_Disp(){
	if(rom_Disp_Mode == 0){
		pce_rom_FG_Disp();
	}
	else{
		pce_rom_BG_Disp();
	}
}
//����������������������������������������������������������������
//rom�\���A�h���X�����炵�܂�
//		�v���X�����A�}�C�i�X�����A�ʂ��w��ł��܂�
//����������������������������������������������������������������
void pce_adr_updn(int val)
{
	rom_datacnt += val;		//�o�C�g�J�E���^
	if(rom_datacnt<0){
		rom_datacnt = 0;
	}
	if(rom_datacnt >(ROMDT_ST2-0x2000)){
		rom_datacnt = ROMDT_ST2-0x2000;
	}
	rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//���[�h�|�C���^
}
