// 2000.6.18
// フルカラー版 elDraw
// 元ファイル = el.h (1999.11.22)

// Borland C++ Builder,Borland C++ Compilerでコンパイルする際には
// このファイルをインクルードする前に #define BCC と書く必要があります。

// 最新版はこちら http://www.ky.xaxon.ne.jp/~hitoshi/index.htm
// 何かありましたら こちらまで  hitoshi@ky.xaxon.ne.jp （小林 均）


// DirectX7以降の新しいコード
#ifdef NEWCODE

//#define LPDIRECTDRAW LPDIRECTDRAW7
//#define LPDIRECTDRAWSURFACE LPDIRECTDRAWSURFACE7
#define DDSURFACEDESC DDSURFACEDESC2
//#define DDSCAPS DDSCAPS2
//#define IDirectDraw IDirectDraw7
//#define IDirectDrawSurface IDirectDrawSurface7

#define DD_UNLOCK(Surface,Para)\
\
	Surface->Unlock(NULL);

#else

#define DD_UNLOCK(Surface,Para)\
\
	Surface->Unlock(Para);

#endif


// MMXをコンパイルした時の警告表示回避（elDraw32.hの最後で元に戻しています）
#pragma warning( disable : 4799 )


class elDraw32
{
	public:

	static void  Init(void);

	static BOOL  MMX_CHECK(void); // ＭＭＸがあるかどうか チェックをする関数
	static BOOL  MMX_CHECKED;     // ＭＭＸがあるかどうか チェックをしたか のフラグ
	static BOOL  USE_MMX;         // ＭＭＸを使うかどうかのフラグ

	static void  ColorFill(int,int,int,int,COLORREF);
	static BOOL  ColorBlend(int,int,int,int,COLORREF);
	static BOOL  MirrorLayer(int,int,int,DDOBJ,int,int,int,int);

