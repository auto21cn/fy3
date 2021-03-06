// Room: /u/swordman/yangzhou/ycsz
inherit ROOM;

void create ()
{
  set ("short", "砚池山庄");
  set ("long", @LONG
砚池山庄旧名荷花山庄，大概是因为每年夏季，庄内荷花
满池的原故吧。原先这里是扬州大盐商何永贵的私宅，后因盐
业没落，易主多次后被当代文豪，“扬州八怪”之首的--郑板
桥所得。因就池挥毫洗墨，故题名曰“砚池山庄”。庄中翠竹
掩映，碧水荡漾，文人墨客常畅谈于此，乐而忘返。向南是一
片青竹林。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xijie2",
  "south" : __DIR__"ycsz1",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mentu" : 2,
]));

  setup();
}
