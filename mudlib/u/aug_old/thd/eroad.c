// thd:eroad.c

inherit ROOM;

void create()
{
      set("short", "石板路");
	set("long", @LONG
这里是桃花岛的东面，你要是沿着这条路一直往西走就可以到达桃花
岛的中心也就是桃花岛主黄药师的住所，但你面前那千百株桃花树看一眼
就要头晕，更别说在其中发现正确的道路了。此时正是桃花盛开的时节，
千千万万朵桃花在你眼前摇弋着，就如同千千万万朵粉红色的云彩。你眼
看着这盛开的桃花，鼻中闻着着醉人的花香，一时间陶醉在这片世外桃源
之中，似乎已经忘记了真实的时空。而石板路的东面有一座精巧的亭子。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/yapu3" :  2,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"bulletin" : "...\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"east",
          "east" : __DIR__"front_testsword",
          "northwest" : __DIR__"neroad",
          "southwest" : __DIR__"seroad",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

