//Room: majiu1.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���ǿ͵������ǣ����깩Ӧ���ʲ��ϡ������Թ����ӽ��£�ɶ����
��أ��͵�Ҳ�ػ��ź��ˣ������ǻ����ǣ�����Ǻ����տ���������ι��
���㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·�����������µ���ľ����
����һ����ľ��(paizi)��
    �����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "city2");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
//	"/d/chengdu/npc/zaohongma":1,
//	"/d/chengdu/npc/huangbiaoma":1,
//	"/d/chengdu/npc/ziliuma":1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ������һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ��  ��  ��:  rideyz
          ��ͼ������:  rideht


TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"kedian",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}