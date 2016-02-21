// thd:hall.c
// 97.7.14 bu Aug

inherit ROOM;

void create()
{
      set("short", "议事大厅");
	set("long", @LONG
这里是桃花岛的议事大厅。黄岛主决定受徒、开除、接待贵宾等重大
事物皆在此处进行。这里的大厅和归云庄的大厅迥然不同，这儿的大厅一
点也没有富贵之气，它和岛上别的屋子一样都是用竹子搭成的，连屋中的
桌椅也是竹子做的。大堂中央悬挂着幅竹林七杰饮酒行乐图。一切都是那
么的自然，不代一点世俗俗气。这一切都显示出黄药师隐士般的潇洒豁达
，和他身为武学宗师的宏大气势。大厅的东面是黄岛主的书房，西面是花
园。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/huang_yaoshi" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 3 */
	    "northeast" : __DIR__"yard1",
	    "northwest" : __DIR__"bookroom",
	    "south" : __DIR__"in_road4",
	]));
      
      set("valid_startroom", 1);
	setup();
//	replace_program(ROOM);
	"/u/aug/thd/thd_b"->foo();
//	load_object("/daemon/board/thd_b");
}

