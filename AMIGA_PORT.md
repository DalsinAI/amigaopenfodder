Open Fodder for AmigaOS 3.x
===========================

Open Fodder 2.0.0 (https://github.com/OpenFodder/openfodder, GPL 3; its
bundled Duktape, json, md5 and other helpers under their own licences, in
the COPYING.* files), the open-source engine for Sensible Software's
Cannon Fodder, for AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG
screen, on OpenGPU's SDL 2.

Base: tag 2.0.0 (commit 5eb41363). Branch team2/openfodder-amiga.

Status: lab runs (Instance-45, 6 November 2026, with the data pack): the
"Select Campaign" menu, the chapter book and the Amiga Format Christmas
Special's first mission (map, squad, sidebar) run, at full screen. The
mouse needs SDL2.module's relative mode (gfopenrtg #181, OpenGPU after
0.6): with 0.6 the crosshair neither moves nor clicks. Not yet played
through a whole mission.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- OpenGPU 0.6 or later: opengpu.library and LIBS:OpenGPU/SDL2.module and
  SDL2_mixer.module (installed by OpenUp).
- Open Fodder's data pack, and for the full game your own Cannon Fodder:
  1. Download https://github.com/OpenFodder/data/releases/download/1.6.0/Data.pack.1.6.0.zip
     (Open Fodder's campaign files and six Cannon Fodder demos from Amiga
     magazine cover disks) and unpack it into the OpenFodder drawer.
  2. For the full game, copy your own Cannon Fodder files into
     Data/Amiga (from WHDLoad's install, or the floppies unpacked with Open
     Fodder's SOS Unpacker), Data/Amiga_CD or Data/Dos_CD, as upstream's
     INSTALL.md says.


How to play
-----------

Open the OpenFodder drawer and double-click OpenFodder. Open Fodder offers
the versions it finds in Data/; with only the data pack, the demos.



Standard keys
-------------

Every AmiCradle game has the same keys on Right Amiga (GFOpenUp's
SDL2.module, after 0.8.26):

- Right Amiga + F: window or full screen, remembered for next time
- Right Amiga + P: pause (Right Amiga + P again goes on)
- Right Amiga + Q: quit
- Right Amiga + M: free the mouse pointer, or let the game take it again
- Right Amiga + S: a screenshot in the drawer's Screenshots
- Help: this game's keys (the drawer's Controls file)
- Right Amiga + F1, F2: F11, F12; Right Amiga + cursor keys: Page Up,
  Page Down, Home, End

The FULLSCREEN tooltype on the game's icon (take the brackets off) starts
it full screen.


Building
--------

GFOpenAmigaGCC 16.2.0-open4 or later and the OpenGPU developer kit:

    make -f amiga/Makefile.amigaos -j2 dist \
         STOVE=/path/to/openamigagcc-16.2.0-open4 \
         NDK=/path/to/OpenNDK/Include_H SDL2KIT=/path/to/opengpu-sdk

CMake is not run: amiga/Makefile.amigaos compiles every Source/*.cpp (as
CMakeLists.txt does) and makes gitver.hpp itself. Output:
build/amigaos/OpenFodder (stripped; .debug beside it); 'dist' makes
dist/OpenFodder/ and dist/OpenFodder.info.


What was changed
----------------

- Source/stdafx.cpp: main() first moves into the drawer (amiga/
  amiga_start.c: Open Fodder looks for Data/ in the current directory
  first) and closes at exit the screens SDL2.module 0.6 can leave
  (amiga/amiga_screens.c). amiga/stack.c: 512 KB of stack.
- Source/ResourceMan.cpp, DirectoryList(): one '/' between a drawer and
  its files (upstream always added one, and on AmigaDOS "a//" is a's
  parent: no game data was found).
- amiga/amiga_prelude.hpp (included before every file): std::atoll,
  strtoll, strtoull, strtof, strtold, llabs, stoll, stoull and stold, which
  the GCC 16 stove's libstdc++ for the 68040 leaves out (configured
  without _GLIBCXX_USE_C99) though libnix has them.
- Source/stdafx.cpp, tool_EndianSwap(): does nothing on a big-endian CPU.
  The maps and sprite lists (.map, .spt) and the tile tables are big
  endian and upstream swaps them for x86; on the 68k that swap turned a
  sprite's type into junk, and choosing a mission jumped through
  mSprite_Function[] into nowhere (Sprite_Handle_Loop).
- Source/Utils/dukglue/detail_primitive_types.h: bindings for unsigned
  long and long, which size_t and ssize_t are on m68k (on Linux they are
  the 64-bit types dukglue binds already).


Licences
--------

Open Fodder: GPL 3 (COPYING.txt in the drawer); its bundled code: BSD,
LGPL 2.1, MIT and zlib (COPYING.*.txt). The data pack: Open Fodder's
campaign files, and demos released by Sensible Software and the magazines
as free cover-disk demos. The amiga/ files are the AmiCradle Team's, GPL 3
or later.
