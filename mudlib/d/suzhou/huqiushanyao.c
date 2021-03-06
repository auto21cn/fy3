// Room: /d/suzhou/huqiushanyao.c

inherit ROOM;

void create()
{
	set("short", "虎丘山腰");
	set("long", @LONG
你现在站在虎丘山的半山腰上，来往游人不断。山顶的虎丘塔已清晰可见。
放眼四周松林密布，你突然发现林中似有一角寺檐，但眨眼之间却又踪迹皆无。
正所谓“塔从林外出，山向寺中藏”。西面有一园门，不知是什么去处。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" :__DIR__"huqiushanxia",
		"west" :__DIR__"yuanmen",
		"northup" :__DIR__"huqiushanding",
]));
	set("objects",([
	__DIR__"npc/jinxiangke":1,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
