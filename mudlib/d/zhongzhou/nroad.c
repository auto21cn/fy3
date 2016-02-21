// Room: /d/zhongzhou/nroad.c

inherit ROOM;

void create()
{
	set("short", "石板大道");
	set("long", @LONG
这儿靠中府不远，路上行人来往不断，你的眉头也舒展了开来，步子也
越迈越大。北面就是「中州府」，往南则通往苏州、杭州、武当等各地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"toyy",
  "north" : __DIR__"nanmeng",
]));
set("outdoors","/d/zhongzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
