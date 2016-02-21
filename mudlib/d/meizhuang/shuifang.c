// Room: /d/suzhou/meizhuang/shuifang.c

inherit ROOM;

void create()
{
	set("short", "睡房");
	set("long", @LONG
这儿是梅庄弟子休息的地方，好象不接待其他门派。房间内除了几张
大床可以睡觉之外，只有个正冒清烟的香炉。四周的窗户早已被帘子遮住，
挡住了光线。你一进来就有种昏昏欲睡的感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shibanlu2",
]));
	set("objects",([
	__DIR__"npc/xiaotong":1,
]));
	set("sleep_room",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
