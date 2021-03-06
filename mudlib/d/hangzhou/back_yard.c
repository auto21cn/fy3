// Room: /d/hangzhou/back_yard.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这个练武场建在厅堂的后面,场地四面遍植杨柳,边上摆着几个石锁. 
几个弟子正挥舞着兵器拆招练式.北面的空地上竖着几根木桩(logs)，还 
挖了若干个大沙坑(pits)。东面是一间厢房,备客人休息. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 2,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "pits" : "沙坑里有些年轻人在练习轻功，你也可以跳(tiao)下去试试。 
",
  "logs" : "几根木桩上有不少兵器打过的痕迹(da)。 
",
]));
	set("outdoors", "/d/hangzhou");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating.c",
  "east" : __DIR__"sleep_room.c",
]));

	setup();
	replace_program(ROOM);
}
