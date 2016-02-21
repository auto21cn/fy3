// Room: /u/xizhen/room/bolin.c
// Data: 南宫逸(nangong)
// Time: 公元：1999年4月2日，北京时间：20时15分23秒。




inherit ROOM;



void create()

{

	set("short", "柏林");
	set("long", @LONG
0LONG
	);
	set("outdoors", "wudang");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/d/hangzhou/lu3",
  "northup" : __DIR__"shijie",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/famu" : 1,
  __DIR__"npc/monkey" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
