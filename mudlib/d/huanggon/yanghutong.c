// Room: /d/huanggon/yanghutong.c

inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
杨柳胡同是条弯曲的小胡同,道上都是石板路,两边是民房,大多已
经很破旧,房子很矮小,要进门的话一定要低了头才行,几个挑了担子的
小贩从你身边经过.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xidan1",
  "northwest" : __DIR__"yanghutong1",
]));

	setup();
	replace_program(ROOM);
}
