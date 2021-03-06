// Room: /d/kaifeng/daxiong.c

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
经过九级石头台阶，正面就是佛祖神像，两边普贤和文殊。高大的
佛像几乎挨到了屋顶，令人凌然生威。正对着门的地方摆着供桌，上面
是时鲜的瓜果。供桌两边的大蜡烛比人还高。两边是十八罗汉。
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/rulaixiang.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhongyuan",
  "north" : __DIR__"houyuan",
]));

	setup();
	replace_program(ROOM);
}
