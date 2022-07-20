//ROM読み込みエリア 最大のスト２に合わせ、４メガバイトまで
// 1024 x 1024 = 1048576(100000h)    1mega byte

//#define ROMDT_ST2 0x100000*4
//#define ROMDT_ST2 0x100000*16    //220420 cdromromも読みたいため16メガバイトに
#define ROMDT_ST2 0x100000*0x20    //220505 スーパー雷電 26MB サファイヤ17MB ダウンロード2(19MB)
                                   // ウインズオブ 7.4MB   サイキックストーム12MB ネクスザールスペシャル6.5MB
                                   // スターパロジャー 4.2MB フォゴットン 9.1MB
                                   // 大旋風とかは2-4MBです。


unsigned char romdata[ROMDT_ST2];
int rom_datacnt;

//pceの画像はデータをワードアクセスのため
unsigned short *rom_ptr;
//────────────────────────────────
//────────────────────────────────
int romFileSize = 0;



//────────────────────────────────
//rom読み込み関数
//────────────────────────────────
//(21/12/08) .pceのときヘッダ200hを取る処理を追加。取らないときは.binのこと

int pce_Read()
{
	int Rtype = 0;   // 0=.pce 1=.bin
	int i,lp;
	FILE *fp;
	char buf[_MAX_PATH];

	for(lp=0;lp<ROMDT_ST2;lp++){
		romdata[lp]=0;
	}

	//iniファイルより前回アクセスしたディレクトリを取りだして設定
	makefullpath();
	ini_GetStr("DIR", "CURENT",szDrvPath,buf);
	//カレントディレクトリとして設定
	SetCurrentDirectory(buf);

	strcpy( RomName, "*.pce;*.bin" );
	if(NULL == OpenDlg( "romファイル（.pce）", RomName )){
		strcpy( RomName, "KungFu.pce" );
	}

	//移動したのちのカレントディレクトリをiniに保存。
	//カレントディレクトリの取得
	GetCurrentDirectory(_MAX_PATH, buf);
	//保存
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

	if(( romFileSize % 0x2000 )==0x200){  //ファイルサイズが+200hの半端があればヘッダ付き。
		//0x200はヘッダを読み飛ばした量
		rom_datacnt =0x200;   //ワードカウンタ
		rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//ワードポインタ
	}
	else{
		rom_datacnt =0x000;
		rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//ワードポインタ
	}
*/

	//.pceならヘッダを捨てる
	for( i=0; i<500; i++ ){
		if( RomName[i] == '\0' )break;

		if( RomName[i] == '.' )
			if(         (RomName[i+1] == 'P') || (RomName[i+1] == 'p') )
				if(     (RomName[i+2] == 'C') || (RomName[i+2] == 'c') )
					if( (RomName[i+3] == 'E') || (RomName[i+3] == 'e') )
					{
						//fpから0x200読み飛ばし
						romFileSize = fread(&romdata[0],1,0x200,fp);
						break;
					}
	}
	//pceのromの最大サイズであるストツーのサイズで読み込む
	romFileSize = fread(&romdata[0],1,ROMDT_ST2,fp);
	fclose(fp);

	rom_datacnt =0x000;
	rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//ワードポインタ

	return(0);
}

//────────────────────────────────
// スプライトの表示
//rom表示アドレスから0x2000バイト（8x8スプライト分）表示
//────────────────────────────────
//表示開始左上座標
#define DISP_RU_X 365
#define DISP_RU_Y 40

//表示位置テーブル
//６４個のスプライトの表示位置Ｘ、Ｙ
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
//スプライトがこの順番になるように表示
// 00 01  10 11  20 21  30 31
// 02 03  12 13  22 23  32 33
// 04 05  14 15  24 25  34 35
// 06 07  16 17  26 27  36 37
// 08 09  18 19  28 29  38 39
// 0A 0B  1A 1B  2A 2B  3A 3B
// 0C 0D  1C 1D  2C 2D  3C 3D
// 0E 0F  1E 1F  2E 2F  3E 3F

//16x16ドットの作業領域
short dot_wok[256];


//$2000ぶん8x8セルの画像をスプライトとして描画。
//この関数、すごーく遅いので注意。

