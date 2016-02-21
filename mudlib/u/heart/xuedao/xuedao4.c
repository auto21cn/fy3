// Room: /u/uuui/xuedao/xuedao4.c

inherit ROOM;

void create()
{
	set("short", "石洞前");
	set("long", @LONG
这里已经里天魔洞很近了。四周杂草丛生。石洞看
上去象是天然形成的。两扇石门上隐约能看到天魔洞几
个大字。显然这门很长时间没有关过了。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xuedaomen/1");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xuedao5",
  "south" : __DIR__"xuedao3",
  "west" : __DIR__"xuedao6",
  "east" : __DIR__"xuedao1",
]));

	setup();
	replace_program(ROOM);
}
