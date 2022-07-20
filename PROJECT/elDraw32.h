// 2000.6.18
// �t���J���[�� elDraw
// ���t�@�C�� = el.h (1999.11.22)

// Borland C++ Builder,Borland C++ Compiler�ŃR���p�C������ۂɂ�
// ���̃t�@�C�����C���N���[�h����O�� #define BCC �Ə����K�v������܂��B

// �ŐV�ł͂����� http://www.ky.xaxon.ne.jp/~hitoshi/index.htm
// ��������܂����� ������܂�  hitoshi@ky.xaxon.ne.jp �i���� �ρj


// DirectX7�ȍ~�̐V�����R�[�h
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


// MMX���R���p�C���������̌x���\������ielDraw32.h�̍Ō�Ō��ɖ߂��Ă��܂��j
#pragma warning( disable : 4799 )


class elDraw32
{
	public:

	static void  Init(void);

	static BOOL  MMX_CHECK(void); // �l�l�w�����邩�ǂ��� �`�F�b�N������֐�
	static BOOL  MMX_CHECKED;     // �l�l�w�����邩�ǂ��� �`�F�b�N�������� �̃t���O
	static BOOL  USE_MMX;         // �l�l�w���g�����ǂ����̃t���O

	static void  ColorFill(int,int,int,int,COLORREF);
	static BOOL  ColorBlend(int,int,int,int,COLORREF);
	static BOOL  MirrorLayer(int,int,int,DDOBJ,int,int,int,int);

