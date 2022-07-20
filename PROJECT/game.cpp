/*** ***************************************************************************
ピクセルのゲット、セットのサンプルプログラムです。

画面（裏画面）、画像情報と両方からピクセルのゲット、セットができます。
******************************************************************************/
#include <conio.h>		// for getch();
#include <stdio.h>
#include <dos.h>

#include "el.h"	//最新版el.h
#include "elDraw32.h"  //21/12/08追加

#include "data.cpp"
#include "sub.cpp"

extern char szPath[_MAX_PATH];       //￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥test.exe
extern char szDrive[_MAX_DRIVE];     //c:
extern char szDir[_MAX_DIR];         //￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥
extern char szFileName[_MAX_FNAME];  //test
extern char szExt[_MAX_EXT];         //.exe
extern char szDrvPath[_MAX_PATH];    //c:￥mydocuments￥新しいﾌｫﾙﾀﾞ(7)￥test￥test.exe
extern char szOutput[_MAX_PATH * 5 + 1024];//(^^;
void makefullpath();
void ini_GetStr(char *section,char *koumoku, char *szAppName,char *buf);
int ini_GetInt(char *section,char *koumoku,char *szAppName);
void ini_SetStr(char *section,char *koumoku,char *szAppName,char *str);
void ini_SetInt(char *section,char *koumoku,char *szAppName,int val);

int pce_Read();
void pce_rom_Disp();
void pce_adr_updn(int val);
void mouse_fnc();
void mouse_box_disp();
void make_paletwindow();

int bitmap_palet_Read(char *fname);
void bitmap_palet_Wright();
void text_disp();
void GameScreen(void);

#define WINDOWX 1000
#define WINDOWY 480

#define PAL_L 50
#define PAL_U 40
#define PAL_R 50+260
#define PAL_D 40+260

#define GAGE_X   140
#define GAGE_R_Y (400-60)
#define GAGE_G_Y (420-60)
#define GAGE_B_Y (440-60)

#define ROMBTN_X 320
#define ROMBTN_Y (310)


//テキストを表示する位置です
#define Y_step 15
#define Y_000 0
#define Y_001 Y_step-10
#define Y_002 Y_step*2
#define Y_003 Y_step*3
#define Y_004 Y_step*4
#define Y_005 Y_step*5
#define Y_006 Y_step*6
#define Y_007 Y_step*7
#define Y_008 Y_step*8
#define Y_009 Y_step*9
#define Y_010 Y_step*10
#define Y_011 Y_step*11
#define Y_012 Y_step*12
#define Y_013 Y_step*13
#define Y_014 Y_step*14
#define Y_015 Y_step*15
#define Y_016 Y_step*16
#define Y_017 Y_step*17
#define Y_018 Y_step*18
#define Y_019 Y_step*19
#define Y_020 Y_step*20
#define Y_021 Y_step*21
#define Y_022 Y_step*22
#define Y_023 Y_step*23
#define Y_024 Y_step*24
#define Y_025 Y_step*25
#define Y_026 Y_step*26
#define Y_027 Y_step*27
#define Y_028 Y_step*28
#define Y_029 Y_step*29
#define Y_030 Y_step*30

/********************************************************************************/
/*                                                                              */
/*  メイン関数                                                                  */
/*                                                                              */
/********************************************************************************/
#define GAME_SCREEN 1  // タイトル画面です。タイトルのデモです。

int elMain("PCEビューアー")
{
	elWindow(WINDOWX,WINDOWY,FALSE);		//ウインドウモードです。
	elSetWindow( RUN_NOTOP );		//他のウインドウが重なれるように設定（メッセージウインドウのため）
	_ShowDialog=TRUE;				//マウスを表示するため

	elLoop()
	{
		elSetScreen(GAME_SCREEN,GameScreen());		//
	}
	elExitMain();
}
/********************************************************************************/
/*                                                                              */
/*  ウィンドウ生成関数                                                          */
/*                                                                              */
/********************************************************************************/
//状態処理の前に無条件に最初に呼ばれるモジュールです。
//DDOBJ GamenBMP;
//DDOBJ MouseBMP;
//DDOBJ MousewokBMP;

