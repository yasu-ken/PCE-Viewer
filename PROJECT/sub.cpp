
//char textworkbuf[MAX_PATH];
char textworkbuf[1024];

//**************************************
// 今の日付と時間の文字列を得る
//**************************************
char * GetStr_DayAndTime()
{
	time_t t = time(NULL);
	struct tm *local = localtime(&t);
	//char * const wdays[] = { "日", "月", "火", "水", "木", "金", "土" };
	char * const wdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	sprintf(textworkbuf, ";[ %04d/%02d/%02d (%s)] %02d:%02d:%02d\n",
			local->tm_year + 1900,
			local->tm_mon + 1,
			local->tm_mday,
			wdays[local->tm_wday],
			local->tm_hour,
			local->tm_min,
			local->tm_sec);

	return textworkbuf;
}


//**************************************
// EXEのあるパスを得る
//**************************************
char * GetInstallPath()
{

	char Path[MAX_PATH+1]; 
	char drive[MAX_PATH+1],dir[MAX_PATH+1],fname[MAX_PATH+1],ext[MAX_PATH+1];

	if(0 != GetModuleFileName( NULL, Path, MAX_PATH ))  // 実行ファイルの完全パスを取得
	{
		_splitpath(Path,drive,dir,fname,ext);   //パス名を分解

		//printf("完全パス               : %s\n",Path);
		//printf("ドライブ               : %s\n",drive);
		//printf("ディレクトリ パス      : %s\n",dir);
		//printf("ファイル名(拡張子なし) : %s\n",fname);
		//printf("拡張子                 : %s\n",ext);

		sprintf(textworkbuf, "%s%s",drive,dir );

		return textworkbuf;
	}

	return NULL;  //エラー
}


//**************************************
//指定ファイル名をインストールディレクトリ(EXEのあるフォルダ)からのフルパスにします
//    ロムを読み込むためにカレントディレクトリを移動した場合
//    EXEのあるフォルダにあるファイルを見失うため
//**************************************
char *GetFullPath_ThisFile( char *fname )
{
	char Path[1024];
	char *dir;

	dir = GetInstallPath();

	if( dir == NULL )return NULL;

	sprintf(Path, "%s%s",dir,fname );
	strcpy(textworkbuf,Path);

	return textworkbuf;
}



//---------------------------------------------------------------
// 四角を描画
//---------------------------------------------------------------
// あまりにも点描画が遅いため、あるていど早くする努力をしてみました。
// 21/12/08

//void elDraw32_ColorFill(int X1,int Y1,int X2,int Y2,COLORREF Color)
void elDraw32_ColorFill(int X1,int Y1,int X2,int Y2, int rr,int gg, int bb )
{
	static DDBLTFX ddbltfx;
	static RECT rect;

	rect.left   = X1;
	rect.top    = Y1;
	rect.right  = X2;
	rect.bottom = Y2;

	ddbltfx.dwSize      = sizeof(ddbltfx);
	//ddbltfx.dwFillColor = GetRValue(Color)<<elDraw::ShiftR|
	//					GetGValue(Color)<<elDraw::ShiftG|
	//					GetBValue(Color)<<elDraw::ShiftB;
	ddbltfx.dwFillColor = rr<<elDraw::ShiftR|
						  gg<<elDraw::ShiftG|
						  bb<<elDraw::ShiftB;

	//DDBack->Blt(&rect,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&ddbltfx);
	DDBack->Blt(&rect,NULL,NULL,DDBLT_COLORFILL,&ddbltfx);
}



//上の関数をマクロにしてみました
	DDBLTFX cf_ddbltfx;
	RECT cf_rect;

#define ColFilMac(X1,Y1,X2,Y2,rr,gg,bb) \
	cf_rect.left   = X1; \
	cf_rect.top    = Y1; \
	cf_rect.right  = X2; \
	cf_rect.bottom = Y2; \
	cf_ddbltfx.dwSize      = sizeof(cf_ddbltfx);  \
	cf_ddbltfx.dwFillColor = rr<<elDraw::ShiftR|  \
						  gg<<elDraw::ShiftG|     \
						  bb<<elDraw::ShiftB;     \
	DDBack->Blt(&cf_rect,NULL,NULL,DDBLT_COLORFILL,&cf_ddbltfx);

