// wen's workroom

inherit ROOM;

void create()
{
	set("short","测试屋二");
      set("long", @LONG
	测试房屋二，什么都没有。
LONG);
	set("exits", ([ /* sizeof() == 3 */
		"south":__DIR__"testroom1.c",
	]));
	set("objects",([
		"/npc/test4":1,
	]));
      	setup();
	replace_program(ROOM);
}