void elCreate(void)
{
	// いまどきのパソコンならフルカラーにしているので。
	// @@@@@@@ 21/12/08
	elDraw::SetFullColor();

	// 仮想画面
	//elDraw::Screen(WINDOWX,WINDOWY);
	//たしか二階のパソコンでは、RAMにしたほうが高速だったような。
	//ドットごとにカラーでぬりつぶす処理がものすごく遅いです。(21/12/09)
	elDraw::Screen(WINDOWX,WINDOWY, CREATE_RAM );

	// 仮想画面の設定
	elDraw::VirtualScreen(0,0,WINDOWX,WINDOWY);

	elCallScreen(GAME_SCREEN);		//EL状態遷移 メインのスレッドへ
}
/********************************************************************************/
/*                                                                              */
/*  キーボード関数                                                              */
/*                                                                              */
/********************************************************************************/
void elKeyboard(void)
{
	case VK_ESCAPE:
		elDraw::Exit();
		break;
	elExitKeyboard();
}

/********************************************************************************/
/*                                                                              */
/*  イベント関数                                                                */
/*                                                                              */
/********************************************************************************/
long elEvent(void)
{
	elExitEvent();
}

/********************************************************************************/
/*                                                                              */
/*  メインループ                                                                */
/*                                                                              */
/********************************************************************************/

void pal_1_disp(){
	//カーソル位置ニ、paletヲ表示
	elDraw32::ColorFill(PAL_L+4+((select_Pal%16))*16,
					  PAL_U+4+((select_Pal/16))*16,
					  PAL_L+4+((select_Pal%16))*16+14,
					  PAL_U+4+((select_Pal/16))*16+14,
					  RGB(
							windows_paltbl[ palet[select_Pal].red ],
							windows_paltbl[ palet[select_Pal].green ],
							windows_paltbl[ palet[select_Pal].blue ])
							);
}

void cur_disp(){
	//カーソル位置ニ、カーソルヲ表示
	elDraw32::ColorFill(PAL_L+4+((select_Pal%16))*16-1,
					  PAL_U+4+((select_Pal/16))*16-1,
					  PAL_L+4+((select_Pal%16))*16+16-1,
					  PAL_U+4+((select_Pal/16))*16+16-1,
					  RGB(255,255,255));
	pal_1_disp();
}
void cur_clr(){
	//カーソル位置ノカーソルを消去
	elDraw32::ColorFill(PAL_L+4+((select_Pal%16))*16-1,
					  PAL_U+4+((select_Pal/16))*16-1,
					  PAL_L+4+((select_Pal%16))*16+16-1,
					  PAL_U+4+((select_Pal/16))*16+16-1,
					  RGB(128,128,128));
	pal_1_disp();
}

void 	mode_help_disp()
{
	//カーソル位置ニ、paletヲ表示
	elDraw32::ColorFill(0,0,640,300,RGB(0,0,0));

	elFont::Begin(GOTHIC,14,0,FALSE,FALSE,FALSE);
	elFont::Color(RGB(255,255,255),0,FALSE);
	elFont::Draw( 200,Y_001,"PC Engine Viewer");

	elFont::Draw( 40,Y_002,"<<<<< PALET >>>>>");
	elFont::Draw( 40,Y_003,"Z Key---RED +1LEVEL  X Key---RED -1LEVEL");
	elFont::Draw( 40,Y_004,"A Key---GREEN +1     S Key---GREEN -1");
	elFont::Draw( 40,Y_005,"Q Key---BLUE +1      W Key---BLUE -1");
	elFont::Draw( 40,Y_006,"CURSOL Key-----Select Color");
	elFont::Draw( 40,Y_007,"C Key---Color COPY     V Key---PASTE");
	elFont::Draw( 40,Y_008,"F1Key---Palet load ");
	elFont::Draw( 40,Y_009,"F5Key---Palet save ");

	elFont::Draw( 40,Y_011,"<<<<< ROM >>>>>");
	elFont::Draw( 40,Y_012,"NUM1---ROMADR+1     NUM7---ADR -1");
	elFont::Draw( 40,Y_013,"NUM2---ROMADR+200h  NUM8---ADR -200h");
	elFont::Draw( 40,Y_014,"NUM3---ROMADR+2000  NUM9---ADR -2000h");

	elFont::Draw( 340,Y_002,"PCE Palet...");
	elFont::Draw( 340,Y_003,"Sprite = 16Palet.  BG = 16Palet.");
	elFont::Draw( 340,Y_004,"1Palet = 16Color.");
	elFont::Draw( 340,Y_005,"1Color = R(3bit),G(3bit),B(3bit).");
	elFont::Draw( 340,Y_006,"3bit = 8Level ((min)0,1,2...6,7(max))");
	elFont::Draw( 340,Y_007,"(Sprite = 256Color.  BG = 256Color.)");
	elFont::Before();
}

