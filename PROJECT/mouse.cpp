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
	{GAGE_X-70,GAGE_R_Y-4,	20,20,	"←"},		//パレット赤
	{GAGE_X-35,GAGE_R_Y-4,	20,20,	"→"},		//パレット赤
	{GAGE_X-70,GAGE_G_Y-4,	20,20,	"←"},		//パレット緑
	{GAGE_X-35,GAGE_G_Y-4,	20,20,	"→"},		//パレット緑
	{GAGE_X-70,GAGE_B_Y-4,	20,20,	"←"},		//パレット青
	{GAGE_X-35,GAGE_B_Y-4,	20,20,	"→"},		//パレット青

	{PAL_R,PAL_D-85,	20,40,	"↑"},		//パレットセレクト
	{PAL_R,PAL_D-85+45,	20,40,	"↓"},		//パレットセレクト

	{GAGE_X- 90,GAGE_B_Y+55,	60,20,	" LOAD "},		//パレット読み込み
	{GAGE_X- 20,GAGE_B_Y+55,	60,20,	" SAVE "},		//パレット書き込み
	{GAGE_X+180,GAGE_B_Y+55,	120,20,	" ROM LOAD "},		//ROM
	{GAGE_X+ 50,GAGE_B_Y+55,	60,20,	" HELP "},

	//10
	{ROMBTN_X    ,ROMBTN_Y		,65,20,	"↑-1h "},
	{ROMBTN_X    ,ROMBTN_Y+24	,65,20,	"↓+1h "},
	{ROMBTN_X+75 ,ROMBTN_Y		,65,20,	"↑-8h "},
	{ROMBTN_X+75 ,ROMBTN_Y+24	,65,20,	"↓+8h "},
	{ROMBTN_X+150,ROMBTN_Y		,65,20,	"↑-20h "},
	{ROMBTN_X+150,ROMBTN_Y+24	,65,20,	"↓+20h "},
	{ROMBTN_X+225,ROMBTN_Y		,65,20,	"↑-80h "},
	{ROMBTN_X+225,ROMBTN_Y+24	,65,20,	"↓+80h "},
	//
	{ROMBTN_X    ,ROMBTN_Y+60		,65,20,	"↑-200h "},
	{ROMBTN_X    ,ROMBTN_Y+60+24	,65,20,	"↓+200h "},
	{ROMBTN_X+75 ,ROMBTN_Y+60		,65,20,	"↑-800h "},
	{ROMBTN_X+75 ,ROMBTN_Y+60+24	,65,20,	"↓+800h "},
	{ROMBTN_X+150,ROMBTN_Y+60		,65,20,	"↑-2000h"},
	{ROMBTN_X+150,ROMBTN_Y+60+24	,65,20,	"↓+2000h"},
	{ROMBTN_X+225,ROMBTN_Y+60		,65,20,	"↑-8000h"},
	{ROMBTN_X+225,ROMBTN_Y+60+24	,65,20,	"↓+8000h"},
	{PAL_L,PAL_U,PAL_R-PAL_L,PAL_D-PAL_U,""},		//palet

	{GAGE_X+330,GAGE_B_Y+55,	60,20,	" SPR / BG "},
	{GAGE_X+410,GAGE_B_Y+55,	60,20,	" BMP SAVE "}
	};

