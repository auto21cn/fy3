// Room: /d/huashan/shaluo.c

inherit ROOM;

void create()
{
	set("short", "莎萝坪");
	set("long", @LONG
沿着玉泉，踏过累累石涧，由山径迤逦而上，就来到了莎萝坪。从这
里山路开始陡峭，南面一条迂回盘旋的山道，称作「十八盘」，通往山上。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xx");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/haoke" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
  "southup" : __DIR__"qingke",
  "northeast" : __DIR__"shanhongpb",
  "northwest" : __DIR__"path1",
]));

	setup();
	replace_program(ROOM);
}
