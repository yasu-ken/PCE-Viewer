/********************************************************************************/
/*                                                                              */
/********************************************************************************/
#define BTN_MAX 31

struct botton_st {
	int xx,yy;
	int lenx,leny;
	char *title;
}	botton_Data[BTN_MAX]={
	//0
	{GAGE_X-70,GAGE_R_Y-4,	20,20,	"��"},		//�p���b�g��
	{GAGE_X-35,GAGE_R_Y-4,	20,20,	"��"},		//�p���b�g��
	{GAGE_X-70,GAGE_G_Y-4,	20,20,	"��"},		//�p���b�g��
	{GAGE_X-35,GAGE_G_Y-4,	20,20,	"��"},		//�p���b�g��
	{GAGE_X-70,GAGE_B_Y-4,	20,20,	"��"},		//�p���b�g��
	{GAGE_X-35,GAGE_B_Y-4,	20,20,	"��"},		//�p���b�g��

	{PAL_R,PAL_D-85,	20,40,	"��"},		//�p���b�g�Z���N�g
	{PAL_R,PAL_D-85+45,	20,40,	"��"},		//�p���b�g�Z���N�g

	{GAGE_X- 90,GAGE_B_Y+55,	60,20,	" LOAD "},		//�p���b�g�ǂݍ���
	{GAGE_X- 20,GAGE_B_Y+55,	60,20,	" SAVE "},		//�p���b�g��������
	{GAGE_X+180,GAGE_B_Y+55,	120,20,	" ROM LOAD "},		//ROM
	{GAGE_X+ 50,GAGE_B_Y+55,	60,20,	" HELP "},

	//10
	{ROMBTN_X    ,ROMBTN_Y		,65,20,	"��-1h "},
	{ROMBTN_X    ,ROMBTN_Y+24	,65,20,	"��+1h "},
	{ROMBTN_X+75 ,ROMBTN_Y		,65,20,	"��-8h "},
	{ROMBTN_X+75 ,ROMBTN_Y+24	,65,20,	"��+8h "},
	{ROMBTN_X+150,ROMBTN_Y		,65,20,	"��-20h "},
	{ROMBTN_X+150,ROMBTN_Y+24	,65,20,	"��+20h "},
	{ROMBTN_X+225,ROMBTN_Y		,65,20,	"��-80h "},
	{ROMBTN_X+225,ROMBTN_Y+24	,65,20,	"��+80h "},
	//
	{ROMBTN_X    ,ROMBTN_Y+60		,65,20,	"��-200h "},
	{ROMBTN_X    ,ROMBTN_Y+60+24	,65,20,	"��+200h "},
	{ROMBTN_X+75 ,ROMBTN_Y+60		,65,20,	"��-800h "},
	{ROMBTN_X+75 ,ROMBTN_Y+60+24	,65,20,	"��+800h "},
	{ROMBTN_X+150,ROMBTN_Y+60		,65,20,	"��-2000h"},
	{ROMBTN_X+150,ROMBTN_Y+60+24	,65,20,	"��+2000h"},
	{ROMBTN_X+225,ROMBTN_Y+60		,65,20,	"��-8000h"},
	{ROMBTN_X+225,ROMBTN_Y+60+24	,65,20,	"��+8000h"},
	{PAL_L,PAL_U,PAL_R-PAL_L,PAL_D-PAL_U,""},		//palet

	{GAGE_X+330,GAGE_B_Y+55,	60,20,	" SPR / BG "},
	{GAGE_X+410,GAGE_B_Y+55,	60,20,	" BMP SAVE "}
	};

void mouse_box_disp()
{
	int lp;
	for(lp=0;lp<BTN_MAX;lp++){
		if(lp!= 28){		//28�����͏������܂���
			elDraw::Box(	botton_Data[lp].xx,	botton_Data[lp].yy,
					botton_Data[lp].xx+botton_Data[lp].lenx,
					botton_Data[lp].yy+botton_Data[lp].leny,
					RGB(0,0,0),			//box color
					RGB(128,128,128),	//line
					2);
				elFont::Begin(GOTHIC,16,0,FALSE,FALSE,FALSE);
				elFont::Color(RGB(255,255,255),RGB(0,0,128),FALSE);
				elFont::Draw(botton_Data[lp].xx,botton_Data[lp].yy,botton_Data[lp].title);
				elFont::Before();
		}
	}
}

void select_pal(int val){		//+1 or -1
	int lp;
	viewer_Pal += val;	//�Z���N�g����Ă���16�F�p���b�g�i�P�U�j
	if(viewer_Pal<0)viewer_Pal=15;
	if(viewer_Pal>15)viewer_Pal=0;
	gamen_rewrite();

	for(lp=0;lp<16;lp++){
		elDraw::ShowFormat( PAL_L-14,PAL_U+lp*16+4,"  ");
	}
	elDraw::ShowFormat( PAL_L-14,PAL_U+(viewer_Pal*16)+4,"��");
	elDraw::ShowFormat( PAL_R,PAL_D-85-14,"Pal=%-2d",viewer_Pal);
}

