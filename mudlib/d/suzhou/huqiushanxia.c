// Room: /d/suzhou/huqiushanxia.c

inherit ROOM;

void create()
{
	set("short", "虎丘山下");
	set("long", @LONG
虎丘山素有吴中第一名胜之称，有三绝九宜十八景之胜。大诗人苏东坡曾感
叹曰：到苏州而不游虎丘及憾事也。你四处张望了一下，青松绿柳风景宜人，确
是游玩的好地方。你深深的吸了口气，渐渐淡忘了江湖上的恩恩怨怨。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"xiaolu1",
		"northup" :__DIR__"huqiushanyao",
]));
	set("objects",([
		__DIR__"npc/tiaofu":2,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
