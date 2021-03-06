// Room: /u/swordman/yangzhou/damingshi1
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG
这里是雄伟庄严的大雄宝殿，两边是青面撩牙的四大金刚，中间供奉着
如来佛祖的金像，殿内香烟缭绕，无数善男信女来此烧香磕头，正中是一块
蒲团，供香客礼拜。右手是善缘箱，供钱财布施用。殿后有一小门，通往禅
房。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhuchi" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chanfang",
  "south" : __DIR__"damingshi",
]));

        create_door("north", "小门", "south", DOOR_CLOSED);
  setup();
}
