// thd:hill2.c

inherit ROOM;

void create()
{
      set("short", "半月坪");
	set("long", @LONG
这里是块稍微平整些的山地。游人到这里往往要休息一番，再开始新
的征程。从这里山路一分为二，东面的山路是去囚龙洞的，而西边的山路
一直同到山顶。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 3 */
          "northeast" : __DIR__"hill3",  
          "northwest" : __DIR__"hill5",        
          "southdown" : __DIR__"hill1",     
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