void gamen_rewrite(){
	int lp,lpx,lpy;

	elDraw32::ColorFill(
				PAL_L,
				PAL_U,
				PAL_R,
				PAL_D,
				RGB(128,128,128));
	lp=0;
	for(lpy=0; lpy<16;lpy++){
		for(lpx=0; lpx<16;lpx++){
			elDraw32::ColorFill(PAL_L+4+lpx*16,
							  PAL_U+4+lpy*16,
							  PAL_L+4+lpx*16+14,
							  PAL_U+4+lpy*16+14,
							  RGB(
								windows_paltbl[ palet[lp].red ],
								windows_paltbl[ palet[lp].green ],
								windows_paltbl[ palet[lp].blue ])
							);
			lp++;
		}
	}

	//pceビューアー画面
	pce_rom_Disp();

	//void mouse_box_disp();
	//mouse_box_disp();

	//カーソル位置ニ、カーソルヲ表示
	cur_disp();
}

void GameScreen(void)
{
	int lp;
//	WORD Color;

	// 画面が切り換わった直後の場合
	if (elChangeScreen())
	{
		exitflg=0;
		elDraw::Clear();
//		elDraw::LineLayer(0,0,1,GamenBMP,0,0,640,480);
		//配列クリア
		for(lp=0;lp<256;lp++){
			palet[lp].red=0;
			palet[lp].green=0;
			palet[lp].blue=0;
		}
		//配列にパレット読み込み
		if(bitmap_palet_Read("001.bmp")== -1)
		{
			elDraw::Exit();
			return;
		}

		//pceロム読み込み
		if(pce_Read()== -1)
		{
			elDraw::Exit();
			return;
		}

		//全画面表示
		gamen_rewrite();
		text_disp();
	}

	elSystem::GetKey('Z',&z_key);			//RED palet value ++
	elSystem::GetKey('X',&x_key);			//RED palet value --
	elSystem::GetKey('A',&a_key);			//GRN palet value ++
	elSystem::GetKey('S',&s_key);			//GRN palet value --
	elSystem::GetKey('Q',&q_key);			//BLE palet value ++
	elSystem::GetKey('W',&w_key);			//BLE palet value --
	elSystem::GetKey('C',&c_key);			//copy
	elSystem::GetKey('V',&v_key);			//past
	elSystem::GetKey(VK_UP,&up_key);		//カーソル移動
	elSystem::GetKey(VK_DOWN,&dn_key);
	elSystem::GetKey(VK_LEFT,&lt_key);
	elSystem::GetKey(VK_RIGHT,&rt_key);

	elSystem::GetKey(VK_NUMPAD0,&num_0key);	//disp adr = 0h

	elSystem::GetKey(VK_NUMPAD7,&num_7key);	//disp adr -= 10000h
	//elSystem::GetKey(VK_NUMPAD8,&num_8key);	//disp adr -= 200h
	elSystem::GetKey(VK_NUMPAD9,&num_9key);	//disp adr -= 10000h

	//elSystem::GetKey(VK_NUMPAD4,&num_4key);	//表示幅縮小
	//elSystem::GetKey(VK_NUMPAD6,&num_6key);	//表示幅拡大
	elSystem::GetKey(VK_NUMPAD4,&num_4key);	//disp adr -= 2000h
	elSystem::GetKey(VK_NUMPAD6,&num_6key);	//disp adr += 2000h

	elSystem::GetKey(VK_NUMPAD1,&num_1key);	//disp adr -= 800h
	//elSystem::GetKey(VK_NUMPAD2,&num_2key);	//disp adr += 200h
	elSystem::GetKey(VK_NUMPAD3,&num_3key);	//disp adr += 800h

	mouse_fnc();

	if(help_flg==0){

		if(num_0key==PUSH_KEY){
			pce_adr_updn(-0x200000);  //計算結果がマイナスのとき、0x0000になります
			gamen_rewrite();		//全画面表示
		}

		if(num_1key==PUSH_KEY){
			pce_adr_updn(-0x800);
			gamen_rewrite();		//全画面表示
		}
		if(num_3key==PUSH_KEY){
			pce_adr_updn(0x800);
			gamen_rewrite();		//全画面表示
		}

		if(num_4key==PUSH_KEY){		//表示幅縮小
			pce_adr_updn(-0x2000);
			//rom_BG_High =16;		//BGモード時の表示の大きさ
			//rom_BG_Width--;
			gamen_rewrite();		//全画面表示
		}
		if(num_6key==PUSH_KEY){	//表示幅拡大
			pce_adr_updn(0x2000);
			//rom_BG_High =16;		//BGモード時の表示の大きさ
			//rom_BG_Width++;
			gamen_rewrite();		//全画面表示
		}

		if(num_7key==PUSH_KEY){
			pce_adr_updn(-0x10000);
			gamen_rewrite();		//全画面表示
		}
		if(num_9key==PUSH_KEY){
			pce_adr_updn(0x10000);
			gamen_rewrite();		//全画面表示
		}
	
		//load
		elSystem::GetKey(VK_F1,&f1_key);
		if(f1_key==PUSH_KEY){
			bitmap_palet_Read( NULL );
			//全画面表示
			gamen_rewrite();
		}
		//save
		elSystem::GetKey(VK_F5,&f5_key);
		if(f5_key==PUSH_KEY){
			bitmap_palet_Wright();
			//全画面表示
			gamen_rewrite();
		}
	
		if(up_key==PUSH_KEY){
			cur_clr();		//カーソル位置ノカーソルを消去
			if((select_Pal-16)<0){select_Pal=select_Pal-16+256;}
			else{	select_Pal=select_Pal-16;}
			cur_disp();		//カーソル位置ニ、カーソルヲ表示
			make_paletwindow();
		}
		else if(dn_key==PUSH_KEY){
			cur_clr();		//カーソル位置ノカーソルを消去
			if((select_Pal+16)>255){select_Pal=select_Pal+16-256;}
			else{select_Pal=select_Pal+16;}
			cur_disp();		//カーソル位置ニ、カーソルヲ表示
			make_paletwindow();
		}
		else if(lt_key==PUSH_KEY){
			cur_clr();		//カーソル位置ノカーソルを消去
			if((select_Pal-1)<0){select_Pal=255;}
			else{	select_Pal=select_Pal-1;}
			cur_disp();		//カーソル位置ニ、カーソルヲ表示
			make_paletwindow();
		}
		else if(rt_key==PUSH_KEY){
			cur_clr();		//カーソル位置ノカーソルを消去
			if((select_Pal+1)>255){select_Pal=0;}
			else{	select_Pal=select_Pal+1;}
			cur_disp();		//カーソル位置ニ、カーソルヲ表示
			make_paletwindow();
		}
		else{}
	
		if(x_key==PUSH_KEY){
			if(palet[select_Pal].blue < 7)palet[select_Pal].blue++;
			make_paletwindow();
		}
		if(z_key==PUSH_KEY){
			if(palet[select_Pal].blue > 0)palet[select_Pal].blue--;
			make_paletwindow();
		}
		if(s_key==PUSH_KEY){
			if(palet[select_Pal].green < 7)palet[select_Pal].green++;
			make_paletwindow();
		}
		if(a_key==PUSH_KEY){
			if(palet[select_Pal].green > 0)palet[select_Pal].green--;
			make_paletwindow();
		}
		if(w_key==PUSH_KEY){
			if(palet[select_Pal].red < 7)palet[select_Pal].red++;
			make_paletwindow();
		}
		if(q_key==PUSH_KEY){
			if(palet[select_Pal].red > 0)palet[select_Pal].red--;
			make_paletwindow();
		}
	
		//パレットのコピー、ペースト
		if(c_key==PUSH_KEY){
			palet_copywok.red 	= palet[select_Pal].red;
			palet_copywok.green	= palet[select_Pal].green;
			palet_copywok.blue 	= palet[select_Pal].blue;
			make_paletwindow();
	
		}
		if(v_key==PUSH_KEY){
			palet[select_Pal].red 	= palet_copywok.red;
			palet[select_Pal].green = palet_copywok.green;
			palet[select_Pal].blue 	= palet_copywok.blue;
			make_paletwindow();
		}
	}

	elDraw::ShowFPS();
	_ShowMouse=TRUE;

	elDraw::Refresh();

	if(exitflg!=0){
	elDraw::Exit();
	}
}

