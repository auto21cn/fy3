// Room: /d/new/huanhua/dloushan.c

inherit ROOM;

void create()
{
	set("short", "娄山脚下");
	set("long", @LONG
眼前一座高山挺秀,绿树掩印,怪石嶙峋.峰高处直插白云.正是大娄山.
前面不远的山脚下,有座破烂的亭子.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"road1",
  "north" : __DIR__"hxianting",
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/new");

	setup();
	replace_program(ROOM);
}
