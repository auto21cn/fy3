// Room: /d/suzhou/huqiuta.c

inherit ROOM;

void create()
{
	set("short", "虎丘塔");
	set("long", @LONG
此塔相传建于五代，又名云岩寺塔。你抬头仰望，塔顶似乎已湮没于云层之
中。此塔不仅是苏州名胜，而且渐渐成为了苏州城的象征。你仔细的观察了一下，
发现虎丘塔并非笔直，而是略微向北倾斜。你心想这可能也是此塔成名的原因吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" :__DIR__"guanyinquan",
]));
	set("objects",([
	__DIR__"npc/hutawuseng":2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