void mouse_fnc()
{
	//�}�E�X�ɂ��A����̈�̃N���b�N�ŏ���
	//	elDraw::Line(MousePX-10,MousePY,MousePX+10,MousePY,RGB(255,255,255),1);

	int lp;
	int xx1,yy1,xx2,yy2;
	mouse_box_disp();
	//select_pal(0);

	//220505 �Ȃ�ł�������́E�E�E20�N�ԋC�t���Ȃ������B����Ȃɂ������񃋁[�v����K�v�Ȃ��ł��B�R�����g�ɁB
	//���ڕ����[�v���Ă邩��A�`������x���J��Ԃ��Ƃ��x���Ȃ��Ă����̂ł��B
	//�E�E�E�Ǝv������A�R�����g�ɏo���Ȃ��悤�ł��B�����Ȃ��Ȃ�܂��B
	for(lp=0;lp<BTN_MAX;lp++)
	{

		xx1 = botton_Data[lp].xx;
		yy1 = botton_Data[lp].yy;
		xx2 = botton_Data[lp].xx+botton_Data[lp].lenx;
		yy2 = botton_Data[lp].yy+botton_Data[lp].leny;

		if((MousePX >= xx1) && (MousePX <xx2) &&
		   (MousePY >= yy1) && (MousePY <yy2))
		{

			elFont::Begin(GOTHIC,16,0,FALSE,FALSE,FALSE);
			elFont::Color(RGB(0,255,0),RGB(255,0,255),FALSE);
			elFont::Draw(botton_Data[lp].xx,botton_Data[lp].yy,botton_Data[lp].title);
			elFont::Before();
			if (MouseCL==PUSH_KEY)
			{
				//MouseCL=FALSE;			//@@@@@@@�A�����ĂQ�V�[���������Ă��܂����Ƃ����邽��

				//�N���b�N�������ڂ��������܂�
				switch(lp){
					case 0:		//"��"�p���b�g��
						palet[select_Pal].red--;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
						//break;
					case 1:		//"��"�p���b�g��
						palet[select_Pal].red++;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 2:		//"��"�p���b�g��
						palet[select_Pal].green--;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 3:		//"��"�p���b�g��
						palet[select_Pal].green++;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 4:		//"��"�p���b�g��
						palet[select_Pal].blue--;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 5:		//"��"�p���b�g��
						palet[select_Pal].blue++;
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���

					case 6:		//���p���b�g�Z���N�g
						select_pal(-1);
						//viewer_Pal--;		//�Z���N�g����Ă���16�F�p���b�g�i�P�U�j
						//if(viewer_Pal<0)viewer_Pal=15;
						//gamen_rewrite();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 7:		//���p���b�g�Z���N�g
						select_pal(1);
						//viewer_Pal++;		//�Z���N�g����Ă���16�F�p���b�g�i�P�U�j
						//if(viewer_Pal>15)viewer_Pal=0;
						//gamen_rewrite();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 8:		//" LOAD "		//�p���b�g�ǂݍ���
						if(bitmap_palet_Read( NULL )== -1){return;}
						gamen_rewrite();
						text_disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���

					case 9:		//" SAVE "		//�p���b�g��������
						bitmap_palet_Wright();
						gamen_rewrite();
						text_disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���

					case 10:	//" ROM LOAD "	//ROM
						//pce�����ǂݍ���
						if(pce_Read()== -1){return;}
						//�S��ʕ\��
						gamen_rewrite();
						text_disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���

					case 11:	//" HELP "
						if(help_flg==0){
							help_flg=1;
							mode_help_disp();
						}
						else{
							help_flg=0;
							elDraw::Clear();
							//�S��ʕ\��
							gamen_rewrite();
							text_disp();
						}
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 12:	//"��-1h "
						pce_adr_updn(-0x01);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 13:	//"��+1h "
						pce_adr_updn(0x01);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 14:	//"��-8h "
						pce_adr_updn(-0x08);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 15:	//"��+8h "
						pce_adr_updn(0x08);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 16:	//"��-20h "
						pce_adr_updn(-0x20);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 17:	//"��+20h "
						pce_adr_updn(0x20);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 18:	//"��-80h "
						pce_adr_updn(-0x80);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 19:	//"��+80h "
						pce_adr_updn(0x80);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 20:	//"��-200h "
						pce_adr_updn(-0x200);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 21:	//"��+200h "
						pce_adr_updn(0x200);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 22:	//"��-800h "
						pce_adr_updn(-0x800);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 23:	//"��+800h "
						pce_adr_updn(0x800);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 24:	//"��-2000h"
						pce_adr_updn(-0x2000);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 25:	//"��+2000h"
						pce_adr_updn(0x2000);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 26:	//"��-8000h"
						pce_adr_updn(-0x8000);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 27:	//"��+8000h"
						pce_adr_updn(0x8000);pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 28:
						cur_clr();		//�J�[�\���ʒu�m�J�[�\��������
						select_Pal= (MousePX-xx1)/16+(MousePY-yy1)/16*16;
						cur_disp();		//�J�[�\���ʒu�j�A�J�[�\�����\��
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���

					case 29:
						rom_Disp_Mode++;
						if(rom_Disp_Mode>=2){
							rom_Disp_Mode=0;//0=Sprite 1=BG
						}
						pce_rom_Disp();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					case 30:
						void bmpsave();
						bmpsave();
						return;   //220505 �m�肵���烋�[�v�p������rtn�̂���
					default:
						break;
				}
				if(palet[select_Pal].red<0)
					palet[select_Pal].red=0;
				if(palet[select_Pal].green<0)
					palet[select_Pal].green=0;
				if(palet[select_Pal].blue<0)
					palet[select_Pal].blue=0;
				if(palet[select_Pal].red>7)
					palet[select_Pal].red=7;
				if(palet[select_Pal].green>7)
					palet[select_Pal].green=7;
				if(palet[select_Pal].blue>7)
					palet[select_Pal].blue=7;

				if(	help_flg==0)
					make_paletwindow();
			}
		}
	}
}
