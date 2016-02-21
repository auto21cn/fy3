// Room: /d/huanhua/changlang3.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条长长的回廊,蓝色琉璃瓦铺面,红漆柱子每隔三丈就成对排列两边. 
廊外是假山,曲径通幽,别有情趣.北面山崖下有个洞口. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"changlang2.c",
  "north" : __DIR__"jt_cave",
]));
	set("outdoors", "/d/new");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
