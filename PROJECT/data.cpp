int exitflg=0;
int rom_BG_High = 16;		//BGモード時の表示の大きさ
int rom_BG_Width= 16;

int rom_Disp_Mode = 0;		//0=Sprite 1=BG



int help_flg =0x00;		//HELP表示フラグ
int viewer_Pal = 0x00;

//********************************
struct palet256_info{
		int red;			//８階調あります。
		int green;
		int blue;
		};

struct palet256_info palet[256];		//256色パレット構造体
struct palet256_info palet_copywok;

int f1_key;
int f5_key;
int z_key;			//palet value ++
int x_key;			//palet value --
int a_key;			//palet value ++
int s_key;			//palet value --
int q_key;			//palet value ++
int w_key;			//palet value --
int c_key;			//copy
int v_key;			//past
int up_key;			//カーソル移動
int dn_key;
int lt_key;
int rt_key;

int num_0key;
int num_1key;
int num_2key;
int num_3key;
int num_4key;
int num_5key;
int num_6key;
int num_7key;
int num_8key;
int num_9key;

int select_Pal=0;		//現在編集中のパレット

//pce８階調のパレットを256階調に変換
//int windows_paltbl[8]={0,63,95,127,159,191,223,255};
//PCE８階調パレットをelの32階調に変換
//int windows_paltbl[8]={0,6,12,16,20,24,28,31};

//int windows_paltbl[8]={0,7,11,15,19,23,27,31};  //2004年 ハイカラーのころ
int windows_paltbl[8]={0,56,88,120,152,184,220,255};    //21/12/08 フルカラー対応




int	filesize=0;  //ファイルサイズが+200hの半端があればヘッダ付き。
char FileTitle[256]="BMPファイル";
char FileName[_MAX_PATH]="sample.bmp";		//ディフォルトパレットファイル名
char RomName[_MAX_PATH]="KungFu.pce";		//ディフォルトロム名

