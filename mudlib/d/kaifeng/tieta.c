// Room: /d/kaifeng/tieta.c

inherit ROOM;

void create()
{
	set("short", "开封铁塔");
	set("long", @LONG
塔高55米.八角十三层.当年此地为宋开宝寺，故又名『开宝寺塔』，
塔身为褐色琉璃砖砌成混私铁铸，民间俗称其为铁塔.塔身修长,气势
雄伟,砖面饰以飞天,佛像,乐伎等数十种图案,栩栩如生。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 2,
]));
	set("outdoors", "/d/kaifeng");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jieying",
  "east" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