	static BOOL  BlendLayer(int,int,DDOBJ,int,int,int,int);
	static BOOL  BlendLayer(int,int,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BlendLayer(int,int,float,float,float,DDOBJ,int,int,int,int); //（MMX対応）
//	static BOOL  BlendLayer(int,int,int,DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,int,int,int,DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,float,float,float,int,int,int,
//							DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,int,int,int,int,int,int,
//							DDOBJ,int,int,int,int);
	static BOOL  AddBlendLayer(int,int,DDOBJ,int,int,int,int); //（MMX対応）
//	static BOOL  AddBlendLayer(int,int,float,DDOBJ,int,int,int,int);
	static BOOL  DelBlendLayer(int,int,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  EdgeBlendLayer(int,int,DDOBJ,int,int,int,int);
	static BOOL  PlainLayer(int,int,BOOL,BOOL,BOOL,DDOBJ,int,int,int,int);
	static BOOL  BrightLayer(int,int,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BrightLayer(int,int,float,float,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BrightLayer(int,int,int,DDOBJ,int,int,int,int);
	static BOOL  BrightLayer(int,int,int,int,int,DDOBJ,int,int,int,int);
	static BOOL  ShadeLayer(int,int,int,DDOBJ,int,int,int,int);
	static BOOL  GrayLayer(int,int,DDOBJ,int,int,int,int);
	static BOOL  MeshLayer(int,int,int,int,int,float,float,DDOBJ,int,int,int,int);
	static BOOL  RotateLayer(int,int,int,int,int,DDOBJ,int,int,int,int);
	static BOOL  TileRotateLayer(int,int,int,int,int,DDOBJ,int,int,int,int);
	static BOOL  ZoomRotateLayer(int,int,int,int,int,float,DDOBJ,int,int,int,int);
	static BOOL  TileZoomRotateLayer(int,int,int,int,int,float,DDOBJ,
									 int,int,int,int);
	static BOOL  MysteryLayer(int,int,int,int,int,float,float,float,float,
							  float,float,float,DDOBJ,int,int,int,int);
	static BOOL  PickLayer(int,int,int,int,DDOBJ,int,int,int,int);
	static BOOL  ShiftLayer(int,int,float,DDOBJ,int,int,int,int);
//	static void  CreateTunnel(int,int,int,int,int,int,int,int,int,int);    // 32ビット化 必要なし
	static BOOL  TunnelLayer(int,int,int,int,DDOBJ);
	static BOOL  LightLayer(int,int,int,int,int,WORD,BOOL,DDOBJ,int,int,int,int);

	// ハイカラー・MMX対応版（elDraw32の内部で使用）
	static BOOL  BlendLayer16MMX(int,int,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BlendLayer16MMX(int,int,float,float,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BrightLayer16MMX(int,int,float,DDOBJ,int,int,int,int); //（MMX対応）
	static BOOL  BrightLayer16MMX(int,int,float,float,float,DDOBJ,int,int,int,int); //（MMX対応）

	// 以下の５つは 元のelにはありません(独自拡張版)
	static BOOL  DelBlendLayerEx(int,int,DDOBJ,int,int,int,int);           // ＲＧＢを使った減算ブレンド（MMX対応）
	static BOOL  GrayLayerEx(int,int,DDOBJ,int,int,int,int);               // (R+G+B)/3 ではないグレースケール
	static BOOL  RotateLayerEx(int,int,int,int,int,DDOBJ,int,int,int,int); // 回転＋アンチエイリアス・ほっしーさん作
//	static BOOL  ShiftLayerEx(int,int,int,float,DDOBJ,int,int,int,int);    // 角度指定付きピクセルシフト
	static BOOL  LimitLayer(int,int,int,DDOBJ,int,int,int,int);            // シャドー部を切り捨てて描画

	// 独自拡張版のハイカラー版（elDraw32の内部で使用）
	static BOOL  DelBlendLayerEx16(int,int,DDOBJ,int,int,int,int);           // ＲＧＢを使った減算ブレンド
	static BOOL  GrayLayerEx16(int,int,DDOBJ,int,int,int,int);               // (R+G+B)/3 ではないグレースケール
	static BOOL  RotateLayerEx16(int,int,int,int,int,DDOBJ,int,int,int,int); // 回転＋アンチエイリアス・ほっしーさん作
//	static BOOL  ShiftLayerEx16(int,int,int,float,DDOBJ,int,int,int,int);    // 角度指定付きピクセルシフト
	static BOOL  LimitLayer16(int,int,int,DDOBJ,int,int,int,int);            // シャドー部を切り捨てて描画

	static BOOL Initialized;
	static unsigned char AddBlendList[];
	static unsigned char DelBlendList[];
	static unsigned char GrayList[];
	static unsigned char GrayListExR[];
	static unsigned char GrayListExG[];
	static unsigned char GrayListExB[];

	union Buff32
	{
		UINT Buff;
		unsigned char BuffRGB[4];
	};
};

// リスト情報
BOOL elDraw32::Initialized=FALSE;
//unsigned short elDraw::BlendList[3*32*32*32];
unsigned char elDraw32::AddBlendList[512];
unsigned char elDraw32::DelBlendList[256*256];
unsigned char elDraw32::GrayList[256+256+256];
unsigned char elDraw32::GrayListExR[256];
unsigned char elDraw32::GrayListExG[256];
unsigned char elDraw32::GrayListExB[256];


// MMXチェック用フラグ
BOOL  elDraw32::MMX_CHECKED=FALSE;     // ＭＭＸがあるかどうか チェックをしたか のフラグ
BOOL  elDraw32::USE_MMX=FALSE;         // ＭＭＸを使うかどうかのフラグ

// VC++にはない インラインアセンブラの命令(MMX用)
#ifndef BCC
#define CPUID\
	_asm _emit 0x0f\
	_asm _emit 0xa2

#define EMMS\
	_asm _emit 0x0f\
	_asm _emit 0x77
#endif // #ifndef BCC

// BCB Learning Edition と Borland C++ Compiler5.5用
// 『インテル・アーキテクチャ・ソフトウェア・ディベロッパーズ・マニュアル 中巻』より参照
#ifdef BCC

#define CPUID __emit__(0x0f,0xa2);
#define EMMS  __emit__(0x0f,0x77);

#define mm0 0
#define mm1 1
#define mm2 2
#define mm3 3
#define mm4 4
#define mm5 5
#define mm6 6
#define mm7 7
#define mm8 8

// メモリ位置の表現には、アドレス、BPからの１バイト値のオフセット、BPからの４バイト値のオフセット、レジスタ値、があります。
// ここでは、アドレスを前提としています。
// そのため、変数memは遠い位置にあるか、staticで宣言しておかなければいけません。
// 例：
// static __int64 Src,Dest;
// MOVQ_mm_mem(mm0,Src)
// MOVQ_mem_mm(Dest,mm0)
#define MOVD_mm_mem(mm,mem)			__emit__(0x0f,0x6e,mm*8|0x05,&mem);		// Mod=00 REG R/M=101
#define MOVD_mem_mm(mem,mm)			__emit__(0x0f,0x7e,mm*8|0x05,&mem);		// Mod=00 REG R/M=101
#define MOVQ_mm_mem(mm,mem)			__emit__(0x0f,0x6f,mm*8|0x05,&mem);		// Mod=00 REG R/M=101
#define MOVQ_mem_mm(mem,mm)			__emit__(0x0f,0x7f,mm*8|0x05,&mem);		// Mod=00 REG R/M=101

#define PACKUSWB_mm_mm(mm_1,mm_2)	__emit__(0x0f,0x67,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PAND_mm_mm(mm_1,mm_2)		__emit__(0x0f,0xdb,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PADDUSB_mm_mm(mm_1,mm_2)	__emit__(0x0f,0xdc,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PADDUSW_mm_mm(mm_1,mm_2)	__emit__(0x0f,0xdd,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PADDW_mm_mm(mm_1,mm_2)		__emit__(0x0f,0xfd,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PMULHW_mm_mm(mm_1,mm_2)		__emit__(0x0f,0xe5,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PSUBUSB_mm_mm(mm_1,mm_2)	__emit__(0x0f,0xd8,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PUNPCKLBW_mm_mm(mm_1,mm_2)	__emit__(0x0f,0x60,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PUNPCKLWD_mm_mem(mm,mem)	__emit__(0x0f,0x61,mm*8|0x05,&mem);		// Mod=00 REG R/M=101
#define PUNPCKLDQ_mm_mm(mm_1,mm_2)	__emit__(0x0f,0x62,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2
#define PXOR_mm_mm(mm_1,mm_2)		__emit__(0x0f,0xef,0xc0|mm_1*8|mm_2);	// Mod=11 REG=mm_1 R/M=mm_2

#endif // #ifdef BCC


/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  ルックアップテーブルの作成                             ※ elDraw32で使用  -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

void elDraw32::Init(void)
{
	int i,j;
	unsigned char x;

		// フルカラー用 ブレンド合成結果リストの作成
/*		for (c=0;c<3;c++)
		{
			for (b=0;b<32;b++)
			{
				for (i=0;i<32;i++)
				{
					for (j=0;j<32;j++)
					{
						x=0;

						if (i-b>=0)
						{
							x+=i-b;
						}

						if (j-(31-b)>=0)
						{
							x+=j-(31-b);
						}

						switch (c)
						{
							case 0: x<<=sr; break;
							case 1: x<<=sg; break;
							case 2: x<<=sb; break;
						}

						BlendList[(c<<15)+(b<<10)+(i<<5)+j]=x;
					}
				}
			}
		}
*/
	// フルカラー用 加算ブレンド合成結果リストの作成
	for (i=0;i<256;i++)
	{
		elDraw32::AddBlendList[i]=i;
		elDraw32::AddBlendList[i+256]=0xff;
	}

	// フルカラー用 減算ブレンド合成結果リストの作成
	for (i=0;i<256;i++)
	{
		for (j=0;j<256;j++)
		{
			x=0;

			if (i-j>0)
			{
				x=i-j;
			}

			elDraw32::DelBlendList[i*256+j]=x;
		}
	}

	// グレースケール計算結果リストの作成
	for (i=0;i<256*3;i++)
	{
		elDraw32::GrayList[i]=(unsigned int)((double)i/(double)3);
	}

	// グレースケール計算結果リストの作成（独自拡張版 用）
	for (i=0;i<256;i++)
	{
		// ↓この式は 1999.10月号の 月刊Ｃマガジンを参考にしました。
		elDraw32::GrayListExR[i]=(unsigned int)((double)i*0.3);
		elDraw32::GrayListExG[i]=(unsigned int)((double)i*0.59);
		elDraw32::GrayListExB[i]=(unsigned int)((double)i*0.11);
	}

	elDraw32::Initialized=TRUE;

	if (elDraw32::MMX_CHECKED==FALSE)
	{
		elDraw32::MMX_CHECK();
	}

	return;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  ＭＭＸの検出                                                              -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::MMX_CHECK(void)
{
	static bool _CPUID;      // CPUIDを使用できるかどうか
	static int FeatureFlags; // 検出時に使用

	// CPUIDの検出
	#ifndef BCC
	_asm
	{
		pushfd
		pop eax
		xor eax,00200000h
		push eax
		popfd
		pushfd
		pop ebx
		cmp eax,ebx
		mov _CPUID,1
		je support_CPUID
		mov _CPUID,0
		support_CPUID:
	}
	#else // #ifndef BCC
	{
		__emit__(0x9c);						// pushfd
		__emit__(0x58);						// pop eax
		__emit__(0x35,0x00200000u);			// xor eax,00200000h
		__emit__(0x50);						// push eax
		__emit__(0x9d);						// popfd
		__emit__(0x9c);						// pushfd
		__emit__(0x5b);						// pop ebx
		__emit__(0x3b,0xc3);				// cmp eax,ebx
		__emit__(0xc6,0x05,&_CPUID,0x01);	// mov _CPUID,1
		__emit__(0x74,0x07);				// je support_CPUID
		__emit__(0xc6,0x05,&_CPUID,0x00);	// mov _CPUID,0
//											// support_CPUID:
	}
	#endif // #ifndef BCC

	if (!_CPUID) // CPUID がサポートされていない (==80386以下なのでＭＭＸもなし)
	{
		elDraw32::MMX_CHECKED=TRUE;
		elDraw32::USE_MMX=FALSE;
		return FALSE;
	}

	// ＭＭＸの検出
	#ifndef BCC
	_asm
	{
		mov eax,0
		CPUID
		mov FeatureFlags,eax
	}
	#else // #ifndef BCC
	{
		__emit__(0xb8,0u);					// mov eax,0
		CPUID								// CPUID
		__emit__(0xa3,&FeatureFlags);		// mov FeatureFlags,eax
	}
	#endif // #ifndef BCC

	// ＭＭＸがあるかどうかチェックできなかった場合
	if (FeatureFlags==0)
	{
		MMX_CHECKED=TRUE;
		USE_MMX=FALSE;
		return FALSE;
	}

	if (FeatureFlags>0)
	{
		#ifndef BCC
		_asm
		{
			mov eax,1
			CPUID
			mov FeatureFlags,edx
		}
		#else // #ifndef BCC
		{
			__emit__(0xb8,1u);					// mov eax,1
			CPUID								// CPUID
			__emit__(0x89,0x15,&FeatureFlags);	// mov FeatureFlags,edx
		}
		#endif // #ifndef BCC

		// ＭＭＸが検出された場合
		if (FeatureFlags&0x00800000)
		{
			MMX_CHECKED=TRUE;
			USE_MMX=TRUE;
		}
		// ＭＭＸが検出されなかった場合
		else
		{
			MMX_CHECKED=TRUE;
			USE_MMX=FALSE;
			return FALSE;
		}
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  指定された領域を任意の色で初期化                                          -*/
/*-                                                                            -*/
/*-    int X1         : 左上Ｘ座標                                             -*/
/*-    int Y1         : 左上Ｙ座標                                             -*/
/*-    int X2         : 右下Ｘ座標                                             -*/
/*-    int Y2         : 右下Ｙ座標                                             -*/
/*-    COLORREF Color : 色 ( RGB(赤,緑,青)で指定 )                             -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

//void elDraw::ColorFill(int X1,int Y1,int X2,int Y2,WORD Color)
void elDraw32::ColorFill(int X1,int Y1,int X2,int Y2,COLORREF Color)//
{
	if (elSystem::ColorBit()<24) {
		elDraw::ColorFill(X1,Y1,X2,Y2,RGB16(GetRValue(Color)>>3,GetGValue(Color)>>3,GetBValue(Color)>>3));return;}

	static DDBLTFX ddbltfx;
	static RECT rect;

	rect.left=X1;
	rect.top=Y1;
	rect.right=X2;
	rect.bottom=Y2;

	ddbltfx.dwSize=sizeof(ddbltfx);
//	ddbltfx.dwFillColor=Color;
	ddbltfx.dwFillColor=GetRValue(Color)<<elDraw::ShiftR|
						GetGValue(Color)<<elDraw::ShiftG|
						GetBValue(Color)<<elDraw::ShiftB;

	DDBack->Blt(&rect,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&ddbltfx);
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  カラーブレンド ( 50% )                                     ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int X1         : 左上Ｘ座標                                             -*/
/*-    int Y1         : 左上Ｙ座標                                             -*/
/*-    int X2         : 右下Ｘ座標                                             -*/
/*-    int Y2         : 右下Ｙ座標                                             -*/
/*-    COLORREF Color : 色 ( RGB(赤,緑,青)で指定 )                             -*/
/*-                                                                            -*/
/*-    戻り値     : TRUE  = 正常終了                                           -*/
/*-               : FALSE = エラー発生                                         -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

//BOOL elDraw::ColorBlend(int X1,int Y1,int X2,int Y2,WORD Color)
BOOL elDraw32::ColorBlend(int X1,int Y1,int X2,int Y2,COLORREF Color)//
{
	if (elSystem::ColorBit()<24) return elDraw::ColorBlend(X1,Y1,X2,Y2,RGB16(GetRValue(Color)>>3,GetGValue(Color)>>3,GetBValue(Color)>>3));

	static HRESULT ddret;
	static DDSURFACEDESC ddsd;
//	static LPWORD data;
	static LPDWORD data;//
	static long AddPitch;
	static int x,y;
	static UINT Buff,Buff2;

	// 描画領域の計算
	if (X2>elDraw::Vx2) X2-=X2-elDraw::Vx2;
	if (Y2>elDraw::Vy2) Y2-=Y2-elDraw::Vy2;
	if (X1<elDraw::Vx1) X1=elDraw::Vx1;
	if (Y1<elDraw::Vy1) Y1=elDraw::Vy1;

	// 描画できる場合
	if (X2>=X1 && Y2>=Y1)
	{
		// 構造体の初期化
		memset(&ddsd,0x00,sizeof(DDSURFACEDESC));
		ddsd.dwSize=sizeof(DDSURFACEDESC);

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch=ddsd.lPitch>>1;
		AddPitch=ddsd.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data=(LPWORD)ddsd.lpSurface+Y1*AddPitch;
		data=(LPDWORD)ddsd.lpSurface+Y1*AddPitch;//

		// Colorの変換（elDraw32にて付け足し）//
		Color=	GetRValue(Color)<<elDraw::ShiftR| //
				GetGValue(Color)<<elDraw::ShiftG| //
				GetBValue(Color)<<elDraw::ShiftB; //

		// 色を先に50%化
		Buff2=Color>>1;
		Buff2&=elDraw::MaskRGB;

		// データ転送
		for (y=Y1;y<Y2;y++)
		{
			for (x=X1;x<X2;x++)
			{
				Buff=*(data+x);

				Buff>>=1;
				Buff&=elDraw::MaskRGB;

				*(data+x)=Buff+Buff2;
			}

			// Ｙ方向に加算
			data+=AddPitch;
		}

		// スプライトのロック解除
		DD_UNLOCK(DDBack,ddsd.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  これより以後の 変数の置き換え                          ※ elDraw32で使用  -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

#define Vx1 elDraw::Vx1
#define Vy1 elDraw::Vy1
#define Vx2 elDraw::Vx2
#define Vy2 elDraw::Vy2

#define MaskR	elDraw::MaskR
#define MaskG	elDraw::MaskG
#define MaskB	elDraw::MaskB
#define MaskRGB	elDraw::MaskRGB
#define BitR	elDraw::BitR
#define BitG	elDraw::BitG
#define BitB	elDraw::BitB
#define ShiftR	elDraw::ShiftR
#define ShiftG	elDraw::ShiftG
#define ShiftB	elDraw::ShiftB
#define ShiftR2	elDraw::ShiftR2
#define ShiftG2	elDraw::ShiftG2
#define ShiftB2	elDraw::ShiftB2
#define BlendList	elDraw::BlendList

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 反転 )                                                 -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Mirror  : 反転タイプ                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

// 反転タイプ
//static const int NORMAL=0;    // 反転なし
//static const int MIRROR_X=1;  // 左右反転
//static const int MIRROR_Y=2;  // 上下反転
//static const int MIRROR_XY=3; // 上下左右反転

BOOL elDraw32::MirrorLayer(int Px,int Py,int Mirror,DDOBJ ObjDD,
						 int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::MirrorLayer(Px,Py,Mirror,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int Px2,Py2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;
	Px2=Px;
	Py2=Py;

	if (Px2+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px2+(Ex-Sx)-Vx2);
	}

	if (Py2+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py2+(Ey-Sy)-Vy2);
	}

	if (Px2<Vx1)
	{
		X1+=(Vx1-Px2);
		Ex-=(Vx1-Px2);
		Px2=Vx1;
	}

	if (Py2<Vy1)
	{
		Y1+=(Vy1-Py2);
		Ey-=(Vy1-Py2);
		Py2=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		if (Mirror==NORMAL)
		{
			// スプライトの先頭位置を取得
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					Buff=*(data1+x);

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+x)=Buff;
					}
				}

				// Ｙ方向に加算
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_X)
		{
			// スプライトの先頭位置を取得
			if (Px<Vx1)
			{
//				data1=(LPWORD)ddsd1.lpSurface+X1+Px+Y1*AddPitch1;
				data1=(LPDWORD)ddsd1.lpSurface+X1+Px+Y1*AddPitch1;//
			}
			else
			{
//				data1=(LPWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+Y1*AddPitch1;
				data1=(LPDWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+Y1*AddPitch1;//
			}

//			data2=(LPWORD)ddsd2.lpSurface+Px2+(Ex-Sx-1)+Py2*AddPitch2;
			data2=(LPDWORD)ddsd2.lpSurface+Px2+(Ex-Sx-1)+Py2*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					Buff=*(data1+x);

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2-x)=Buff;
					}
				}

				// Ｙ方向に加算
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_Y)
		{
			// スプライトの先頭位置を取得
			if (Py<Vy1)
			{
//				data1=(LPWORD)ddsd1.lpSurface+X1+(Y1+Ey-Sy-1+Py)*AddPitch1;
				data1=(LPDWORD)ddsd1.lpSurface+X1+(Y1+Ey-Sy-1+Py)*AddPitch1;//
			}
			else
			{
//				data1=(LPWORD)ddsd1.lpSurface+X1+
				data1=(LPDWORD)ddsd1.lpSurface+X1+
					  (Y1+Ey-Sy-1+Y2-(Ey-Sy))*AddPitch1;
			}

//			data2=(LPWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;
			data2=(LPDWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					Buff=*(data1+x);

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+x)=Buff;
					}
				}

				// Ｙ方向に加算
				data1-=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_XY)
		{
			// スプライトの先頭位置を取得
			if (Px>=Vx1 && Py>=Vy1)
			{
//				data1=(LPWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+
				data1=(LPDWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+
					  (Y1+Ey-Sy-1+Y2-(Ey-Sy))*AddPitch1;
			}
			else
			{
				if (Px<Vx1)
				{
//					data1=(LPWORD)ddsd1.lpSurface+X1+Px+
					data1=(LPDWORD)ddsd1.lpSurface+X1+Px+
						  (Y1+Ey-Sy-1+Y2-(Ey-Sy))*AddPitch1;
				}

				if (Py<Vy1)
				{
//					data1=(LPWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+
					data1=(LPDWORD)ddsd1.lpSurface+X1+(X2-(Ex-Sx))+
						  (Y1+Ey-Sy-1+Py)*AddPitch1;
				}

				if (Px<Vx1 && Py<Vy1)
				{
//					data1=(LPWORD)ddsd1.lpSurface+X1+Px+
					data1=(LPDWORD)ddsd1.lpSurface+X1+Px+
						  (Y1+Ey-Sy-1+Py)*AddPitch1;
				}
			}

//			data2=(LPWORD)ddsd2.lpSurface+Px2+(Ex-Sx-1)+Py2*AddPitch2;
			data2=(LPDWORD)ddsd2.lpSurface+Px2+(Ex-Sx-1)+Py2*AddPitch2;

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					Buff=*(data1+x);

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2-x)=Buff;
					}
				}

				// Ｙ方向に加算
				data1-=AddPitch1;
				data2+=AddPitch2;
			}
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 50%ブレンド )                           ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BlendLayer(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::BlendLayer(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,Buff2;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

//				if (Buff!=0x0000)
				if (Buff!=0x00000000)//
				{
					Buff>>=1;
					Buff&=MaskRGB;
					Buff2=*(data2+x)>>1;
					Buff2&=MaskRGB;

					*(data2+x)=Buff+Buff2;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 値指定ブレンド )                        ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    float Blend : 混合率 ( 0.0 ～ 1.0 )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BlendLayer(int Px,int Py,float Blend,DDOBJ ObjDD,
						int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::BlendLayer16MMX(Px,Py,Blend,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R1,G1,B1,R2,G2,B2;
	static unsigned int R1,G1,B1,R2,G2,B2;//
	static float Bd;

	static elDraw32::Buff32 Buff1,Buff2;
	static int RGB_R,RGB_G,RGB_B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// ブレンド値の算出
		Bd=F(1)-Blend;

		// データ転送
		// ＭＭＸを使わない場合
		if (!elDraw32::USE_MMX)
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R1=(Buff>>ShiftR)&BitR;
//					G1=(Buff>>ShiftG)&BitG;
//					B1=(Buff>>ShiftB)&BitB;

//					Buff=*(data2+x);
					Buff2.Buff=*(data2+x);//

//					R2=(Buff>>ShiftR)&BitR;
//					G2=(Buff>>ShiftG)&BitG;
//					B2=(Buff>>ShiftB)&BitB;

//					R1=(unsigned int)(F(R1)*Blend+F(R2)*Bd);
//					G1=(unsigned int)(F(G1)*Blend+F(G2)*Bd);
//					B1=(unsigned int)(F(B1)*Blend+F(B2)*Bd);
					Buff1.BuffRGB[RGB_R]=(unsigned char)(F(Buff1.BuffRGB[RGB_R])*Blend+F(Buff2.BuffRGB[RGB_R])*Bd);//
					Buff1.BuffRGB[RGB_G]=(unsigned char)(F(Buff1.BuffRGB[RGB_G])*Blend+F(Buff2.BuffRGB[RGB_G])*Bd);//
					Buff1.BuffRGB[RGB_B]=(unsigned char)(F(Buff1.BuffRGB[RGB_B])*Blend+F(Buff2.BuffRGB[RGB_B])*Bd);//

//					*(data2+x)=(R1<<ShiftR)|(G1<<ShiftG)|(B1<<ShiftB);
					*(data2+x)=Buff1.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // ＭＭＸを使わない場合 ここまで
		// ＭＭＸを使う場合
		else
		{
		static unsigned __int32 Blend32;
		static unsigned __int32 Bd32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // ＭＭＸを使う時のバッファ Srcは転送元
		static unsigned __int32 BuffDest1; // Destは転送先

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Blend32=((unsigned __int32)((float)0x7fff*(float)Blend));	// ブレンド値を整数にする
		Bd32=((unsigned __int32)((float)0x7fff*(float)Bd));			// ブレンド値を整数にする

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movd mm2,Blend32			// mm2レジスタに転送元のブレンド値を入れる
			_asm punpcklwd mm2,Blend32		// mm2レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			_asm punpckldq mm2,mm2			// mm2レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			_asm movd mm3,Bd32				// mm3レジスタに転送先のブレンド値を入れる
			_asm punpcklwd mm3,Bd32			// mm3レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			_asm punpckldq mm3,mm3			// mm3レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			_asm pxor mm7,mm7				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			_asm movq mm6,ONE				// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend32)		// mm2レジスタに転送元のブレンド値を入れる
			PUNPCKLWD_mm_mem(mm2,Blend32)	// mm2レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			PUNPCKLDQ_mm_mm(mm2,mm2)		// mm2レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			MOVD_mm_mem(mm3,Bd32)			// mm3レジスタに転送先のブレンド値を入れる
			PUNPCKLWD_mm_mem(mm3,Bd32)		// mm3レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			PUNPCKLDQ_mm_mm(mm3,mm3)		// mm3レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送

		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1)
				{
					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm0,BuffSrc1	// mm0レジスタの  0-31ビットに BuffSrc1を入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						movd mm1,BuffDest1	// mm1レジスタの  0-31ビットに BuffDest1を入れる
						punpcklbw mm1,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm1,mm1		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm1,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm1,mm3		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						paddusw mm0,mm1		// mm0レジスタと mm1レジスタを足す
						pand mm0,mm5		// マスクをする
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd BuffDest1,mm0	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,BuffSrc1)	// mm0レジスタの  0-31ビットに BuffSrc1を入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						MOVD_mm_mem(mm1,BuffDest1)	// mm1レジスタの  0-31ビットに BuffDest1を入れる
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm1,mm1)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm1,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm1,mm3)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						PADDUSW_mm_mm(mm0,mm1)		// mm0レジスタと mm1レジスタを足す
						PAND_mm_mm(mm0,mm5)			// マスクをする
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(BuffDest1,mm0)	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC
					*(data2+x)=BuffDest1;
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGB値指定ブレンド )                     ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px       : 描画Ｘ座標                                               -*/
/*-    int Py       : 描画Ｙ座標                                               -*/
/*-    float BlendR : 赤の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    float BlendG : 緑の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    float BlendB : 青の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    DDOBJ ObjDD  : スプライト情報                                           -*/
/*-    int X1       : スプライト左上Ｘ座標                                     -*/
/*-    int Y1       : スプライト左上Ｙ座標                                     -*/
/*-    int X2       : スプライト右下Ｘ座標                                     -*/
/*-    int Y2       : スプライト右下Ｙ座標                                     -*/
/*-                                                                            -*/
/*-    戻り値       : TRUE  = 正常終了                                         -*/
/*-                 : FALSE = エラー発生                                       -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BlendLayer(int Px,int Py,float BlendR,float BlendG,float BlendB,
						DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::BlendLayer16MMX(Px,Py,BlendR,BlendG,BlendB,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R1,G1,B1,R2,G2,B2;
	static unsigned int R1,G1,B1,R2,G2,B2;//
	static float BdR,BdG,BdB;

	static elDraw32::Buff32 Buff1,Buff2;
	static int RGB_R,RGB_G,RGB_B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// ブレンド値の算出
		BdR=F(1)-BlendR;
		BdG=F(1)-BlendG;
		BdB=F(1)-BlendB;

		// データ転送
		// ＭＭＸを使わない場合
		if (!elDraw32::USE_MMX)
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R1=(Buff>>ShiftR)&BitR;
//					G1=(Buff>>ShiftG)&BitG;
//					B1=(Buff>>ShiftB)&BitB;

//					Buff=*(data2+x);
					Buff2.Buff=*(data2+x);//

//					R2=(Buff>>ShiftR)&BitR;
//					G2=(Buff>>ShiftG)&BitG;
//					B2=(Buff>>ShiftB)&BitB;

//					R1=(unsigned int)(F(R1)*BlendR+F(R2)*BdR);
//					G1=(unsigned int)(F(G1)*BlendG+F(G2)*BdG);
//					B1=(unsigned int)(F(B1)*BlendB+F(B2)*BdB);
					Buff1.BuffRGB[RGB_R]=(unsigned char)(F(Buff1.BuffRGB[RGB_R])*BlendR+F(Buff2.BuffRGB[RGB_R])*BdR);//
					Buff1.BuffRGB[RGB_G]=(unsigned char)(F(Buff1.BuffRGB[RGB_G])*BlendG+F(Buff2.BuffRGB[RGB_G])*BdG);//
					Buff1.BuffRGB[RGB_B]=(unsigned char)(F(Buff1.BuffRGB[RGB_B])*BlendB+F(Buff2.BuffRGB[RGB_B])*BdB);//

//					*(data2+x)=(R1<<ShiftR)|(G1<<ShiftG)|(B1<<ShiftB);
					*(data2+x)=Buff1.Buff;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // ＭＭＸを使わない場合 ここまで
		// ＭＭＸを使う場合
		else
		{
		static unsigned __int32 Blend32R,Blend32G,Blend32B;
		static unsigned __int32 Bd32R,Bd32G,Bd32B;
		static unsigned __int64 Blend64,Bd64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // ＭＭＸを使う時のバッファ Srcは転送元
		static unsigned __int32 BuffDest1; // Destは転送先

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Blend32R=((unsigned __int32)((float)0x7fff*(float)BlendR));				// ブレンド値を整数にする
		Blend32G=((unsigned __int32)((float)0x7fff*(float)BlendG));				// ブレンド値を整数にする
		Blend32B=((unsigned __int32)((float)0x7fff*(float)BlendB));				// ブレンド値を整数にする
		Blend64=(unsigned __int64)Blend32R<<(RGB_R*16)|(unsigned __int64)Blend32G<<(RGB_G*16)|(unsigned __int64)Blend32B<<(RGB_B*16);	// ブレンド値を64ビットに入れる
		Bd32R=((unsigned __int32)((float)0x7fff*(float)BdR));					// ブレンド値を整数にする
		Bd32G=((unsigned __int32)((float)0x7fff*(float)BdG));					// ブレンド値を整数にする
		Bd32B=((unsigned __int32)((float)0x7fff*(float)BdB));					// ブレンド値を整数にする
		Bd64=(unsigned __int64)Bd32R<<(RGB_R*16)|(unsigned __int64)Bd32G<<(RGB_G*16)|(unsigned __int64)Bd32B<<(RGB_B*16);				// ブレンド値を64ビットに入れる

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movq mm2,Blend64		// mm2レジスタに転送元のブレンド値を入れる
			_asm movq mm3,Bd64			// mm3レジスタに転送先のブレンド値を入れる
			_asm pxor mm7,mm7			// mm7を ０にクリアする
			ONE=0x0000000100010001;		// 四捨五入に使う
			_asm movq mm6,ONE			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend64)		// mm2レジスタに転送元のブレンド値を入れる
			MOVQ_mm_mem(mm3,Bd64)			// mm3レジスタに転送先のブレンド値を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1)
				{
					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm0,BuffSrc1	// mm0レジスタの  0-31ビットに BuffSrc1を入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						movd mm1,BuffDest1	// mm1レジスタの  0-31ビットに BuffDest1を入れる
						punpcklbw mm1,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm1,mm1		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm1,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm1,mm3		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						paddusw mm0,mm1		// mm0レジスタと mm1レジスタを足す
						pand mm0,mm5		// マスクをする
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd BuffDest1,mm0	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,BuffSrc1)	// mm0レジスタの  0-31ビットに BuffSrc1を入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						MOVD_mm_mem(mm1,BuffDest1)	// mm1レジスタの  0-31ビットに BuffDest1を入れる
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm1,mm1)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm1,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm1,mm3)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						PADDUSW_mm_mm(mm0,mm1)		// mm0レジスタと mm1レジスタを足す
						PAND_mm_mm(mm0,mm5)			// マスクをする
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(BuffDest1,mm0)	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC
					*(data2+x)=BuffDest1;
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 値指定ブレンド / 彩度比率無視 )         ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Blend   : 混合率 ( 0 ～ 31 )                                        -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/
/* まだ考え中・・
// ブレンドリスト、どうしよう？

BOOL elDraw32::BlendLayer(int Px,int Py,int Blend,DDOBJ ObjDD,
						int X1,int Y1,int X2,int Y2)
{
	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R1,G1,B1,R2,G2,B2;
	static int Bd;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// ブレンド値の算出
		Bd=(31-Blend)<<10;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					R1=GetRGB[Buff].r;
					G1=GetRGB[Buff].g;
					B1=GetRGB[Buff].b;

					Buff=*(data2+x);

					R2=GetRGB[Buff].r;
					G2=GetRGB[Buff].g;
					B2=GetRGB[Buff].b;

					R1=BlendList[Bd+(R1<<5)+R2];
					G1=BlendList[(1<<15)+Bd+(G1<<5)+G2];
					B1=BlendList[(2<<15)+Bd+(B1<<5)+B2];

					*(data2+x)=R1|G1|B1;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}
*/

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 加算ブレンド )                          ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::AddBlendLayer(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::AddBlendLayer(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R1,G1,B1,R2,G2,B2;

	static union elDraw32::Buff32 Buff1,Buff2;
	static int RGB_R,RGB_G,RGB_B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		//ＭＭＸを使わない場合
		if (!elDraw32::USE_MMX)
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R1=GetRGB[Buff].r;
//					G1=GetRGB[Buff].g;
//					B1=GetRGB[Buff].b;

//					Buff=*(data2+x);
					Buff2.Buff=*(data2+x);//

//					R2=GetRGB[Buff].r;
//					G2=GetRGB[Buff].g;
//					B2=GetRGB[Buff].b;

//					R1=AddBlendList[(R1<<5)+R2];
//					G1=AddBlendList[(1<<15)+(G1<<5)+G2];
//					B1=AddBlendList[(2<<15)+(B1<<5)+B2];

					Buff1.BuffRGB[RGB_R]=elDraw32::AddBlendList[Buff1.BuffRGB[RGB_R]+Buff2.BuffRGB[RGB_R]];//
					Buff1.BuffRGB[RGB_G]=elDraw32::AddBlendList[Buff1.BuffRGB[RGB_G]+Buff2.BuffRGB[RGB_G]];//
					Buff1.BuffRGB[RGB_B]=elDraw32::AddBlendList[Buff1.BuffRGB[RGB_B]+Buff2.BuffRGB[RGB_B]];//

//					*(data2+x)=R1|G1|B1;
					*(data2+x)=Buff1.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // ＭＭＸを使わない場合 ここまで
		//ＭＭＸを使う場合
		else
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int64 BuffSrc;
		static unsigned __int64 BuffDest;

		MaskBit64=0x0000000000ffffff;	//マスク用データ
		#ifndef BCC
			_asm movq mm7,MaskBit64
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64)
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc=*(data1+x);

				if (BuffSrc!=0x00000000)
				{
					BuffDest=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm0,BuffSrc		// mm0レジスタの  0-31ビットに BuffSrcを入れる
						movd mm1,BuffDest		// mm1レジスタの  0-31ビットに BuffDestを入れる

						paddusb mm0,mm1			// サチュレーション(飽和)付きで mm0=mm0+mm1 の 演算をする(８ビット境界、unsigned)
						pand mm0,mm7			// 念のためマスクをする

						movd BuffDest,mm0		// BuffDestに mm0レジスタの  0-31ビットを入れる
					}
					#else
						MOVD_mm_mem(mm0,BuffSrc)		// mm0レジスタの  0-31ビットに BuffSrcを入れる
						MOVD_mm_mem(mm1,BuffDest)		// mm1レジスタの  0-31ビットに BuffDestを入れる

						PADDUSB_mm_mm(mm0,mm1)			// サチュレーション(飽和)付きで mm0=mm0+mm1 の 演算をする(８ビット境界、unsigned)
						PAND_mm_mm(mm0,mm7)				// 念のためマスクをする

						MOVD_mem_mm(BuffDest,mm0)		// BuffDestに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC
					*(data2+x)=(unsigned long)BuffDest;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS // EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 加算値指定ブレンド )                ※ ハイカラー専用  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    float Blend : 混合率 ( 0.0 ～ 1.0 )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/
/*
BOOL elDraw::AddBlendLayer(int Px,int Py,float Blend,DDOBJ ObjDD,
						   int X1,int Y1,int X2,int Y2)
{
	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R1,G1,B1,R2,G2,B2;
	static int Bd;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// ブレンド値の算出
		Bd=((int)(F(31)-Blend*F(31)))<<10;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					R1=GetRGB[Buff].r;
					G1=GetRGB[Buff].g;
					B1=GetRGB[Buff].b;

					Buff=*(data2+x);

					R2=GetRGB[Buff].r;
					G2=GetRGB[Buff].g;
					B2=GetRGB[Buff].b;

					R1=AddBlendList[Bd+(R1<<5)+R2];
					G1=AddBlendList[(1<<15)+Bd+(G1<<5)+G2];
					B1=AddBlendList[(2<<15)+Bd+(B1<<5)+B2];

					*(data2+x)=R1|G1|B1;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}
*/

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 減算ブレンド )                          ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::DelBlendLayer(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::DelBlendLayer(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R1,R2,G2,B2;

	static union elDraw32::Buff32 Buff1,Buff2;//
	static int RGB_R,RGB_G,RGB_B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		if (!elDraw32::USE_MMX) // MMXを使わない場合
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R1=GetRGB[Buff].r;

//					Buff=*(data2+x);
					Buff2.Buff=*(data2+x);//

//					R2=GetRGB[Buff].r;
//					G2=GetRGB[Buff].g;
//					B2=GetRGB[Buff].b;

//					R2=DelBlendList[(R2<<5)+R1];
//					G2=DelBlendList[(1<<10)+(G2<<5)+R1];
//					B2=DelBlendList[(2<<10)+(B2<<5)+R1];

					Buff2.BuffRGB[RGB_R]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_R]<<8)+Buff1.BuffRGB[RGB_R]];//
					Buff2.BuffRGB[RGB_G]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_G]<<8)+Buff1.BuffRGB[RGB_R]];//
					Buff2.BuffRGB[RGB_B]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_B]<<8)+Buff1.BuffRGB[RGB_R]];//

//					*(data2+x)=R2|G2|B2;
					*(data2+x)=Buff2.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMXを使わない場合ここまで
		else //ＭＭＸを使う場合
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1; //ＭＭＸを使う時のバッファ･Srcは転送元
		static unsigned __int32 BuffDest1;//Destは転送先

