// Room: /d/huanggon/yuhuayuan2.c

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
御花园中,垒石高而为峰,引水曲而为溪,上加小桥数座,只要一出坤
宁门,就是两棵合抱的古树,上面枝叶交织,相互纠缠,形成一道天然拱门,
一条小径就从这门下穿过,小路不远是个铁香炉,再北就是钦安殿.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuqianshiwei.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"qingandian",
  "south" : __DIR__"kunningon",
  "east" : __DIR__"cininggon",
]));
	set("outdoors", "/d/huanggon");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
