// thd:in_road6.c

inherit ROOM;

void create()
{
      set("short", "林间小路");
	set("long", @LONG
你走在一条林间小路上。四周的桃花树又开始繁密起来，你眼前似乎
出现无数条路。你开始分不清该走哪条路了。而这里的桃花树又实在太相
向了，你再怎么走下去，恐怕连来路都要分不清了。四周虽然看似平静，
实际确蕴含着无穷的杀机。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "northeast" : __DIR__"in_road7",
	    "west" : __DIR__"in_road5",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

