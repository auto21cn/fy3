// Room: /u/swordman/yangzhou/nandaj3.c

inherit ROOM;

void create ()
{
  set ("short", "南大街");
  set ("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。西边是兵营所在，行人 
稀少，静悄悄地很是冷清。东边是一个杂货铺，由这往南是扬州南门。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chefu" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zahuopu",
  "west" : __DIR__"bingying",
  "north" : __DIR__"nandaj2",
  "south" : __DIR__"nanmen",
]));
  set("outdoors", "/u/swordman");

  setup();
}
