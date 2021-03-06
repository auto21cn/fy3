// Room: /d/kaifeng/qianshou.c

inherit ROOM;

void create()
{
	set("short", "千手千眼佛殿");
	set("long", @LONG
这座佛殿中供奉的是千手千眼观音，据说观音菩萨普渡众生，化身
万千。你仔细看去，只见佛像伸出长长短短的手臂，每个手掌中心都
有只眼睛。意思是警告你『我眼睛多，什么都能注意到，我手多，什么
都能管到，可别作坏事。』.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fangsheng",
  "east" : __DIR__"houyuan",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/oldwomen.c" : 1,
  __DIR__"npc/obj/guanyin.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
