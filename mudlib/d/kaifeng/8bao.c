// Room: /d/kaifeng/8bao.c

inherit ROOM;

void create()
{
	set("short", "八宝琉璃殿");
	set("long", @LONG
这座大殿相对于大雄殿来说要小得多，但却显得富丽精致无比，大
殿的檐面是用琉璃瓦铺的，四面的墙壁上都镂刻了佛经故事，正中的
弥勒佛像用黄金，翡翠，宝石，珍珠等装饰，称八宝佛像。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/jiansi.c" : 1,
  __DIR__"npc/obj/milexiang.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houyuan",
  "northdown" : __DIR__"gongmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
