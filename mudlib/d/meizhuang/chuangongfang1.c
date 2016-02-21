// Room: /d/suzhou/meizhuang/chuangongfang1.c

inherit ROOM;

void create()
{
	set("short", "传功房");
	set("long", @LONG
这儿是丹青生弟子的练功场所。除了在房间四周摆放了些兵刃、护具
之外，整个屋内空空荡荡，显而是为了练功方便。西面门帐后面便是丹青
生居住的地方了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"danqingju",
  "east" : __DIR__"heilang2",
]));
	set("objects",([
//	 __DIR__"obj/bingqijia4":1,
		__DIR__"npc/chuangongdizi4":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
