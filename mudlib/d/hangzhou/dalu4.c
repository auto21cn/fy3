// Room: /d/hangzhou/npc/dalu4 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "大路");
  set ("long", @LONG
一条宽阔的大道,来往的人络绎不绝,扬起一路的风尘,从此向东,
有个叉路口,再向北就是雁荡山区,而向西南则是杭州.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/suzhou/dadao3",
  "east" : __DIR__"dalu3",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "e" : "",
]));
  set("outdoors", "/d/hangzhou");
  setup();
}