void FG_Box( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy)
{
	int lp,linecnt,dotcnt,lpx,lpy,pln_cnt,wok;
	unsigned short linedata;	//１ライン16ドットのデータ
	unsigned short setbit;		//1 2 4 8（プレーンに設定するビット）

	elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=SPR",rom_datacnt+dispadr_add);

	//６４個のスプライトを表示
	for(lp=0;lp<64;lp++){

		for(wok=0;wok<256;wok++){
			dot_wok[wok]=0;				//黒でクリア
		}

/*
		//0のプレーン=1 1のプレーン=2 2のプレーン=4 3のプレーン=8
		setbit = 0x01;
		for(pln_cnt=0;pln_cnt<4;pln_cnt++)		//プレーン４枚
		{
			for(linecnt = 0;linecnt<16;linecnt++)	//16ライン
			{
				linedata = *romptr;		//１ライン分データを取りだし
				romptr++;

				for(dotcnt = 0;dotcnt<16;dotcnt++)		//16ビット
				{
					//・HIGHのビットを調べます ONならデータをカラーを設定
					if(linedata & 0x8000)
					{
						dot_wok[linecnt*16+dotcnt] |= setbit;
					}
					//・ワード情報を<<1
					linedata = linedata<<1;
				}
			}
			setbit = setbit <<1 ;		//1 2 4 8
		}
*/

		//上の処理をループ展開します。

		short *dotptr;

		setbit = 0x01;		//0のプレーン=1 1のプレーン=2 2のプレーン=4 3のプレーン=8
		for(pln_cnt=0;pln_cnt<4;pln_cnt++)		//プレーン４枚
		{
			for(linecnt = 0;linecnt<256;linecnt+=16) //16ライン
			{
				linedata = *romptr;		//１ライン分データを取りだし
				romptr++;

				dotptr = &dot_wok[linecnt];   //16おき

				//・HIGHのビットを調べます ONならデータをカラーを設定
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

				wok = wok+viewer_Pal * 16;		//セレクトされている16色パレット

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

	romptr = rom_ptr;		//オリジナルの値を壊さないため

	FG_Box( romptr         ,0x0000, 0,0 );
	FG_Box( romptr + 0x1000,0x2000, 128+8,0 );  //short*0x1000 = 0x2000byte
	FG_Box( romptr + 0x2000,0x4000, 256+16,0 );
	FG_Box( romptr + 0x3000,0x6000, 384+24,0 );

	//家のマシンでは遅くなりすぎます。(2008年)
	//FG_Box( romptr + 0x4000,0x8000, 0,     128+16 );
	//FG_Box( romptr + 0x5000,0xa000, 128+8, 128+16 );  //short*0x1000 = 0x2000byte
	//FG_Box( romptr + 0x6000,0xc000, 256+16,128+16 );
	//FG_Box( romptr + 0x7000,0xe000, 384+24,128+16 );
}
//────────────────────────────────
// BGの表示
// rom表示アドレスから0x2000バイト（8x8スプライト分）表示
//────────────────────────────────

void BG_Box( unsigned short *romptr,int dispadr_add, int ofsx,int ofsy)
{
	int lp,linecnt,dotcnt,lpx,lpy,wok;
	unsigned short linedata;	//１ライン16ドットのデータ
	unsigned short setbit;		//1 2 4 8（プレーンに設定するビット）

	elDraw::ShowFormat( DISP_RU_X+ofsx,DISP_RU_Y-16+ofsy,"ADR:$%06X TYPE=BG ",rom_datacnt+dispadr_add);

	//256個のBGを表示
	//for(lp=0;lp<256;lp++){

	//※指定幅、高さの画像の表示
	for(lp=0;lp< rom_BG_High*rom_BG_Width;lp++){

		for(wok=0;wok<256;wok++){
			dot_wok[wok]=0;				//黒でクリア
		}

		//0のプレーン=1 1のプレーン=2 2のプレーン=4 3のプレーン=8
		for(linecnt = 0;linecnt<8;linecnt++){	//8word(2プレーン分)
			setbit = 0x01;
			linedata = *romptr;		//16bitデータを取りだし
			romptr++;

			//上位８ビットだけしらべて、ビットがONなら横８ドットに展開します
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//・HIGHのビットを調べます ONならデータをカラーを設定
				if(linedata & 0x8000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//・byte情報を<<1
				linedata = linedata<<1;
			}

			//プレーン++
			setbit = setbit <<1 ;		//1 2 4 8
			//下位８ビットをしらべて、ビットがONなら横８ドットに展開します
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//・HIGHのビットを調べます ONならデータをカラーを設定
				if(linedata & 0x8000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//・byte情報を<<1
				linedata = linedata<<1;
			}
		}

		for(linecnt = 0;linecnt<8;linecnt++){	//8word(2プレーン分)
			setbit = 0x04;
			linedata = *romptr;		//16bitデータを取りだし
			romptr++;

			//上位８ビットだけしらべて、ビットがONなら横８ドットに展開します
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//・HIGHのビットを調べます ONならデータをカラーを設定
				if(linedata & 0x8000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//・byte情報を<<1
				linedata = linedata<<1;
			}

			//プレーン++
			setbit = setbit <<1 ;		//1 2 4 8
			//下位８ビットをしらべて、ビットがONなら横８ドットに展開します
			for(dotcnt = 0;dotcnt<8;dotcnt++){
				//・HIGHのビットを調べます ONならデータをカラーを設定
				if(linedata & 0x8000){
					dot_wok[linecnt*8+dotcnt] |= setbit;
				}
				//・byte情報を<<1
				linedata = linedata<<1;
			}
		}

		//8x8dot
		for(lpy=0;lpy<8;lpy++){
			for(lpx=0;lpx<8;lpx++){
				wok = dot_wok[lpy*8+lpx];		//0...15 palet no.

				wok = wok+viewer_Pal * 16;		//セレクトされている16色パレット

				elDraw32::ColorFill(
								//DISP_RU_X+(lp%16)*8 +lpx,
								//DISP_RU_Y+(lp/16)*8 +lpy,
								//DISP_RU_X+(lp%16)*8 +lpx+1,
								//DISP_RU_Y+(lp/16)*8 +lpy+1,
								DISP_RU_X+ofsx+(lp%rom_BG_Width)*8 +lpx,//※指定幅、高さの画像の表示
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
	romptr = rom_ptr;	//オリジナルの値を壊さないため

	BG_Box( romptr         ,0x0000, 0,0 );
	BG_Box( romptr + 0x1000,0x2000, 128+8,0 );  //short*0x1000 = 0x2000byte
	BG_Box( romptr + 0x2000,0x4000, 256+16,0 );
	BG_Box( romptr + 0x3000,0x6000, 384+24,0 );

	//家のマシンでは遅くなりすぎます。
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
//────────────────────────────────
//rom表示アドレスをずらします
//		プラス方向、マイナス方向、量を指定できます
//────────────────────────────────
void pce_adr_updn(int val)
{
	rom_datacnt += val;		//バイトカウンタ
	if(rom_datacnt<0){
		rom_datacnt = 0;
	}
	if(rom_datacnt >(ROMDT_ST2-0x2000)){
		rom_datacnt = ROMDT_ST2-0x2000;
	}
	rom_ptr =(unsigned short *)&romdata[rom_datacnt];	//ワードポインタ
}