//２５６個のパレット、下のゲージを描画。パレットはROMビューア画面にも反映
void make_paletwindow()
{
	int lp;
	//カーソル位置のパレットを画面に反映
	pal_1_disp();

	//ビューアー画面にもパレットを反映
	pce_rom_Disp();

	//一番下にゲージを描画
	for(lp=1;lp<8;lp++){
		if(lp<=(palet[select_Pal].red)){
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_R_Y,
						GAGE_X+lp*16+15,	GAGE_R_Y+6,
						RGB(255,0,0));
		}
		else{
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_R_Y,
						GAGE_X+lp*16+15,	GAGE_R_Y+6,
						RGB(0,0,0));
		}
	}
	for(lp=1;lp<8;lp++){
		if(lp<=(palet[select_Pal].green)){
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_G_Y,
						GAGE_X+lp*16+15,	GAGE_G_Y+6,
						RGB(0,255,0));
		}
		else{
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_G_Y,
						GAGE_X+lp*16+15,	GAGE_G_Y+6,
						RGB(0,0,0));
		}
	}
	for(lp=1;lp<8;lp++){
		if(lp<=(palet[select_Pal].blue)){
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_B_Y,
						GAGE_X+lp*16+15,	GAGE_B_Y+6,
						RGB(0,0,255));
		}
		else{
			elDraw32::ColorFill(
						GAGE_X+lp*16,		GAGE_B_Y,
						GAGE_X+lp*16+15,	GAGE_B_Y+6,
						RGB(0,0,0));
		}
	}
}
/********************************************************************************/
/*                                                                              */
/********************************************************************************/


