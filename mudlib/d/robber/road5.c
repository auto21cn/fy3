// Room: /d/robber/road5.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条宽阔的大路，来往的人多是彪悍的江湖汉子，两端不时有烟尘滚
滚，那是骏马奔驰而过留下的形迹，路的北面有个茶寮。
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("objects",([
		"/npc/man1":2,
		"/npc/man2":1,
	]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/sandboy/to_zhongzhou2",
  "east" : __DIR__"road3",
  "north" : __DIR__"tearoom",
]));

	setup();
	replace_program(ROOM);
}
