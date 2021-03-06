// Room: /u/xxy/room/fenhuang.c

inherit ROOM;

void create()
{
	set("short", "凤凰台");
	set("long", @LONG
这个小山包高约十米,径约三十米,古称凤凰堡,堡上建有"圣积晚钟亭",
亭中悬挂莲花铜钟(zhong)一口.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/emei");
	set("item_desc", ([ /* sizeof() == 1 */
  "zhong" : "钟高2.8米,钟唇径2.4米,重1.25万公斤,号称'天府钟王',
钟体铸刻着晋唐以来历代帝王和高僧的名号,以及'阿含经'
文,连同佛揭,铭,疏等共约七万字.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"road",
  "northdown" : __DIR__"gate",
]));

	setup();
	replace_program(ROOM);
}
