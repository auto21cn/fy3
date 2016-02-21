// Room: /u/yuki/songshan/luyansi.c

inherit ROOM;

void create()
{
	set("short", "芦岩寺");
	set("long", @LONG
    芦岩寺很小，但是是嵩山派存放本门武功秘芨的地方。门口
有嵩山派的长老看管，只有具备一定条件的本门弟子才允许进去
取武功秘芨学习。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"simen.c",
]));

	setup();
	replace_program(ROOM);
}
