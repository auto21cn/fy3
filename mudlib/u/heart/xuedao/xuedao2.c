// Room: /u/uuui/xuedao/xuedao2.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这里是一片空地，地面上杂草丛生，草丛中隐隐有
白色的骨头，仔细看去，竟然是人骨！有的人骨上还有
隐隐的血迹，让人毛骨悚然。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xuedaomen/1");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xuedao1",
  "west" : __DIR__"xuedao3",
]));

	setup();
	replace_program(ROOM);
}
