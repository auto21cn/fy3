// Room: /d/taiwan/zhangfang.c

inherit ROOM;

void create()
{
	set("short", "帐房");
	set("long", @LONG
房间中间摆了张长方桌子,后面摆的太师椅子上坐着个瘦削的半百老 
头,鼻梁上架着副半框眼镜.手上拿着支毛笔在本帐簿上点点划划.桌上除 
了一副半旧的算盘外,还摆着个茶杯.除了门口那面的三面墙边摆着几个高 
高的柜子.里面摆满了各种卷宗. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dayuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiye.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