void mouse_box_disp()
{
	int lp;
	for(lp=0;lp<BTN_MAX;lp++){
		if(lp!= 28){		//28だけは処理しません
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
	viewer_Pal += val;	//セレクトされている16色パレット（１６個）
	if(viewer_Pal<0)viewer_Pal=15;
	if(viewer_Pal>15)viewer_Pal=0;
	gamen_rewrite();

	for(lp=0;lp<16;lp++){
		elDraw::ShowFormat( PAL_L-14,PAL_U+lp*16+4,"  ");
	}
	elDraw::ShowFormat( PAL_L-14,PAL_U+(viewer_Pal*16)+4,"→");
	elDraw::ShowFormat( PAL_R,PAL_D-85-14,"Pal=%-2d",viewer_Pal);
}

void mouse_fnc()
{
	//マウスにより、ある領域のクリックで処理
	//	elDraw::Line(MousePX-10,MousePY,MousePX+10,MousePY,RGB(255,255,255),1);

	int lp;
	int xx1,yy1,xx2,yy2;
	mouse_box_disp();
	//select_pal(0);

	//220505 なんですかこれは・・・20年間気付かなかった。こんなにたくさんループする必要ないです。コメントに。
	//項目分ループしてるから、描画を何度も繰り返すとき遅くなっていたのです。
	//・・・と思ったら、コメントに出来ないようです。動かなくなります。
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
				//MouseCL=FALSE;			//@@@@@@@連続して２シーン処理してしまうことがあるため

				//クリックした項目を処理します
				switch(lp){
					case 0:		//"←"パレット赤
						palet[select_Pal].red--;
						return;   //220505 確定したらループ継続せずrtnのこと
						//break;
					case 1:		//"→"パレット赤
						palet[select_Pal].red++;
						return;   //220505 確定したらループ継続せずrtnのこと
					case 2:		//"←"パレット緑
						palet[select_Pal].green--;
						return;   //220505 確定したらループ継続せずrtnのこと
					case 3:		//"→"パレット緑
						palet[select_Pal].green++;
						return;   //220505 確定したらループ継続せずrtnのこと
					case 4:		//"←"パレット青
						palet[select_Pal].blue--;
						return;   //220505 確定したらループ継続せずrtnのこと
					case 5:		//"→"パレット青
						palet[select_Pal].blue++;
						return;   //220505 確定したらループ継続せずrtnのこと

					case 6:		//↑パレットセレクト
						select_pal(-1);
						//viewer_Pal--;		//セレクトされている16色パレット（１６個）
						//if(viewer_Pal<0)viewer_Pal=15;
						//gamen_rewrite();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 7:		//↓パレットセレクト
						select_pal(1);
						//viewer_Pal++;		//セレクトされている16色パレット（１６個）
						//if(viewer_Pal>15)viewer_Pal=0;
						//gamen_rewrite();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 8:		//" LOAD "		//パレット読み込み
						if(bitmap_palet_Read( NULL )== -1){return;}
						gamen_rewrite();
						text_disp();
						return;   //220505 確定したらループ継続せずrtnのこと

					case 9:		//" SAVE "		//パレット書き込み
						bitmap_palet_Wright();
						gamen_rewrite();
						text_disp();
						return;   //220505 確定したらループ継続せずrtnのこと

					case 10:	//" ROM LOAD "	//ROM
						//pceロム読み込み
						if(pce_Read()== -1){return;}
						//全画面表示
						gamen_rewrite();
						text_disp();
						return;   //220505 確定したらループ継続せずrtnのこと

					case 11:	//" HELP "
						if(help_flg==0){
							help_flg=1;
							mode_help_disp();
						}
						else{
							help_flg=0;
							elDraw::Clear();
							//全画面表示
							gamen_rewrite();
							text_disp();
						}
						return;   //220505 確定したらループ継続せずrtnのこと
					case 12:	//"↑-1h "
						pce_adr_updn(-0x01);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 13:	//"↓+1h "
						pce_adr_updn(0x01);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 14:	//"↑-8h "
						pce_adr_updn(-0x08);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 15:	//"↓+8h "
						pce_adr_updn(0x08);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 16:	//"↑-20h "
						pce_adr_updn(-0x20);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 17:	//"↓+20h "
						pce_adr_updn(0x20);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 18:	//"↑-80h "
						pce_adr_updn(-0x80);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 19:	//"↓+80h "
						pce_adr_updn(0x80);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 20:	//"↑-200h "
						pce_adr_updn(-0x200);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 21:	//"↓+200h "
						pce_adr_updn(0x200);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 22:	//"↑-800h "
						pce_adr_updn(-0x800);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 23:	//"↓+800h "
						pce_adr_updn(0x800);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 24:	//"↑-2000h"
						pce_adr_updn(-0x2000);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 25:	//"↓+2000h"
						pce_adr_updn(0x2000);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 26:	//"↑-8000h"
						pce_adr_updn(-0x8000);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 27:	//"↓+8000h"
						pce_adr_updn(0x8000);pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 28:
						cur_clr();		//カーソル位置ノカーソルを消去
						select_Pal= (MousePX-xx1)/16+(MousePY-yy1)/16*16;
						cur_disp();		//カーソル位置ニ、カーソルヲ表示
						return;   //220505 確定したらループ継続せずrtnのこと

					case 29:
						rom_Disp_Mode++;
						if(rom_Disp_Mode>=2){
							rom_Disp_Mode=0;//0=Sprite 1=BG
						}
						pce_rom_Disp();
						return;   //220505 確定したらループ継続せずrtnのこと
					case 30:
						void bmpsave();
						bmpsave();
						return;   //220505 確定したらループ継続せずrtnのこと
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