		MaskBit64=0x0000000000ffffff;	//マスク用データ
		#ifndef BCC
			_asm movq mm7,MaskBit64 // mm7レジスタにマスク用データを入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64) // mm7レジスタにマスク用データを入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1!=0x00000000) //黒の場合は処理しない
				{
					// R値のみで減算
					R1=(BuffSrc1>>ShiftR)&BitR;
					R1=(R1<<16)+(R1<<8)+R1;

					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm1,R1				// mm1レジスタの  0-31ビットに R1を入れる
						movd mm0,BuffDest1		// mm0レジスタの  0-31ビットに BuffDest1を入れる
						psubusb mm0,mm1			// サチュレーション(飽和)付きで mm0=mm0-mm1 の 演算をする (８ビット境界、unsigned)
						pand mm0,mm7			// 念のためマスクをする
						movd BuffDest1,mm0		// BuffDest1に mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm1,R1)				// mm1レジスタの  0-31ビットに R1を入れる
						MOVD_mm_mem(mm0,BuffDest1)		// mm0レジスタの  0-31ビットに BuffDest1を入れる
						PSUBUSB_mm_mm(mm0,mm1)			// サチュレーション(飽和)付きで mm0=mm0-mm1 の 演算をする (８ビット境界、unsigned)
						PAND_mm_mm(mm0,mm7)				// 念のためマスクをする
						MOVD_mem_mm(BuffDest1,mm0)		// BuffDest1に mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=BuffDest1;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( エッジブレンド )                        ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::EdgeBlendLayer(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::EdgeBlendLayer(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,Buff2,R,G,B;
	static UINT R,G,B;//
	static int Count;

	static union elDraw32::Buff32 Buff1,Buff2;//
	static int RGB_R,RGB_G,RGB_B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;
					R=Buff1.BuffRGB[RGB_R];//
					G=Buff1.BuffRGB[RGB_G];//
					B=Buff1.BuffRGB[RGB_B];//

					Count=1;

//					Buff2=*(data1+x-1);
					Buff2.Buff=*(data1+x-1);//

//					if (x>Sx && Buff2==0x0000)
					if (x>Sx && Buff2.Buff==0x00000000)//
					{
//						Buff2=*(data2+x-1);
						Buff2.Buff=*(data2+x-1);//

//						R+=GetRGB[Buff2].r;
//						G+=GetRGB[Buff2].g;
//						B+=GetRGB[Buff2].b;
						R+=Buff2.BuffRGB[RGB_R];//
						G+=Buff2.BuffRGB[RGB_G];//
						B+=Buff2.BuffRGB[RGB_B];//

						Count++;
					}

//					Buff2=*(data1+x+1);
					Buff2.Buff=*(data1+x+1);//

//					if (x<Ex-1 && Buff2==0x0000)
					if (x<Ex-1 && Buff2.Buff==0x00000000)//
					{
//						Buff2=*(data2+x+1);
						Buff2.Buff=*(data2+x+1);//

//						R+=GetRGB[Buff2].r;
//						G+=GetRGB[Buff2].g;
//						B+=GetRGB[Buff2].b;
						R+=Buff2.BuffRGB[RGB_R];//
						G+=Buff2.BuffRGB[RGB_G];//
						B+=Buff2.BuffRGB[RGB_B];//

						Count++;
					}

//					Buff2=*(data1+x-AddPitch1);
					Buff2.Buff=*(data1+x-AddPitch1);//

//					if (y>Sy && Buff2==0x0000)
					if (y>Sy && Buff2.Buff==0x00000000)//
					{
//						Buff2=*(data2+x-AddPitch2);
						Buff2.Buff=*(data2+x-AddPitch2);//

//						R+=GetRGB[Buff2].r;
//						G+=GetRGB[Buff2].g;
//						B+=GetRGB[Buff2].b;
						R+=Buff2.BuffRGB[RGB_R];//
						G+=Buff2.BuffRGB[RGB_G];//
						B+=Buff2.BuffRGB[RGB_B];//

						Count++;
					}

//					Buff2=*(data1+x+AddPitch1);
					Buff2.Buff=*(data1+x+AddPitch1);//

//					if (y<Ey-1 && Buff2==0x0000)
					if (y<Ey-1 && Buff2.Buff==0x00000000)//
					{
//						Buff2=*(data2+x+AddPitch2);
						Buff2.Buff=*(data2+x+AddPitch2);//

//						R+=GetRGB[Buff2].r;
//						G+=GetRGB[Buff2].g;
//						B+=GetRGB[Buff2].b;
						R+=Buff2.BuffRGB[RGB_R];//
						G+=Buff2.BuffRGB[RGB_G];//
						B+=Buff2.BuffRGB[RGB_B];//

						Count++;
					}

					if (Count>1)
					{
//						R/=Count;
//						G/=Count;
//						B/=Count;
						Buff2.BuffRGB[RGB_R]=R/Count;//
						Buff2.BuffRGB[RGB_G]=G/Count;//
						Buff2.BuffRGB[RGB_B]=B/Count;//

//						*(data2+x)=(R<<elDraw::ShiftR)|(G<<elDraw::ShiftG)|
//								   (B<<elDraw::ShiftB);
						*(data2+x)=Buff2.Buff;
					}
					else
					{
//						*(data2+x)=Buff;
						*(data2+x)=Buff1.Buff;//
					}
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGBプレーン抽出 )                       ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    BOOL PlainR : 赤の抽出                                                  -*/
/*-    BOOL PlainG : 緑の抽出                                                  -*/
/*-    BOOL PlainB : 青の抽出                                                  -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::PlainLayer(int Px,int Py,BOOL PlainR,BOOL PlainG,BOOL PlainB,
						DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::PlainLayer(Px,Py,PlainR,PlainG,PlainB,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,Color;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// マスクの作成
//		Color=0x0000;
		Color=0x00000000;//
		if (PlainR) Color|=MaskR;
		if (PlainG) Color|=MaskG;
		if (PlainB) Color|=MaskB;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

//				if (Buff!=0x0000)
				if (Buff!=0x00000000)//
				{
					*(data2+x)=Buff&Color;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 明度調整 )                              ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px       : 描画Ｘ座標                                               -*/
/*-    int Py       : 描画Ｙ座標                                               -*/
/*-    float Bright : 明度 ( 0.0 ～ 1.0 )                                      -*/
/*-    DDOBJ ObjDD  : スプライト情報                                           -*/
/*-    int X1       : スプライト左上Ｘ座標                                     -*/
/*-    int Y1       : スプライト左上Ｙ座標                                     -*/
/*-    int X2       : スプライト右下Ｘ座標                                     -*/
/*-    int Y2       : スプライト右下Ｙ座標                                     -*/
/*-                                                                            -*/
/*-    戻り値       : TRUE  = 正常終了                                         -*/
/*-                 : FALSE = エラー発生                                       -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer(int Px,int Py,float Bright,DDOBJ ObjDD,
						 int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::BrightLayer16MMX(Px,Py,Bright,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R,G,B;
	static unsigned int R,G,B;//

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		if (!elDraw32::USE_MMX) // MMXを使わない場合
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					R=(Buff>>ShiftR)&BitR;
//					G=(Buff>>ShiftG)&BitG;
//					B=(Buff>>ShiftB)&BitB;

//					R=(unsigned int)(F(R)*Bright);
//					G=(unsigned int)(F(G)*Bright);
//					B=(unsigned int)(F(B)*Bright);
					Buff.BuffRGB[RGB_R]=(unsigned char)(F(Buff.BuffRGB[RGB_R])*Bright);//
					Buff.BuffRGB[RGB_G]=(unsigned char)(F(Buff.BuffRGB[RGB_G])*Bright);//
					Buff.BuffRGB[RGB_B]=(unsigned char)(F(Buff.BuffRGB[RGB_B])*Bright);//

//					*(data2+x)=(R<<ShiftR)|(G<<ShiftG)|(B<<ShiftB);
					*(data2+x)=Buff.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMXを使わない場合ここまで
		else //ＭＭＸを使う場合
		{
		static unsigned __int32 Bright32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Bright32=((unsigned __int32)((float)0x7fff*(float)Bright));	// 明度値を整数にする

		EMMS

		#ifndef BCC
			_asm movd mm1,Bright32		// mm1レジスタに明度値を入れる
			_asm punpcklwd mm1,Bright32	// mm1レジスタの 0-31ビットに明度値(２つ)を入れる
			_asm punpckldq mm1,mm1		// mm1レジスタの 0-63ビットに明度値(４つ)を入れる
			_asm pxor mm7,mm7			// mm7を ０にクリアする
			ONE=0x0000000100010001;		// 四捨五入に使う
			_asm movq mm6,ONE			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;// マスク用データ
			_asm movq mm5,MaskBit64		// mm5レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVD_mm_mem(mm1,Bright32)		// mm1レジスタに明度値を入れる
			PUNPCKLWD_mm_mem(mm1,Bright32)	// mm1レジスタの 0-31ビットに明度値(２つ)を入れる
			PUNPCKLDQ_mm_mm(mm1,mm1)		// mm1レジスタの 0-63ビットに明度値(４つ)を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff.Buff=*(data1+x);

				if (Buff.Buff!=0x00000000)
				{
					#ifndef BCC
					_asm
					{
						movd mm0,Buff.Buff	// mm0レジスタの  0-31ビットに Buff.Buffを入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をするため)
						paddw mm0,mm6		// １を足す(四捨五入のため)

						pmulhw mm0,mm1		// 掛け算(出てくるのは 計算結果の 32ビットのうち 上位16ビット)
						pand mm0,mm5		// マスクをする
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(mm7はダミー)

						movd Buff.Buff,mm0	// Buff.Buffに mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff.Buff)	// mm0レジスタの  0-31ビットに Buff.Buffを入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をするため)
						PADDW_mm_mm(mm0,mm6)		// １を足す(四捨五入のため)

						PMULHW_mm_mm(mm0,mm1)		// 掛け算(出てくるのは 計算結果の 32ビットのうち 上位16ビット)
						PAND_mm_mm(mm0,mm5)			// マスクをする
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(mm7はダミー)

						MOVD_mem_mm(Buff.Buff,mm0)	// Buff.Buffに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=Buff.Buff;
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGB明度調整 )                           ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px        : 描画Ｘ座標                                              -*/
/*-    int Py        : 描画Ｙ座標                                              -*/
/*-    float BrightR : 赤の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    float BrightG : 緑の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    float BrightB : 青の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    DDOBJ ObjDD   : スプライト情報                                          -*/
/*-    int X1        : スプライト左上Ｘ座標                                    -*/
/*-    int Y1        : スプライト左上Ｙ座標                                    -*/
/*-    int X2        : スプライト右下Ｘ座標                                    -*/
/*-    int Y2        : スプライト右下Ｙ座標                                    -*/
/*-                                                                            -*/
/*-    戻り値        : TRUE  = 正常終了                                        -*/
/*-                  : FALSE = エラー発生                                      -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer(int Px,int Py,float BrightR,float BrightG,float BrightB,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::BrightLayer16MMX(Px,Py,BrightR,BrightG,BrightB,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R,G,B;
	static unsigned int R,G,B;//

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;
		AddPitch2=ddsd2.lPitch/4;

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		if (!elDraw32::USE_MMX) // ＭＭＸを使わない場合
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					R=(Buff>>ShiftR)&BitR;
//					G=(Buff>>ShiftG)&BitG;
//					B=(Buff>>ShiftB)&BitB;

//					R=(unsigned int)(F(R)*BrightR);
//					G=(unsigned int)(F(G)*BrightG);
//					B=(unsigned int)(F(B)*BrightB);
					Buff.BuffRGB[RGB_R]=(unsigned char)(F(Buff.BuffRGB[RGB_R])*BrightR);//
					Buff.BuffRGB[RGB_G]=(unsigned char)(F(Buff.BuffRGB[RGB_G])*BrightG);//
					Buff.BuffRGB[RGB_B]=(unsigned char)(F(Buff.BuffRGB[RGB_B])*BrightB);//

//					*(data2+x)=(R<<ShiftR)|(G<<ShiftG)|(B<<ShiftB);
					*(data2+x)=Buff.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // ＭＭＸを使わない場合 ここまで
		// ＭＭＸを使う場合
		else
		{
		static unsigned __int32 Bright32R,Bright32G,Bright32B;
		static unsigned __int64 Bright64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Bright32R=((unsigned __int32)((float)0x7fff*(float)BrightR));				// 明度値を整数にする
		Bright32G=((unsigned __int32)((float)0x7fff*(float)BrightG));				// 明度値を整数にする
		Bright32B=((unsigned __int32)((float)0x7fff*(float)BrightB));				// 明度値を整数にする
		Bright64=(unsigned __int64)Bright32R<<(RGB_R*16)|(unsigned __int64)Bright32G<<(RGB_G*16)|(unsigned __int64)Bright32B<<(RGB_B*16);	// 明度値を64ビットに入れる

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movq mm2,Bright64			// mm2レジスタに明度値を入れる
			_asm pxor mm7,mm7				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			_asm movq mm6,ONE				// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Bright64)		// mm2レジスタに明度値を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff.Buff=*(data1+x);

				if (Buff.Buff!=0x00000000)
				{
					#ifndef BCC
					_asm
					{
						movd mm0,Buff.Buff	// mm0レジスタの  0-31ビットに Buff.Buffを入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						pand mm0,mm5		// マスクをする
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd Buff.Buff,mm0	// Buff.Buffに mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff.Buff)	// mm0レジスタの  0-31ビットに Buff.Buffを入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						PAND_mm_mm(mm0,mm5)			// マスクをする
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(Buff.Buff,mm0)	// Buff.Buffに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=Buff.Buff;
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 明度調整 / 彩度比率無視 )               ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Bright  : 明度 ( 0 ～ 31 )                                          -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer(int Px,int Py,int Bright,DDOBJ ObjDD,
						 int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::BrightLayer(Px,Py,Bright,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,R,G,B;
	static UINT R,G,B;//
	static int Bt;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// ブライト値の算出
//		Bt=31-Bright;
		Bt=255-(int)(Bright<<3|Bright>>2);//5→8ビットに拡張

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)
				{
//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;

//					R=DelBlendList[Bt+(R<<5)];
//					G=DelBlendList[(1<<10)+Bt+(G<<5)];
//					B=DelBlendList[(2<<10)+Bt+(B<<5)];
					Buff.BuffRGB[RGB_R]=elDraw32::DelBlendList[Bt+(Buff.BuffRGB[RGB_R]<<8)];//
					Buff.BuffRGB[RGB_G]=elDraw32::DelBlendList[Bt+(Buff.BuffRGB[RGB_G]<<8)];//
					Buff.BuffRGB[RGB_B]=elDraw32::DelBlendList[Bt+(Buff.BuffRGB[RGB_B]<<8)];//

//					*(data2+x)=R|G|B;
					*(data2+x)=Buff.Buff;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGB明度調整 / 彩度比率無視 )            ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int BrightR : 赤の明度 ( 0 ～ 31 )                                      -*/
/*-    int BrightG : 緑の明度 ( 0 ～ 31 )                                      -*/
/*-    int BrightB : 青の明度 ( 0 ～ 31 )                                      -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer(int Px,int Py,int BrightR,int BrightG,int BrightB,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::BrightLayer(Px,Py,BrightR,BrightG,BrightB,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,R,G,B;
	static UINT R,G,B;//
	static int BtR,BtG,BtB;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// ブライト値の算出
//		BtR=31-BrightR;
//		BtG=31-BrightG;
//		BtB=31-BrightB;
		BtR=255-(int)(BrightR<<3|BrightR>>2);//5→8ビットに拡張
		BtG=255-(int)(BrightG<<3|BrightG>>2);//5→8ビットに拡張
		BtB=255-(int)(BrightB<<3|BrightB>>2);//5→8ビットに拡張

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;

//					R=DelBlendList[BtR+(R<<5)];
//					G=DelBlendList[(1<<10)+BtG+(G<<5)];
//					B=DelBlendList[(2<<10)+BtB+(B<<5)];
					Buff.BuffRGB[RGB_R]=elDraw32::DelBlendList[BtR+(Buff.BuffRGB[RGB_R]<<8)];//
					Buff.BuffRGB[RGB_G]=elDraw32::DelBlendList[BtG+(Buff.BuffRGB[RGB_G]<<8)];//
					Buff.BuffRGB[RGB_B]=elDraw32::DelBlendList[BtB+(Buff.BuffRGB[RGB_B]<<8)];//

//					*(data2+x)=R|G|B;
					*(data2+x)=Buff.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( ぼかし )                                ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Shade   : ぼかしの強さ ( 1 ～ )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::ShadeLayer(int Px,int Py,int Shade,DDOBJ ObjDD,
						int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::ShadeLayer(Px,Py,Shade,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static int xx,yy,Sx2,Sy2,Ex2,Ey2;
//	static UINT Buff,R,G,B;
	static UINT R,G,B;
	static int Sd;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// ぼかし値の算出
		Sd=Shade*Shade;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			Sy2=0;
			Ey2=Shade;

			if (y+Ey2>Ey)
			{
				Sy2-=y+Ey2-Ey;
				Ey2-=y+Ey2-Ey;
			}

			for (x=Sx;x<Ex;x++)
			{
//				if (*(data1+x)!=0x0000)
				if (*(data1+x)!=0x00000000)
				{
					R=0;
					G=0;
					B=0;

					Sx2=0;
					Ex2=Shade;

					if (x+Ex2>Ex)
					{
						Sx2-=x+Ex2-Ex;
						Ex2-=x+Ex2-Ex;
					}

					if (Shade==2)
					{
//						Buff=*(data1+x+Sx2+Sy2*AddPitch1);
						Buff.Buff=*(data1+x+Sx2+Sy2*AddPitch1);//

//						R+=GetRGB[Buff].r;
//						G+=GetRGB[Buff].g;
//						B+=GetRGB[Buff].b;
						R+=Buff.BuffRGB[RGB_R];//
						G+=Buff.BuffRGB[RGB_G];//
						B+=Buff.BuffRGB[RGB_B];//

//						Buff=*(data1+x+Sx2+1+Sy2*AddPitch1);
						Buff.Buff=*(data1+x+Sx2+1+Sy2*AddPitch1);//

//						R+=GetRGB[Buff].r;
//						G+=GetRGB[Buff].g;
//						B+=GetRGB[Buff].b;
						R+=Buff.BuffRGB[RGB_R];//
						G+=Buff.BuffRGB[RGB_G];//
						B+=Buff.BuffRGB[RGB_B];//

//						Buff=*(data1+x+Sx2+(Sy2+1)*AddPitch1);
						Buff.Buff=*(data1+x+Sx2+(Sy2+1)*AddPitch1);//

//						R+=GetRGB[Buff].r;
//						G+=GetRGB[Buff].g;
//						B+=GetRGB[Buff].b;
						R+=Buff.BuffRGB[RGB_R];//
						G+=Buff.BuffRGB[RGB_G];//
						B+=Buff.BuffRGB[RGB_B];//

//						Buff=*(data1+x+Sx2+1+(Sy2+1)*AddPitch1);
						Buff.Buff=*(data1+x+Sx2+1+(Sy2+1)*AddPitch1);//

//						R+=GetRGB[Buff].r;
//						G+=GetRGB[Buff].g;
//						B+=GetRGB[Buff].b;
						R+=Buff.BuffRGB[RGB_R];//
						G+=Buff.BuffRGB[RGB_G];//
						B+=Buff.BuffRGB[RGB_B];//

						R>>=2;
						G>>=2;
						B>>=2;
					}
					else
					{
						for (xx=Sx2;xx<Ex2;xx++)
						{
							for (yy=Sy2;yy<Ey2;yy++)
							{
//								Buff=*(data1+x+xx+AddPitch1*yy);
								Buff.Buff=*(data1+x+xx+AddPitch1*yy);//

//								R+=GetRGB[Buff].r;
//								G+=GetRGB[Buff].g;
//								B+=GetRGB[Buff].b;
								R+=Buff.BuffRGB[RGB_R];//
								G+=Buff.BuffRGB[RGB_G];//
								B+=Buff.BuffRGB[RGB_B];//
							}
						}

						R/=Sd;
						G/=Sd;
						B/=Sd;
					}

					*(data2+x)=(R<<ShiftR2)|(G<<ShiftG2)|(B<<ShiftB2);
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( グレースケール )                        ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::GrayLayer(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::GrayLayer(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,R,G,B,Color;
	static UINT R,G,B,Color;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;

//					Color=GrayList[R+G+B];
					Color=elDraw32::GrayList[Buff.BuffRGB[RGB_R]+Buff.BuffRGB[RGB_G]+Buff.BuffRGB[RGB_B]];//
//					Buff=(Color<<ShiftR2)|(Color<<ShiftG2)|(Color<<ShiftB2);
					Buff.BuffRGB[RGB_R]=Color;//
					Buff.BuffRGB[RGB_G]=Color;//
					Buff.BuffRGB[RGB_B]=Color;//

//					*(data2+x)=Buff;
					*(data2+x)=Buff.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( メッシュ )                              ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px        : 描画Ｘ座標                                              -*/
/*-    int Py        : 描画Ｙ座標                                              -*/
/*-    int WaveSize  : ウェーブの大きさ                                        -*/
/*-    int WaveCount : ウェーブの発生数                                        -*/
/*-    int Step      : メッシュの荒さ                                          -*/
/*-    float Zoom    : メッシュのズーム                                        -*/
/*-    float Angle   : メッシュの傾き                                          -*/
/*-    DDOBJ ObjDD   : スプライト情報                                          -*/
/*-    int X1        : スプライト左上Ｘ座標                                    -*/
/*-    int Y1        : スプライト左上Ｙ座標                                    -*/
/*-    int X2        : スプライト右下Ｘ座標                                    -*/
/*-    int Y2        : スプライト右下Ｙ座標                                    -*/
/*-                                                                            -*/
/*-    戻り値        : TRUE  = 正常終了                                        -*/
/*-                  : FALSE = エラー発生                                      -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::MeshLayer(int Px,int Py,int WaveSize,int WaveCount,int Step,
					   float Zoom,float Angle,DDOBJ ObjDD,
					   int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::MeshLayer(Px,Py,WaveSize,WaveCount,Step,Zoom,Angle,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static float xx,yy,zz;
	static int Dx,Dy;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y+=Step)
		{
			zz=F(-1)+F(2)/F(Y2-Y1)*F(y);

			for (x=Sx;x<Ex;x+=Step)
			{
				xx=F(-1)+F(2)/F(X2-X1)*F(x);
				yy=F(WaveSize*(exp(-xx*xx+zz*zz)*cos(WaveCount*sqrt(xx*xx+zz*zz))+
				   F(1))/F(2)+y);

				Dx=(int)((F(x)+F(y)*Angle)*Zoom);
				Dy=(int)(yy*Zoom);

				if (Px+Dx>=Vx1 && Px+Dx<Vx2 && Py+Dy>=Vy1 && Py+Dy<Vy2)
				{
					*(data2+Dx+Dy*AddPitch2)=*(data1+x);
				}
			}

			data1+=AddPitch1*Step;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 回転 )                                  ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::RotateLayer(int Px1,int Py1,int Px2,int Py2,int Angle,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::RotateLayer(Px1,Py1,Px2,Py2,Angle,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx,ry,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;   //
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4; //

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// 回転の中心点を取得
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx=tx2/360-cx2;
				ry=ty2/360-cy2;

				if (rx>=0 && rx<X2-X1 && ry>=0 && ry<Y2-Y1 &&
					x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
					Buff=*(data1+rx+ry*AddPitch1);

//					if (Buff!=0x0000) *(data2+x+y*AddPitch2)=Buff;
					if (Buff!=0x00000000) *(data2+x+y*AddPitch2)=Buff;
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];//
				ty2+=elDraw::RotateData[Angle];//
			}

//			tx1-=RotateData[Angle];
//			ty1+=RotateData[Angle+90];
			tx1-=elDraw::RotateData[Angle];//
			ty1+=elDraw::RotateData[Angle+90];//
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( タイル＋回転 )                          ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::TileRotateLayer(int Px1,int Py1,int Px2,int Py2,int Angle,
							 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::TileRotateLayer(Px1,Py1,Px2,Py2,Angle,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx,ry,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// 回転の中心点を取得
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx=abs(tx2/360-cx2);
				ry=abs(ty2/360-cy2);

				if (x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
					Buff=*(data1+rx%(X2-X1)+ry%(Y2-Y1)*AddPitch1);

//					if (Buff!=0x0000) *(data2+x+y*AddPitch2)=Buff;
					if (Buff!=0x00000000) *(data2+x+y*AddPitch2)=Buff;//
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];//
				ty2+=elDraw::RotateData[Angle];//
			}

//			tx1-=RotateData[Angle];
//			ty1+=RotateData[Angle+90];
			tx1-=elDraw::RotateData[Angle];//
			ty1+=elDraw::RotateData[Angle+90];//
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 拡大縮小＋回転 )                        ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    float Zoom  : 拡大縮小する値                                            -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::ZoomRotateLayer(int Px1,int Py1,int Px2,int Py2,int Angle,
							 float Zoom,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::ZoomRotateLayer(Px1,Py1,Px2,Py2,Angle,Zoom,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx,ry,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// 回転の中心点を取得
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx=(int)(F(tx2/360-cx2)/Zoom);
				ry=(int)(F(ty2/360-cy2)/Zoom);

				if (rx>=0 && rx<X2-X1 && ry>=0 && ry<Y2-Y1 &&
					x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
					Buff=*(data1+rx+ry*AddPitch1);

//					if (Buff!=0x0000) *(data2+x+y*AddPitch2)=Buff;
					if (Buff!=0x00000000) *(data2+x+y*AddPitch2)=Buff;//
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];//
				ty2+=elDraw::RotateData[Angle];//
			}

//			tx1-=RotateData[Angle];
//			ty1+=RotateData[Angle+90];
			tx1-=elDraw::RotateData[Angle];//
			ty1+=elDraw::RotateData[Angle+90];//
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( タイル＋拡大縮小＋回転 )                ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    float Zoom  : 拡大縮小する値                                            -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::TileZoomRotateLayer(int Px1,int Py1,int Px2,int Py2,int Angle,
								 float Zoom,DDOBJ ObjDD,int X1,int Y1,
								 int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::TileZoomRotateLayer(Px1,Py1,Px2,Py2,Angle,Zoom,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx,ry,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// 回転の中心点を取得
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx=abs((int)(F(tx2/360-cx2)/Zoom));
				ry=abs((int)(F(ty2/360-cy2)/Zoom));

				if (x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
					Buff=*(data1+rx%(X2-X1)+ry%(Y2-Y1)*AddPitch1);

//					if (Buff!=0x0000) *(data2+x+y*AddPitch2)=Buff;
					if (Buff!=0x00000000) *(data2+x+y*AddPitch2)=Buff;//
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];//
				ty2+=elDraw::RotateData[Angle];//
			}

//			tx1-=RotateData[Angle];
//			ty1+=RotateData[Angle+90];
			tx1-=elDraw::RotateData[Angle];//
			ty1+=elDraw::RotateData[Angle+90];//
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( タイル＋拡大縮小率可変＋回転 )          ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1          : 描画左上Ｘ座標                                       -*/
/*-    int Py1          : 描画左上Ｙ座標                                       -*/
/*-    int Px2          : 描画右下Ｘ座標                                       -*/
/*-    int Py2          : 描画右下Ｙ座標                                       -*/
/*-    int Angle        : 回転角度 ( 反時計回り )                              -*/
/*-    float ZoomStartX : Ｘ方向拡大縮小率の初期値                             -*/
/*-    float ZoomAddX   : Ｘ方向拡大縮小率の加減値                             -*/
/*-    float ZoomStartY : Ｙ方向拡大縮小率の初期値                             -*/
/*-    float ZoomAddY   : Ｙ方向拡大縮小率の加減値                             -*/
/*-    float Red        : 赤の明度                                             -*/
/*-    float Green      : 緑の明度                                             -*/
/*-    float Blue       : 青の明度                                             -*/
/*-    DDOBJ ObjDD      : スプライト情報                                       -*/
/*-    int X1           : スプライト左上Ｘ座標                                 -*/
/*-    int Y1           : スプライト左上Ｙ座標                                 -*/
/*-    int X2           : スプライト右下Ｘ座標                                 -*/
/*-    int Y2           : スプライト右下Ｙ座標                                 -*/
/*-                                                                            -*/
/*-    戻り値           : TRUE  = 正常終了                                     -*/
/*-                     : FALSE = エラー発生                                   -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::MysteryLayer(int Px1,int Py1,int Px2,int Py2,int Angle,
						  float ZoomStartX,float ZoomAddX,
						  float ZoomStartY,float ZoomAddY,
						  float Red,float Green,float Blue,
						  DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::MysteryLayer(Px1,Py1,Px2,Py2,Angle,
											ZoomStartX,ZoomAddX,ZoomStartY,ZoomAddY,
											Red,Green,Blue,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx,ry,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
//	static UINT Buff,R,G,B;
	static UINT R,G,B;//
	static float ZoomX,ZoomY;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		// 回転の中心点を取得
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		// 拡大率の初期化
		ZoomX=ZoomStartX;
		ZoomY=ZoomStartY;

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx=abs((int)(F(tx2/360-cx2)/ZoomX));
				ry=abs((int)(F(ty2/360-cy2)/ZoomY));

				if (x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
//					Buff=*(data1+rx%(X2-X1)+ry%(Y2-Y1)*AddPitch1);
					Buff.Buff=*(data1+rx%(X2-X1)+ry%(Y2-Y1)*AddPitch1);//

//					if (Buff!=0x0000)
					if (Buff.Buff!=0x00000000)//
					{
//						R=GetRGB[Buff].r;
//						G=GetRGB[Buff].g;
//						B=GetRGB[Buff].b;

//						R=(UINT)(F(R)*Red);
//						G=(UINT)(F(G)*Green);
//						B=(UINT)(F(B)*Blue);
						Buff.BuffRGB[RGB_R]=(unsigned char)(F(Buff.BuffRGB[RGB_R])*Red);//
						Buff.BuffRGB[RGB_G]=(unsigned char)(F(Buff.BuffRGB[RGB_G])*Green);//
						Buff.BuffRGB[RGB_B]=(unsigned char)(F(Buff.BuffRGB[RGB_B])*Blue);//

//						Buff=(R<<ShiftR2)|(G<<ShiftG2)|(B<<ShiftB2);

//						*(data2+x+y*AddPitch2)=Buff;
						*(data2+x+y*AddPitch2)=Buff.Buff;//
					}
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];//
				ty2+=elDraw::RotateData[Angle];//
			}

			ZoomX+=ZoomAddX;
			ZoomY+=ZoomAddY;

//			tx1-=RotateData[Angle];
//			ty1+=RotateData[Angle+90];
			tx1-=elDraw::RotateData[Angle];//
			ty1+=elDraw::RotateData[Angle+90];//
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  ピクセルピック                                             ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Mode    : 参照位置                                                  -*/
/*-                  PICK_LEFT   = 左側１ドットを参照                          -*/
/*-                  PICK_RIGHT  = 右側１ドットを参照                          -*/
/*-                  PICK_TOP    = 上側１ドットを参照                          -*/
/*-                  PICK_BOTTOM = 下側１ドットを参照                          -*/
/*-    int Start   : 開始位置                                                  -*/
/*-                  ModeがPICK_LEFTまたはPICK_RIGHT = 0 ～ X2-1               -*/
/*-                  ModeがPICK_TOPまたはPICK_BOTTOM = 0 ～ Y2-1               -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

// 参照位置
//static const int PICK_LEFT=0;
//static const int PICK_RIGHT=1;
//static const int PICK_TOP=2;
//static const int PICK_BOTTOM=3;

BOOL elDraw32::PickLayer(int Px,int Py,int Mode,int Start,DDOBJ ObjDD,
					   int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::PickLayer(Px,Py,Mode,Start,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff;

	// 描画領域の計算
//	if (Mode==PICK_LEFT) X2=Width-X1;
//	if (Mode==PICK_TOP) Y2=Height-Y1;
	if (Mode==PICK_LEFT) X2=elDraw::Width-X1;
	if (Mode==PICK_TOP) Y2=elDraw::Height-Y1;

	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		if (Mode==PICK_LEFT)
		{
			// スプライトの先頭位置を取得
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					if (x-Sx<=(UINT)Start)
					{
						Buff=*(data1+x);
					}

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+x)=Buff;
					}
				}

				// Ｙ方向に加算
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_RIGHT)
		{
			// スプライトの先頭位置を取得
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Py*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					if (x-Sx<=(UINT)Start)
					{
						Buff=*(data1+Start);
					}
					else
					{
						Buff=*(data1+x);
					}

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+Px+x)=Buff;
					}
				}

				for (x=0;x<(UINT)Px;x++)
				{
					*(data2+x)=*(data1+Start);
				}

				// Ｙ方向に加算
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_TOP)
		{
			// スプライトの先頭位置を取得
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

			// データ転送
			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					if (y-Sy<=(UINT)Start)
					{
						Buff=*(data1+x+y*AddPitch1);
					}
					else
					{
						Buff=*(data1+x+Start*AddPitch1);
					}

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+x)=Buff;
					}
				}

				// Ｙ方向に加算
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_BOTTOM)
		{
			// スプライトの先頭位置を取得
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px;//+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px;//+Py*AddPitch2;//

			// データ転送
			for (y=0;y<(UINT)Py;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					*(data2+x)=*(data1+x+Start*AddPitch1);
				}

				// Ｙ方向に加算
				data2+=AddPitch2;
			}

			for (y=Sy;y<Ey;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					if (y-Sy<=(UINT)Start)
					{
						Buff=*(data1+x+Start*AddPitch1);
					}
					else
					{
						Buff=*(data1+x+y*AddPitch1);
					}

//					if (Buff!=0x0000)
					if (Buff!=0x00000000)//
					{
						*(data2+x)=Buff;
					}
				}

				// Ｙ方向に加算
				data2+=AddPitch2;
			}
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  ピクセルシフト                                             ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    float Shift : シフト率 ( 0.0 ～ 1.0 )                                   -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::ShiftLayer(int Px,int Py,float Shift,DDOBJ ObjDD,
						int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::ShiftLayer(Px,Py,Shift,ObjDD,X1,Y1,X2,Y2);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static int x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff;
	static int St;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// シフト値の算出
		St=(int)(F(31)-Shift*F(31));

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					Buff=GetRGB[Buff].r;
					Buff.BuffRGB[RGB_R]>>=3;//

//					if ((int)Buff-St>0)
					if ((int)Buff.BuffRGB[RGB_R]-St>0)//
					{
//						Buff-=St;
						Buff.BuffRGB[RGB_R]-=St;//
					}
					else
					{
//						Buff=0;
						Buff.BuffRGB[RGB_R]=0;//
					}

//					if (Buff>=Ey-y) Buff=0;
					if (Buff.BuffRGB[RGB_R]>=Ey-y) Buff.BuffRGB[RGB_R]=0;//

//					*(data2+x)=*(data2+x+Buff*AddPitch2);
					*(data2+x)=*(data2+x+Buff.BuffRGB[RGB_R]*AddPitch2);//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( トンネル )                              ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Rotate  : 回転 ( 0 ～ スプライトのＸサイズ )                        -*/
/*-    int Dist    : 距離 ( 0 ～ スプライトのＹサイズ )                        -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::TunnelLayer(int Px,int Py,int Rotate,int Dist,DDOBJ ObjDD)
{
	if (elSystem::ColorBit()<24) return elDraw::TunnelLayer(Px,Py,Rotate,Dist,ObjDD);//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,y2;
	static UINT Buff;
	static int Gx,Gy;

	// 構造体の初期化
	memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
	ddsd1.dwSize=sizeof(DDSURFACEDESC);
	memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
	ddsd2.dwSize=sizeof(DDSURFACEDESC);

	// スプライトのロック
	ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

	if (ddret!=DD_OK)
	{
		return FALSE;
	}

	// 画面スプライトのロック
	ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

	if (ddret!=DD_OK)
	{
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

		return FALSE;
	}

	// Ｙ方向への追加バイト数の取得
//	AddPitch1=ddsd1.lPitch>>1;
//	AddPitch2=ddsd2.lPitch>>1;
	AddPitch1=ddsd1.lPitch>>2;//
	AddPitch2=ddsd2.lPitch>>2;//

	// スプライトの先頭位置を取得
//	data1=(LPWORD)ddsd1.lpSurface;
//	data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
	data1=(LPDWORD)ddsd1.lpSurface;
	data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

	// データ転送
//	for (y=0,y2=0;y<TunnelDisplayY;y++,y2+=TunnelDisplayX)
	for (y=0,y2=0;y<elDraw::TunnelDisplayY;y++,y2+=elDraw::TunnelDisplayX)//
	{
//		for (x=0;x<TunnelDisplayX;x++)
		for (x=0;x<elDraw::TunnelDisplayX;x++)//
		{
			Gx=TunnelList[y2+x].x+Rotate;
			Gy=TunnelList[y2+x].y+Dist;

//			if (Gx>=TunnelSpriteX) Gx-=TunnelSpriteX;
//			if (Gy>=TunnelSpriteY) Gy-=TunnelSpriteY;
			if (Gx>=elDraw::TunnelSpriteX) Gx-=elDraw::TunnelSpriteX;//
			if (Gy>=elDraw::TunnelSpriteY) Gy-=elDraw::TunnelSpriteY;//

			*(data2+x)=*(data1+Gx+Gy*AddPitch1);
		}

		// Ｙ方向に加算
		data2+=AddPitch2;
	}

	// スプライトのロック解除
	DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
	DD_UNLOCK(DDBack,ddsd2.lpSurface);

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( ライト )                                ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Red     : 赤の減退 ( 0～ )                                          -*/
/*-    int Green   : 緑の減退 ( 0～ )                                          -*/
/*-    int Blue    : 青の減退 ( 0～ )                                          -*/
/*-    WORD Dir    : 光の方向                                                  -*/
/*-                  ( CREATE_DIR(左下,下,右下,左,右,左上,上,右上)で指定 )     -*/
/*-    BOOL Show   : スプライトの表示                                          -*/
/*-                  TRUE  = スプライトとライトを表示                          -*/
/*-                  FALSE = ライトのみ表示                                    -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::LightLayer(int Px,int Py,int Red,int Green,int Blue,WORD Dir,
						BOOL Show,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw::LightLayer(Px,Py,Red,Green,Blue,Dir,
														Show,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2,data3,data4;
	static LPDWORD data1,data2,data3,data4;//
	static long AddPitch1,AddPitch2;
	static UINT i,x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,Buff2;
	static UINT R,G,B,R2,G2,B2;
	static int Count=0;

	static union elDraw32::Buff32 Buff,Buff2;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	Red=Red*8;//
	Green=Green*8;//
	Blue=Blue*8;//

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					if (Show) *(data2+x)=Buff;
					if (Show) *(data2+x)=Buff.Buff;//

//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;
					R=Buff.BuffRGB[RGB_R];
					G=Buff.BuffRGB[RGB_G];
					B=Buff.BuffRGB[RGB_B];

					R>>=Red;
					G>>=Green;
					B>>=Blue;

//					i=elEffect::FireRandomList[Count];
					i=(rand()%3)*8;
					if (++Count==10000) Count=0;

					if (R>=i)
					{
						R-=i;
					}
					else
					{
						R=0;
					}

					if (G>=i)
					{
						G-=i;
					}
					else
					{
						G=0;
					}

					if (B>=i)
					{
						B-=i;
					}
					else
					{
						B=0;
					}

					data3=data2;
					data4=data2;

					for (i=0;i<31;i++)
					{
//						if (R) R--;
//						if (G) G--;
//						if (B) B--;
						if (((int)R-8)>=0) R-=8; else R=0;//
						if (((int)G-8)>=0) G-=8; else G=0;//
						if (((int)B-8)>=0) B-=8; else B=0;//

//						if (R+G+B==0x0000) break;
						if (R+G+B==0x0000) break;//

//						if ((int)(Py+y)-(int)i>=Vy1)
						if ((int)(Py+y)-(int)i>Vy1) //？？i>Vy1 にするとアクセス違反がなくなる。el.hのバグ？？
						{
							data3-=AddPitch2;

							if (Dir&0x40)
							{
//								Buff=*(data3+x);
								Buff.Buff=*(data3+x);//

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data3+x)=(R2<<ShiftR2)|
//										   (G2<<ShiftG2)|
//										   (B2<<ShiftB2);
								*(data3+x)=(R2<<ShiftR)|//
										   (G2<<ShiftG)|//
										   (B2<<ShiftB);//
							}

							if (Dir&0x20 && (int)(Px+x)-(int)i>=Vx1)
							{
//								Buff=*(data3+x-i);
								Buff.Buff=*(data3+x-i);//

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data3+x-i)=(R2<<ShiftR2)|
//											 (G2<<ShiftG2)|
//											 (B2<<ShiftB2);
								*(data3+x-i)=(R2<<ShiftR)|//
											 (G2<<ShiftG)|//
											 (B2<<ShiftB);//
							}

							if (Dir&0x80 && (int)(Px+x)+(int)i<Vx2)
							{
//								Buff=*(data3+x+i);
								Buff.Buff=*(data3+x+i); //

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data3+x+i)=(R2<<ShiftR2)|
//											 (G2<<ShiftG2)|
//											 (B2<<ShiftB2);
								*(data3+x+i)=(R2<<ShiftR)|//
											 (G2<<ShiftG)|//
											 (B2<<ShiftB);//
							}
						}

						if ((int)(Py+y)+(int)i<Vy2)
						{
							data4+=AddPitch2;

							if (Dir&0x02)
							{
//								Buff=*(data4+x);
								Buff.Buff=*(data4+x);

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data4+x)=(R2<<ShiftR2)|
//										   (G2<<ShiftG2)|
//										   (B2<<ShiftB2);
								*(data4+x)=(R2<<ShiftR)|//
										   (G2<<ShiftG)|//
										   (B2<<ShiftB);//
							}

							if (Dir&0x01 && (int)(Px+x)-(int)i>=Vx1)
							{
//								Buff=*(data4+x-i);
								Buff.Buff=*(data4+x-i);//

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data4+x-i)=(R2<<ShiftR2)|
//											 (G2<<ShiftG2)|
//											 (B2<<ShiftB2);
								*(data4+x-i)=(R2<<ShiftR)|//
											 (G2<<ShiftG)|//
											 (B2<<ShiftB);//
							}

							if (Dir&0x04 && (int)(Px+x)+(int)i<Vx2)
							{
//								Buff=*(data4+x+i);
								Buff.Buff=*(data4+x+i);//

//								R2=R+GetRGB[Buff].r;
//								G2=G+GetRGB[Buff].g;
//								B2=B+GetRGB[Buff].b;
								R2=R+Buff.BuffRGB[RGB_R];//
								G2=G+Buff.BuffRGB[RGB_G];//
								B2=B+Buff.BuffRGB[RGB_B];//

//								if (R2>31) R2=31;
//								if (G2>31) G2=31;
//								if (B2>31) B2=31;
								if (R2>255) R2=255;//
								if (G2>255) G2=255;//
								if (B2>255) B2=255;//

//								*(data4+x+i)=(R2<<ShiftR2)|
//											 (G2<<ShiftG2)|
//											 (B2<<ShiftB2);
								*(data4+x+i)=(R2<<ShiftR)|//
											 (G2<<ShiftG)|//
											 (B2<<ShiftB);//
							}
						}

						if (Dir&0x08 && (int)(Px+x)-(int)i>=Vx1)
						{
//							Buff=*(data2+x-i);
							Buff.Buff=*(data2+x-i);//

//							R2=R+GetRGB[Buff].r;
//							G2=G+GetRGB[Buff].g;
//							B2=B+GetRGB[Buff].b;
							R2=R+Buff.BuffRGB[RGB_R];//
							G2=G+Buff.BuffRGB[RGB_G];//
							B2=B+Buff.BuffRGB[RGB_B];//

//							if (R2>31) R2=31;
//							if (G2>31) G2=31;
//							if (B2>31) B2=31;
							if (R2>255) R2=255;//
							if (G2>255) G2=255;//
							if (B2>255) B2=255;//

//							*(data2+x-i)=(R2<<ShiftR2)|
//										 (G2<<ShiftG2)|
//										 (B2<<ShiftB2);
							*(data2+x-i)=(R2<<ShiftR)|//
										 (G2<<ShiftG)|//
										 (B2<<ShiftB);//
						}

						if (Dir&0x10 && (int)(Px+x)+(int)i<Vx2)
						{
//							Buff=*(data2+x+i);
							Buff.Buff=*(data2+x+i);//

//							R2=R+GetRGB[Buff].r;
//							G2=G+GetRGB[Buff].g;
//							B2=B+GetRGB[Buff].b;
							R2=R+Buff.BuffRGB[RGB_R];//
							G2=G+Buff.BuffRGB[RGB_G];//
							B2=B+Buff.BuffRGB[RGB_B];//

//							if (R2>31) R2=31;
//							if (G2>31) G2=31;
//							if (B2>31) B2=31;
							if (R2>255) R2=255;//
							if (G2>255) G2=255;//
							if (B2>255) B2=255;//

//							*(data2+x+i)=(R2<<ShiftR2)|
//										 (G2<<ShiftG2)|
//										 (B2<<ShiftB2);
							*(data2+x+i)=(R2<<ShiftR)|//
										 (G2<<ShiftG)|//
										 (B2<<ShiftB);//
						}
					}
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 値指定ブレンド )               ※ ハイカラー・MMX専用  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    float Blend : 混合率 ( 0.0 ～ 1.0 )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BlendLayer16MMX(int Px,int Py,float Blend,DDOBJ ObjDD,
						int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::MMX_CHECKED==FALSE) elDraw32::MMX_CHECK();
	if (elDraw32::USE_MMX==FALSE) return elDraw::BlendLayer(Px,Py,Blend,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
	static unsigned int Buff,R1,G1,B1,R2,G2,B2;
	static float Bd;

	static elDraw32::Buff32 Buff1,Buff2;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// ブレンド値の算出
		Bd=F(1)-Blend;

		// データ転送
		// ＭＭＸを使う場合
		static unsigned __int32 Blend32;
		static unsigned __int32 Bd32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // ＭＭＸを使う時のバッファ Srcは転送元
		static unsigned __int32 BuffDest1; // Destは転送先

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Blend32=((unsigned __int32)((float)0x7fff*(float)Blend));	// ブレンド値を整数にする
		Bd32=((unsigned __int32)((float)0x7fff*(float)Bd));			// ブレンド値を整数にする

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movd mm2,Blend32			// mm2レジスタに転送元のブレンド値を入れる
			_asm punpcklwd mm2,Blend32		// mm2レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			_asm punpckldq mm2,mm2			// mm2レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			_asm movd mm3,Bd32				// mm3レジスタに転送先のブレンド値を入れる
			_asm punpcklwd mm3,Bd32			// mm3レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			_asm punpckldq mm3,mm3			// mm3レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			_asm pxor mm7,mm7				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			_asm movq mm6,ONE				// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVD_mm_mem(mm2,Blend32)		// mm2レジスタに転送元のブレンド値を入れる
			PUNPCKLWD_mm_mem(mm2,Blend32)	// mm2レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			PUNPCKLDQ_mm_mm(mm2,mm2)		// mm2レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			MOVD_mm_mem(mm3,Bd32)			// mm3レジスタに転送先のブレンド値を入れる
			PUNPCKLWD_mm_mem(mm3,Bd32)		// mm3レジスタの 0-31ビットにブレンド値(計２つ)を入れる
			PUNPCKLDQ_mm_mm(mm3,mm3)		// mm3レジスタの 0-63ビットにブレンド値(計４つ)を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff)
				{
					Buff1.BuffRGB[0]=(Buff>>ShiftR)&BitR;
					Buff1.BuffRGB[1]=(Buff>>ShiftG)&BitG;
					Buff1.BuffRGB[2]=(Buff>>ShiftB)&BitB;

					Buff=*(data2+x);

					Buff2.BuffRGB[0]=(Buff>>ShiftR)&BitR;
					Buff2.BuffRGB[1]=(Buff>>ShiftG)&BitG;
					Buff2.BuffRGB[2]=(Buff>>ShiftB)&BitB;

					#ifndef BCC
					_asm
					{
						movd mm0,Buff1.Buff	// mm0レジスタの  0-31ビットに Buff1を入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						movd mm1,Buff2.Buff	// mm1レジスタの  0-31ビットに Buff2を入れる
						punpcklbw mm1,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm1,mm1		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm1,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm1,mm3		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						paddusw mm0,mm1		// mm0レジスタと mm1レジスタを足す
//						pand mm0,mm5		// マスクをする（必要なし？）
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd Buff1.Buff,mm0	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff1.Buff)	// mm0レジスタの  0-31ビットに Buff1を入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						MOVD_mm_mem(mm1,Buff2.Buff)	// mm1レジスタの  0-31ビットに Buff2を入れる
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm1,mm1)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm1,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm1,mm3)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						PADDUSW_mm_mm(mm0,mm1)		// mm0レジスタと mm1レジスタを足す
//						PAND_mm_mm(mm0,mm5)			// マスクをする（必要なし？）
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(Buff1.Buff,mm0)	// BuffDest1に mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=(Buff1.BuffRGB[0]<<ShiftR)|(Buff1.BuffRGB[1]<<ShiftG)|(Buff1.BuffRGB[2]<<ShiftB);
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGB値指定ブレンド )            ※ ハイカラー・MMX専用  -*/
/*-                                                                            -*/
/*-    int Px       : 描画Ｘ座標                                               -*/
/*-    int Py       : 描画Ｙ座標                                               -*/
/*-    float BlendR : 赤の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    float BlendG : 緑の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    float BlendB : 青の混合率 ( 0.0 ～ 1.0 )                                -*/
/*-    DDOBJ ObjDD  : スプライト情報                                           -*/
/*-    int X1       : スプライト左上Ｘ座標                                     -*/
/*-    int Y1       : スプライト左上Ｙ座標                                     -*/
/*-    int X2       : スプライト右下Ｘ座標                                     -*/
/*-    int Y2       : スプライト右下Ｙ座標                                     -*/
/*-                                                                            -*/
/*-    戻り値       : TRUE  = 正常終了                                         -*/
/*-                 : FALSE = エラー発生                                       -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BlendLayer16MMX(int Px,int Py,float BlendR,float BlendG,float BlendB,
						DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::MMX_CHECKED==FALSE) elDraw32::MMX_CHECK();
	if (elDraw32::USE_MMX==FALSE) return elDraw::BlendLayer(Px,Py,BlendR,BlendG,BlendB,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
	static unsigned int Buff,R1,G1,B1,R2,G2,B2;
	static float BdR,BdG,BdB;

	static elDraw32::Buff32 Buff1,Buff2;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// ブレンド値の算出
		BdR=F(1)-BlendR;
		BdG=F(1)-BlendG;
		BdB=F(1)-BlendB;

		// データ転送
		// ＭＭＸを使う場合
		static unsigned __int32 Blend32R,Blend32G,Blend32B;
		static unsigned __int32 Bd32R,Bd32G,Bd32B;
		static unsigned __int64 Blend64,Bd64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Blend32R=((unsigned __int32)((float)0x7fff*(float)BlendR));				// ブレンド値を整数にする
		Blend32G=((unsigned __int32)((float)0x7fff*(float)BlendG));				// ブレンド値を整数にする
		Blend32B=((unsigned __int32)((float)0x7fff*(float)BlendB));				// ブレンド値を整数にする
		Blend64=(unsigned __int64)Blend32R|(unsigned __int64)Blend32G<<16|(unsigned __int64)Blend32B<<32;	// ブレンド値を64ビットに入れる
		Bd32R=((unsigned __int32)((float)0x7fff*(float)BdR));					// ブレンド値を整数にする
		Bd32G=((unsigned __int32)((float)0x7fff*(float)BdG));					// ブレンド値を整数にする
		Bd32B=((unsigned __int32)((float)0x7fff*(float)BdB));					// ブレンド値を整数にする
		Bd64=(unsigned __int64)Bd32R|(unsigned __int64)Bd32G<<16|(unsigned __int64)Bd32B<<32;				// ブレンド値を64ビットに入れる

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movq mm2,Blend64		// mm2レジスタに転送元のブレンド値を入れる
			_asm movq mm3,Bd64			// mm3レジスタに転送先のブレンド値を入れる
			_asm pxor mm7,mm7			// mm7を ０にクリアする
			ONE=0x0000000100010001;		// 四捨五入に使う
			_asm movq mm6,ONE			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend64)		// mm2レジスタに転送元のブレンド値を入れる
			MOVQ_mm_mem(mm3,Bd64)			// mm3レジスタに転送先のブレンド値を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					Buff1.BuffRGB[0]=(Buff>>ShiftR)&BitR;
					Buff1.BuffRGB[1]=(Buff>>ShiftG)&BitG;
					Buff1.BuffRGB[2]=(Buff>>ShiftB)&BitB;

					Buff=*(data2+x);

					Buff2.BuffRGB[0]=(Buff>>ShiftR)&BitR;
					Buff2.BuffRGB[1]=(Buff>>ShiftG)&BitG;
					Buff2.BuffRGB[2]=(Buff>>ShiftB)&BitB;

					#ifndef BCC
					_asm
					{
						movd mm0,Buff1.Buff	// mm0レジスタの  0-31ビットに Buff1.Buffを入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						movd mm1,Buff2.Buff	// mm1レジスタの  0-31ビットに Buff2.Buffを入れる
						punpcklbw mm1,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm1,mm1		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm1,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm1,mm3		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						paddusw mm0,mm1		// mm0レジスタと mm1レジスタを足す
//						pand mm0,mm5		// マスクをする（必要なし？）
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd Buff1.Buff,mm0	// Buff1.Buffに mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff1.Buff)	// mm0レジスタの  0-31ビットに Buff1.Buffを入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						MOVD_mm_mem(mm1,Buff2.Buff)	// mm1レジスタの  0-31ビットに Buff2.Buffを入れる
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm1,mm1)		// 倍にする(ブレンド値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm1,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm1,mm3)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

						PADDUSW_mm_mm(mm0,mm1)		// mm0レジスタと mm1レジスタを足す
//						PAND_mm_mm(mm0,mm5)			// マスクをする（必要なし？）
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(Buff1.Buff,mm0)	// Buff1.Buffに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=(Buff1.BuffRGB[0]<<ShiftR)|(Buff1.BuffRGB[1]<<ShiftG)|(Buff1.BuffRGB[2]<<ShiftB);
				}
			}
			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 明度調整 )                     ※ ハイカラー・MMX専用  -*/
/*-                                                                            -*/
/*-    int Px       : 描画Ｘ座標                                               -*/
/*-    int Py       : 描画Ｙ座標                                               -*/
/*-    float Bright : 明度 ( 0.0 ～ 1.0 )                                      -*/
/*-    DDOBJ ObjDD  : スプライト情報                                           -*/
/*-    int X1       : スプライト左上Ｘ座標                                     -*/
/*-    int Y1       : スプライト左上Ｙ座標                                     -*/
/*-    int X2       : スプライト右下Ｘ座標                                     -*/
/*-    int Y2       : スプライト右下Ｙ座標                                     -*/
/*-                                                                            -*/
/*-    戻り値       : TRUE  = 正常終了                                         -*/
/*-                 : FALSE = エラー発生                                       -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer16MMX(int Px,int Py,float Bright,DDOBJ ObjDD,
						 int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::MMX_CHECKED==FALSE) elDraw32::MMX_CHECK();
	if (elDraw32::USE_MMX==FALSE) return elDraw::BrightLayer(Px,Py,Bright,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
	static unsigned int Buff1,R,G,B;

	static union elDraw32::Buff32 Buff2;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// データ転送
		// ＭＭＸを使う場合
		static unsigned __int32 Bright32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Bright32=((unsigned __int32)((float)0x7fff*(float)Bright));	// 明度値を整数にする

		EMMS

		#ifndef BCC
			_asm movd mm1,Bright32			// mm1レジスタに明度値を入れる
			_asm punpcklwd mm1,Bright32		// mm1レジスタの 0-31ビットに明度値(２つ)を入れる
			_asm punpckldq mm1,mm1			// mm1レジスタの 0-63ビットに明度値(４つ)を入れる
			_asm pxor mm7,mm7				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			_asm movq mm6,ONE				// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5レジスタにMaskBit64を入れる
		#else // #ifndef BCC
			MOVD_mm_mem(mm1,Bright32)		// mm1レジスタに明度値を入れる
			PUNPCKLWD_mm_mem(mm1,Bright32)	// mm1レジスタの 0-31ビットに明度値(２つ)を入れる
			PUNPCKLDQ_mm_mm(mm1,mm1)		// mm1レジスタの 0-63ビットに明度値(４つ)を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5レジスタにMaskBit64を入れる
		#endif // #ifndef BCC

		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff1=*(data1+x);

				if (Buff1!=0x0000)
				{
					Buff2.BuffRGB[0]=(Buff1>>ShiftR)&BitR;
					Buff2.BuffRGB[1]=(Buff1>>ShiftG)&BitG;
					Buff2.BuffRGB[2]=(Buff1>>ShiftB)&BitB;

					#ifndef BCC
					_asm
					{
						movd mm0,Buff2.Buff	// mm0レジスタの  0-31ビットに Buff2.Buffを入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をするため)
						paddw mm0,mm6		// １を足す(四捨五入のため)

						pmulhw mm0,mm1		// 掛け算(出てくるのは 計算結果の 32ビットのうち 上位16ビット)
//						pand mm0,mm5		// マスクをする（必要なし？）
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(mm7はダミー)

						movd Buff2.Buff,mm0	// Buff2.Buffに mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff2.Buff)	// mm0レジスタの  0-31ビットに Buff2.Buffを入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をするため)
						PADDW_mm_mm(mm0,mm6)		// １を足す(四捨五入のため)

						PMULHW_mm_mm(mm0,mm1)		// 掛け算(出てくるのは 計算結果の 32ビットのうち 上位16ビット)
//						PAND_mm_mm(mm0,mm5)			// マスクをする（必要なし？）
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(mm7はダミー)

						MOVD_mem_mm(Buff2.Buff,mm0)	// Buff2.Buffに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=(Buff2.BuffRGB[0]<<ShiftR)|(Buff2.BuffRGB[1]<<ShiftG)|(Buff2.BuffRGB[2]<<ShiftB);
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( RGB明度調整 )                  ※ ハイカラー・MMX専用  -*/
/*-                                                                            -*/
/*-    int Px        : 描画Ｘ座標                                              -*/
/*-    int Py        : 描画Ｙ座標                                              -*/
/*-    float BrightR : 赤の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    float BrightG : 緑の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    float BrightB : 青の明度 ( 0.0 ～ 1.0 )                                 -*/
/*-    DDOBJ ObjDD   : スプライト情報                                          -*/
/*-    int X1        : スプライト左上Ｘ座標                                    -*/
/*-    int Y1        : スプライト左上Ｙ座標                                    -*/
/*-    int X2        : スプライト右下Ｘ座標                                    -*/
/*-    int Y2        : スプライト右下Ｙ座標                                    -*/
/*-                                                                            -*/
/*-    戻り値        : TRUE  = 正常終了                                        -*/
/*-                  : FALSE = エラー発生                                      -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::BrightLayer16MMX(int Px,int Py,float BrightR,float BrightG,float BrightB,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::MMX_CHECKED==FALSE) elDraw32::MMX_CHECK();
	if (elDraw32::USE_MMX==FALSE) return elDraw::BrightLayer(Px,Py,BrightR,BrightG,BrightB,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static unsigned int x,y,Sx,Sy,Ex,Ey;
	static unsigned int Buff1,R,G,B;

	static union elDraw32::Buff32 Buff2;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// データ転送
		// ＭＭＸを使う場合
		static unsigned __int32 Bright32R,Bright32G,Bright32B;
		static unsigned __int64 Bright64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//↓ホントは 0x10000 にしたいんだけど、16ビット以内、符号付きでないといけないので、やむなくその最大値(==0x7fff)を使う
		Bright32R=((unsigned __int32)((float)0x7fff*(float)BrightR));				// 明度値を整数にする
		Bright32G=((unsigned __int32)((float)0x7fff*(float)BrightG));				// 明度値を整数にする
		Bright32B=((unsigned __int32)((float)0x7fff*(float)BrightB));				// 明度値を整数にする
		Bright64=(unsigned __int64)Bright32R|(unsigned __int64)Bright32G<<16|(unsigned __int64)Bright32B<<32;	// 明度値を64ビットに入れる

		EMMS						// 浮動小数点レジスタをクリアする

		#ifndef BCC
			_asm movq mm2,Bright64			// mm2レジスタに明度値を入れる
			_asm pxor mm7,mm7				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			_asm movq mm6,ONE				// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			_asm movq mm5,MaskBit64			// mm5 レジスタに MaskBit64を入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Bright64)		// mm2レジスタに明度値を入れる
			PXOR_mm_mm(mm7,mm7)				// mm7を ０にクリアする
			ONE=0x0000000100010001;			// 四捨五入に使う
			MOVQ_mm_mem(mm6,ONE)			// mm6レジスタに ONEを入れる
			MaskBit64=0x0000ffffffffffff;	// マスク用データ
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 レジスタに MaskBit64を入れる
		#endif // #ifndef BCC

		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff1=*(data1+x);

				if (Buff1!=0x0000)
				{
					Buff2.BuffRGB[0]=(Buff1>>ShiftR)&BitR;
					Buff2.BuffRGB[1]=(Buff1>>ShiftG)&BitG;
					Buff2.BuffRGB[2]=(Buff1>>ShiftB)&BitB;

					#ifndef BCC
					_asm
					{
						movd mm0,Buff2.Buff	// mm0レジスタの  0-31ビットに Buff2.Buffを入れる
						punpcklbw mm0,mm7	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						paddw mm0,mm0		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						paddw mm0,mm6		// RGBそれぞれに１を足す(四捨五入のため)
						pmulhw mm0,mm2		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

//						pand mm0,mm5		// マスクをする（必要なし？）
						packuswb mm0,mm7	// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						movd Buff2.Buff,mm0	// Buff2.Buffに mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff2.Buff)	// mm0レジスタの  0-31ビットに Buff2.Buffを入れる
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00と画像データを１バイトづつ交互に入れる(これで画像データの R･G･B それぞれがバイト値からワード値になる)
						PADDW_mm_mm(mm0,mm0)		// 倍にする(明度値が半分になっているので こっちを倍にするのと、四捨五入をしたいため)
						PADDW_mm_mm(mm0,mm6)		// RGBそれぞれに１を足す(四捨五入のため)
						PMULHW_mm_mm(mm0,mm2)		// 掛け算(出てくる答は 計算結果の 32ビットのうち 上位16ビット)

//						PAND_mm_mm(mm0,mm5)			// マスクをする（必要なし？）
						PACKUSWB_mm_mm(mm0,mm7)		// mm0レジスタの 0-31ビットに RGB値を取り出す(ワード値をバイト値にもどす。mm7はダミー)

						MOVD_mem_mm(Buff2.Buff,mm0)	// Buff2.Buffに mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=(Buff2.BuffRGB[0]<<ShiftR)|(Buff2.BuffRGB[1]<<ShiftG)|(Buff2.BuffRGB[2]<<ShiftB);
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( ＲＧＢを使った減算ブレンド )            ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::DelBlendLayerEx(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::DelBlendLayerEx16(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R1,R2,G2,B2;

	static union elDraw32::Buff32 Buff1,Buff2;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		if (!USE_MMX) // MMXを使わない場合
		{
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff1.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff1.Buff!=0x00000000)//
				{
//					R1=GetRGB[Buff].r;

//					Buff=*(data2+x);
					Buff2.Buff=*(data2+x);//

//					R2=GetRGB[Buff].r;
//					G2=GetRGB[Buff].g;
//					B2=GetRGB[Buff].b;

//					R2=DelBlendList[(R2<<5)+R1];
//					G2=DelBlendList[(1<<10)+(G2<<5)+R1];
//					B2=DelBlendList[(2<<10)+(B2<<5)+R1];

					Buff2.BuffRGB[RGB_R]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_R]<<8)+Buff1.BuffRGB[RGB_R]];//
					Buff2.BuffRGB[RGB_G]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_G]<<8)+Buff1.BuffRGB[RGB_G]];//
					Buff2.BuffRGB[RGB_B]=elDraw32::DelBlendList[(Buff2.BuffRGB[RGB_B]<<8)+Buff1.BuffRGB[RGB_B]];//

//					*(data2+x)=R2|G2|B2;
					*(data2+x)=Buff2.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMXを使わない場合ここまで
		else //ＭＭＸを使う場合
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1; //ＭＭＸを使う時のバッファ･Srcは転送元
		static unsigned __int32 BuffDest1;//Destは転送先

		MaskBit64=0x0000000000ffffff;	//マスク用データ
		#ifndef BCC
			_asm movq mm7,MaskBit64		// mm7レジスタにマスク用データを入れる
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64)	// mm7レジスタにマスク用データを入れる
		#endif // #ifndef BCC

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1!=0x00000000) //黒の場合は処理しない
				{
					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm1,BuffSrc1		// mm1レジスタの  0-31ビットに BuffSrc1を入れる
						movd mm0,BuffDest1		// mm0レジスタの  0-31ビットに BuffDest1を入れる
						psubusb mm0,mm1			// サチュレーション(飽和)付きで mm0=mm0-mm1 の 演算をする (８ビット境界、unsigned)
						pand mm0,mm7			// 念のためマスクをする
						movd BuffDest1,mm0		// BuffDest1に mm0レジスタの  0-31ビットを入れる
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm1,BuffSrc1)		// mm1レジスタの  0-31ビットに BuffSrc1を入れる
						MOVD_mm_mem(mm0,BuffDest1)		// mm0レジスタの  0-31ビットに BuffDest1を入れる
						PSUBUSB_mm_mm(mm0,mm1)			// サチュレーション(飽和)付きで mm0=mm0-mm1 の 演算をする (８ビット境界、unsigned)
						PAND_mm_mm(mm0,mm7)				// 念のためマスクをする
						MOVD_mem_mm(BuffDest1,mm0)		// BuffDest1に mm0レジスタの  0-31ビットを入れる
					#endif // #ifndef BCC

					*(data2+x)=BuffDest1;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( ＲＧＢを使った減算ブレンド )        ※ ハイカラー専用  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::DelBlendLayerEx16(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,R1,R2,G2,B2;
	static UINT Buff,R1,G1,B1,R2,G2,B2;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					R1=GetRGB[Buff].r;
					G1=GetRGB[Buff].g;//
					B1=GetRGB[Buff].b;//

					Buff=*(data2+x);

					R2=GetRGB[Buff].r;
					G2=GetRGB[Buff].g;
					B2=GetRGB[Buff].b;

//					R2=DelBlendList[(R2<<5)+R1];
//					G2=DelBlendList[(1<<10)+(G2<<5)+R1];
//					B2=DelBlendList[(2<<10)+(B2<<5)+R1];
					R2=elDraw::DelBlendList[(R2<<5)+R1];
					G2=elDraw::DelBlendList[(1<<10)+(G2<<5)+G1];//
					B2=elDraw::DelBlendList[(2<<10)+(B2<<5)+B1];//

					*(data2+x)=R2|G2|B2;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( (R+G+B)/3 ではないグレースケール )      ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::GrayLayerEx(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::GrayLayerEx16(Px,Py,ObjDD,X1,Y1,X2,Y2);//

	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
//	static UINT Buff,R,G,B,Color;
	static UINT R,G,B,Color;

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

//				if (Buff!=0x0000)
				if (Buff.Buff!=0x00000000)//
				{
//					R=GetRGB[Buff].r;
//					G=GetRGB[Buff].g;
//					B=GetRGB[Buff].b;

//					Color=GrayList[R+G+B];
					Color=	elDraw32::GrayListExR[Buff.BuffRGB[RGB_R]]+
							elDraw32::GrayListExG[Buff.BuffRGB[RGB_G]]+
							elDraw32::GrayListExB[Buff.BuffRGB[RGB_B]];//
//					Buff=(Color<<ShiftR2)|(Color<<ShiftG2)|(Color<<ShiftB2);
					Buff.BuffRGB[RGB_R]=Color;//
					Buff.BuffRGB[RGB_G]=Color;//
					Buff.BuffRGB[RGB_B]=Color;//

//					*(data2+x)=Buff;
					*(data2+x)=Buff.Buff;//
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( (R+G+B)/3 ではないグレースケール )  ※ ハイカラー専用  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::GrayLayerEx16(int Px,int Py,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elDraw32::Initialized==FALSE) elDraw32::Init();//

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static UINT x,y,Sx,Sy,Ex,Ey;
	static UINT Buff,R,G,B,Color;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+((int)Ex-(int)Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+((int)Ey-(int)Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					R=GetRGB[Buff].r;
					G=GetRGB[Buff].g;
					B=GetRGB[Buff].b;

//					Color=GrayList[R+G+B];
					Color=	elDraw32::GrayListExR[R]+
							elDraw32::GrayListExG[G]+
							elDraw32::GrayListExB[B];//
//					Buff=(Color<<ShiftR2)|(Color<<ShiftG2)|(Color<<ShiftB2);
					Buff=(Color<<ShiftR2)|(Color<<ShiftG2)|(Color<<ShiftB2);//

					*(data2+x)=Buff;
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 回転＋アンチエイリアス )                ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::RotateLayerEx(int Px1,int Py1,int Px2,int Py2,int Angle,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)

{
	if (elSystem::ColorBit()<24) return elDraw32::RotateLayerEx16(Px1,Py1,Px2,Py2,Angle,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx1,rx2,ry1,ry2,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R,G,B;//
	static unsigned int R,G,B;//

	static union elDraw32::Buff32 Buff;//
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// 回転の中心点を取得
		cx1=(Px2-Px1)/2;
		cy1=(Py2-Py1)/2;
		cx2=((Px2-Px1)-(X2-X1))/2;
		cy2=((Py2-Py1)-(Y2-Y1))/2;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle   ];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle   ]-cy1*elDraw::RotateData[Angle+90];//

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;
//			ry1=(ty2-elDraw::RotateData[Angle   ]/4)/360-cy2;//
//			ry2=(ty2+elDraw::RotateData[Angle   ]/4)/360-cy2;//

			for (x=0;x<Px2-Px1;x++)
			{
				rx1=(tx2-elDraw::RotateData[Angle+90]/4)/360-cx2;
				rx2=(tx2+elDraw::RotateData[Angle+90]/4)/360-cx2;
				ry1=(ty2-elDraw::RotateData[Angle   ]/4)/360-cy2;
				ry2=(ty2+elDraw::RotateData[Angle   ]/4)/360-cy2;

				if (rx1>=0 && rx1<X2-X1 && ry1>=0 && ry1<Y2-Y1 &&
					rx2>=0 && rx2<X2-X1 && ry2>=0 && ry2<Y2-Y1 &&
					x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
//					Buff=*(data1+rx+ry*AddPitch1);

					// 4点の色を合成します。
					Buff.Buff = *(data1+rx1+ry1*AddPitch1);
					if (Buff.Buff==0x00000000) Buff.Buff=*(data2+x+y*AddPitch2);
//					R =(Buff>>ShiftR)&BitR;
//					G =(Buff>>ShiftG)&BitG;
//					B =(Buff>>ShiftB)&BitB;
					R =Buff.BuffRGB[RGB_R];
					G =Buff.BuffRGB[RGB_G];
					B =Buff.BuffRGB[RGB_B];

//					Buff = *(data1+rx1+ry2*AddPitch1);
//					if (Buff==0x00000000) Buff=*(data2+x+y*AddPitch2);
					Buff.Buff = *(data1+rx1+ry2*AddPitch1);
					if (Buff.Buff==0x00000000) Buff.Buff=*(data2+x+y*AddPitch2);
//					R+=(Buff>>ShiftR)&BitR;
//					G+=(Buff>>ShiftG)&BitG;
//					B+=(Buff>>ShiftB)&BitB;
					R+=Buff.BuffRGB[RGB_R];
					G+=Buff.BuffRGB[RGB_G];
					B+=Buff.BuffRGB[RGB_B];

//					Buff = *(data1+rx2+ry1*AddPitch1);
//					if (Buff==0x00000000) Buff=*(data2+x+y*AddPitch2);
					Buff.Buff = *(data1+rx2+ry1*AddPitch1);
					if (Buff.Buff==0x00000000) Buff.Buff=*(data2+x+y*AddPitch2);
//					R+=(Buff>>ShiftR)&BitR;
//					G+=(Buff>>ShiftG)&BitG;
//					B+=(Buff>>ShiftB)&BitB;
					R+=Buff.BuffRGB[RGB_R];
					G+=Buff.BuffRGB[RGB_G];
					B+=Buff.BuffRGB[RGB_B];

//					Buff = *(data1+rx2+ry2*AddPitch1);
//					if (Buff==0x00000000) Buff=*(data2+x+y*AddPitch2);
					Buff.Buff = *(data1+rx2+ry2*AddPitch1);
					if (Buff.Buff==0x00000000) Buff.Buff=*(data2+x+y*AddPitch2);
//					R+=(Buff>>ShiftR)&BitR;
//					G+=(Buff>>ShiftG)&BitG;
//					B+=(Buff>>ShiftB)&BitB;
					R+=Buff.BuffRGB[RGB_R];
					G+=Buff.BuffRGB[RGB_G];
					B+=Buff.BuffRGB[RGB_B];

//					Buff=((R/4)<<ShiftR)|((G/4)<<ShiftG)|((B/4)<<ShiftB);
					Buff.BuffRGB[RGB_R]=R/4;
					Buff.BuffRGB[RGB_G]=G/4;
					Buff.BuffRGB[RGB_B]=B/4;
//					if (Buff!=*(data2+x+y*AddPitch2)) *(data2+x+y*AddPitch2)=Buff;//
					if (Buff.Buff!=*(data2+x+y*AddPitch2)) *(data2+x+y*AddPitch2)=Buff.Buff;//
				}

//				tx2+=RotateData[Angle+90];
//				ty2+=RotateData[Angle];
				tx2+=elDraw::RotateData[Angle+90];
				ty2+=elDraw::RotateData[Angle   ];
			}

			tx1-=elDraw::RotateData[Angle   ];
			ty1+=elDraw::RotateData[Angle+90];
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 回転 )                              ※ ハイカラー専用  -*/
/*-                                                                            -*/
/*-    int Px1     : 描画左上Ｘ座標                                            -*/
/*-    int Py1     : 描画左上Ｙ座標                                            -*/
/*-    int Px2     : 描画右下Ｘ座標                                            -*/
/*-    int Py2     : 描画右下Ｙ座標                                            -*/
/*-    int Angle   : 回転角度 ( 反時計回り )                                   -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::RotateLayerEx16(int Px1,int Py1,int Px2,int Py2,int Angle,
						 DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static int x,y,cx1,cy1,cx2,cy2,rx1,rx2,ry1,ry2,tx1,tx2,ty1,ty2;
	static int Sx,Sy,Ex,Ey;
	static unsigned int Buff,R,G,B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=Px2-Px1;
	Ey=Py2-Py1;

	if (Px1+Ex>Vx2)
	{
		Ex-=(Px1+Ex-Vx2);
	}

	if (Py1+Ey>Vy2)
	{
		Ey-=(Py1+Ey-Vy2);
	}

	if (Px1<Vx1)
	{
		Sx+=(Vx1-Px1);
	}

	if (Py1<Vy1)
	{
		Sy+=(Vy1-Py1);
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// 回転の中心点を取得
		cx1=(Px2-Px1)/2;
		cy1=(Py2-Py1)/2;
		cx2=((Px2-Px1)-(X2-X1))/2;
		cy2=((Py2-Py1)-(Y2-Y1))/2;
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle   ];
		ty1=cy1*360-cx1*elDraw::RotateData[Angle   ]-cy1*elDraw::RotateData[Angle+90];

		for (y=0;y<Py2-Py1;y++)
		{
			tx2=tx1;
			ty2=ty1;

			for (x=0;x<Px2-Px1;x++)
			{
				rx1=(tx2-elDraw::RotateData[Angle+90]/4)/360-cx2;
				rx2=(tx2+elDraw::RotateData[Angle+90]/4)/360-cx2;
				ry1=(ty2-elDraw::RotateData[Angle   ]/4)/360-cy2;
				ry2=(ty2+elDraw::RotateData[Angle   ]/4)/360-cy2;

				if (rx1>=0 && rx1<X2-X1 && ry1>=0 && ry1<Y2-Y1 &&
				rx2>=0 && rx2<X2-X1 && ry2>=0 && ry2<Y2-Y1 &&
				x>=Sx && x<Ex && y>=Sy && y<Ey)
				{
//					Buff=*(data1+rx+ry*AddPitch1);

					// 4点の色を合成します。
					Buff = *(data1+rx1+ry1*AddPitch1);
					if (Buff==0x0000) Buff=*(data2+x+y*AddPitch2);
					R =(Buff>>ShiftR)&BitR;
					G =(Buff>>ShiftG)&BitG;
					B =(Buff>>ShiftB)&BitB;

					Buff = *(data1+rx1+ry2*AddPitch1);
					if (Buff==0x0000) Buff=*(data2+x+y*AddPitch2);
					R+=(Buff>>ShiftR)&BitR;
					G+=(Buff>>ShiftG)&BitG;
					B+=(Buff>>ShiftB)&BitB;

					Buff = *(data1+rx2+ry1*AddPitch1);
					if (Buff==0x0000) Buff=*(data2+x+y*AddPitch2);
					R+=(Buff>>ShiftR)&BitR;
					G+=(Buff>>ShiftG)&BitG;
					B+=(Buff>>ShiftB)&BitB;

					Buff = *(data1+rx2+ry2*AddPitch1);
					if (Buff==0x0000) Buff=*(data2+x+y*AddPitch2);
					R+=(Buff>>ShiftR)&BitR;
					G+=(Buff>>ShiftG)&BitG;
					B+=(Buff>>ShiftB)&BitB;

					Buff=((R/4)<<ShiftR)|((G/4)<<ShiftG)|((B/4)<<ShiftB);

					if (Buff!=(UINT)*(data2+x+y*AddPitch2)) *(data2+x+y*AddPitch2)=Buff;//
				}

				tx2+=elDraw::RotateData[Angle+90];
				ty2+=elDraw::RotateData[Angle   ];
			}

			tx1-=elDraw::RotateData[Angle   ];
			ty1+=elDraw::RotateData[Angle+90];
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 独自拡張・シャドー部の切り捨て )        ※ フルカラー  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Limit   : しきい値 ( 0 ～ 255 )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::LimitLayer(int Px,int Py,int Limit,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	if (elSystem::ColorBit()<24) return elDraw32::LimitLayer16(Px,Py,Limit,ObjDD,X1,Y1,X2,Y2);

	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
//	static LPWORD data1,data2;
	static LPDWORD data1,data2;//
	static long AddPitch1,AddPitch2;
	static int x,y,Sx,Sy,Ex,Ey;
//	static unsigned int Buff,R1,G1,B1,R2,G2,B2;
	static unsigned int R1,G1,B1,R2,G2,B2;

	static union elDraw32::Buff32 Buff;
	static int RGB_R,RGB_G,RGB_B;//

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+(Ex-Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+(Ey-Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGBのフォーマットによってアクセスするアドレスを変える //
		if (MaskR==0xff0000)
		{
			RGB_R=2;
			RGB_G=1;
			RGB_B=0;
		}
		else
		{
			RGB_R=0;
			RGB_G=1;
			RGB_B=2;
		}

		// Ｙ方向への追加バイト数の取得
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// スプライトの先頭位置を取得
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
//				Buff=*(data1+x);
				Buff.Buff=*(data1+x);//

				if (Buff.Buff!=0x00000000)//
				{
					if ((Buff.BuffRGB[RGB_R]>Limit)||
						(Buff.BuffRGB[RGB_G]>Limit)||
						(Buff.BuffRGB[RGB_B]>Limit))
					{
						*(data2+x)=Buff.Buff;
					}

				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  スプライトの描画 ( 独自拡張・シャドー部の切り捨て )    ※ ハイカラー専用  -*/
/*-                                                                            -*/
/*-    int Px      : 描画Ｘ座標                                                -*/
/*-    int Py      : 描画Ｙ座標                                                -*/
/*-    int Limit   : しきい値 ( 0 ～ 255 )                                     -*/
/*-    DDOBJ ObjDD : スプライト情報                                            -*/
/*-    int X1      : スプライト左上Ｘ座標                                      -*/
/*-    int Y1      : スプライト左上Ｙ座標                                      -*/
/*-    int X2      : スプライト右下Ｘ座標                                      -*/
/*-    int Y2      : スプライト右下Ｙ座標                                      -*/
/*-                                                                            -*/
/*-    戻り値      : TRUE  = 正常終了                                          -*/
/*-                : FALSE = エラー発生                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::LimitLayer16(int Px,int Py,int Limit,DDOBJ ObjDD,int X1,int Y1,int X2,int Y2)
{
	static HRESULT ddret;
	static DDSURFACEDESC ddsd1,ddsd2;
	static LPWORD data1,data2;
	static long AddPitch1,AddPitch2;
	static int x,y,Sx,Sy,Ex,Ey;
	static unsigned int Buff,R,G,B;

	// 描画領域の計算
	Sx=0;
	Sy=0;
	Ex=X2-X1;
	Ey=Y2-Y1;

	if (Px+(Ex-Sx)>Vx2)
	{
		Ex-=(Px+(Ex-Sx)-Vx2);
	}

	if (Py+(Ey-Sy)>Vy2)
	{
		Ey-=(Py+(Ey-Sy)-Vy2);
	}

	if (Px<Vx1)
	{
		X1+=(Vx1-Px);
		Ex-=(Vx1-Px);
		Px=Vx1;
	}

	if (Py<Vy1)
	{
		Y1+=(Vy1-Py);
		Ey-=(Vy1-Py);
		Py=Vy1;
	}

	// 描画できる場合
	if (Ex>=Sx && Ey>=Sy)
	{
		// 構造体の初期化
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// スプライトのロック
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// 画面スプライトのロック
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// Ｙ方向への追加バイト数の取得
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// スプライトの先頭位置を取得
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// 8ビット->5ビットにする
		Limit>>=3;

		// データ転送
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				Buff=*(data1+x);

				if (Buff!=0x0000)
				{
					if ((GetRGB[Buff].r>Limit)||
						(GetRGB[Buff].g>Limit)||
						(GetRGB[Buff].b>Limit))
					{
						*(data2+x)=Buff;
					}
				}
			}

			// Ｙ方向に加算
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// スプライトのロック解除
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}


/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  変数の置き換え（元へ戻す）                             ※ elDraw32で使用  -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

#undef Vx1
#undef Vy1
#undef Vx2
#undef Vy2

#undef MaskR
#undef MaskG
#undef MaskB
#undef MaskRGB
#undef BitR
#undef BitG
#undef BitB
#undef ShiftR
#undef ShiftG
#undef ShiftB
#undef ShiftR2
#undef ShiftG2
#undef ShiftB2
#undef BlendList


// MMXをコンパイルした時の警告表示回避を元に戻す
#pragma warning( default : 4799 )