//バグ有り・・・アラインメント考慮せず。
//アラインメントのためにbfSize以下すべてニバイトずれています。
//この形式でデータを保存してはじめてわかりました。06年7月
//biClrImporantは本当は4なのに2バイトになって正常動作しているのは
//ストラクチャの中身が全部ニバイトずれているからです。
//ここはとりあえずこのままにします・・・

struct BMAPHEADER {
	unsigned char	bfType0;		//1 データ形式(B)
	unsigned char	bfType1;		//1 データ形式(M)
	unsigned long	bfSize;			//4 ファイルサイズ
	unsigned short	bfReserved1;	//2 予約
	unsigned short	bfReserved2;	//2 予約
	unsigned long	bfOffBits;		//4 ビットマップデータの開始オフセット
	unsigned long	biSize;			//4 ヘッダーのサイズ（以下のデータ）
	long			biWidth;		//4 水平ドット数
	long			biHeight;		//4 垂直ドット数
	unsigned short	biPlanes;		//2 プレーン数
	unsigned short	biBitCount;		//2 １ピクセル当たりのビット数(8)
	unsigned long	biCompression;	//4 圧縮形式（０＝無し）
	unsigned long	biSizeImage;	//4 ビットマップデータサイズ
	long			biXPixPerMeter;	//4 水平解像度
	long			biYPixPerMeter;	//4 垂直解像度
	unsigned long	biClrUsed;		//4 使用色数
//	unsigned long	biClrImporant;	//4 重要な色？
//	unsigned short  dmy;			//2 ※仕様書にない空白の領域？
	unsigned short	biClrImporant;	//2 重要な色？
	unsigned char	palet[256][4];	//1024 256色パレット
};

