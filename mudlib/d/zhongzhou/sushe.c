//sushe
  

inherit ROOM;

void create()
{
	set("short", "演员房间");
	set("long", @LONG
这里是是戏院内演员的休息的地方，好几张大床占了房间的大半，床
上男的女的衣服乱七八糟，看起来他们男的女的就混在一起睡！北面的墙
上有几张名角的画像。有个小孩在床边玩呢。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiyuan",
	]));
	set("objects", ([
	__DIR__"npc/xiaohai" : 2,
	]));

	setup();
	replace_program(ROOM);
}

