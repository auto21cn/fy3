// ximen.c 西门


inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
	这里是长安镇的西门，眼前城墙高耸，墙上的箭垛里好象还有人
走来走去。阳光照来，城墙上闪过几道白光，似乎是兵器反射出的光。城
门上题着‘西门’两个大字，门口站着一些官兵，正手持兵刃盘问着来往
的行人们。从这里折而向北，就是终南山脚了。
LONG
	);

	set("exits", ([
		"east" : __DIR__"xijie",
		"northeast" : __DIR__"shanlu1",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
	replace_program(ROOM);
}