# PCE-Viewer
It becomes binary data and displays image data.

PC Engine (Turbo Graphics 16) Viewer

  ROM  .pce( + $200 byte Hedder )
       .bin
  YAME (TG16 Emulator) SAVE DATA.
       .st1 .st2 .st3 .st4
  Magic Engine (TG16 Emulator) SAVE DATA.
       .me1 .me2. me3 .me4 .me5

  ISO ( CD-ROMx2 GAME CD --> TRACK 02 BINALY DATA )
       .iso

...etc, read and view non-archive graphics data.

;------------------------------------------------------------

USAGE:

Double-click pce_viewer to start it.
A file dialog will open, so load the target file.

I have confirmed the operation on Windows7 32bit 64bit.

;------------------------------------------------------------

Build:

vc++6.0
( DirectX Ver. ----> directx9.0c )

Open "Project.dsw".

Build -> Batch Build -> check「Project -Win32 el」->"Rebuild All"Button.

rename game.exe --> pceviewer.exe.

(Even if I build it in debug mode, it doesn't work for some reason.)

;------------------------------------------------------------

Liblaly

I am using the following completely free graphic library.

Easy Link Library
    Botchy World
    http://www3.justnet.ne.jp/~botchy/index.html

Eldraw32
    http://www.ky.xaxon.ne.jp/~hitoshi/index.htm

;------------------------------------------------------------

Version:

2022/07/21   Ver. 0.7.1 Release

2022/05/26   Ver. 0.7.1
             A little faster. Bug removal.

2022/04/20   Ver. 0.7
             CDROMx2 is Divided into $800 bytes.

2021/12/09   Ver. 0.6
             bug fix.

2006/07/16   Ver. 0.5
2003/08/05   Ver. 0.1


;------------------------------------------------------------

License:

The MIT License.

;------------------------------------------------------------

I would like to thank the users, informants, and graphic library authors.
