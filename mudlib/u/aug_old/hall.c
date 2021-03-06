// lu:hall.c
#include <localtime.h>

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是归云庄议事的大厅。这大厅占地极广，足有三十多平米。厅中
有四根一人都抱不过来的大石柱，其中一根柱上还有个清晰的手掌印。厅
中正中一把太师椅，两旁各有十来把椅子，这椅子都是上好的红楠木制成
的，看来甚为珍贵。太师椅后面是张供桌，供奉这福禄寿三仙，两旁两根
小臂般粗细的红蜡烛。大厅的西边是庄主的书房，东边是归云庄的武库，
北边是庄主的寝室，东北是炼丹房，南面是练武场。
LONG
	);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/lu_guanying" :  1,
	]));

	set("detail", ([ /* sizeof() == 1 */
		"手掌印" : "这个手掌印据说是庄主的师妹梅超风和江南七怪的弟子郭靖交手时留下的。\n",
]));

	set("exits", ([ /* sizeof() == 5 */
		"east" : __DIR__"weapon_room",
		"west" : __DIR__"bookroom",
		"north": __DIR__"bedroom",
		"south": __DIR__"square",
       	"northeast": __DIR__"pharmacy",
	]));

	set("outdoors", "lu_town");

      set("valid_startroom", 1);
	setup();
//	replace_program(ROOM);
//	load_object("/daemon/board/lu_b");
	"/obj/board/luboard"->foo();

}

int valid_leave(object me, string dir)
{
  mapping gt;
  object ob;

  gt = NATURE_D->game_time(1);
/*
  if((gt[LT_HOUR] <=6 )||(gt[LT_HOUR] >=22)) 
  {
    if(dir=="west") 
      return notify_fail("你发现书房的门已经被锁起来了，你进不去。\n");
    if(dir=="north") 
      return notify_fail("你发现寝室的门已经被锁起来了，你进不去。\n");
  }
*/

  ob = present("lu", this_object());
  if( objectp(ob) && ob->is_npc() )
  {
 // by musix  if((dir!="south")&&((string)me->query("class")!="taohua")) 
       if((dir!="south")&&((string)me->query("family/family_name")!="桃花岛"))
      return notify_fail("陆少庄主双手一拦，不让你进去，说道：你不是桃花岛弟子,不能进去。\n");
  }
  
  if(dir=="northeast")
    me->set_temp("kick",0); 

  return ::valid_leave(me, dir);  
}
