// Room: /d/suzhou/chengbeijie3.c

inherit ROOM;

void create()
{
	set("short", "城北街");
	set("long", @LONG
街东不少青年人进进出出，忙得汗水已湿透衣衫。对面街西相对安静一些，
大门敞开，左右各立一尊石狮，门匾上好大一个“武”字，屋内还不时传出兵器
撞击之声。街道南北延伸，来往行人不断。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" :__DIR__"chengbeijie2",
		"east" :__DIR__"daoxiangcun",
		"west" :__DIR__"bingqipu",
		"north" :__DIR__"chengbeijie4",
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
