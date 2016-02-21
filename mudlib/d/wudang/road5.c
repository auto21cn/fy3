// Room: /d/wudang/road1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条官道，青石铺成。继续往西南走可以到达大理，南边直通海滩。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast":__DIR__"road4",
  "southwest":__DIR__"road6",
  "south":__DIR__"road7",
]));
set("outdoors","/d/wudang");
	set("no_clean_up", 0);

	set("objects",([
		"/npc/man5":1,
	]));
	setup();
	replace_program(ROOM);
}
