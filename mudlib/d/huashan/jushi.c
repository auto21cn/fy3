// Room: /d/huashan/jushi.c

inherit ROOM;

void create()
{
	set("short", "居室");
	set("long", @LONG
这里是岳夫人的寝室，岳夫人在江湖上人称「淑女剑」，为人极有骨
气，她的居室却相当朴素，床椅之外，靠窗(window)处有个梳妆台(tai)，
墙上挂着一口宝剑(sword)， 蛇皮吞口看来很是锋利。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 3 */
  "tai" : "这是一张红漆梳妆台，半开的抽屉斜插着几朵鲜花。
",
  "sword" : "这是上次前往福建时带回的龙泉剑。
",
  "window" : "窗外就是天声峡了。往外望去，云深谷幽令人目眩。
",
]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/ning":1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changlang",
]));

	setup();
	replace_program(ROOM);
}
