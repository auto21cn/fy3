// Room: /d/wudang/shilu1.c

inherit ROOM;

void create()
{
	set("short", "石路");
	set("long", @LONG
一条幽静的石子路，几乎见不到什么人。西南通向武当，东北方面可到苏
州、杭州、中州府等地。
LONG
	);
set("outdoors","/d/wudang");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"towudang",
  "southwest" : __DIR__"shilu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
