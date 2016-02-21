// music yangzhou's 叉路口 1

inherit ROOM;

void create()
{
  set ("short", "叉路口");
  set ("long", @LONG
	这是一个叉路，南面通往扬州城区，北面通往瘦西湖山庄，西
面是一片无边旷野，放眼望去不见人烟，隐约有条泥泞小道，不知通向
哪里，也许可能找人打听打听。
LONG);

  set("objects", ([ /* sizeof() == 1 */
           __DIR__"npc/xiaofan" : 1,
                 ]));
  set("outdoors", "/d/yangzhou");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huangye5",
  "south" : __DIR__"jiedao1",
  "north" : __DIR__"jiedao4",
]));
  setup();
}
