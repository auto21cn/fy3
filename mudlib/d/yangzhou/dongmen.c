// Room: /u/swordman/yangzhou/dongmen.c

inherit ROOM;

void create ()
{
  set ("short", "扬州东门");
  set ("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，官兵们警惕
地注视着过往行人，你最好小心为妙。一条笔直的青石板大道向东
西两边延伸。东边是郊外，隐约可见一片一望无际的树林，神秘莫
测。西边是城里。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing" : 3,
]));
  set("outdoors", "x");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jiaowai",
  "west" : __DIR__"ddajie1",
]));

  setup();
}
