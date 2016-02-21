// Room: /d/zhongzhou/dangpu.c

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是铁二娘开的当铺。这当铺可能和官府有勾结。在这里不管你的东
西的来路如何都照收。你也可以看看有什么东西你需要也可以去买一点。
不过价钱可能要比其他地方要贵一点。
LONG
	);
	set("guarded", ([ /* sizeof() == 1 */
  "north" : ({ }),
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhousongtian.c" : 1,
  __DIR__"npc/yitai" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yanling",
]));

	setup();
	replace_program(ROOM);
}
