// Room: /d/quanzhou/datang.c

inherit ROOM;

void create()
{
	set("short", "大堂");
	set("long", @LONG
这里是泉州府大堂,一幅山河日月图上方,高挂着一块匾额,上面是泥 
金大字'明镜高悬',知府大人只认银子不认人,是个贪得无厌的家伙.长案旁边
有块虎头牌子(sigh), 
LONG
	);
	set("no_clean_up", 0);
//        set("no_fight", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "sigh" : "申办路引,每位五两,多多益善,恕不零找.
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhifu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
