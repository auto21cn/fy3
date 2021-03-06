// Room: /d/quanzhou/haigang
inherit ROOM;

void create ()
{
  set ("short", "安海港");
  set ("long", @LONG
安海港是附近最大的海港,停满了各类的商船,因为离次不远就是台湾 
岛,所以来往的船只很多,远达东瀛异国.码头上来往的船员,搬运工,甚至 
暗娼小贩,不一而足. 
LONG);

  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chuanlaoda.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wuliqiao",
  "enter":__DIR__"duchuan",
]));
  set("outdoors", "/d/quanzhou");
  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if ((dir=="enter") && !me->query_temp("luyin/target"))
	{
		ob = present("sun", this_object());
	if(objectp(ob)&&!userp(ob)&&living(ob))
		{
			message_vision("\n$N伸手把$n拦住说：这位客官,请先验看路引！\n", ob, me);
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