char buf[0x10000+100];

struct BMAPHEADER *bitmap_ptr;

unsigned char val_henkan(unsigned char val){
	if(val <63)		 {return(0);}
	else if(val <95) {return(1);}
	else if(val <127){return(2);}
	else if(val <159){return(3);}
	else if(val <191){return(4);}
	else if(val <223){return(5);}
	else if(val <255){return(6);}
	else 			 {return(7);}	//==255
}
///////////////////////////////////////////////////////////////////
//                                                               //
//                     ダイアログ関数                            //
//                                                               //
///////////////////////////////////////////////////////////////////
BOOL OpenDlg(char* lpstrFileTitle,char* lpstrFile)
{
	int i,j;
	OPENFILENAME ofn;
	char Filter[]=" すべてのファイル ";

	j=(int)strlen(Filter);
	for (i=0;i<j;i++) if (Filter[i]==' ') Filter[i]=NULL;

	memset(&ofn,0x00,sizeof(OPENFILENAME));
	ofn.lStructSize=sizeof(OPENFILENAME);
	ofn.hwndOwner=hwnd;
	ofn.lpstrFilter=(LPCTSTR)Filter;
	ofn.nFilterIndex=1;
	ofn.lpstrFile=(LPTSTR)lpstrFile;
	ofn.nMaxFile=256;
	ofn.lpstrFileTitle=(LPTSTR)lpstrFileTitle;
	ofn.nMaxFileTitle=256;
	ofn.Flags=OFN_PATHMUSTEXIST;
	ofn.lpstrDefExt=(LPCTSTR)"mp3";

	return GetOpenFileName(&ofn);
}


int bitmap_palet_Read( char *fname )
{
	int lp;
	FILE *fp;

	if( fname == NULL ){

		strcpy( FileName, "*.bmp" );

		//iniファイルより前回アクセスしたディレクトリを取りだして設定
		makefullpath();
		ini_GetStr("DIR", "CURENT",szDrvPath,buf);
		//カレントディレクトリとして設定
		SetCurrentDirectory(buf);

		if(NULL == OpenDlg( FileTitle, FileName )){
			strcpy( FileName, "sample.bmp" );
		}

		//移動したのちのカレントディレクトリをiniに保存。
		//カレントディレクトリの取得
		GetCurrentDirectory(_MAX_PATH, buf);
		//保存
		ini_SetStr("DIR", "CURENT",szDrvPath,buf);

	}
	else{
		strcpy( FileName, GetFullPath_ThisFile( fname ) );
	}


	if (( fp = fopen(FileName, "rb" )) == NULL )
	{
		elDraw::Error("bmpread()","BMP file not found");
		exitflg=1;
		return(-1);
	}
	filesize = fread(&buf[0],1,0x5000,fp);   //
	fclose(fp);

	bitmap_ptr =(struct BMAPHEADER *)buf;

	//0,63,95,127,159,191,223,255 を 01234567
	for(lp=0;lp<256;lp++){
		palet[lp].blue	= val_henkan( bitmap_ptr->palet[lp][0]);		//b
		palet[lp].green	= val_henkan( bitmap_ptr->palet[lp][1]);		//g
		palet[lp].red 	= val_henkan( bitmap_ptr->palet[lp][2]);		//r
	}
	return(0);
}

