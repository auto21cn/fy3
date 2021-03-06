// Room: /d/huanggon/ndajie.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
北大街横贯东西,从皇宫的后门穿过.这条街道位于京城的北面,店铺
较少,所住的都是些穷苦人.来往的人多面带菜色,此地向南拐,就是店铺林
立的王府井了.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  "/d/taishan/npc/dao-ke.c" : 1,
  "/d/taishan/npc/jian-ke.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wangfujing2",
  "west" : __DIR__"ndajie1",
]));

	setup();
	replace_program(ROOM);
}
