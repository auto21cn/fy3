// Room: /d/lingjiu/chufang.c

inherit ROOM;

void create()
{
	set("short", "藕香榭");
	set("long", @LONG
这是间厨房， 浓郁的饭菜香味一个劲地钻进你的鼻子， 你仿佛听到
“咕咕”的响声，环顾四周不知来源。 原来是你的肚子作怪。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 4 */
  "/daemon/class/lingjiu/tbcheng.c" : 1,
  __DIR__"obj/gao" : 2,
  __DIR__"obj/suanmei" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changl6",
]));

	setup();
	replace_program(ROOM);
}