	static BOOL  BlendLayer(int,int,DDOBJ,int,int,int,int);
	static BOOL  BlendLayer(int,int,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  BlendLayer(int,int,float,float,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
//	static BOOL  BlendLayer(int,int,int,DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,int,int,int,DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,float,float,float,int,int,int,
//							DDOBJ,int,int,int,int);
//	static BOOL  BlendLayer(int,int,int,int,int,int,int,int,
//							DDOBJ,int,int,int,int);
	static BOOL  AddBlendLayer(int,int,DDOBJ,int,int,int,int); //�iMMX�Ή��j
//	static BOOL  AddBlendLayer(int,int,float,DDOBJ,int,int,int,int);
	static BOOL  DelBlendLayer(int,int,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  EdgeBlendLayer(int,int,DDOBJ,int,int,int,int);
	static BOOL  PlainLayer(int,int,BOOL,BOOL,BOOL,DDOBJ,int,int,int,int);
	static BOOL  BrightLayer(int,int,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  BrightLayer(int,int,float,float,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
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
//	static void  CreateTunnel(int,int,int,int,int,int,int,int,int,int);    // 32�r�b�g�� �K�v�Ȃ�
	static BOOL  TunnelLayer(int,int,int,int,DDOBJ);
	static BOOL  LightLayer(int,int,int,int,int,WORD,BOOL,DDOBJ,int,int,int,int);

	// �n�C�J���[�EMMX�Ή��ŁielDraw32�̓����Ŏg�p�j
	static BOOL  BlendLayer16MMX(int,int,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  BlendLayer16MMX(int,int,float,float,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  BrightLayer16MMX(int,int,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j
	static BOOL  BrightLayer16MMX(int,int,float,float,float,DDOBJ,int,int,int,int); //�iMMX�Ή��j

	// �ȉ��̂T�� ����el�ɂ͂���܂���(�Ǝ��g����)
	static BOOL  DelBlendLayerEx(int,int,DDOBJ,int,int,int,int);           // �q�f�a���g�������Z�u�����h�iMMX�Ή��j
	static BOOL  GrayLayerEx(int,int,DDOBJ,int,int,int,int);               // (R+G+B)/3 �ł͂Ȃ��O���[�X�P�[��
	static BOOL  RotateLayerEx(int,int,int,int,int,DDOBJ,int,int,int,int); // ��]�{�A���`�G�C���A�X�E�ق����[�����
//	static BOOL  ShiftLayerEx(int,int,int,float,DDOBJ,int,int,int,int);    // �p�x�w��t���s�N�Z���V�t�g
	static BOOL  LimitLayer(int,int,int,DDOBJ,int,int,int,int);            // �V���h�[����؂�̂Ăĕ`��

	// �Ǝ��g���ł̃n�C�J���[�ŁielDraw32�̓����Ŏg�p�j
	static BOOL  DelBlendLayerEx16(int,int,DDOBJ,int,int,int,int);           // �q�f�a���g�������Z�u�����h
	static BOOL  GrayLayerEx16(int,int,DDOBJ,int,int,int,int);               // (R+G+B)/3 �ł͂Ȃ��O���[�X�P�[��
	static BOOL  RotateLayerEx16(int,int,int,int,int,DDOBJ,int,int,int,int); // ��]�{�A���`�G�C���A�X�E�ق����[�����
//	static BOOL  ShiftLayerEx16(int,int,int,float,DDOBJ,int,int,int,int);    // �p�x�w��t���s�N�Z���V�t�g
	static BOOL  LimitLayer16(int,int,int,DDOBJ,int,int,int,int);            // �V���h�[����؂�̂Ăĕ`��

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

// ���X�g���
BOOL elDraw32::Initialized=FALSE;
//unsigned short elDraw::BlendList[3*32*32*32];
unsigned char elDraw32::AddBlendList[512];
unsigned char elDraw32::DelBlendList[256*256];
unsigned char elDraw32::GrayList[256+256+256];
unsigned char elDraw32::GrayListExR[256];
unsigned char elDraw32::GrayListExG[256];
unsigned char elDraw32::GrayListExB[256];


// MMX�`�F�b�N�p�t���O
BOOL  elDraw32::MMX_CHECKED=FALSE;     // �l�l�w�����邩�ǂ��� �`�F�b�N�������� �̃t���O
BOOL  elDraw32::USE_MMX=FALSE;         // �l�l�w���g�����ǂ����̃t���O

// VC++�ɂ͂Ȃ� �C�����C���A�Z���u���̖���(MMX�p)
#ifndef BCC
#define CPUID\
	_asm _emit 0x0f\
	_asm _emit 0xa2

#define EMMS\
	_asm _emit 0x0f\
	_asm _emit 0x77
#endif // #ifndef BCC

// BCB Learning Edition �� Borland C++ Compiler5.5�p
// �w�C���e���E�A�[�L�e�N�`���E�\�t�g�E�F�A�E�f�B�x���b�p�[�Y�E�}�j���A�� �����x���Q��
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

// �������ʒu�̕\���ɂ́A�A�h���X�ABP����̂P�o�C�g�l�̃I�t�Z�b�g�ABP����̂S�o�C�g�l�̃I�t�Z�b�g�A���W�X�^�l�A������܂��B
// �����ł́A�A�h���X��O��Ƃ��Ă��܂��B
// ���̂��߁A�ϐ�mem�͉����ʒu�ɂ��邩�Astatic�Ő錾���Ă����Ȃ���΂����܂���B
// ��F
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
/*-  ���b�N�A�b�v�e�[�u���̍쐬                             �� elDraw32�Ŏg�p  -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

void elDraw32::Init(void)
{
	int i,j;
	unsigned char x;

		// �t���J���[�p �u�����h�������ʃ��X�g�̍쐬
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
	// �t���J���[�p ���Z�u�����h�������ʃ��X�g�̍쐬
	for (i=0;i<256;i++)
	{
		elDraw32::AddBlendList[i]=i;
		elDraw32::AddBlendList[i+256]=0xff;
	}

	// �t���J���[�p ���Z�u�����h�������ʃ��X�g�̍쐬
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

	// �O���[�X�P�[���v�Z���ʃ��X�g�̍쐬
	for (i=0;i<256*3;i++)
	{
		elDraw32::GrayList[i]=(unsigned int)((double)i/(double)3);
	}

	// �O���[�X�P�[���v�Z���ʃ��X�g�̍쐬�i�Ǝ��g���� �p�j
	for (i=0;i<256;i++)
	{
		// �����̎��� 1999.10������ �����b�}�K�W�����Q�l�ɂ��܂����B
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
/*-  �l�l�w�̌��o                                                              -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

BOOL elDraw32::MMX_CHECK(void)
{
	static bool _CPUID;      // CPUID���g�p�ł��邩�ǂ���
	static int FeatureFlags; // ���o���Ɏg�p

	// CPUID�̌��o
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

	if (!_CPUID) // CPUID ���T�|�[�g����Ă��Ȃ� (==80386�ȉ��Ȃ̂łl�l�w���Ȃ�)
	{
		elDraw32::MMX_CHECKED=TRUE;
		elDraw32::USE_MMX=FALSE;
		return FALSE;
	}

	// �l�l�w�̌��o
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

	// �l�l�w�����邩�ǂ����`�F�b�N�ł��Ȃ������ꍇ
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

		// �l�l�w�����o���ꂽ�ꍇ
		if (FeatureFlags&0x00800000)
		{
			MMX_CHECKED=TRUE;
			USE_MMX=TRUE;
		}
		// �l�l�w�����o����Ȃ������ꍇ
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
/*-  �w�肳�ꂽ�̈��C�ӂ̐F�ŏ�����                                          -*/
/*-                                                                            -*/
/*-    int X1         : ����w���W                                             -*/
/*-    int Y1         : ����x���W                                             -*/
/*-    int X2         : �E���w���W                                             -*/
/*-    int Y2         : �E���x���W                                             -*/
/*-    COLORREF Color : �F ( RGB(��,��,��)�Ŏw�� )                             -*/
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
/*-  �J���[�u�����h ( 50% )                                     �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int X1         : ����w���W                                             -*/
/*-    int Y1         : ����x���W                                             -*/
/*-    int X2         : �E���w���W                                             -*/
/*-    int Y2         : �E���x���W                                             -*/
/*-    COLORREF Color : �F ( RGB(��,��,��)�Ŏw�� )                             -*/
/*-                                                                            -*/
/*-    �߂�l     : TRUE  = ����I��                                           -*/
/*-               : FALSE = �G���[����                                         -*/
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

	// �`��̈�̌v�Z
	if (X2>elDraw::Vx2) X2-=X2-elDraw::Vx2;
	if (Y2>elDraw::Vy2) Y2-=Y2-elDraw::Vy2;
	if (X1<elDraw::Vx1) X1=elDraw::Vx1;
	if (Y1<elDraw::Vy1) Y1=elDraw::Vy1;

	// �`��ł���ꍇ
	if (X2>=X1 && Y2>=Y1)
	{
		// �\���̂̏�����
		memset(&ddsd,0x00,sizeof(DDSURFACEDESC));
		ddsd.dwSize=sizeof(DDSURFACEDESC);

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch=ddsd.lPitch>>1;
		AddPitch=ddsd.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data=(LPWORD)ddsd.lpSurface+Y1*AddPitch;
		data=(LPDWORD)ddsd.lpSurface+Y1*AddPitch;//

		// Color�̕ϊ��ielDraw32�ɂĕt�������j//
		Color=	GetRValue(Color)<<elDraw::ShiftR| //
				GetGValue(Color)<<elDraw::ShiftG| //
				GetBValue(Color)<<elDraw::ShiftB; //

		// �F����50%��
		Buff2=Color>>1;
		Buff2&=elDraw::MaskRGB;

		// �f�[�^�]��
		for (y=Y1;y<Y2;y++)
		{
			for (x=X1;x<X2;x++)
			{
				Buff=*(data+x);

				Buff>>=1;
				Buff&=elDraw::MaskRGB;

				*(data+x)=Buff+Buff2;
			}

			// �x�����ɉ��Z
			data+=AddPitch;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(DDBack,ddsd.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  ������Ȍ�� �ϐ��̒u������                          �� elDraw32�Ŏg�p  -*/
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
/*-  �X�v���C�g�̕`�� ( ���] )                                                 -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Mirror  : ���]�^�C�v                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

// ���]�^�C�v
//static const int NORMAL=0;    // ���]�Ȃ�
//static const int MIRROR_X=1;  // ���E���]
//static const int MIRROR_Y=2;  // �㉺���]
//static const int MIRROR_XY=3; // �㉺���E���]

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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		if (Mirror==NORMAL)
		{
			// �X�v���C�g�̐擪�ʒu���擾
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px2+Py2*AddPitch2;//

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_X)
		{
			// �X�v���C�g�̐擪�ʒu���擾
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

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_Y)
		{
			// �X�v���C�g�̐擪�ʒu���擾
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

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1-=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mirror==MIRROR_XY)
		{
			// �X�v���C�g�̐擪�ʒu���擾
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

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1-=AddPitch1;
				data2+=AddPitch2;
			}
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( 50%�u�����h )                           �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �l�w��u�����h )                        �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    float Blend : ������ ( 0.0 �` 1.0 )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς���
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �u�����h�l�̎Z�o
		Bd=F(1)-Blend;

		// �f�[�^�]��
		// �l�l�w���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // �l�l�w���g��Ȃ��ꍇ �����܂�
		// �l�l�w���g���ꍇ
		else
		{
		static unsigned __int32 Blend32;
		static unsigned __int32 Bd32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // �l�l�w���g�����̃o�b�t�@ Src�͓]����
		static unsigned __int32 BuffDest1; // Dest�͓]����

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Blend32=((unsigned __int32)((float)0x7fff*(float)Blend));	// �u�����h�l�𐮐��ɂ���
		Bd32=((unsigned __int32)((float)0x7fff*(float)Bd));			// �u�����h�l�𐮐��ɂ���

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movd mm2,Blend32			// mm2���W�X�^�ɓ]�����̃u�����h�l������
			_asm punpcklwd mm2,Blend32		// mm2���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			_asm punpckldq mm2,mm2			// mm2���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			_asm movd mm3,Bd32				// mm3���W�X�^�ɓ]����̃u�����h�l������
			_asm punpcklwd mm3,Bd32			// mm3���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			_asm punpckldq mm3,mm3			// mm3���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			_asm pxor mm7,mm7				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE				// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend32)		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			PUNPCKLWD_mm_mem(mm2,Blend32)	// mm2���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			PUNPCKLDQ_mm_mm(mm2,mm2)		// mm2���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			MOVD_mm_mem(mm3,Bd32)			// mm3���W�X�^�ɓ]����̃u�����h�l������
			PUNPCKLWD_mm_mem(mm3,Bd32)		// mm3���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			PUNPCKLDQ_mm_mm(mm3,mm3)		// mm3���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��

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
						movd mm0,BuffSrc1	// mm0���W�X�^��  0-31�r�b�g�� BuffSrc1������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						movd mm1,BuffDest1	// mm1���W�X�^��  0-31�r�b�g�� BuffDest1������
						punpcklbw mm1,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm1,mm1		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm1,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm1,mm3		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						paddusw mm0,mm1		// mm0���W�X�^�� mm1���W�X�^�𑫂�
						pand mm0,mm5		// �}�X�N������
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd BuffDest1,mm0	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,BuffSrc1)	// mm0���W�X�^��  0-31�r�b�g�� BuffSrc1������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						MOVD_mm_mem(mm1,BuffDest1)	// mm1���W�X�^��  0-31�r�b�g�� BuffDest1������
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm1,mm1)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm1,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm1,mm3)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						PADDUSW_mm_mm(mm0,mm1)		// mm0���W�X�^�� mm1���W�X�^�𑫂�
						PAND_mm_mm(mm0,mm5)			// �}�X�N������
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(BuffDest1,mm0)	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC
					*(data2+x)=BuffDest1;
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB�l�w��u�����h )                     �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px       : �`��w���W                                               -*/
/*-    int Py       : �`��x���W                                               -*/
/*-    float BlendR : �Ԃ̍����� ( 0.0 �` 1.0 )                                -*/
/*-    float BlendG : �΂̍����� ( 0.0 �` 1.0 )                                -*/
/*-    float BlendB : �̍����� ( 0.0 �` 1.0 )                                -*/
/*-    DDOBJ ObjDD  : �X�v���C�g���                                           -*/
/*-    int X1       : �X�v���C�g����w���W                                     -*/
/*-    int Y1       : �X�v���C�g����x���W                                     -*/
/*-    int X2       : �X�v���C�g�E���w���W                                     -*/
/*-    int Y2       : �X�v���C�g�E���x���W                                     -*/
/*-                                                                            -*/
/*-    �߂�l       : TRUE  = ����I��                                         -*/
/*-                 : FALSE = �G���[����                                       -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς���
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �u�����h�l�̎Z�o
		BdR=F(1)-BlendR;
		BdG=F(1)-BlendG;
		BdB=F(1)-BlendB;

		// �f�[�^�]��
		// �l�l�w���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // �l�l�w���g��Ȃ��ꍇ �����܂�
		// �l�l�w���g���ꍇ
		else
		{
		static unsigned __int32 Blend32R,Blend32G,Blend32B;
		static unsigned __int32 Bd32R,Bd32G,Bd32B;
		static unsigned __int64 Blend64,Bd64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // �l�l�w���g�����̃o�b�t�@ Src�͓]����
		static unsigned __int32 BuffDest1; // Dest�͓]����

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Blend32R=((unsigned __int32)((float)0x7fff*(float)BlendR));				// �u�����h�l�𐮐��ɂ���
		Blend32G=((unsigned __int32)((float)0x7fff*(float)BlendG));				// �u�����h�l�𐮐��ɂ���
		Blend32B=((unsigned __int32)((float)0x7fff*(float)BlendB));				// �u�����h�l�𐮐��ɂ���
		Blend64=(unsigned __int64)Blend32R<<(RGB_R*16)|(unsigned __int64)Blend32G<<(RGB_G*16)|(unsigned __int64)Blend32B<<(RGB_B*16);	// �u�����h�l��64�r�b�g�ɓ����
		Bd32R=((unsigned __int32)((float)0x7fff*(float)BdR));					// �u�����h�l�𐮐��ɂ���
		Bd32G=((unsigned __int32)((float)0x7fff*(float)BdG));					// �u�����h�l�𐮐��ɂ���
		Bd32B=((unsigned __int32)((float)0x7fff*(float)BdB));					// �u�����h�l�𐮐��ɂ���
		Bd64=(unsigned __int64)Bd32R<<(RGB_R*16)|(unsigned __int64)Bd32G<<(RGB_G*16)|(unsigned __int64)Bd32B<<(RGB_B*16);				// �u�����h�l��64�r�b�g�ɓ����

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movq mm2,Blend64		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			_asm movq mm3,Bd64			// mm3���W�X�^�ɓ]����̃u�����h�l������
			_asm pxor mm7,mm7			// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;		// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend64)		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			MOVQ_mm_mem(mm3,Bd64)			// mm3���W�X�^�ɓ]����̃u�����h�l������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,BuffSrc1	// mm0���W�X�^��  0-31�r�b�g�� BuffSrc1������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						movd mm1,BuffDest1	// mm1���W�X�^��  0-31�r�b�g�� BuffDest1������
						punpcklbw mm1,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm1,mm1		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm1,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm1,mm3		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						paddusw mm0,mm1		// mm0���W�X�^�� mm1���W�X�^�𑫂�
						pand mm0,mm5		// �}�X�N������
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd BuffDest1,mm0	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,BuffSrc1)	// mm0���W�X�^��  0-31�r�b�g�� BuffSrc1������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						MOVD_mm_mem(mm1,BuffDest1)	// mm1���W�X�^��  0-31�r�b�g�� BuffDest1������
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm1,mm1)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm1,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm1,mm3)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						PADDUSW_mm_mm(mm0,mm1)		// mm0���W�X�^�� mm1���W�X�^�𑫂�
						PAND_mm_mm(mm0,mm5)			// �}�X�N������
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(BuffDest1,mm0)	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC
					*(data2+x)=BuffDest1;
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �l�w��u�����h / �ʓx�䗦���� )         �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Blend   : ������ ( 0 �` 31 )                                        -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/
/* �܂��l�����E�E
// �u�����h���X�g�A�ǂ����悤�H

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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �u�����h�l�̎Z�o
		Bd=(31-Blend)<<10;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}
*/

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���Z�u�����h )                          �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς���
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
		//�l�l�w���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // �l�l�w���g��Ȃ��ꍇ �����܂�
		//�l�l�w���g���ꍇ
		else
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int64 BuffSrc;
		static unsigned __int64 BuffDest;

		MaskBit64=0x0000000000ffffff;	//�}�X�N�p�f�[�^
		#ifndef BCC
			_asm movq mm7,MaskBit64
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64)
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,BuffSrc		// mm0���W�X�^��  0-31�r�b�g�� BuffSrc������
						movd mm1,BuffDest		// mm1���W�X�^��  0-31�r�b�g�� BuffDest������

						paddusb mm0,mm1			// �T�`�����[�V����(�O�a)�t���� mm0=mm0+mm1 �� ���Z������(�W�r�b�g���E�Aunsigned)
						pand mm0,mm7			// �O�̂��߃}�X�N������

						movd BuffDest,mm0		// BuffDest�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else
						MOVD_mm_mem(mm0,BuffSrc)		// mm0���W�X�^��  0-31�r�b�g�� BuffSrc������
						MOVD_mm_mem(mm1,BuffDest)		// mm1���W�X�^��  0-31�r�b�g�� BuffDest������

						PADDUSB_mm_mm(mm0,mm1)			// �T�`�����[�V����(�O�a)�t���� mm0=mm0+mm1 �� ���Z������(�W�r�b�g���E�Aunsigned)
						PAND_mm_mm(mm0,mm7)				// �O�̂��߃}�X�N������

						MOVD_mem_mm(BuffDest,mm0)		// BuffDest�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC
					*(data2+x)=(unsigned long)BuffDest;
				}
			}

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS // EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���Z�l�w��u�����h )                �� �n�C�J���[��p  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    float Blend : ������ ( 0.0 �` 1.0 )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �u�����h�l�̎Z�o
		Bd=((int)(F(31)-Blend*F(31)))<<10;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}
*/

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���Z�u�����h )                          �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς���
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
		if (!elDraw32::USE_MMX) // MMX���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMX���g��Ȃ��ꍇ�����܂�
		else //�l�l�w���g���ꍇ
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1; //�l�l�w���g�����̃o�b�t�@�Src�͓]����
		static unsigned __int32 BuffDest1;//Dest�͓]����

		MaskBit64=0x0000000000ffffff;	//�}�X�N�p�f�[�^
		#ifndef BCC
			_asm movq mm7,MaskBit64 // mm7���W�X�^�Ƀ}�X�N�p�f�[�^������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64) // mm7���W�X�^�Ƀ}�X�N�p�f�[�^������
		#endif // #ifndef BCC

		// �f�[�^�]��
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1!=0x00000000) //���̏ꍇ�͏������Ȃ�
				{
					// R�l�݂̂Ō��Z
					R1=(BuffSrc1>>ShiftR)&BitR;
					R1=(R1<<16)+(R1<<8)+R1;

					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm1,R1				// mm1���W�X�^��  0-31�r�b�g�� R1������
						movd mm0,BuffDest1		// mm0���W�X�^��  0-31�r�b�g�� BuffDest1������
						psubusb mm0,mm1			// �T�`�����[�V����(�O�a)�t���� mm0=mm0-mm1 �� ���Z������ (�W�r�b�g���E�Aunsigned)
						pand mm0,mm7			// �O�̂��߃}�X�N������
						movd BuffDest1,mm0		// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm1,R1)				// mm1���W�X�^��  0-31�r�b�g�� R1������
						MOVD_mm_mem(mm0,BuffDest1)		// mm0���W�X�^��  0-31�r�b�g�� BuffDest1������
						PSUBUSB_mm_mm(mm0,mm1)			// �T�`�����[�V����(�O�a)�t���� mm0=mm0-mm1 �� ���Z������ (�W�r�b�g���E�Aunsigned)
						PAND_mm_mm(mm0,mm7)				// �O�̂��߃}�X�N������
						MOVD_mem_mm(BuffDest1,mm0)		// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=BuffDest1;
				}
			}

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �G�b�W�u�����h )                        �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς���
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB�v���[�����o )                       �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    BOOL PlainR : �Ԃ̒��o                                                  -*/
/*-    BOOL PlainG : �΂̒��o                                                  -*/
/*-    BOOL PlainB : �̒��o                                                  -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �}�X�N�̍쐬
//		Color=0x0000;
		Color=0x00000000;//
		if (PlainR) Color|=MaskR;
		if (PlainG) Color|=MaskG;
		if (PlainB) Color|=MaskB;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���x���� )                              �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px       : �`��w���W                                               -*/
/*-    int Py       : �`��x���W                                               -*/
/*-    float Bright : ���x ( 0.0 �` 1.0 )                                      -*/
/*-    DDOBJ ObjDD  : �X�v���C�g���                                           -*/
/*-    int X1       : �X�v���C�g����w���W                                     -*/
/*-    int Y1       : �X�v���C�g����x���W                                     -*/
/*-    int X2       : �X�v���C�g�E���w���W                                     -*/
/*-    int Y2       : �X�v���C�g�E���x���W                                     -*/
/*-                                                                            -*/
/*-    �߂�l       : TRUE  = ����I��                                         -*/
/*-                 : FALSE = �G���[����                                       -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
		if (!elDraw32::USE_MMX) // MMX���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMX���g��Ȃ��ꍇ�����܂�
		else //�l�l�w���g���ꍇ
		{
		static unsigned __int32 Bright32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Bright32=((unsigned __int32)((float)0x7fff*(float)Bright));	// ���x�l�𐮐��ɂ���

		EMMS

		#ifndef BCC
			_asm movd mm1,Bright32		// mm1���W�X�^�ɖ��x�l������
			_asm punpcklwd mm1,Bright32	// mm1���W�X�^�� 0-31�r�b�g�ɖ��x�l(�Q��)������
			_asm punpckldq mm1,mm1		// mm1���W�X�^�� 0-63�r�b�g�ɖ��x�l(�S��)������
			_asm pxor mm7,mm7			// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;		// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64		// mm5���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVD_mm_mem(mm1,Bright32)		// mm1���W�X�^�ɖ��x�l������
			PUNPCKLWD_mm_mem(mm1,Bright32)	// mm1���W�X�^�� 0-31�r�b�g�ɖ��x�l(�Q��)������
			PUNPCKLDQ_mm_mm(mm1,mm1)		// mm1���W�X�^�� 0-63�r�b�g�ɖ��x�l(�S��)������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,Buff.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff.Buff������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ������邽��)
						paddw mm0,mm6		// �P�𑫂�(�l�̌ܓ��̂���)

						pmulhw mm0,mm1		// �|���Z(�o�Ă���̂� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)
						pand mm0,mm5		// �}�X�N������
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(mm7�̓_�~�[)

						movd Buff.Buff,mm0	// Buff.Buff�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff.Buff������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ������邽��)
						PADDW_mm_mm(mm0,mm6)		// �P�𑫂�(�l�̌ܓ��̂���)

						PMULHW_mm_mm(mm0,mm1)		// �|���Z(�o�Ă���̂� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)
						PAND_mm_mm(mm0,mm5)			// �}�X�N������
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(mm7�̓_�~�[)

						MOVD_mem_mm(Buff.Buff,mm0)	// Buff.Buff�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=Buff.Buff;
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB���x���� )                           �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px        : �`��w���W                                              -*/
/*-    int Py        : �`��x���W                                              -*/
/*-    float BrightR : �Ԃ̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    float BrightG : �΂̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    float BrightB : �̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    DDOBJ ObjDD   : �X�v���C�g���                                          -*/
/*-    int X1        : �X�v���C�g����w���W                                    -*/
/*-    int Y1        : �X�v���C�g����x���W                                    -*/
/*-    int X2        : �X�v���C�g�E���w���W                                    -*/
/*-    int Y2        : �X�v���C�g�E���x���W                                    -*/
/*-                                                                            -*/
/*-    �߂�l        : TRUE  = ����I��                                        -*/
/*-                  : FALSE = �G���[����                                      -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;
		AddPitch2=ddsd2.lPitch/4;

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
		if (!elDraw32::USE_MMX) // �l�l�w���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // �l�l�w���g��Ȃ��ꍇ �����܂�
		// �l�l�w���g���ꍇ
		else
		{
		static unsigned __int32 Bright32R,Bright32G,Bright32B;
		static unsigned __int64 Bright64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Bright32R=((unsigned __int32)((float)0x7fff*(float)BrightR));				// ���x�l�𐮐��ɂ���
		Bright32G=((unsigned __int32)((float)0x7fff*(float)BrightG));				// ���x�l�𐮐��ɂ���
		Bright32B=((unsigned __int32)((float)0x7fff*(float)BrightB));				// ���x�l�𐮐��ɂ���
		Bright64=(unsigned __int64)Bright32R<<(RGB_R*16)|(unsigned __int64)Bright32G<<(RGB_G*16)|(unsigned __int64)Bright32B<<(RGB_B*16);	// ���x�l��64�r�b�g�ɓ����

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movq mm2,Bright64			// mm2���W�X�^�ɖ��x�l������
			_asm pxor mm7,mm7				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE				// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Bright64)		// mm2���W�X�^�ɖ��x�l������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,Buff.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff.Buff������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						pand mm0,mm5		// �}�X�N������
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd Buff.Buff,mm0	// Buff.Buff�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff.Buff������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						PAND_mm_mm(mm0,mm5)			// �}�X�N������
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(Buff.Buff,mm0)	// Buff.Buff�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=Buff.Buff;
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���x���� / �ʓx�䗦���� )               �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Bright  : ���x ( 0 �` 31 )                                          -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �u���C�g�l�̎Z�o
//		Bt=31-Bright;
		Bt=255-(int)(Bright<<3|Bright>>2);//5��8�r�b�g�Ɋg��

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB���x���� / �ʓx�䗦���� )            �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int BrightR : �Ԃ̖��x ( 0 �` 31 )                                      -*/
/*-    int BrightG : �΂̖��x ( 0 �` 31 )                                      -*/
/*-    int BrightB : �̖��x ( 0 �` 31 )                                      -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �u���C�g�l�̎Z�o
//		BtR=31-BrightR;
//		BtG=31-BrightG;
//		BtB=31-BrightB;
		BtR=255-(int)(BrightR<<3|BrightR>>2);//5��8�r�b�g�Ɋg��
		BtG=255-(int)(BrightG<<3|BrightG>>2);//5��8�r�b�g�Ɋg��
		BtB=255-(int)(BrightB<<3|BrightB>>2);//5��8�r�b�g�Ɋg��

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �ڂ��� )                                �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Shade   : �ڂ����̋��� ( 1 �` )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �ڂ����l�̎Z�o
		Sd=Shade*Shade;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �O���[�X�P�[�� )                        �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���b�V�� )                              �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px        : �`��w���W                                              -*/
/*-    int Py        : �`��x���W                                              -*/
/*-    int WaveSize  : �E�F�[�u�̑傫��                                        -*/
/*-    int WaveCount : �E�F�[�u�̔�����                                        -*/
/*-    int Step      : ���b�V���̍r��                                          -*/
/*-    float Zoom    : ���b�V���̃Y�[��                                        -*/
/*-    float Angle   : ���b�V���̌X��                                          -*/
/*-    DDOBJ ObjDD   : �X�v���C�g���                                          -*/
/*-    int X1        : �X�v���C�g����w���W                                    -*/
/*-    int Y1        : �X�v���C�g����x���W                                    -*/
/*-    int X2        : �X�v���C�g�E���w���W                                    -*/
/*-    int Y2        : �X�v���C�g�E���x���W                                    -*/
/*-                                                                            -*/
/*-    �߂�l        : TRUE  = ����I��                                        -*/
/*-                  : FALSE = �G���[����                                      -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ��] )                                  �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;   //
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4; //

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// ��]�̒��S�_���擾
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �^�C���{��] )                          �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// ��]�̒��S�_���擾
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �g��k���{��] )                        �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    float Zoom  : �g��k������l                                            -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// ��]�̒��S�_���擾
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �^�C���{�g��k���{��] )                �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    float Zoom  : �g��k������l                                            -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// ��]�̒��S�_���擾
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �^�C���{�g��k�����ρ{��] )          �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1          : �`�捶��w���W                                       -*/
/*-    int Py1          : �`�捶��x���W                                       -*/
/*-    int Px2          : �`��E���w���W                                       -*/
/*-    int Py2          : �`��E���x���W                                       -*/
/*-    int Angle        : ��]�p�x ( �����v��� )                              -*/
/*-    float ZoomStartX : �w�����g��k�����̏����l                             -*/
/*-    float ZoomAddX   : �w�����g��k�����̉����l                             -*/
/*-    float ZoomStartY : �x�����g��k�����̏����l                             -*/
/*-    float ZoomAddY   : �x�����g��k�����̉����l                             -*/
/*-    float Red        : �Ԃ̖��x                                             -*/
/*-    float Green      : �΂̖��x                                             -*/
/*-    float Blue       : �̖��x                                             -*/
/*-    DDOBJ ObjDD      : �X�v���C�g���                                       -*/
/*-    int X1           : �X�v���C�g����w���W                                 -*/
/*-    int Y1           : �X�v���C�g����x���W                                 -*/
/*-    int X2           : �X�v���C�g�E���w���W                                 -*/
/*-    int Y2           : �X�v���C�g�E���x���W                                 -*/
/*-                                                                            -*/
/*-    �߂�l           : TRUE  = ����I��                                     -*/
/*-                     : FALSE = �G���[����                                   -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		// ��]�̒��S�_���擾
		cx1=(Px2-Px1)>>1;
		cy1=(Py2-Py1)>>1;
		cx2=((Px2-Px1)-(X2-X1))>>1;
		cy2=((Py2-Py1)-(Y2-Y1))>>1;
//		tx1=cx1*360-cx1*RotateData[Angle+90]+cy1*RotateData[Angle];
//		ty1=cy1*360-cx1*RotateData[Angle]-cy1*RotateData[Angle+90];
		tx1=cx1*360-cx1*elDraw::RotateData[Angle+90]+cy1*elDraw::RotateData[Angle];//
		ty1=cy1*360-cx1*elDraw::RotateData[Angle]-cy1*elDraw::RotateData[Angle+90];//

		// �g�嗦�̏�����
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �s�N�Z���s�b�N                                             �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Mode    : �Q�ƈʒu                                                  -*/
/*-                  PICK_LEFT   = �����P�h�b�g���Q��                          -*/
/*-                  PICK_RIGHT  = �E���P�h�b�g���Q��                          -*/
/*-                  PICK_TOP    = �㑤�P�h�b�g���Q��                          -*/
/*-                  PICK_BOTTOM = �����P�h�b�g���Q��                          -*/
/*-    int Start   : �J�n�ʒu                                                  -*/
/*-                  Mode��PICK_LEFT�܂���PICK_RIGHT = 0 �` X2-1               -*/
/*-                  Mode��PICK_TOP�܂���PICK_BOTTOM = 0 �` Y2-1               -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
/*-                                                                            -*/
/*------------------------------------------------------------------------------*/

// �Q�ƈʒu
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;
		AddPitch2=ddsd2.lPitch>>2;

		if (Mode==PICK_LEFT)
		{
			// �X�v���C�g�̐擪�ʒu���擾
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_RIGHT)
		{
			// �X�v���C�g�̐擪�ʒu���擾
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Py*AddPitch2;//

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data1+=AddPitch1;
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_TOP)
		{
			// �X�v���C�g�̐擪�ʒu���擾
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

			// �f�[�^�]��
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

				// �x�����ɉ��Z
				data2+=AddPitch2;
			}
		}

		if (Mode==PICK_BOTTOM)
		{
			// �X�v���C�g�̐擪�ʒu���擾
//			data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//			data2=(LPWORD)ddsd2.lpSurface+Px;//+Py*AddPitch2;
			data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
			data2=(LPDWORD)ddsd2.lpSurface+Px;//+Py*AddPitch2;//

			// �f�[�^�]��
			for (y=0;y<(UINT)Py;y++)
			{
				for (x=Sx;x<Ex;x++)
				{
					*(data2+x)=*(data1+x+Start*AddPitch1);
				}

				// �x�����ɉ��Z
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

				// �x�����ɉ��Z
				data2+=AddPitch2;
			}
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �s�N�Z���V�t�g                                             �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    float Shift : �V�t�g�� ( 0.0 �` 1.0 )                                   -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �V�t�g�l�̎Z�o
		St=(int)(F(31)-Shift*F(31));

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �g���l�� )                              �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Rotate  : ��] ( 0 �` �X�v���C�g�̂w�T�C�Y )                        -*/
/*-    int Dist    : ���� ( 0 �` �X�v���C�g�̂x�T�C�Y )                        -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �\���̂̏�����
	memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
	ddsd1.dwSize=sizeof(DDSURFACEDESC);
	memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
	ddsd2.dwSize=sizeof(DDSURFACEDESC);

	// �X�v���C�g�̃��b�N
	ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

	if (ddret!=DD_OK)
	{
		return FALSE;
	}

	// ��ʃX�v���C�g�̃��b�N
	ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

	if (ddret!=DD_OK)
	{
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

		return FALSE;
	}

	// �x�����ւ̒ǉ��o�C�g���̎擾
//	AddPitch1=ddsd1.lPitch>>1;
//	AddPitch2=ddsd2.lPitch>>1;
	AddPitch1=ddsd1.lPitch>>2;//
	AddPitch2=ddsd2.lPitch>>2;//

	// �X�v���C�g�̐擪�ʒu���擾
//	data1=(LPWORD)ddsd1.lpSurface;
//	data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
	data1=(LPDWORD)ddsd1.lpSurface;
	data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

	// �f�[�^�]��
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

		// �x�����ɉ��Z
		data2+=AddPitch2;
	}

	// �X�v���C�g�̃��b�N����
	DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
	DD_UNLOCK(DDBack,ddsd2.lpSurface);

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���C�g )                                �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Red     : �Ԃ̌��� ( 0�` )                                          -*/
/*-    int Green   : �΂̌��� ( 0�` )                                          -*/
/*-    int Blue    : �̌��� ( 0�` )                                          -*/
/*-    WORD Dir    : ���̕���                                                  -*/
/*-                  ( CREATE_DIR(����,��,�E��,��,�E,����,��,�E��)�Ŏw�� )     -*/
/*-    BOOL Show   : �X�v���C�g�̕\��                                          -*/
/*-                  TRUE  = �X�v���C�g�ƃ��C�g��\��                          -*/
/*-                  FALSE = ���C�g�̂ݕ\��                                    -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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
						if ((int)(Py+y)-(int)i>Vy1) //�H�Hi>Vy1 �ɂ���ƃA�N�Z�X�ᔽ���Ȃ��Ȃ�Bel.h�̃o�O�H�H
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �l�w��u�����h )               �� �n�C�J���[�EMMX��p  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    float Blend : ������ ( 0.0 �` 1.0 )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �u�����h�l�̎Z�o
		Bd=F(1)-Blend;

		// �f�[�^�]��
		// �l�l�w���g���ꍇ
		static unsigned __int32 Blend32;
		static unsigned __int32 Bd32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1;  // �l�l�w���g�����̃o�b�t�@ Src�͓]����
		static unsigned __int32 BuffDest1; // Dest�͓]����

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Blend32=((unsigned __int32)((float)0x7fff*(float)Blend));	// �u�����h�l�𐮐��ɂ���
		Bd32=((unsigned __int32)((float)0x7fff*(float)Bd));			// �u�����h�l�𐮐��ɂ���

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movd mm2,Blend32			// mm2���W�X�^�ɓ]�����̃u�����h�l������
			_asm punpcklwd mm2,Blend32		// mm2���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			_asm punpckldq mm2,mm2			// mm2���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			_asm movd mm3,Bd32				// mm3���W�X�^�ɓ]����̃u�����h�l������
			_asm punpcklwd mm3,Bd32			// mm3���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			_asm punpckldq mm3,mm3			// mm3���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			_asm pxor mm7,mm7				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE				// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVD_mm_mem(mm2,Blend32)		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			PUNPCKLWD_mm_mem(mm2,Blend32)	// mm2���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			PUNPCKLDQ_mm_mm(mm2,mm2)		// mm2���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			MOVD_mm_mem(mm3,Bd32)			// mm3���W�X�^�ɓ]����̃u�����h�l������
			PUNPCKLWD_mm_mem(mm3,Bd32)		// mm3���W�X�^�� 0-31�r�b�g�Ƀu�����h�l(�v�Q��)������
			PUNPCKLDQ_mm_mm(mm3,mm3)		// mm3���W�X�^�� 0-63�r�b�g�Ƀu�����h�l(�v�S��)������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,Buff1.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff1������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						movd mm1,Buff2.Buff	// mm1���W�X�^��  0-31�r�b�g�� Buff2������
						punpcklbw mm1,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm1,mm1		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm1,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm1,mm3		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						paddusw mm0,mm1		// mm0���W�X�^�� mm1���W�X�^�𑫂�
//						pand mm0,mm5		// �}�X�N������i�K�v�Ȃ��H�j
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd Buff1.Buff,mm0	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff1.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff1������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						MOVD_mm_mem(mm1,Buff2.Buff)	// mm1���W�X�^��  0-31�r�b�g�� Buff2������
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm1,mm1)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm1,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm1,mm3)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						PADDUSW_mm_mm(mm0,mm1)		// mm0���W�X�^�� mm1���W�X�^�𑫂�
//						PAND_mm_mm(mm0,mm5)			// �}�X�N������i�K�v�Ȃ��H�j
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(Buff1.Buff,mm0)	// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=(Buff1.BuffRGB[0]<<ShiftR)|(Buff1.BuffRGB[1]<<ShiftG)|(Buff1.BuffRGB[2]<<ShiftB);
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB�l�w��u�����h )            �� �n�C�J���[�EMMX��p  -*/
/*-                                                                            -*/
/*-    int Px       : �`��w���W                                               -*/
/*-    int Py       : �`��x���W                                               -*/
/*-    float BlendR : �Ԃ̍����� ( 0.0 �` 1.0 )                                -*/
/*-    float BlendG : �΂̍����� ( 0.0 �` 1.0 )                                -*/
/*-    float BlendB : �̍����� ( 0.0 �` 1.0 )                                -*/
/*-    DDOBJ ObjDD  : �X�v���C�g���                                           -*/
/*-    int X1       : �X�v���C�g����w���W                                     -*/
/*-    int Y1       : �X�v���C�g����x���W                                     -*/
/*-    int X2       : �X�v���C�g�E���w���W                                     -*/
/*-    int Y2       : �X�v���C�g�E���x���W                                     -*/
/*-                                                                            -*/
/*-    �߂�l       : TRUE  = ����I��                                         -*/
/*-                 : FALSE = �G���[����                                       -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �u�����h�l�̎Z�o
		BdR=F(1)-BlendR;
		BdG=F(1)-BlendG;
		BdB=F(1)-BlendB;

		// �f�[�^�]��
		// �l�l�w���g���ꍇ
		static unsigned __int32 Blend32R,Blend32G,Blend32B;
		static unsigned __int32 Bd32R,Bd32G,Bd32B;
		static unsigned __int64 Blend64,Bd64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Blend32R=((unsigned __int32)((float)0x7fff*(float)BlendR));				// �u�����h�l�𐮐��ɂ���
		Blend32G=((unsigned __int32)((float)0x7fff*(float)BlendG));				// �u�����h�l�𐮐��ɂ���
		Blend32B=((unsigned __int32)((float)0x7fff*(float)BlendB));				// �u�����h�l�𐮐��ɂ���
		Blend64=(unsigned __int64)Blend32R|(unsigned __int64)Blend32G<<16|(unsigned __int64)Blend32B<<32;	// �u�����h�l��64�r�b�g�ɓ����
		Bd32R=((unsigned __int32)((float)0x7fff*(float)BdR));					// �u�����h�l�𐮐��ɂ���
		Bd32G=((unsigned __int32)((float)0x7fff*(float)BdG));					// �u�����h�l�𐮐��ɂ���
		Bd32B=((unsigned __int32)((float)0x7fff*(float)BdB));					// �u�����h�l�𐮐��ɂ���
		Bd64=(unsigned __int64)Bd32R|(unsigned __int64)Bd32G<<16|(unsigned __int64)Bd32B<<32;				// �u�����h�l��64�r�b�g�ɓ����

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movq mm2,Blend64		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			_asm movq mm3,Bd64			// mm3���W�X�^�ɓ]����̃u�����h�l������
			_asm pxor mm7,mm7			// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;		// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Blend64)		// mm2���W�X�^�ɓ]�����̃u�����h�l������
			MOVQ_mm_mem(mm3,Bd64)			// mm3���W�X�^�ɓ]����̃u�����h�l������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
		#endif // #ifndef BCC

		// �f�[�^�]��
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
						movd mm0,Buff1.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff1.Buff������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						movd mm1,Buff2.Buff	// mm1���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						punpcklbw mm1,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm1,mm1		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm1,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm1,mm3		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						paddusw mm0,mm1		// mm0���W�X�^�� mm1���W�X�^�𑫂�
//						pand mm0,mm5		// �}�X�N������i�K�v�Ȃ��H�j
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd Buff1.Buff,mm0	// Buff1.Buff�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff1.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff1.Buff������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						MOVD_mm_mem(mm1,Buff2.Buff)	// mm1���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						PUNPCKLBW_mm_mm(mm1,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm1,mm1)		// �{�ɂ���(�u�����h�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm1,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm1,mm3)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

						PADDUSW_mm_mm(mm0,mm1)		// mm0���W�X�^�� mm1���W�X�^�𑫂�
//						PAND_mm_mm(mm0,mm5)			// �}�X�N������i�K�v�Ȃ��H�j
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(Buff1.Buff,mm0)	// Buff1.Buff�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=(Buff1.BuffRGB[0]<<ShiftR)|(Buff1.BuffRGB[1]<<ShiftG)|(Buff1.BuffRGB[2]<<ShiftB);
				}
			}
			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ���x���� )                     �� �n�C�J���[�EMMX��p  -*/
/*-                                                                            -*/
/*-    int Px       : �`��w���W                                               -*/
/*-    int Py       : �`��x���W                                               -*/
/*-    float Bright : ���x ( 0.0 �` 1.0 )                                      -*/
/*-    DDOBJ ObjDD  : �X�v���C�g���                                           -*/
/*-    int X1       : �X�v���C�g����w���W                                     -*/
/*-    int Y1       : �X�v���C�g����x���W                                     -*/
/*-    int X2       : �X�v���C�g�E���w���W                                     -*/
/*-    int Y2       : �X�v���C�g�E���x���W                                     -*/
/*-                                                                            -*/
/*-    �߂�l       : TRUE  = ����I��                                         -*/
/*-                 : FALSE = �G���[����                                       -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �f�[�^�]��
		// �l�l�w���g���ꍇ
		static unsigned __int32 Bright32;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Bright32=((unsigned __int32)((float)0x7fff*(float)Bright));	// ���x�l�𐮐��ɂ���

		EMMS

		#ifndef BCC
			_asm movd mm1,Bright32			// mm1���W�X�^�ɖ��x�l������
			_asm punpcklwd mm1,Bright32		// mm1���W�X�^�� 0-31�r�b�g�ɖ��x�l(�Q��)������
			_asm punpckldq mm1,mm1			// mm1���W�X�^�� 0-63�r�b�g�ɖ��x�l(�S��)������
			_asm pxor mm7,mm7				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE				// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5���W�X�^��MaskBit64������
		#else // #ifndef BCC
			MOVD_mm_mem(mm1,Bright32)		// mm1���W�X�^�ɖ��x�l������
			PUNPCKLWD_mm_mem(mm1,Bright32)	// mm1���W�X�^�� 0-31�r�b�g�ɖ��x�l(�Q��)������
			PUNPCKLDQ_mm_mm(mm1,mm1)		// mm1���W�X�^�� 0-63�r�b�g�ɖ��x�l(�S��)������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5���W�X�^��MaskBit64������
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
						movd mm0,Buff2.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ������邽��)
						paddw mm0,mm6		// �P�𑫂�(�l�̌ܓ��̂���)

						pmulhw mm0,mm1		// �|���Z(�o�Ă���̂� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)
//						pand mm0,mm5		// �}�X�N������i�K�v�Ȃ��H�j
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(mm7�̓_�~�[)

						movd Buff2.Buff,mm0	// Buff2.Buff�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff2.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ������邽��)
						PADDW_mm_mm(mm0,mm6)		// �P�𑫂�(�l�̌ܓ��̂���)

						PMULHW_mm_mm(mm0,mm1)		// �|���Z(�o�Ă���̂� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)
//						PAND_mm_mm(mm0,mm5)			// �}�X�N������i�K�v�Ȃ��H�j
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(mm7�̓_�~�[)

						MOVD_mem_mm(Buff2.Buff,mm0)	// Buff2.Buff�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=(Buff2.BuffRGB[0]<<ShiftR)|(Buff2.BuffRGB[1]<<ShiftG)|(Buff2.BuffRGB[2]<<ShiftB);
				}
			}

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( RGB���x���� )                  �� �n�C�J���[�EMMX��p  -*/
/*-                                                                            -*/
/*-    int Px        : �`��w���W                                              -*/
/*-    int Py        : �`��x���W                                              -*/
/*-    float BrightR : �Ԃ̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    float BrightG : �΂̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    float BrightB : �̖��x ( 0.0 �` 1.0 )                                 -*/
/*-    DDOBJ ObjDD   : �X�v���C�g���                                          -*/
/*-    int X1        : �X�v���C�g����w���W                                    -*/
/*-    int Y1        : �X�v���C�g����x���W                                    -*/
/*-    int X2        : �X�v���C�g�E���w���W                                    -*/
/*-    int Y2        : �X�v���C�g�E���x���W                                    -*/
/*-                                                                            -*/
/*-    �߂�l        : TRUE  = ����I��                                        -*/
/*-                  : FALSE = �G���[����                                      -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �f�[�^�]��
		// �l�l�w���g���ꍇ
		static unsigned __int32 Bright32R,Bright32G,Bright32B;
		static unsigned __int64 Bright64;
		static unsigned __int64 ONE;
		static unsigned __int64 MaskBit64;

		//���z���g�� 0x10000 �ɂ������񂾂��ǁA16�r�b�g�ȓ��A�����t���łȂ��Ƃ����Ȃ��̂ŁA��ނȂ����̍ő�l(==0x7fff)���g��
		Bright32R=((unsigned __int32)((float)0x7fff*(float)BrightR));				// ���x�l�𐮐��ɂ���
		Bright32G=((unsigned __int32)((float)0x7fff*(float)BrightG));				// ���x�l�𐮐��ɂ���
		Bright32B=((unsigned __int32)((float)0x7fff*(float)BrightB));				// ���x�l�𐮐��ɂ���
		Bright64=(unsigned __int64)Bright32R|(unsigned __int64)Bright32G<<16|(unsigned __int64)Bright32B<<32;	// ���x�l��64�r�b�g�ɓ����

		EMMS						// ���������_���W�X�^���N���A����

		#ifndef BCC
			_asm movq mm2,Bright64			// mm2���W�X�^�ɖ��x�l������
			_asm pxor mm7,mm7				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			_asm movq mm6,ONE				// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			_asm movq mm5,MaskBit64			// mm5 ���W�X�^�� MaskBit64������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm2,Bright64)		// mm2���W�X�^�ɖ��x�l������
			PXOR_mm_mm(mm7,mm7)				// mm7�� �O�ɃN���A����
			ONE=0x0000000100010001;			// �l�̌ܓ��Ɏg��
			MOVQ_mm_mem(mm6,ONE)			// mm6���W�X�^�� ONE������
			MaskBit64=0x0000ffffffffffff;	// �}�X�N�p�f�[�^
			MOVQ_mm_mem(mm5,MaskBit64)		// mm5 ���W�X�^�� MaskBit64������
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
						movd mm0,Buff2.Buff	// mm0���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						punpcklbw mm0,mm7	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						paddw mm0,mm0		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						paddw mm0,mm6		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						pmulhw mm0,mm2		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

//						pand mm0,mm5		// �}�X�N������i�K�v�Ȃ��H�j
						packuswb mm0,mm7	// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						movd Buff2.Buff,mm0	// Buff2.Buff�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm0,Buff2.Buff)	// mm0���W�X�^��  0-31�r�b�g�� Buff2.Buff������
						PUNPCKLBW_mm_mm(mm0,mm7)	// 0x00�Ɖ摜�f�[�^���P�o�C�g�Â��݂ɓ����(����ŉ摜�f�[�^�� R�G�B ���ꂼ�ꂪ�o�C�g�l���烏�[�h�l�ɂȂ�)
						PADDW_mm_mm(mm0,mm0)		// �{�ɂ���(���x�l�������ɂȂ��Ă���̂� ��������{�ɂ���̂ƁA�l�̌ܓ�������������)
						PADDW_mm_mm(mm0,mm6)		// RGB���ꂼ��ɂP�𑫂�(�l�̌ܓ��̂���)
						PMULHW_mm_mm(mm0,mm2)		// �|���Z(�o�Ă��铚�� �v�Z���ʂ� 32�r�b�g�̂��� ���16�r�b�g)

//						PAND_mm_mm(mm0,mm5)			// �}�X�N������i�K�v�Ȃ��H�j
						PACKUSWB_mm_mm(mm0,mm7)		// mm0���W�X�^�� 0-31�r�b�g�� RGB�l�����o��(���[�h�l���o�C�g�l�ɂ��ǂ��Bmm7�̓_�~�[)

						MOVD_mem_mm(Buff2.Buff,mm0)	// Buff2.Buff�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=(Buff2.BuffRGB[0]<<ShiftR)|(Buff2.BuffRGB[1]<<ShiftG)|(Buff2.BuffRGB[2]<<ShiftB);
				}
			}

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �q�f�a���g�������Z�u�����h )            �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
		if (!USE_MMX) // MMX���g��Ȃ��ꍇ
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}
		} // MMX���g��Ȃ��ꍇ�����܂�
		else //�l�l�w���g���ꍇ
		{
		static unsigned __int64 MaskBit64;
		static unsigned __int32 BuffSrc1; //�l�l�w���g�����̃o�b�t�@�Src�͓]����
		static unsigned __int32 BuffDest1;//Dest�͓]����

		MaskBit64=0x0000000000ffffff;	//�}�X�N�p�f�[�^
		#ifndef BCC
			_asm movq mm7,MaskBit64		// mm7���W�X�^�Ƀ}�X�N�p�f�[�^������
		#else // #ifndef BCC
			MOVQ_mm_mem(mm7,MaskBit64)	// mm7���W�X�^�Ƀ}�X�N�p�f�[�^������
		#endif // #ifndef BCC

		// �f�[�^�]��
		for (y=Sy;y<Ey;y++)
		{
			for (x=Sx;x<Ex;x++)
			{
				BuffSrc1=*(data1+x);

				if (BuffSrc1!=0x00000000) //���̏ꍇ�͏������Ȃ�
				{
					BuffDest1=*(data2+x);

					#ifndef BCC
					_asm
					{
						movd mm1,BuffSrc1		// mm1���W�X�^��  0-31�r�b�g�� BuffSrc1������
						movd mm0,BuffDest1		// mm0���W�X�^��  0-31�r�b�g�� BuffDest1������
						psubusb mm0,mm1			// �T�`�����[�V����(�O�a)�t���� mm0=mm0-mm1 �� ���Z������ (�W�r�b�g���E�Aunsigned)
						pand mm0,mm7			// �O�̂��߃}�X�N������
						movd BuffDest1,mm0		// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					}
					#else // #ifndef BCC
						MOVD_mm_mem(mm1,BuffSrc1)		// mm1���W�X�^��  0-31�r�b�g�� BuffSrc1������
						MOVD_mm_mem(mm0,BuffDest1)		// mm0���W�X�^��  0-31�r�b�g�� BuffDest1������
						PSUBUSB_mm_mm(mm0,mm1)			// �T�`�����[�V����(�O�a)�t���� mm0=mm0-mm1 �� ���Z������ (�W�r�b�g���E�Aunsigned)
						PAND_mm_mm(mm0,mm7)				// �O�̂��߃}�X�N������
						MOVD_mem_mm(BuffDest1,mm0)		// BuffDest1�� mm0���W�X�^��  0-31�r�b�g������
					#endif // #ifndef BCC

					*(data2+x)=BuffDest1;
				}
			}

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		EMMS

		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �q�f�a���g�������Z�u�����h )        �� �n�C�J���[��p  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( (R+G+B)/3 �ł͂Ȃ��O���[�X�P�[�� )      �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch>>1;
//		AddPitch2=ddsd2.lPitch>>1;
		AddPitch1=ddsd1.lPitch>>2;//
		AddPitch2=ddsd2.lPitch>>2;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( (R+G+B)/3 �ł͂Ȃ��O���[�X�P�[�� )  �� �n�C�J���[��p  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if ((int)Ex>=(int)Sx && (int)Ey>=(int)Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch>>1;
		AddPitch2=ddsd2.lPitch>>1;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ��]�{�A���`�G�C���A�X )                �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0x00,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0x00,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
//		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/4;//
		data2=(LPDWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/4;//

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// ��]�̒��S�_���擾
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

					// 4�_�̐F���������܂��B
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( ��] )                              �� �n�C�J���[��p  -*/
/*-                                                                            -*/
/*-    int Px1     : �`�捶��w���W                                            -*/
/*-    int Py1     : �`�捶��x���W                                            -*/
/*-    int Px2     : �`��E���w���W                                            -*/
/*-    int Py2     : �`��E���x���W                                            -*/
/*-    int Angle   : ��]�p�x ( �����v��� )                                   -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*ddsd1.lPitch/2;
		data2=(LPWORD)ddsd2.lpSurface+Px1+Py1*ddsd2.lPitch/2;

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// ��]�̒��S�_���擾
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

					// 4�_�̐F���������܂��B
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

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �Ǝ��g���E�V���h�[���̐؂�̂� )        �� �t���J���[  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Limit   : �������l ( 0 �` 255 )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// RGB�̃t�H�[�}�b�g�ɂ���ăA�N�Z�X����A�h���X��ς��� //
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

		// �x�����ւ̒ǉ��o�C�g���̎擾
//		AddPitch1=ddsd1.lPitch/2;
//		AddPitch2=ddsd2.lPitch/2;
		AddPitch1=ddsd1.lPitch/4;//
		AddPitch2=ddsd2.lPitch/4;//

		// �X�v���C�g�̐擪�ʒu���擾
//		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
//		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;
		data1=(LPDWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;//
		data2=(LPDWORD)ddsd2.lpSurface+Px+Py*AddPitch2;//

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}

/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �X�v���C�g�̕`�� ( �Ǝ��g���E�V���h�[���̐؂�̂� )    �� �n�C�J���[��p  -*/
/*-                                                                            -*/
/*-    int Px      : �`��w���W                                                -*/
/*-    int Py      : �`��x���W                                                -*/
/*-    int Limit   : �������l ( 0 �` 255 )                                     -*/
/*-    DDOBJ ObjDD : �X�v���C�g���                                            -*/
/*-    int X1      : �X�v���C�g����w���W                                      -*/
/*-    int Y1      : �X�v���C�g����x���W                                      -*/
/*-    int X2      : �X�v���C�g�E���w���W                                      -*/
/*-    int Y2      : �X�v���C�g�E���x���W                                      -*/
/*-                                                                            -*/
/*-    �߂�l      : TRUE  = ����I��                                          -*/
/*-                : FALSE = �G���[����                                        -*/
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

	// �`��̈�̌v�Z
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

	// �`��ł���ꍇ
	if (Ex>=Sx && Ey>=Sy)
	{
		// �\���̂̏�����
		memset(&ddsd1,0,sizeof(DDSURFACEDESC));
		ddsd1.dwSize=sizeof(DDSURFACEDESC);
		memset(&ddsd2,0,sizeof(DDSURFACEDESC));
		ddsd2.dwSize=sizeof(DDSURFACEDESC);

		// �X�v���C�g�̃��b�N
		ddret=Sprite[ObjDD].Object->Lock(NULL,&ddsd1,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			return FALSE;
		}

		// ��ʃX�v���C�g�̃��b�N
		ddret=DDBack->Lock(NULL,&ddsd2,DDLOCK_WAIT,NULL);

		if (ddret!=DD_OK)
		{
			DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);

			return FALSE;
		}

		// �x�����ւ̒ǉ��o�C�g���̎擾
		AddPitch1=ddsd1.lPitch/2;
		AddPitch2=ddsd2.lPitch/2;

		// �X�v���C�g�̐擪�ʒu���擾
		data1=(LPWORD)ddsd1.lpSurface+X1+Y1*AddPitch1;
		data2=(LPWORD)ddsd2.lpSurface+Px+Py*AddPitch2;

		// 8�r�b�g->5�r�b�g�ɂ���
		Limit>>=3;

		// �f�[�^�]��
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

			// �x�����ɉ��Z
			data1+=AddPitch1;
			data2+=AddPitch2;
		}

		// �X�v���C�g�̃��b�N����
		DD_UNLOCK(Sprite[ObjDD].Object,ddsd1.lpSurface);
		DD_UNLOCK(DDBack,ddsd2.lpSurface);
	}

	return TRUE;
}


/*------------------------------------------------------------------------------*/
/*-                                                                            -*/
/*-  �ϐ��̒u�������i���֖߂��j                             �� elDraw32�Ŏg�p  -*/
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


// MMX���R���p�C���������̌x���\����������ɖ߂�
#pragma warning( default : 4799 )


