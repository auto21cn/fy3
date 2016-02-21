// Room: /d/xxy/zhuting
#include <room.h> 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "石屋");
  set ("long", @LONG
这所长宽各达数十丈的高大房子完全是用大石头叠起,坚不可破.两排
长明灯绕墙而明.一根巨大石柱从地下升起,撑起屋顶,四面墙上雕刻着许多
花纹,走兽,神灵.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoudao3",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "石柱" : "这根柱子需十多人才能抱过.隐隐露出淡淡的紫色纹理.
",
]));
   create_door("south","厚木门","north",DOOR_CLOSED);
  setup();
}
void init()
{
    add_action("do_tune","move");
}
int do_tune(string str)
{
     object ob;
          ob=this_player();
    if (!ob||environment(ob)!=this_object()) return notify_fail("");
  if (!str) return notify_fail("你要移动什么东西?\n");
  if (str!="石柱") return 0;
  message_vision("$N双手抱住大厅中的石柱，用力转动!\n",ob);
  message_vision("大厅西侧的墙面缓缓退去，$N走了进去.\n",ob);
  ob->move(__DIR__"mishi");
  return 1;
}