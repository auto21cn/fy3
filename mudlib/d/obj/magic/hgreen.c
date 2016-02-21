// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit HAMMER;

void create()
{
  set_name("��ɫ��ë", ({ "green hair", "greenhair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ������ɫ�ĺ�ë������������ɴ���������transform����\n");
    set("unit", "��");
    set("value",10000);
  }
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  init_hammer(10+random(20));
  setup();
}

string name_suffix()
{
  return "��";
}


string new_unit()
{
  return "��";
}

int init ()  
{   
  add_action ("do_transform", "transform");
  add_action ("do_wield", "wield");
  return 1;
}

int do_wield (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"���Ƚ������������Ҫ��������\n");
    return 1;
  }
  return 0; // to invoke standard function
}
