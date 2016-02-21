// Room: /d/robber/mudroad1.c

inherit ROOM;

void create()
{
	set("short", "黄泥路");
	set("long", @LONG
一条七拐八弯的黄泥路,坑坑洼洼的很不好走,前面不远有个小土岗,
上面依稀有些松柏树.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"mudroad",
  "northup" : __DIR__"hill",
]));

	setup();
	replace_program(ROOM);
}
