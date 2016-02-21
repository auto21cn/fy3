// Room: /d/huanggon/kunningon.c

inherit ROOM;

void create()
{
	set("short", "坤宁宫");
	set("long", @LONG
坤宁宫原先是皇后的居处,后来改成皇帝和皇后结婚的洞房.按照规矩
结婚后要在此过上三天.此殿的中间是满人举行萨满教仪式的神殿.坤宁宫
南是交泰殿,北面过坤宁门就是御花园.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiaotaidian",
  "north" : __DIR__"yuhuayuan2",
]));

	setup();
	replace_program(ROOM);
}
