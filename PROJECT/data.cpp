int exitflg=0;
int rom_BG_High = 16;		//BG���[�h���̕\���̑傫��
int rom_BG_Width= 16;

int rom_Disp_Mode = 0;		//0=Sprite 1=BG



int help_flg =0x00;		//HELP�\���t���O
int viewer_Pal = 0x00;

//********************************
struct palet256_info{
		int red;			//�W�K������܂��B
		int green;
		int blue;
		};

struct palet256_info palet[256];		//256�F�p���b�g�\����
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
int up_key;			//�J�[�\���ړ�
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

int select_Pal=0;		//���ݕҏW���̃p���b�g

//pce�W�K���̃p���b�g��256�K���ɕϊ�
//int windows_paltbl[8]={0,63,95,127,159,191,223,255};
//PCE�W�K���p���b�g��el��32�K���ɕϊ�
//int windows_paltbl[8]={0,6,12,16,20,24,28,31};

//int windows_paltbl[8]={0,7,11,15,19,23,27,31};  //2004�N �n�C�J���[�̂���
int windows_paltbl[8]={0,56,88,120,152,184,220,255};    //21/12/08 �t���J���[�Ή�




int	filesize=0;  //�t�@�C���T�C�Y��+200h�̔��[������΃w�b�_�t���B
char FileTitle[256]="BMP�t�@�C��";
char FileName[_MAX_PATH]="sample.bmp";		//�f�B�t�H���g�p���b�g�t�@�C����
char RomName[_MAX_PATH]="KungFu.pce";		//�f�B�t�H���g������

