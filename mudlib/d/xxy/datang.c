// Room: /d/xxy/datang 
inherit ROOM; 
 
void create ()
{
  set ("short", "大厅");
  set ("long", @LONG
进门是一间广阔的大厅,外面的粉墙高有丈五,这大厅却是地平窄门. 
厅门摆设很多桌椅,乍看十分杂乱,其实暗含菊笫?西墙角,有条长长的 
柜台,柜台里面坐着两个面目清秀的中年人,正在弈棋.正面的粉墙上一 
块好大的牌子(sign),吸引了大家的目光. 
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yongdao2",
  "west" : __DIR__"yongdao",
  "north" : __DIR__"zoulang",
  "southdown" : __DIR__"fdian",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "        本店住宿分五等 
            －等：获得[我]级武士称号，入主院内天风楼； 
            二等：获得[武]级武士称号，入住院内武字楼; 
            三等: 获得[威]级武士称号，入住院内[威]级寝室; 
            四等: 获得[扬]级武士称号，入住院内[扬]级寝室; 
            五等:凡不能获得武士称号者，可在本店东侧大敞铺休息; 
 注:请到西侧比武厅测试.
",
]));
  set("objects", ([ /* sizeof() == 2 */
//	  "/d/jinding/obj/pot.c" : 1,
  __DIR__"npc/dazhanggui.c" : 1,
]));

  setup();
}
int valid_leave(object me,string dir)
{
   object ob;
   ob=present("pai",me);
   if (!ob&&dir=="north")
         return notify_fail("大掌柜一把拉住"+me->name()+",指了指墙上的招牌!\n");
   else 
  return ::valid_leave(me,dir);
}