void bitmap_palet_Wright(){
	int lp;
	FILE *fp;

	bitmap_ptr =(struct BMAPHEADER *)buf;

//※適当に作成したファイルではエディタに読み込めませんでした。
//起動時にsample.bmpを読み込み、読み込んだままの形式で保存します
//	bitmap_ptr->bfType0		= 'B';
//	bitmap_ptr->bfType1		= 'M';
//	bitmap_ptr->bfSize		=0x2000;	//ファイルサイズ
//	bitmap_ptr->bfReserved1	=0;			//予約
//	bitmap_ptr->bfReserved2	=0;			//予約
//	bitmap_ptr->bfOffBits	=0x1000;	//ビットマップデータの開始オフセット
//	bitmap_ptr->biSize		=40;	//ヘッダーのサイズ（以下のデータ）
//	bitmap_ptr->biWidth		=100;	//水平ドット数
//	bitmap_ptr->biHeight	=100;	//垂直ドット数
//	bitmap_ptr->biPlanes	=1;		//プレーン数
//	bitmap_ptr->biBitCount	=8;		//１ピクセル当たりのビット数(8)
//	bitmap_ptr->biCompression=0;	//圧縮形式（０＝無し）
//	bitmap_ptr->biSizeImage	=0;	//ビットマップデータサイズ
//	bitmap_ptr->biXPixPerMeter=0;	//水平解像度
//	bitmap_ptr->biYPixPerMeter=0;	//垂直解像度
//	bitmap_ptr->biClrUsed	=256;	//使用色数
//	bitmap_ptr->biClrImporant=0;	//重要な色？
////	bitmap_ptr->palet[256][4]=;	//256色パレット

	//01234567を３２倍して0,32,64, 96,128,160,192,224
	//0以外のとき、+31で  0,63,95,127,159,191,223,255
	for(lp=0;lp<256;lp++){
		bitmap_ptr->palet[lp][0]=	palet[lp].blue<<5;			//b
		if(palet[lp].blue != 0)bitmap_ptr->palet[lp][0]+=31;

		bitmap_ptr->palet[lp][1]=	palet[lp].green<<5;			//g
		if(palet[lp].green != 0)bitmap_ptr->palet[lp][1]+=31;

		bitmap_ptr->palet[lp][2]=	palet[lp].red<<5;			//r
		if(palet[lp].red != 0)bitmap_ptr->palet[lp][2]+=31;

		bitmap_ptr->palet[lp][3]=0;		//reserved;
	}
	if (( fp = fopen( FileName, "wb" )) == NULL )
	{
		elDraw::Error("bmpwrite()","BMP file not write error");
		return;
	}
	fwrite(&buf[0], 1,filesize,fp);
	fclose(fp);
}

void text_disp()
{
	elFont::Begin(GOTHIC,14,0,FALSE,FALSE,FALSE);
	elFont::Color(RGB(255,255,255),0,FALSE);
	elFont::Draw( 200,Y_001,"PC Engine Viewer");

	elFont::Draw( 400,Y_001, RomName );  //21/12/08

		//	elFont::Draw( 340,Y_002,"Z Key---RED +1LEVEL    X Key---RED -1LEVEL");
		//	elFont::Draw( 340,Y_003,"A Key---GREEN +1       S Key---GREEN -1");
		//	elFont::Draw( 340,Y_004,"Q Key---BLUE +1        W Key---BLUE -1");
	//elFont::Draw( 340,Y_001,"CURSOL Key-----Move");
	//elFont::Draw( 340,Y_002,"C Key---Palet COPY     V Key---PASTE");
	//elFont::Draw( 340,Y_003,"F1Key---Palet load ");
	//elFont::Draw( 340,Y_004,"F5Key---Palet save ");

	//elFont::Draw( 340,200-10,"PCE Palet...");
	//elFont::Draw( 340,220,"Sprite = 16Palet.  BG = 16Palet.");
	//elFont::Draw( 340,240,"1Palet = 16Color.");
	//elFont::Draw( 340,260,"1Color = R(3bit),G(3bit),B(3bit).");
	//elFont::Draw( 340,280,"3bit = 8Level ((min)0,1,2...6,7(max))");
	//elFont::Draw( 340,300,"(Sprite = 256Color.  BG = 256Color.)");

	elFont::Draw( GAGE_X-5,GAGE_R_Y-20,"    1 2 3 4  5 6 7");
	elFont::Draw( GAGE_X-5,GAGE_R_Y-5,"R:");
	elFont::Draw( GAGE_X-5,GAGE_G_Y-5,"G:");
	elFont::Draw( GAGE_X-5,GAGE_B_Y-5,"B:");
	elFont::Before();
}

#include "viewer.cpp"
#include "bmpsave.cpp"
#include "mouse.cpp"
