// Room: /u/yuki/songshan/qingong.c

inherit ROOM;

void create()
{
	set("short", "寝宫");
	set("long", @LONG
    左冷禅的夫人就住在这里。她生平喜爱洁净，简洁，所以屋子里
面没什么豪华的摆设，所有家具都很简单。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chufang",
]));
        set("objects", ([
                __DIR__"npc/furen" :1,
        ]));


	setup();
	replace_program(ROOM);
}
