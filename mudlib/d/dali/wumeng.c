// Room: /d/dali/wumeng.c

inherit ROOM;

void create()
{
	set("short", "乌蒙村落");
	set("long", @LONG
这里是山的缓坡，乌夷人搬石去土，把这里修成一层层阶梯状的
平台，民居分别建在各处平台上，互不连接，各自有石砌围墙，村中
道路也由石头铺成。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muyangren.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wuyiminju2",
  "north" : __DIR__"wuyiminju1",
  "east" : __DIR__"caopo",
  "west" : __DIR__"wunong",
]));
	set("outdoors", "dali");

	setup();
	replace_program(ROOM);
}
