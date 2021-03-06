// Room: /d/quanzhou/shengmu.c

inherit ROOM;

void create()
{
	set("short", "伊斯兰圣墓");
	set("long", @LONG
唐武德年间,伊斯兰教创始者穆罕默德四位弟子来此传教,后两弟子
葬于此处,其后屡有灵迹,此处又称为'灵山圣墓',墓为两座并列花岗岩
石雕基盖,上建四方形石亭遮盖.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"caodi",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ahong.c" : 1,
  __DIR__"npc/yisilan.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
