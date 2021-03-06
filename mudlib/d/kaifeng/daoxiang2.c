// Room: /d/kaifeng/daoxiang2.c

inherit ROOM;

void create()
{
	set("short", "稻香居二楼");
	set("long", @LONG
老大一个大厅内相互间用屏风隔成十多个小间。穿戴厉索的小二端
着菜来往奔走，如果你分量够的话，还可以捞到个窗边的位置。边喝
酒边看看下面的繁华街景，人生一乐。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/gaoyanei.c" : 1,
  __DIR__"npc/luyuhou.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"daoxiang",
]));

	setup();
	replace_program(ROOM);
}
