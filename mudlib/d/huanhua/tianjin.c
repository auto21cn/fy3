// Room: /d/huanhua/tianjin.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
天井连接内外厅,两边都有三五级台阶相连,另两边就是高高的围墙,
庭中一口古井旁边种了一株老梅,边上的一个荷花缸中还养着几条红
鲤鱼,从此向北,就是内厅,南面是大厅.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/new");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neiting",
  "south" : __DIR__"dating",
]));

	setup();
	replace_program(ROOM);
}
